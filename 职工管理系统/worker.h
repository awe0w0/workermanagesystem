#pragma once
#include "workManager.h"
#include <string>

class Worker {
public:
	//��ʾԱ����Ϣ
	virtual void ShowInfo() = 0;
	//��ȡ��������
	virtual string getDeptName() = 0;

	int m_ID;//ְ�����
	string m_Name;//ְ������
	int m_DeptID;//ְ�����ڲ���id
};