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
			wm.addWorker();
			break;
		case 2:

			break;
		case 3:

			break;
		case4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		default:
			cout << "��������ȷ����ֵ" << endl;
			break;
		}

	}

	return 0;
}