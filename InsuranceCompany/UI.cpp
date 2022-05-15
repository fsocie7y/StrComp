#include "UI.h"

void UI::StartWindow()
{
	system("cls"); //очищення екрану
	cout << "Виберіть дію:" << endl;
	cout << "1. Увійти в акаунт" << endl;
	cout << "2. Зареєструватися" << endl;
	cout << "3. Вихід" << endl;
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
	cout << "Введіть ім'я користувача: ";
	cin >> username;
	cout << "Введіть пароль: ";
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
		cout << "Користувачі відсутні. Зареєструйтесь" << endl;
		system("pause");
		StartWindow();
	}
	if (correct == 1)
	{

		user curUser(username);
		curUser.mainMenu(); //відкриття меню користувача
		system("pause");

		StartWindow();
	}
	if (correct == 0)
	{
		cout << "Неправильне ім'я користувача або пароль" << endl;
		system("pause");
		StartWindow();
	}
}

void UI::newUser()
{
	string username, password;
	cout << "Введіть ім'я користувача: ";
	cin >> username;
	cout << "Придумайте пароль: ";
	cin >> password;
	bool available = DatabaseSession.newUser(username, password);
	if (available == 1) //перевірка на наявність в базі імені користувача
	{
		cout << "Ім'я користувача уже існує" << endl;
		system("pause");
	}
	StartWindow();
}