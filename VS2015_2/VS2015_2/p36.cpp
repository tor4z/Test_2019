#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

#define MAX 7

using namespace std;


static char res[MAX];
static int n;
string str;


void solve(int i)
{
	char tmp;
	int m;

	if (i == n)
	{
		for (size_t j = 0; j < n; j++)
			cout << res[j];
		cout << endl;
	}
	else
	{
		for (size_t k = 0; k < n; k++)
		{
			tmp = str[k];
			for (m = 0; m < i; m++)
				if (tmp == res[m]) break;

			if (m < i)continue;
			res[i] = str[k];
			solve(i + 1);
			cout << endl;
		}
	}
}


int p36()
{
	while (cin >> str)
	{
		n = str.length();
		sort(str.begin(), str.end());
		solve(0);
	}
	return 0;
}