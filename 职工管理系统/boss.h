#pragma once
#include "worker.h"

class Boss:public Worker {
public:

	Boss(int id, string name, int did);

	virtual void ShowInfo() = 0;

	virtual string getDeptName() = 0;
};