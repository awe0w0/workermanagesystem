#include "employee.h"

Employee::Employee(int id,string name,int d_id) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = d_id;
}

void Employee::ShowInfo() {
	cout << "员工id：" << this->m_ID << endl;
	cout << "员工姓名：" << this->m_Name << endl;
	cout << "部门id：" << this->m_DeptID << endl;
	cout << "岗位职责：与经理配合" << endl;
}

string Employee::getDeptName() {
	return string("员工");
}