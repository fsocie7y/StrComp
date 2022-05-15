#include "global.h"
#include "DatabaseUsers.h"
#include "user.h"


class UI
{
private:
	DatabaseUsers DatabaseSession;
public:
	void StartWindow(); //початкове мени
	void auth(); //меню авторизації
	void newUser(); //меню реєстрації
};