#include "employee.h"

Employee::Employee(int id,string name,int d_id) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = d_id;
}

void Employee::ShowInfo() {
	cout << "Ա��id��" << this->m_ID << endl;
	cout << "Ա��������" << this->m_Name << endl;
	cout << "����id��" << this->m_DeptID << endl;
	cout << "��λְ���뾭�����" << endl;
}

string Employee::getDeptName() {
	return string("Ա��");
}