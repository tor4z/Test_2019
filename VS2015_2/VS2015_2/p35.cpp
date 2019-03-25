#include <iostream>
#include <string>

#define MAX 30

using namespace std;


int p35()
{
	string str;
	int N[MAX], n, k, carry, t;
	int bin[10 * MAX];

	while (cin >> str)
	{
		k = 0;
		n = str.length();
		for (int i = 0; i < n; i++)
			N[i] = str[i] - '0';

		for (int i = 0; i < n;)
		{
			carry = 0;
			for (int j = i; j < n; j++)
			{
				t = (N[j] + carry * 10) % 2;
				N[j] = (N[j] + carry * 10) / 2;
				carry = t;
			}
			bin[k++] = carry;
			while (N[i] == 0)i++;
		}


		for (int i = k - 1; i >= 0; i--)
			cout << bin[i];
		cout << endl;
	}
	return 0;
}