#include "user.h"
int random(int min, int max) {
	return min + rand() % (max - min);
}
user::user(string curUsername)
{
	this->curUsername = curUsername;
}

void user::mainMenu()
{
	system("cls"); //очищення екрану
	cout << "Виберіть дію:" << endl;
	cout << "1. Застрахувати власність" << endl;
	cout << "2. Переглянути страховки" << endl;
	cout << "3. Видалити страховку" << endl;
	cout << "4. Вийти" << endl;
	int ch;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		system("cls"); //очищення екрану
		int square, price;
		string name, dateT;
		date dateRegister, dateEnd;

		cout << "Введіть назву власності: " << endl;
		cin >> name;

		time_t t = time(0); //одержання поточної дати
		tm* now = localtime(&t);
		dateRegister.year = now->tm_year + 1900;
		dateRegister.month = now->tm_mon + 1;
		dateRegister.day = now->tm_mday;

		/*dateEnd.year = dateRegister.year + 3;
		dateEnd.month = dateRegister.month;
		dateEnd.day = dateRegister.day;*/
		link:
		cout << "Введіть дату закінчення у форматі\nДД.ММ.РРРР: " << endl;
		cin >> dateT;
		vector<string> tmp;
		tmp = split(dateT,".");
		if (stoi(tmp[0])<=31) {
			dateEnd.day = stoi(tmp[0]);
		}
		else {
			cout << "При вводі допущено помилку, спробуйте ще раз";
			goto link;
		}
		if (stoi(tmp[1])!=0&&stoi(tmp[1])<=12)
		{
			dateEnd.month = stoi(tmp[1]);
		}
		else {
			cout << "При вводі допущено помилку, спробуйте ще раз";
			goto link;
		}
		if (stoi(tmp[2]) != 0 && stoi(tmp[2])>=dateRegister.year)
		{
			dateEnd.year = stoi(tmp[2]);
		}
		else {
			cout << "При вводі допущено помилку, спробуйте ще раз";
			goto link;
		}
		/*cout << "День: ";
		cin >> dateEnd.day;
		cout << "Місяць: ";
		cin >> dateEnd.month;
		cout << "Рік: ";
		cin >> dateEnd.year;*/

		srand(dateEnd.year);
		price = random(500, 5000);

		DatabaseSession.add(curUsername, name, dateRegister, dateEnd, price);
		mainMenu();
		break;
	}
	case 2:
	{
		system("cls"); //очищення екрану

		view();

		system("pause");
		mainMenu();
		break;
	}
	case 3:
	{
		system("cls"); //очищення екрану
		view();
		cout << "Введіть ID страховки яку бажаєте видалити: ";
		int id;
		cin >> id;
		if (DatabaseSession.remove(id, curUsername) == 0)
		{
			cout << "Це не ваша страховка" << endl;
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