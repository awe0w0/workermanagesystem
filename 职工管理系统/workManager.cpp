#include "workManager.h"

workManager::workManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {
		cout << "找不到员工表文件" << endl;
		this->m_EmpNum = 0;;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	int num = this->get_EmpNum();
//	cout << "员工数量为" << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];

	this->init_Emp();

}

workManager::~workManager() {
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		m_EmpArray = NULL;
	}
	
}

void workManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_ID << " ";
		ofs << this->m_EmpArray[i]->m_Name << " ";
		ofs << this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();

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
				worker = new Employee(id, name, 1);
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

		this->save();

		cout << "成功添加" << addNum << "位新员工" << endl;
		this->m_FileIsEmpty = false;
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
	cout << "------------8.清屏-----------" << endl;
	cout << "-----------------------------" << endl;
	cout << endl;
}

int workManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int dId;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	ifs.close();
	return num;
}

void workManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		}

		else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}

		else if (dId == 3) {
			worker = new Boss(id, name, dId);
		}

		this->m_EmpArray[index] = worker;
		index++;

	}
	
	ifs.close();
}

void workManager::Show_Info(int i) {

		cout << "职工号：" << this->m_EmpArray[i]->m_ID<<"\t"
			<< "职工姓名：" << this->m_EmpArray[i]->m_Name<<"\t";
		switch (m_EmpArray[i]->m_DeptID)
		{
		case 1:
			cout << "岗位：员工" << "\t";
			cout << "岗位职责：与经理合作完成任务" << endl;
			break;
		case 2:
			cout << "岗位：经理" << "\t";
			cout << "岗位职责：完成老板的任务"<<endl;
			break;
		case 3:
			cout << "岗位：老板" << "\t";
			cout << "岗位职责：管理公司"<<endl;
			break;

		default:
			break;
		}
}

void workManager::Show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或为空" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			this->Show_Info(i);
		}
	}
}

int workManager::IsExist(int id) {
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_ID == id) {
			index = i;
			break;
		}
	}
	return index;
}

void workManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入要删除的用户id" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1) {
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "职员不存在" << endl;
		}
	}

}

void workManager::Mon_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件为空或不存在" << endl;
	}
	else {
		cout << "请输入修改职工的编号" << endl;
		int id = 0;
		cin >> id;

		int  ret = this->IsExist(id);
		if (ret != -1) {
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到：" << id << "号员工，请输入新职工号" << endl;
			cin >> newId;

			cout << "请输入新姓名" << endl;
			cin >> newName;

			cout << "请选择岗位" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId,newName,1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			case 3:
				worker = new Boss(newId, newName, 3);
				break;

			default:
				break;
			}

			this->m_EmpArray[ret] = worker;

			cout << "修改成功" << endl;

			this->save();

		}
		else {
			cout << "查无此人" << endl;
		}
	}
};

void workManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入查找方式" << endl;
		cout << "1.按职工号查找" << endl;
		cout << "2.按姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) {
			int id = 0;
			cout << "请输入要查找的职工号" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1) {
				cout << "查找成功，该职员信息如下" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else {
				cout << "查无此人" << endl;
			}
		}
		else if (select == 2) {
			string name;
			cout << "请输入查找的姓名" << endl;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++) {
				if (m_EmpArray[i]->m_Name == name) {
					cout << "查找成功，职工编号为" << m_EmpArray[i]->m_ID << "，员工的信息为" << endl;

					flag = true;

					this->m_EmpArray[i]->ShowInfo();
				}
			}
			if (flag == false) {
				cout << "查无此人" << endl;
			}
		}
		else {
			cout << "请输入正确的选项" << endl;
		}
	}
}

void workManager::Sort_Emp(Worker ** arr,int begin,int end) {
	if (begin > end)
		return;

	Worker* tmp = arr[begin];
	int i = begin;
	int j = end;
	Worker* worker = NULL;
	while (i != j) {
		while (arr[j]->m_ID >= tmp->m_ID && j > i)
			j--;
		while (arr[i]->m_ID <= tmp->m_ID && j > i)
			i++;
		if (j > i) {
			worker = arr[i];
			arr[i] = arr[j];
			arr[j] = worker;
		}
	}
	arr[begin] = arr[i];
	arr[i] = tmp;
	Sort_Emp(arr, begin, i - 1);
	Sort_Emp(arr, i + 1, end);
}

void workManager::Clean_File() {
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum;i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清除成功" << endl;
	}
};

void workManager::clear() {
	system("cls");
	this->Show_Menu();
};

void workManager::addWorker() {
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