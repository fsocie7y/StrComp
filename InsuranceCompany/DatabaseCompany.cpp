#include "DatabaseCompany.h"

DatabaseCompany::DatabaseCompany()
{
	ifstream file("curId.txt"); //відкриття файла
	if (file.fail())
	{
		ofstream file("curId.txt"); //відкриття файла
		curId = 0;
		file << curId;
	}
	else
	{
		string temp;
		file >> temp; //зчитування останнього ID з файла
		curId = stoi(temp);
		file.close(); //закриття файла
	}
}

bool DatabaseCompany::load()
{
	int i = 0;
	insur.clear();
	string temp;
	vector <string> buff;
	ifstream file(fileNameT); //відкриття файла
	if (file.fail())
	{
		return 0;
	}
	else
	{
		while (file.eof() != 1) //читання построково доки не закінчиться файл
		{
			file >> temp;
			buff = split(temp, div);
			insur.resize(insur.size() + 1); //запис даних у вектор
			insur[i].id = stoi(buff[0]);
			insur[i].userN = buff[1];
			insur[i].name = buff[2];
			insur[i].dateRegister.day = stoi(buff[3]);
			insur[i].dateRegister.month = stoi(buff[4]);
			insur[i].dateRegister.year = stoi(buff[5]);
			insur[i].dateEnd.day = stoi(buff[6]);
			insur[i].dateEnd.month = stoi(buff[7]);
			insur[i].dateEnd.year = stoi(buff[8]);
			insur[i].price = stoi(buff[9]);
			insur[i].state = buff[10];
			i++;;
		}
		insur.pop_back();
		file.close(); //закриття файла
		return 1;
	}
}

void DatabaseCompany::save()
{
	ofstream file(fileNameT); //відкриття файла
	for (unsigned int i = 0; i < insur.size(); i++)
	{
		file << insur[i].id << div <<  //запис даних у файл
			insur[i].userN << div <<
			insur[i].name << div <<
			insur[i].dateRegister.day << div <<
			insur[i].dateRegister.month << div <<
			insur[i].dateRegister.year << div <<
			insur[i].dateEnd.day << div <<
			insur[i].dateEnd.month << div <<
			insur[i].dateEnd.year << div <<
			insur[i].price << div <<
			insur[i].state << endl;
	}
	file.close(); //закриття файла
	insur.clear();
}

vector<insurInfo> DatabaseCompany::getUserinsur(string name)
{
	load();
	vector<insurInfo> userTours;
	for (unsigned int i = 0; i < insur.size(); i++)
	{
		if (insur[i].userN == name)
		{
			userTours.push_back(insur[i]);
		}
	}
	return userTours;
}

vector<insurInfo> DatabaseCompany::getinsur()
{
	load();
	return insur;
}

void DatabaseCompany::add(string userN, string name, date dateRegister, date dateEnd, int price)
{
	ofstream file(fileNameT, ios_base::app); //відкриття файла
	file << curId << div << //запис в кінець файлу
		userN << div <<
		name << div <<
		dateRegister.day << div <<
		dateRegister.month << div <<
		dateRegister.year << div <<
		dateEnd.day << div <<
		dateEnd.month << div <<
		dateEnd.year << div <<
		price << div <<
		"Обробка" << endl;
	file.close();
	curId++;
	ofstream fileNum("curId.txt");
	fileNum << curId;
	fileNum.close(); //закриття файла
}

bool DatabaseCompany::remove(int num, string curUsername)
{
	load();
	for (unsigned int i = 0; i < insur.size(); i++)
	{
		if (insur[i].userN == curUsername && insur[i].id == num)
		{
			insur.erase(insur.begin() + i);
			save();
			insur.clear();
			return 1;
		}
	}
	return 0;
}

void DatabaseCompany::changeState(int ID, string state)
{
	load();
	for (unsigned int i = 0; i < insur.size(); i++)
	{
		if (insur[i].id == ID)
		{
			insur[i].state = state;
			save();
			insur.clear();
		}
	}
}
