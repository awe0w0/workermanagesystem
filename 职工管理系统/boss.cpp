#include "boss.h"

Boss::Boss(int id, string name, int did) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Boss::ShowInfo() {
	cout << "id��" << this->m_ID << "\t";
	cout << "������" << this->m_Name << "\t";
	cout << "��λ��" << "�ϰ�" << "\t";
	cout << "��λְ�𣺹���˾" << endl;
}

string Boss::getDeptName() {
	return string("�ϰ�");
}