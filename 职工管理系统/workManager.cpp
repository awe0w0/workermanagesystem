#include "workManager.h"

workManager::workManager() {
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
}

workManager::~workManager() {
	
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

		cout << "�ɹ����" << addNum << "λ��Ա��" << endl;
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

void workManager:: addWorker() {
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