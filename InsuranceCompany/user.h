#include "global.h"
#include "operatorCompany.h"
class user
{

private:
	string curUsername;
	vector<insurInfo> curUserinsur;
	DatabaseCompany DatabaseSession;
public:
	user(string curUsername);
	void mainMenu(); //������� ���� �����������
	void view();
};