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
//	cout << "Ա������Ϊ" << num << endl;
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
	cout << "------------8.����-----------" << endl;
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

		cout << "ְ���ţ�" << this->m_EmpArray[i]->m_ID<<"\t"
			<< "ְ��������" << this->m_EmpArray[i]->m_Name<<"\t";
		switch (m_EmpArray[i]->m_DeptID)
		{
		case 1:
			cout << "��λ��Ա��" << "\t";
			cout << "��λְ���뾭������������" << endl;
			break;
		case 2:
			cout << "��λ������" << "\t";
			cout << "��λְ������ϰ������"<<endl;
			break;
		case 3:
			cout << "��λ���ϰ�" << "\t";
			cout << "��λְ�𣺹���˾"<<endl;
			break;

		default:
			break;
		}
}

void workManager::Show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ�Ϊ��" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "������Ҫɾ�����û�id" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1) {
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "ְԱ������" << endl;
		}
	}

}

void workManager::Mon_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else {
		cout << "�������޸�ְ���ı��" << endl;
		int id = 0;
		cin >> id;

		int  ret = this->IsExist(id);
		if (ret != -1) {
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽��" << id << "��Ա������������ְ����" << endl;
			cin >> newId;

			cout << "������������" << endl;
			cin >> newName;

			cout << "��ѡ���λ" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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

			cout << "�޸ĳɹ�" << endl;

			this->save();

		}
		else {
			cout << "���޴���" << endl;
		}
	}
};

void workManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "��������ҷ�ʽ" << endl;
		cout << "1.��ְ���Ų���" << endl;
		cout << "2.����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) {
			int id = 0;
			cout << "������Ҫ���ҵ�ְ����" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1) {
				cout << "���ҳɹ�����ְԱ��Ϣ����" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else {
				cout << "���޴���" << endl;
			}
		}
		else if (select == 2) {
			string name;
			cout << "��������ҵ�����" << endl;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++) {
				if (m_EmpArray[i]->m_Name == name) {
					cout << "���ҳɹ���ְ�����Ϊ" << m_EmpArray[i]->m_ID << "��Ա������ϢΪ" << endl;

					flag = true;

					this->m_EmpArray[i]->ShowInfo();
				}
			}
			if (flag == false) {
				cout << "���޴���" << endl;
			}
		}
		else {
			cout << "��������ȷ��ѡ��" << endl;
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
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

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
		cout << "����ɹ�" << endl;
	}
};

void workManager::clear() {
	system("cls");
	this->Show_Menu();
};

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