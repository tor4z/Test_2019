#include <iostream>
#include <string>

#define MAX 80

using namespace std;


int p29()
{
	string str;
	int n;

	while (getline(cin, str))
	{
		n = 0;
		while (str[n] != '\0')
		{
			switch (str[n])
			{
			case 'z':
				str[n] = 'a';
				break;
			case 'Z':
				str[n] = 'A';
				break;
			default:
				if ((str[n] >= 'a' && str[n] < 'z') || (str[n] >= 'A' && str[n] < 'Z'))
					str[n]++;
			}
			n++;
		}
		cout << str << endl;
	}
	return 0;
}