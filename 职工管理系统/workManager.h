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

	void Show_Emp();

	void Show_Info(int i);

	void Sort_Emp(Worker ** arr, int begin, int end);

	void Del_Emp();

	int IsExist(int id);

	void Mon_Emp();

	void Find_Emp();

	void Add_Emp();

	void save();

	void Show_Menu();

	void Exit();

	//增加职员
	void addWorker();

	~workManager();

};