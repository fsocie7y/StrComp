#include "global.h"
#include "DatabaseUsers.h"
#include "user.h"


class UI
{
private:
	DatabaseUsers DatabaseSession;
public:
	void StartWindow(); //��������� ����
	void auth(); //���� �����������
	void newUser(); //���� ���������
};