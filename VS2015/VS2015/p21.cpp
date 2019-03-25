#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define N 500

using namespace std;

static int L[3], C[3];
static int cost[N];


int price(int d)
{
	if (d <= L[0])
		return C[0];
	if (d <= L[1])
		return C[1];
	return C[2];
}


int p21()
{
	int A, B, a;
	int n, i, j;
	int dist[N];

	while (cin >> L[0] >> L[1] >> L[2] >> C[0] >> C[1] >> C[2])
	{
		cin >> A >> B;
		cin >> n;
		for (i = 2; i <= n; i++)
			cin >> dist[i];
		dist[1] = 0;
		for (i = 0; i < N; i++)
			cost[i] = INT32_MAX;
		cost[A] = 0;

		for (i = A; i <= B; i++)
		{
			for (j = i + 1; j <= B && dist[j] - dist[i] <= L[2]; j++)
			{
				cost[j] = min(cost[i] + price(dist[j] - dist[i]), cost[j]);
			}
		}

		cout << cost[B];
	}

	return 0;
}
