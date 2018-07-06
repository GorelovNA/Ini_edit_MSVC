#include "ini_file.h"

ini_file::ini_file()
{
}

ini_file::~ini_file()
{
}

const DynamicList_cl<Sector_st>& ini_file::get_list()
{
	return Sector_list;
}

/// ������� ��
void ini_file::clear() {
	Sector_list.clear();
}
/// �������� �� (file_name - ��� �����)
/// ���������� true � ������ ������ � false ���� ��������� ������;
bool ini_file::load(const char * file_name) { 
	ifstream* inp = new ifstream(file_name);
	char* buf_name = new char[2048];

	if (!inp->good())
	{
		cout << "File opening error!\n";
		system("PAUSE");
		return 0;
	}
	while (!inp->eof())
	{		
		inp->getline(buf_name, 2048, '[');
		char *ch; ch = buf_name;
		parse_buffer(ch);//������ ������, ��������� ������
	}
	inp->close();
	delete inp;	
	return 1; 
}
/// ���������� �� (file_name - ��� �����)
/// ���������� true � ������ ������ � false ���� ��������� ������;
bool ini_file::store(const char * file_name) { 
	ofstream fout(file_name);
	if (fout.is_open()) {
		Sector_st *sec = Sector_list.head;
		while (sec != NULL) {
			fout << sec->name << endl;
			Param_st *param = sec->Param.head;
			while (param != NULL) {
				fout << param->name;
				if (strlen(param->value) != 0) {
					fout << "=";
					fout << param->value;
				}
				fout << endl;
				param = param->next;
			}
			sec = sec->next;
		}
		fout.close();
		return 1;
	}
	else return 0;
}
/* ������� ������ � �������� �� */
/// ���������� ����� ������
__int32 ini_file::get_section_count() const { 
	__int32 count = 0;
	Sector_st *st;
	st = Sector_list.head;
	while (st != NULL) {
		count++;
		st = st->next;
	}
	return count; }

/// ������� ������ � ������ section � ��� �� ����������
bool ini_file::delete_section(const char * section) { 
	Sector_st *st = Sector_list.search(section);
	if (st == NULL) return 0; //����� ������ ���
	else Sector_list.del_comp(st);
	return 1; }

/// ������� �������� param �� ������ section
bool ini_file::delete_param(const char * section, const char * param) { 
	Sector_st *st = Sector_list.search(section);
	if (st == NULL) return 0; //����� ������ ���
	else {
		Param_st *pt = st->Param.search(param);
		if (pt == NULL) return 0; //��� ������ ���������
		else {
			st->Param.del_comp(pt);
		}
	}
	return 1; }

/* ������� ������ � ����������� �� */
// ����������/�������� ��������
// 1. ���� ����������, �� �������� ��������
// 2. ���� �� ����������, �� ������ �������, �� �������� � ����� ������
// 3. ���� �� ����������, � ������ �� �������, �� �������� � ����� ������ � ���� ����������
/// ����� ������ buf � �������� param ������ section
bool ini_file::set_param(const char * section, const char * param, const char * buf) { 
	if (section == NULL) return 0;
	Sector_st *sec = Sector_list.search(section);
	if (sec == NULL) {//������ �� �������
		if (strlen(section) == 0) return 0;
		Sector_st *s = new Sector_st;
		strcpy_s(s->name, sizeof(s->name), section);
		if (param != NULL) {
			if (strlen(param) == 0) return 0;
			Param_st *p = new Param_st;
			strcpy_s(p->name, sizeof(p->name), param);
			if(buf != NULL)
				strcpy_s(p->value, sizeof(p->value), buf);
			s->Param.add_comp(p);
		}
		Sector_list.add_comp(s);
	}
	else {//������ �������
		Param_st *s = sec->Param.search(param);
		if (s == NULL){//�������� �� ������
			if (param != NULL){
				Param_st *p = new Param_st; //������� �����
				strcpy_s(p->name, sizeof(p->name), param);
				if (buf != NULL)
					strcpy_s(p->value, sizeof(p->value), buf);
				sec->Param.add_comp(p);
			}
		}
		else {//�������� ������
			if (buf != NULL)
				strcpy_s(s->value, sizeof(s->value), buf);
		}
	}
	return 1; }
/// ����� ������ ����� ����� buf[0..count-1] � �������� param ������ section
bool ini_file::set_param(const char * section, const char * param, int count, const int * buf) { 
	char buf_int[20];
	char buf_final[200];

	int j;
	int f = 0;
	for (int i(0); i < count; i++) {
		itoa(buf[i], buf_int, 10);

		j = 0;
		while (buf_int[j] != '\0') {
			buf_final[f] = buf_int[j];
			f++;
			j++;
		}
		buf_final[f] = ' ';
		f++;
	}
	buf_final[f] = '\0'; 
		
	const char* p = buf_final;
	set_param(section, param, p);
	return 1; }
