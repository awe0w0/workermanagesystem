#include <iostream>
using namespace std;
#include "workManager.h"

int main() {

	workManager wm;

	wm.Show_Menu();

	int choice;

	while (true) {
		cout << "����������ѡ��" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.Exit();
			break;
		case 1:
//			wm.addWorker();
			wm.Add_Emp();
			break;
		case 2:
			wm.Show_Emp();
			break;
		case 3:
			wm.Del_Emp();
			break;
		case 4:
			wm.Mon_Emp();
			break;
		case 5:
			wm.Find_Emp();
			break;
		case 6:
			wm.Sort_Emp(wm.m_EmpArray,0,wm.m_EmpNum-1);
			wm.save();
			cout << "����ɹ�" << endl;
			break;
		case 7:
			wm.Clean_File();
			break;
		case 8:
			wm.clear();
			break;
		default:
			cout << "��������ȷ����ֵ" << endl;
			break;
		}

	}

	return 0;
}