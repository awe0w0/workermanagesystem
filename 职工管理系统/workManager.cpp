#include "workManager.h"

workManager::workManager() {
	
}

workManager::~workManager() {
	
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