#pragma once
//template <typename T> class DynamicList_cl<T>;
#include <iostream>
#include <cstdlib>

struct Param_st;
struct Sector_st;

template <typename T>
class DynamicList_cl
{
public:
	T* head;
	T* tail;

	DynamicList_cl() {	// �������� ������� ������
		this->head = NULL;
	};
	~DynamicList_cl() {};
	
	//prototype;	
	bool chk_empty();// �������� ������ �� �������					 
	void add_comp(T* c);// ��������� � ������ ������ ����������						
	T* search(const char *n);// ����� ���������� � ������ �� �����
	void del_comp(Sector_st* sect);// �������� ���������� �� ������
	void del_comp(Param_st* param);// �������� ���������� �� ������
	//void edit_comp(Param_st & param, char * v);
	void edit_comp(Param_st & param, const char * name, const char * value);
	// ��������� �������� ����������
	void edit_comp(Sector_st & sect, char * v);// ��������� �������� ����������
	void clear();// �������

};

struct Param_st {
	Param_st() {
		name[0] = '\0';
		value[0] = '\0';
	}

	char name[200];
	char value[200];
	Param_st* next;
};

struct Sector_st {
	Sector_st() {
		name[0] = '\0';
	}
	char name[100];
	DynamicList_cl<Param_st> Param;
	Sector_st* next;
};




// �������� ������ �� �������
template <typename T>
bool DynamicList_cl<T>::chk_empty()
{
	return (this->head == NULL);
}


// ��������� � ������ ������ ����������
template <typename T>
void DynamicList_cl<T>::add_comp(T* c)
{
	//comp* c = new comp();//��������� � ini file
	//strcpy_s(c->name, 20, n);
	//strcpy_s(c->value, 10, v);
	c->next = NULL;
	if (this->chk_empty())
		this->head = c;
	else
		this->tail->next = c;
	this->tail = c;
}


// ����� ���������� � ������ �� �����
template <typename T>
T* DynamicList_cl<T>::search(const char *n)
{
	if (n == NULL) return NULL;
	T* head_temp;
	head_temp = this->head;
	while (head_temp != NULL)
	{
		if (!strcmp(head_temp->name, n))
			return head_temp;
		head_temp = head_temp->next;
	}
	return head_temp;
}


// �������� ���������� �� ������
template <typename T>
void DynamicList_cl<T>::del_comp(Param_st* param)
{
	if (param == this->head)
	{
		this->head = param->next;
		return;
	}
	Param_st* r = new Param_st();
	r = this->head;	
	while (r->next != param)
		r = r->next;
	r->next = param->next;
	delete param;
}
template <typename T>
void DynamicList_cl<T>::del_comp(Sector_st* sect)
{
	if (sect == this->head)
	{
		this->head = sect->next;
		return;
	}
	Sector_st* r = new Sector_st();
	r = this->head;
	while (r->next != sect)
		r = r->next;
	r->next = sect->next;
	delete sect;
}


// ��������� �������� ����������
template <typename T>
void DynamicList_cl<T>::edit_comp(Param_st &param, const char* name, const char* value)
{
	if(name != NULL && name[0] != '\0')
		strcpy_s(param.name, sizeof(param.name), name);
	if (value != NULL) {
		if (strlen(value) == 0)
			strcpy_s(param.value, sizeof(param.value), " ");
		else strcpy_s(param.value, sizeof(param.value), value);
	}
}
template <typename T>
void DynamicList_cl<T>::edit_comp(Sector_st &sect, char* v)
{
	//strcpy_s(c.value, 10, v);
}

//�������
template <typename T>
void DynamicList_cl<T>::clear() {
	T* r = new T;
	while(this->head != NULL){
		r = this->head->next;		
		delete this->head;
		this->head = r;
	}
	delete r;
}