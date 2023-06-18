#include "employee.h"

Employee::Employee(int id,string name,int d_id) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = d_id;
}

void Employee::ShowInfo() {
	cout << "id：" << this->m_ID << "\t";
	cout << "姓名：" << this->m_Name << "\t";
	cout << "岗位：员工" <<"\t";
	cout << "岗位职责：与经理配合" << endl;
}

string Employee::getDeptName() {
	return string("员工");
}