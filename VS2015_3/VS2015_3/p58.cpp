#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

bool cmp(char a, char b)
{
	a = toupper(a);
	b = toupper(b);
	return a > b;
}


int p58()
{
	string str;
	int n, t;

	while (getline(cin, str))
	{
		n = str.length();
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				while (j <= i && !isalpha(str[j]))j++;
				if (j >= i)break;
				t = j + 1;
				while (t <= i && !isalpha(str[t]))t++;
				if (t <= i)
				{
					if (cmp(str[j], str[t]))
						swap(str[j], str[t]);
				}

			}
		}
		cout << str << endl;
	}

	return 0;
}