#include "global.h"

constexpr auto fileNameT = "insurance.txt";

struct date {
	int day, month, year;
};
struct insurInfo {
	int id, price;
	string name, userN;
	date dateRegister, dateEnd;
	string state;
};

class DatabaseCompany
{
private:
	vector<insurInfo> insur;
	int curId;
	bool load();
public:
	DatabaseCompany();
	void save();
	vector<insurInfo> getUserinsur(string name);
	vector<insurInfo> getinsur();
	void add(string userN, string name, date dateRegister, date dateEnd, int price);
	bool remove(int num, string curUsername);
	void changeState(int ID, string state);
};