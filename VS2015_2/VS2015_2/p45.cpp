#include <iostream>
#include <string>
#include <cctype>


using namespace std;


int p45()
{
	string str;
	int n;
	char c;

	while (getline(cin, str))
	{
		n = str.length();
		for (size_t i = 0; i < n; i++)
		{
			c = str[i];
			if (isalpha(c))
			{
				if (i == 0)
				{
					str[i] = toupper(c);
				}
				else
				{
					if(!isalnum(str[i-1]))
						str[i] = toupper(c);
				}
			}
		}
		cout << str;
	}
	return 0;
}