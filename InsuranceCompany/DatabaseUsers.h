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
	bool load(); //загрузити з файла дані про користувачів
	void save(); //зберегти у файл дані про користувачів
	unsigned int auth(string username, string password); //авторизація
	bool newUser(string username, string password); //реєстрація
};