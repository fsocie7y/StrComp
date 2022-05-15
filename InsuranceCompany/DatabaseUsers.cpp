#include "DatabaseUsers.h"


bool DatabaseUsers::load()
{
	int i = 0;
	Data.clear();
	string temp;
	vector <string> buff;
	ifstream file(fileName); //відкриття файла
	if (file.fail())
	{
		return 0;
	}
	else
	{
		while (file.eof() != 1) //читання построково доки не закінчиться файл
		{
			file >> temp;
			buff = split(temp, udiv);
			Data.resize(Data.size() + 1); //запис даних у вектор
			Data[i].username = buff[0];
			Data[i].password = buff[1];
			i++;;
		}
		Data.pop_back();
		file.close(); //закриття файла
		return 1;
	}
}

void DatabaseUsers::save()
{
	ofstream file(fileName); //відкриття файла
	for (unsigned int i = 0; i < Data.size(); i++)
	{
		file << Data[i].username << udiv << Data[i].password << endl; //запис даних у файл
	}
	file.close(); //закриття файла
	Data.clear();
}

unsigned int DatabaseUsers::auth(string username, string password)
{
	system("cls"); //очищення екрану

	if (load() == 0)
	{
		return 2;
	}
	else
	{
		bool correct = 0;
		for (unsigned int i = 0; i < Data.size(); i++)
		{
			if (username == "operator" && password == "password")
			{
				return 3;
			}
			if (Data[i].username == username && Data[i].password == password)
			{
				correct = 1;
				break;
			}
		}
		Data.clear();
		return correct;
	}
}

bool DatabaseUsers::newUser(string username, string password)
{
	system("cls"); //очищення екрану
	if (load() == 0)
	{
		ofstream file(fileName, ios_base::app); //відкриття файла
		file << username << udiv << password << endl;
		file.close(); //закриття файла
		return 0;
	}
	else
	{
		bool available = 0;
		for (unsigned int i = 0; i < Data.size(); i++)
		{
			if (Data[i].username == username) //перевірка на наявність імені користувача
			{

				available = 1;
				break;
			}
		}
		Data.clear();
		if (available == 0)
		{
			ofstream file(fileName, ios_base::app); //відкриття файла
			file << username << udiv << password << endl;
			file.close(); //закриття файла
		}
		return available;
	}
}