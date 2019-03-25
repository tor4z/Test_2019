#include <iostream>
#include <string>
#include <cctype>

using namespace std;


char transform(char c)
{
	int n = c - 'A';
	n = (n - 5 + 26) % 26;
	return 'A' + n;
}

int p70()
{
	string str;
	while (getline(cin, str))
	{
		if (str == "START" || str == "END")
			continue;
		if (str == "ENDOFINPUT")
			break;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (isalpha(str[i]))
				cout << transform(str[i]);
			else
				cout << str[i];
		}
		cout << endl;
	}
	return 0;
}