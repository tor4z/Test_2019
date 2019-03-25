#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;


int ctoi(char c)
{
	if (isalpha(c))
		return 10 + toupper(c) - 'A';
	else
		return c - '0';
}

int p62()
{
	string str;
	int n;
	long ans;
	while (cin >> str)
	{
		ans = 0;
		n = str.length();
		for (int i = n-1; i >= 0; i--)
		{
			if (toupper(str[i]) == 'X')break;
			ans += ctoi(str[i])*(long)pow(16, n - i - 1);
		}
		cout << ans << endl;
	}
	return 0;
}
