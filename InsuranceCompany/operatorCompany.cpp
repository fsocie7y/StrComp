#include "operatorCompany.h"

operatorOffice::operatorOffice()
{
}

void operatorOffice::mainMenu()
{
	system("cls"); //�������� ������
	cout << "������� ��:" << endl;
	cout << "1. ����������� �� ���������" << endl;
	cout << "2. ������ ������ ���������" << endl;
	cout << "3. �����" << endl;
	int ch;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		system("cls"); //�������� ������

		view(); //�������� ����������

		system("pause");
		mainMenu();
		break;
	}
	case 2:
	{
		system("cls"); //�������� ������
		view();
		cout << "������ ID ������ ���� ����� ������ ������: ";
		int id;
		cin >> id;
		cout << "������ ����: ";
		string state;
		cin >> state;
		DatabaseSession.changeState(id, state);
		system("pause");
		mainMenu();
		break;
	}
	case 3:
	{
		exit(0);
		break;
	}
	default:
		mainMenu();
	}
}

void operatorOffice::view()
{
	vector<insurInfo> userinsur = DatabaseSession.getinsur();
	cout <<
		"|" << setw(2) << right << "ID" <<
		"|" << setw(15) << "����� ��������" <<
		"|" << setw(15) << "���� ���������" <<
		"|" << setw(15) << "���� ���������" <<
		"|" << setw(12) << "ֳ��" <<
		"|" << setw(10) << "����" <<
		"|" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	if (userinsur.empty() == 0)
	{
		for (unsigned int i = 0; i < userinsur.size(); i++)
		{
			cout <<
				"|" << setw(2) << right << userinsur[i].id <<
				"|" << setw(15) << userinsur[i].name <<
				"|" << setw(8) << userinsur[i].dateRegister.day << "." << userinsur[i].dateRegister.month << "." << userinsur[i].dateRegister.year <<
				"|" << setw(8) << userinsur[i].dateEnd.day << "." << userinsur[i].dateEnd.month << "." << userinsur[i].dateEnd.year <<
				"|" << setw(9) << userinsur[i].price << "���" <<
				"|" << setw(10) << userinsur[i].state <<
				"|" << endl;
		}
	}
}