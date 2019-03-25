#include <iostream>
#include <string>

using namespace std;

void swap(char &a, char &b)
{
	char t;
	t = a;
	a = b;
	b = t;
}

int p56()
{
	string str;
	int n;
	while (cin>>str)
	{
		n = str.length();
		for (int i = n-1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (str[j] > str[j + 1])
					swap(str[j], str[j+1]);
			}
		}
		cout << str << endl;
	}
	return 0;
}