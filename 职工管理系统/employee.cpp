#include "employee.h"

Employee::Employee(int id,string name,int d_id) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = d_id;
}

void Employee::ShowInfo() {
	cout << "id��" << this->m_ID << "\t";
	cout << "������" << this->m_Name << "\t";
	cout << "��λ��Ա��" <<"\t";
	cout << "��λְ���뾭�����" << endl;
}

string Employee::getDeptName() {
	return string("Ա��");
}