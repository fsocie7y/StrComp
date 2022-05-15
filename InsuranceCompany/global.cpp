#include "global.h"

vector <string> split(string str, string divider) //функція розділення строки за розділювачем
{
	vector <string> res;
	int start = 0, end, delta = divider.length(), i = 0;
	while ((end = str.find(divider, start)) != string::npos)
	{
		res.push_back(str.substr(start, end - start));
		start = end + delta;
	}
	res.push_back(str.substr(start));
	return res;
}