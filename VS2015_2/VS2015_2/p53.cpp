#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


int p53()
{
	string str, tmp;
	map<string, int>M;
	int n;

	while (cin >> str)
	{
		n = str.length();
		for (int i = 0; i < n; i++)
			for (int j = 1; j < n; j++)
				if (i + j <= n)
				{
					tmp = str.substr(i, j);
					if (M.find(tmp) == M.end())
						M[tmp] = 1;
					else
						M[tmp]++;
				}

		for (auto it = M.begin(); it != M.end(); it++)
			if(it->second > 1)
				cout << it->first << " " << it->second << endl;
	}
	return 0;
}