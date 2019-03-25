#include <iostream>
#include <string>

#define MAX 30

using namespace std;


bool div_able(int c[], int n, int k)
{
	int carry, t;

	carry = 0;
	for (int j = 0; j < n; j++)
	{
		t = (c[j] + carry * 10) % k;
		c[j] = (c[j] + carry * 10) / k;
		carry = t;
	}
	return carry == 0;
}


int p33()
{
	string sc;
	int c[MAX], cc[MAX], n;
	bool flag;

	while (cin>>sc)
	{
		n = sc.length();
		flag = false;
		for (int i = 0; i < n; i++)
			c[i] = sc[i] - '0';

		for (int i = 2; i <= 9; i++)
		{
			for (size_t j = 0; j < n; j++)
				cc[j] = c[j];
			if (div_able(cc, n, i))
			{
				cout << i << " ";
				flag = true;
			}
		}
		if (!flag)
			cout << "none";
		cout << endl;


	}
	return 0;
}