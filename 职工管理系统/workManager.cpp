#include "workManager.h"

workManager::workManager() {
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
}

workManager::~workManager() {
	
}

void workManager::Add_Emp() {

	cout << "请输入增加职工数量" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {
		
		int newSize = this->m_EmpNum +addNum;

		Worker** newSpace = new Worker * [newSize];

		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "位职员id" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "位职员姓名" << endl;
			cin >> name;

			cout << "请输入该职工的岗位" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, i);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;

			default:
				break;
			}

			newSpace[this->m_EmpNum + i] = worker;


		}

		delete m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;

		cout << "成功添加" << addNum << "位新员工" << endl;
	}


	else {
		cout << "请输入正确的数值" << endl;
	}
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