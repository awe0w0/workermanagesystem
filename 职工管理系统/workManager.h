#pragma once
#include <iostream>
using namespace std;
#include <fstream>

class workManager {
public:
	workManager();

	void Show_Menu();

	void Exit();

	//增加职员
	void addWorker();

	~workManager();

};