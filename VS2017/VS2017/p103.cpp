#include <iostream>

#define MAX 1001
#define MAX_N 500

using namespace std;


static int next_number(int x)
{
	if (x % 2 == 0)return x / 2;
	else
		return (3 * x + 1) / 2;
}


int p103()
{
	int n;
	int a[MAX_N];
	int x;
	bool flag[MAX];
	while (cin>>n)
	{
		if (n == 0)break;
		for (size_t i = 0; i < MAX; i++)
			flag[i] = false;
		for (size_t i = 0; i < n; i++)
		{
			cin >> a[i];
			if (!flag[a[i]])
			{
				x = a[i];
				while (x!=1)
				{
					x = next_number(x);
					flag[x] = true;
				}
			}
		}

		bool first = true;
		for (int i = n-1; i >= 0; i--)
		{
			if (!flag[a[i]])
			{
				if (!first)printf(" ");
				first = false;
				printf("%d", a[i]);
			}
		}
		printf("\n");
	}
	return 0;
}