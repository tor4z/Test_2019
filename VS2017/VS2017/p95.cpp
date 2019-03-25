#include <iostream>
#include <string>

using namespace std;


int p95()
{
	int arr[3] = { 0,0,0 };
	string str;
	while (cin >> str)
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == 'Z') arr[0]++;
			else if (str[i] == 'O') arr[1]++;
			else if (str[i] == 'J') arr[2]++;
		}

		while (true)
		{
			for (size_t i = 0; i < 3; i++)
			{
				if (arr[i] != 0)
				{
					arr[i]--;
					if (i == 0)cout << "Z";
					else if (i == 1)cout << "O";
					else if (i == 2)cout << "J";
				}
			}
			if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)break;
		}
		cout << endl;
	}
	return 0;
}