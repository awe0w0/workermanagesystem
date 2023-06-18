#include "manager.h"

Manager::Manager(int id,string name,int did) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Manager::ShowInfo() {
	cout << "id：" << this->m_ID << "\t";
	cout << "姓名：" << this->m_Name << "\t";
	cout << "岗位：经理" << "\t";
	cout << "岗位职责：完成老板的任务" << endl;
}

string Manager::getDeptName() {
	return string("经理");
}