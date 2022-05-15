#include "operatorCompany.h"

operatorOffice::operatorOffice()
{
}

void operatorOffice::mainMenu()
{
	system("cls"); //очищення екрану
	cout << "Виберіть дію:" << endl;
	cout << "1. Переглянути всі страховки" << endl;
	cout << "2. Змінити статус страховки" << endl;
	cout << "3. Вийти" << endl;
	int ch;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		system("cls"); //очищення екрану

		view(); //перегляд перевезень

		system("pause");
		mainMenu();
		break;
	}
	case 2:
	{
		system("cls"); //очищення екрану
		view();
		cout << "Введіть ID заказу стан якого бажаєте змінити: ";
		int id;
		cin >> id;
		cout << "Введіть стан: ";
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
		"|" << setw(15) << "Назва власності" <<
		"|" << setw(15) << "Дата страховки" <<
		"|" << setw(15) << "Дата закінчення" <<
		"|" << setw(12) << "Ціна" <<
		"|" << setw(10) << "Стан" <<
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
				"|" << setw(9) << userinsur[i].price << "грн" <<
				"|" << setw(10) << userinsur[i].state <<
				"|" << endl;
		}
	}
}