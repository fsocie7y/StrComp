#include "UI.h"

void UI::StartWindow()
{
	system("cls"); //�������� ������
	cout << "������� ��:" << endl;
	cout << "1. ����� � ������" << endl;
	cout << "2. ��������������" << endl;
	cout << "3. �����" << endl;
	int ch;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		auth();
		break;
	}
	case 2:
	{
		newUser();
		break;
	}
	case 3:
	{
		exit(0);
		break;
	}
	default:
		StartWindow();
	}
}

void UI::auth()
{
	string username, password;
	unsigned int correct = 0;
	cout << "������ ��'� �����������: ";
	cin >> username;
	cout << "������ ������: ";
	cin >> password;
	correct = DatabaseSession.auth(username, password);
	if (correct == 3)
	{
		operatorOffice operatorO;
		operatorO.mainMenu();
		system("pause");
		StartWindow();
	}
	if (correct == 2)
	{
		cout << "����������� ������. �������������" << endl;
		system("pause");
		StartWindow();
	}
	if (correct == 1)
	{

		user curUser(username);
		curUser.mainMenu(); //�������� ���� �����������
		system("pause");

		StartWindow();
	}
	if (correct == 0)
	{
		cout << "����������� ��'� ����������� ��� ������" << endl;
		system("pause");
		StartWindow();
	}
}

void UI::newUser()
{
	string username, password;
	cout << "������ ��'� �����������: ";
	cin >> username;
	cout << "���������� ������: ";
	cin >> password;
	bool available = DatabaseSession.newUser(username, password);
	if (available == 1) //�������� �� �������� � ��� ���� �����������
	{
		cout << "��'� ����������� ��� ����" << endl;
		system("pause");
	}
	StartWindow();
}