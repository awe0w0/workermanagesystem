#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

class workManager {
public:
	workManager();

	int m_EmpNum;

	Worker** m_EmpArray;

	void Add_Emp();

	void Show_Menu();

	void Exit();

	//增加职员
	void addWorker();

	~workManager();

};