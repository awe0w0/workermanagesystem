#include "boss.h"

Boss::Boss(int id, string name, int did) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Boss::ShowInfo() {
	cout << "id：" << this->m_ID << "\t";
	cout << "姓名：" << this->m_Name << "\t";
	cout << "岗位：" << "老板" << "\t";
	cout << "岗位职责：管理公司" << endl;
}

string Boss::getDeptName() {
	return string("老板");
}