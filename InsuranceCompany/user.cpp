#include "user.h"

user::user(string curUsername)
{
	this->curUsername = curUsername;
}

void user::mainMenu()
{
	system("cls"); //�������� ������
	cout << "������� ��:" << endl;
	cout << "1. ������������ ��������" << endl;
	cout << "2. ����������� ���������" << endl;
	cout << "3. �������� ���������" << endl;
	cout << "4. �����" << endl;
	int ch;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		system("cls"); //�������� ������
		int square, price;
		string name;
		date dateRegister, dateEnd;

		cout << "������ ����� ��������: " << endl;
		cin >> name;

		time_t t = time(0); //��������� ������� ����
		tm* now = localtime(&t);
		dateRegister.year = now->tm_year + 1900;
		dateRegister.month = now->tm_mon + 1;
		dateRegister.day = now->tm_mday;

		/*dateEnd.year = dateRegister.year + 3;
		dateEnd.month = dateRegister.month;
		dateEnd.day = dateRegister.day;*/

		cout << "������ ���� ���������: " << endl;
		cout << "����: ";
		cin >> dateEnd.day;
		cout << "̳����: ";
		cin >> dateEnd.month;
		cout << "г�: ";
		cin >> dateEnd.year;

		srand(time(NULL));
		price = rand() % 10000 + 4000;

		DatabaseSession.add(curUsername, name, dateRegister, dateEnd, price);
		mainMenu();
		break;
	}
	case 2:
	{
		system("cls"); //�������� ������

		view();

		system("pause");
		mainMenu();
		break;
	}
	case 3:
	{
		system("cls"); //�������� ������
		view();
		cout << "������ ID ��������� ��� ������ ��������: ";
		int id;
		cin >> id;
		if (DatabaseSession.remove(id, curUsername) == 0)
		{
			cout << "�� �� ���� ���������" << endl;
		}
		system("pause");
		mainMenu();
		break;
	}
	case 4:
	{
		exit(0);
		break;
	}
	default:
		mainMenu();
	}
}

void user::view()
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