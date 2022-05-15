#include "global.h"

constexpr auto fileName = "users.txt";

class DatabaseUsers
{
private:
	struct userInfo
	{
		string username, password;
	};
	vector <userInfo> Data;
public:
	bool load(); //��������� � ����� ��� ��� ������������
	void save(); //�������� � ���� ��� ��� ������������
	unsigned int auth(string username, string password); //�����������
	bool newUser(string username, string password); //���������
};