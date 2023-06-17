#include "boss.h"

Boss::Boss(int id, string name, int did) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Boss::ShowInfo() {
	cout << "老板id" << this->m_ID << endl;
	cout << "老板名字" << this->m_Name << endl;
	cout << "老板部门id" << this->m_DeptID << endl;
}

string Boss::getDeptName() {
	return string("老板");
}