
///*
#include <cstdio>

#define MAX 100


int test()
{
	char str[MAX];
	int d;
	char c;
	//fgets(str, 100, stdin);
	//printf("%s\n", str);
	// int k = 5;
	// int *arr = new int[k];
	while (1)
	{
		scanf("%s", str);
		printf(">>%d\n", sscanf(str, "%c:%d", &c, &d));
		printf("%c, %d\n", c, d);
	}

	//while(scanf("%s", str)==1)
		//printf("%s\n", str);
	return 0;
}
//*/

/*
#include <cstdio>
#include <algorithm>

#define MAX 100

using namespace std;

static float ans;

static void find_max(float arr[MAX], int i, int n, float Q, float sum)
{
	if (i < n)
	{
		if (sum + arr[i] <= Q)find_max(arr, i + 1, n, Q, sum + arr[i]);
		find_max(arr, i + 1, n, Q, sum);
	}
	else
	{
		ans = max(ans, sum);
	}
}


int test()
{
	float Q, p, arr[MAX], tmp;
	int N, k, idx;
	char ty;
	char str[50];
	bool flag;

	while (scanf("%f %d", &Q, &N))
	{
		if (N == 0)break;

		for (size_t i = 0; i < MAX; i++)
		{
			arr[i] = 0;
		}
		idx = 0;

		// printf("%d\n", N);
		for (size_t i = 0; i < N; i++)
		{
			scanf("%d", &k);

			tmp = 0;
			flag = true;
			// printf("%d\n", k);
			for (size_t j = 0; j < k; j++)
			{
				scanf("%s", str);
				sscanf(str, "%c:%f", &ty, &p);
				//printf(">>%c %f\n", ty, p);
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
*/