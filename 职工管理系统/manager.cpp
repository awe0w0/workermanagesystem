#include "manager.h"

Manager::Manager(int id,string name,int did) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Manager::ShowInfo() {
	cout << "经理id" << this->m_ID << endl;
	cout << "经理姓名" << this->m_Name << endl;
	cout << "经理部门" << this->m_DeptID << endl;
}

string Manager::getDeptName() {
	return string("经理");
}