#pragma once
#include "workManager.h"
#include <string>

class Worker {
public:
	//显示员工信息
	virtual void ShowInfo() = 0;
	//获取部门名称
	virtual string getDeptName() = 0;

	int m_ID;//职工编号
	string m_Name;//职工姓名
	int m_DeptID;//职工所在部门id
};