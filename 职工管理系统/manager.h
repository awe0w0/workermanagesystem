#pragma once
#include "worker.h"

class Manager:public Worker {
public:
	Manager(int id,string name,int did);

	virtual void ShowInfo();

	virtual string getDeptName();
};