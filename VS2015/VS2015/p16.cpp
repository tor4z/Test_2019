#include <iostream>
#define MAX 15

using namespace std;


int c2i(char c)
{
	return c - '0';
}

int p16()
{
	char s1[MAX], s2[MAX];
	int i, j;
	int ans;

	ans = 0;
	i = 0;
	j = 0;

	while (cin >> s1 >> s2)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			j = 0;
			while (s2[j] != '\0')
			{
				ans += c2i(s1[i])*c2i(s2[j]);
				j++;
			}
			i++;
		}
		cout << ans << endl;
	}
	return 0;
}