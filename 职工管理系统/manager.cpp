#include "manager.h"

Manager::Manager(int id,string name,int did) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Manager::ShowInfo() {
	cout << "id��" << this->m_ID << "\t";
	cout << "������" << this->m_Name << "\t";
	cout << "��λ������" << "\t";
	cout << "��λְ������ϰ������" << endl;
}

string Manager::getDeptName() {
	return string("����");
}