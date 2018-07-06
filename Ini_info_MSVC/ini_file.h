#pragma once
#include "DynamicList_cl.h"
#include <fstream>

using namespace std;

class ini_file
{
public:
	ini_file();
	virtual ~ini_file();

	const DynamicList_cl<Sector_st>& get_list();

	/// ������� ��
	void clear();
	/// �������� �� (file_name - ��� �����)
	/// ���������� true � ������ ������ � false ���� ��������� ������;
	bool load(const char * file_name);
	/// ���������� �� (file_name - ��� �����)
	/// ���������� true � ������ ������ � false ���� ��������� ������;
	bool store(const char * file_name);
	/* ������� ������ � �������� �� */
	/// ���������� ����� ������
	__int32 get_section_count() const;
	/// ������� ������ � ������ section � ��� �� ����������
	bool delete_section(const char * section);
	/* ������� ������ � ����������� �� */
	// ����������/�������� ��������
	// 1. ���� ����������, �� �������� ��������
	// 2. ���� �� ����������, �� ������ �������, �� �������� � ����� ������
	// 3. ���� �� ����������, � ������ �� �������, �� �������� � ����� ������ � ���� ����������
	/// ����� ������ buf � �������� param ������ section
	bool set_param(const char * section, const char * param, const char * buf);
	/// ����� ������ ����� ����� buf[0..count-1] � �������� param ������ section
	bool set_param(const char * section, const char * param, int count, const int * buf);
	/// ����� ������ ����� c ��������� ������ buf[0..count-1] � �������� param ������ section
	bool set_param(const char * section, const char * param, int count, const double * buf);
	/// ������ � buf ������ (������ �����) �� ��������� param ������ section
	/// max_buf_size : ������ ������ ��� ������ ������
	/// need_count: ���-�� ��������� ��� ������ ������� �����
	/// fact_count : ������ ����������� ������
	/// ���������� true � ������ ������ � false ���� ��������� ������;
	bool get_param(const char * section, const char * param, int max_buf_size, int * fact_count, char * buf);
	bool get_param(const char * section, const char * param, int need_count, int * fact_count, int * buf);
	bool get_param(const char * section, const char * param, int need_count, int * fact_count, double * buf);
	/// ������� �������� param �� ������ section
	bool delete_param(const char * section, const char * param);

private:
	DynamicList_cl<Sector_st> Sector_list;

	void parse_buffer(char *ch);

};