/// ����� ������ ����� c ��������� ������ buf[0..count-1] � �������� param ������ section
bool ini_file::set_param(const char * section, const char * param, int count, const double * buf) { 
	char buf_int[20];
	char buf_final[200];

	int j;
	int f = 0;
	for (int i(0); i < count; i++) {		
		sprintf(buf_int, "%f", buf[i]);

		j = 0;
		while (buf_int[j] != '\0') {
			buf_final[f] = buf_int[j];
			f++;
			j++;
		}
		buf_final[f] = ' ';
		f++;
	}
	buf_final[f] = '\0';

	const char* p = buf_final;
	set_param(section, param, p);
	return 1;
}

/// ������ � buf ������ (������ �����) �� ��������� param ������ section
/// max_buf_size : ������ ������ ��� ������ ������
/// need_count: ���-�� ��������� ��� ������ ������� �����
/// fact_count : ������ ����������� ������
/// ���������� true � ������ ������ � false ���� ��������� ������;
bool ini_file::get_param(const char * section, const char * param, int max_buf_size, int * fact_count, char * buf) { 
	if (section == NULL || param == NULL) {  return 0; }
	Sector_st *sec = Sector_list.search(section);
	if (sec == NULL) return 0;//������ �� �������
	else {
		Param_st *s = sec->Param.search(param);
		if (s == NULL) return 0;//�������� �� ������
		else {
			if (strlen(s->value) > max_buf_size) return 0;
			else strcpy_s(buf, max_buf_size, s->value);
			*fact_count = strlen(s->value);
		}
	}
	return 1; }


bool ini_file::get_param(const char * section, const char * param, int need_count, int * fact_count, int * buf) { 
	char buf_char[200];
	int fact_count_char = 0;
	*fact_count = 0;
	get_param(section, param, 200, &fact_count_char, &buf_char[0]);	

	int b = 0;
	char temp[100];
	int t = 0;
	while (buf_char[b] != '\0') {
		if (*fact_count >= need_count) return 0;
		if (buf_char[b] == ' ') {
			temp[t] = '\0';
			buf[*fact_count] = atoi(temp);
			*fact_count+=1;
			t = 0; b++;
		}		
		else {
			temp[t] = buf_char[b];
			t++; b++;
		}	
	}
	if (t > 0) {
		temp[t] = '\0';
		buf[*fact_count] = atoi(temp);
		*fact_count += 1;
	}
	return 1; }


bool ini_file::get_param(const char * section, const char * param, int need_count, int * fact_count, double * buf) { 
	char buf_char[200];
	int fact_count_char = 0;
	*fact_count = 0;
	//get_param(section, param, 200, &fact_count_char, &buf_char[0]);
	strcpy_s(buf_char, 200, "1.6 5.7 6.66");

	int b = 0;
	char temp[100];
	int t = 0;
	while (buf_char[b] != '\0') {
		if (*fact_count >= need_count) return 0;
		if (buf_char[b] == ' ') {
			temp[t] = '\0';
			buf[*fact_count] = atof(temp);
			*fact_count += 1;
			t = 0; b++;
		}
		else {
			temp[t] = buf_char[b];
			t++; b++;
		}
	}
	if (t > 0) {
		temp[t] = '\0';
		buf[*fact_count] = atof(temp);
		*fact_count += 1;
	}
	return 1;
}

void ini_file::parse_buffer(char * ch)
{
	char *temp = new char[512];
	auto len = strlen(ch);
	int i = 0;
	int j = 0;
	for (i; i < len;) {
		while (ch[i] == ' ') i++; //���������� ������� � ������			

		j = 1;
		temp[0] = '[';
		while (ch[i] != '\n') {
			temp[j] = ch[i];
			i++;
			j++;
		}
		temp[j] = '\0';

		if (ch[i - 1] == ']') {//������ � ����� ��� �������
			//��������� ������ � ������
			Sector_st *sec = new Sector_st;//����������� ������ � ������ dynamiclist
			strcpy_s(sec->name,sizeof(sec->name),temp);
			Sector_list.add_comp(sec);//add section
			
			i++;
			while (i < len) {//��������� ��������� � ������				
				j = 0;
				
				while (ch[i] != '\n') { temp[j] = ch[i]; i++; j++; }
				temp[j] = '\0';

				Param_st *param = new Param_st;//����������� ������ � ������ dynamiclist

				j = 0;
				int v = 0;
				while(temp[v] == ' ') v++; //���������� ������� � ������
				while (temp[v] != '=' && v < strlen(temp)) { param->name[j] = temp[v]; j++; v++; }
				param->name[j] = '\0';
				j = 0;
				v++;
				while (v < strlen(temp)) { param->value[j] = temp[v]; v++; j++; }
				param->value[j] = '\0';

				//strcpy_s(param->name, sizeof(param->name), temp);
				Sector_list.tail->Param.add_comp(param);//add param

				i++;
			}
		}
		else break; //������ ��� �������, �� �����. ��, ����������
		i++;
	}

	delete[] temp;
}
