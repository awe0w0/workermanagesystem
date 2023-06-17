#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#define FILENAME "empFile.txt"

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

class workManager {
public:
	workManager();

	int m_EmpNum;

	Worker** m_EmpArray;

	bool m_FileIsEmpty;

	int get_EmpNum();

	void init_Emp();

	void Add_Emp();

	void save();

	void Show_Menu();

	void Exit();

	//增加职员
	void addWorker();

	~workManager();

};