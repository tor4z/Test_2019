#include <iostream>
#include <string>
#include <cctype>

#define MAX 100

using namespace std;


int p44()
{
	int a, b, n, num[MAX], res[MAX];
	string str;
	int i, j, k, c, t;

	while (cin >> a)
	{
		cin >> str;
		cin >> b;
		n = str.length();
		for (i = 0; i < n; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
				num[i] = str[i] - '0';
			else
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] = 'a' + str[i] - 'A';
				num[i] = 10 + str[i] - 'a';
			}
		}

		k = 0;
		for (i = 0; i < n;)
		{
			c = 0;
			for (j = i; j < n; j++)
			{
				t = (num[j] + c*a) % b;
				num[j] = (num[j] + c*a) / b;
				c = t;
			}
			while (num[i] == 0)i++;
			res[k++] = c;
		}

		for (i = k - 1; i >= 0; i--)
		{
			if (res[i] < 10)
				printf("%d", res[i]);
			else
				printf("%c", res[i] - 10 + 'A');
		}
		printf("\n");

	}
	return 0;
}