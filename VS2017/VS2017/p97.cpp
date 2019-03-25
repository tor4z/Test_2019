#include <iostream>
#include <string>

using namespace std;


int word_to_int(string str)
{
	if (str == "zero")return 0;
	if (str == "one") return 1;
	if (str == "two")return 2;
	if (str == "three")return 3;
	if (str == "four") return 4;
	if (str == "five")return 5;
	if (str == "six")return 6;
	if (str == "seven") return 7;
	if (str == "eight")return 8;
	if (str == "nine")return 9;
	return 0;
}


int p97()
{
	int A, B;
	string str;
	while (true)
	{
		A = B = 0;
		while (cin >> str)
		{
			if (str != "+")
			{
				A *= 10;
				A += word_to_int(str);
			}
			else
				break;
		}
		while (cin >> str)
		{
			if (str != "=")
			{
				B *= 10;
				B += word_to_int(str);
			}
			else
				break;
		}
		if (A == 0 && B == 0)break;
		cout << A + B << endl;
	}
	return 0;
}