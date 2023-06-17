#include "workManager.h"

workManager::workManager() {
	
}

workManager::~workManager() {
	
}

void workManager::Show_Menu() {
	cout << "-----------------------------" << endl;
	cout << "-----欢迎使用职工管理系统----" << endl;
	cout << "--------0.退出管理程序-------" << endl;
	cout << "--------1.增加职工信息-------" << endl;
	cout << "--------2.显示职工信息-------" << endl;
	cout << "--------3.删除离职职工-------" << endl;
	cout << "--------4.修改职工信息-------" << endl;
	cout << "--------5.查找职工信息-------" << endl;
	cout << "--------6.按照编号排序-------" << endl;
	cout << "--------7.清空所有文档-------" << endl;
	cout << "-----------------------------" << endl;
	cout << endl;
}

void workManager:: addWorker() {
	cout << "请输入要添加的职员数量" << endl;
	ofstream ofs;
	ofs.open("worker.txt", ios::out | ios::app);
	int num = 0;
	cin >> num;
	while (num) {
		cout << "请输入职员身份" << endl;
		char a[10] = { 0 };
		cin >> a;
		ofs << a << endl;
		cout << "请输入职员id" << endl;
		char id[10] = {0};
		cin >> id;
		ofs << id << endl;
		cout << "请输入职员姓名" << endl;
		char name[10] = { 0 };
		cin >> name;
		ofs << name << endl;
		cout << "请输入职员部门" << endl;
		char did[10] = { 0 };
		cin >> did;
		ofs << did << endl;
		cout << "添加成功" << endl;
		num--;
	}
	ofs.close();
}

void workManager::Exit() {
	cout << "感谢您的使用" << endl;
	system("pause");
	exit(0);
}