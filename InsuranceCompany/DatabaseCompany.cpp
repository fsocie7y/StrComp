#include "DatabaseCompany.h"

DatabaseCompany::DatabaseCompany()
{
	ifstream file("curId.txt"); //�������� �����
	if (file.fail())
	{
		ofstream file("curId.txt"); //�������� �����
		curId = 0;
		file << curId;
	}
	else
	{
		string temp;
		file >> temp; //���������� ���������� ID � �����
		curId = stoi(temp);
		file.close(); //�������� �����
	}
}

bool DatabaseCompany::load()
{
	int i = 0;
	insur.clear();
	string temp;
	vector <string> buff;
	ifstream file(fileNameT); //�������� �����
	if (file.fail())
	{
		return 0;
	}
	else
	{
		while (file.eof() != 1) //������� ���������� ���� �� ���������� ����
		{
			file >> temp;
			buff = split(temp, div);
			insur.resize(insur.size() + 1); //����� ����� � ������
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
		file.close(); //�������� �����
		return 1;
	}
}

void DatabaseCompany::save()
{
	ofstream file(fileNameT); //�������� �����
	for (unsigned int i = 0; i < insur.size(); i++)
	{
		file << insur[i].id << div <<  //����� ����� � ����
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
	file.close(); //�������� �����
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
	ofstream file(fileNameT, ios_base::app); //�������� �����
	file << curId << div << //����� � ����� �����
		userN << div <<
		name << div <<
		dateRegister.day << div <<
		dateRegister.month << div <<
		dateRegister.year << div <<
		dateEnd.day << div <<
		dateEnd.month << div <<
		dateEnd.year << div <<
		price << div <<
		"�������" << endl;
	file.close();
	curId++;
	ofstream fileNum("curId.txt");
	fileNum << curId;
	fileNum.close(); //�������� �����
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
