#include "boss.h"

Boss::Boss(int id, string name, int did) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Boss::ShowInfo() {
	cout << "�ϰ�id" << this->m_ID << endl;
	cout << "�ϰ�����" << this->m_Name << endl;
	cout << "�ϰ岿��id" << this->m_DeptID << endl;
}

string Boss::getDeptName() {
	return string("�ϰ�");
}