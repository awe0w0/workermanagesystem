#include "manager.h"

Manager::Manager(int id,string name,int did) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Manager::ShowInfo() {
	cout << "����id" << this->m_ID << endl;
	cout << "��������" << this->m_Name << endl;
	cout << "������" << this->m_DeptID << endl;
}

string Manager::getDeptName() {
	return string("����");
}