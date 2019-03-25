#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

#define MAX 100

using namespace std;

static float ans;

static void find_max(float arr[MAX], int i, int n, float Q, float sum)
{
	if (i < n)
	{
		if (sum + arr[i] <= Q)find_max(arr, i+1, n, Q, sum + arr[i]);
		find_max(arr, i+1, n, Q, sum);
	}
	else
	{
		ans = max(ans, sum);
	}
}


int p100()
{
	float Q, p, arr[MAX], tmp;
	int N, k, idx;
	char ty;
	string str;
	bool flag;

	while (cin >> Q >> N)
	{
		if (N == 0)break;

		for (size_t i = 0; i < MAX; i++)
		{
			arr[i] = 0;
		}
		idx = 0;

		for (size_t i = 0; i < N; i++)
		{
			cin >> k;

			tmp = 0;
			flag = true;
			for (size_t j = 0; j < k; j++)
			{
				cin >> str;
				sscanf(str.c_str(), "%c:%f", &ty, &p);
				if (ty == 'A' || ty == 'B' || ty == 'C')
				{
					tmp += p;
					if (p > 600)
						flag = false;
				}
				else
				{
					flag = false;
				}
			}
			if (flag)arr[idx++] = tmp;
		}

		find_max(arr, 0, idx, Q, 0);
		printf("%.2f\n", ans);
	}
	return 0;
}