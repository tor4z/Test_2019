#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 1000

using namespace std;

static vector<int> prime;

void init()
{
	bool flag;
	for (size_t i = 2; i <= MAX; i++)
	{
		flag = true;
		for (size_t j = 2; j*j <= i; j++)
			if (i%j == 0)
			{
				flag = false;
				break;
			}
		if (flag)
			prime.push_back(i);
	}
}

int p76()
{
	int N, A, k, n;
	vector<int>pa;
	int pn[MAX];
	bool flag;
	init();
	while (cin >> N >> A)
	{
		for (size_t i = 0; i < MAX; i++)
			pn[i] = 0;

		while (A>1)
		{
			for (size_t i = 0; i < prime.size(); i++)
			{
				if (A%prime[i] == 0)
				{
					pa.push_back(prime[i]);
					A /= prime[i];
					break;
				}
			}
		}

		for (size_t i = 2; i <= N; i++)
		{
			n = i;
			while (n>1)
			{
				for (size_t j = 0; j < prime.size(); j++)
				{
					if (n%prime[j] == 0)
					{
						pn[prime[j]]++;
						n /= prime[j];
					}
				}
			}
		}

		k = 0;
		flag = true;
		while (flag)
		{
			for (size_t i = 0; i < pa.size(); i++)
			{
				if (pn[pa[i]] == 0)
				{
					flag = false;
					break;
				}
				else
					pn[pa[i]]--;
			}
			if (flag)k++;
		}

		cout << k << endl;
	}
	return 0;
}