#include "workManager.h"

workManager::workManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {
		cout << "�Ҳ���Ա�����ļ�" << endl;
		this->m_EmpNum = 0;;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	int num = this->get_EmpNum();
	cout << "Ա������Ϊ" << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];

	this->init_Emp();

	for (int i = 0; i < m_EmpNum; i++) {
		cout << "ְ����" << this->m_EmpArray[i]->m_ID
			<< "ְ������" << this->m_EmpArray[i]->m_Name
			<< "���ű��" << this->m_EmpArray[i]->m_DeptID << endl;
	}
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

	cout << "����������ְ������" << endl;

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

			cout << "�������" << i + 1 << "λְԱid" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "λְԱ����" << endl;
			cin >> name;

			cout << "�������ְ���ĸ�λ" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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

		cout << "�ɹ����" << addNum << "λ��Ա��" << endl;
		this->m_FileIsEmpty = false;
	}


	else {
		cout << "��������ȷ����ֵ" << endl;
	}
}

void workManager::Show_Menu() {
	cout << "-----------------------------" << endl;
	cout << "-----��ӭʹ��ְ������ϵͳ----" << endl;
	cout << "--------0.�˳��������-------" << endl;
	cout << "--------1.����ְ����Ϣ-------" << endl;
	cout << "--------2.��ʾְ����Ϣ-------" << endl;
	cout << "--------3.ɾ����ְְ��-------" << endl;
	cout << "--------4.�޸�ְ����Ϣ-------" << endl;
	cout << "--------5.����ְ����Ϣ-------" << endl;
	cout << "--------6.���ձ������-------" << endl;
	cout << "--------7.��������ĵ�-------" << endl;
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
			if (index == 0) {
				cout << "!" << id << "!" << name << "!" << dId << "!";
			}
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

void workManager::addWorker() {
	cout << "������Ҫ��ӵ�ְԱ����" << endl;
	ofstream ofs;
	ofs.open("worker.txt", ios::out | ios::app);
	int num = 0;
	cin >> num;
	while (num) {
		cout << "������ְԱ���" << endl;
		char a[10] = { 0 };
		cin >> a;
		ofs << a << endl;
		cout << "������ְԱid" << endl;
		char id[10] = {0};
		cin >> id;
		ofs << id << endl;
		cout << "������ְԱ����" << endl;
		char name[10] = { 0 };
		cin >> name;
		ofs << name << endl;
		cout << "������ְԱ����" << endl;
		char did[10] = { 0 };
		cin >> did;
		ofs << did << endl;
		cout << "��ӳɹ�" << endl;
		num--;
	}
	ofs.close();
}

void workManager::Exit() {
	cout << "��л����ʹ��" << endl;
	system("pause");
	exit(0);
}