#include <iostream>
#include <string>
#include <algorithm>

#define MAX 50

using namespace std;

static int prime[MAX];

static void init()
{
	int k = 0;
	int n = 2, i;

	while (k < 50)
	{
		for (i = 2; i*i <= n; i++)
		{
			if (n%i == 0)break;
		}
		if (i*i > n)prime[k++] = n;
		n++;
	}
}


int p91()
{
	init();
	string str1, str2;
	int num1[MAX], num2[MAX], ans[MAX];
	int n1, n2, i, n, c;
	while (cin >> str1 >> str2)
	{
		if (str1.length() == 1 && str2.length() == 1 && str1[0] == '0' && str2[0] == '0')break;

		for (i = 0; i < MAX; i++)
		{
			num1[i] = 0;
			num2[i] = 0;
		}

		for (i = 0, n1 = 0; i <= str1.length(); i++)
		{
			if (str1[i] == ',' || str1[i] == '\0')
			{
				n1++;
			}
			else
			{
				num1[n1] *= 10;
				num1[n1] += str1[i] - '0';
			}
		}

		for (i = 0, n2 = 0; i <= str2.length(); i++)
		{
			if (str2[i] == ',' || str2[i] == '\0')
			{
				n2++;
			}
			else
			{
				num2[n2] *= 10;
				num2[n2] += str2[i] - '0';
			}
		}

		reverse(num1, num1 + n1);
		reverse(num2, num2 + n2);

		if (n1 < n2)
		{
			for (i = n1; i < n2; i++)
			{
				num1[i] = 0;
			}
			n = n2;
		}
		else
		{
			for (i = n2; i < n2; i++)
			{
				num2[i] = 0;
			}
			n = n1;
		}

		c = 0;
		for (i = 0; i < n; i++)
		{
			ans[i] = num1[i] + num2[i] + c;
			if (ans[i] >= prime[i])
			{
				c = ans[i] / prime[i];
				ans[i] = ans[i] % prime[i];
			}
			else
				c = 0;
		}
		if (c != 0)ans[i++] = c;

		for (int j = i - 1; j >= 0; j--)
		{
			cout << ans[j];
			if (j > 0)
				cout << ",";
		}
		cout << endl;

	}
	return 0;
}
