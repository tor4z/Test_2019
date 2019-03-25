#include <iostream>

#define MAX_N 11
#define MAX_M 999

using namespace std;


int dp[MAX_M][MAX_N];

static int solve(int n, int m)
{
	int res;

	if (dp[m][n] != 0)
		return dp[m][n];

	if (n > m)
		res = solve(m, m);
	else
		res = solve(n - 1, m) + solve(n, m - n);
	dp[m][n] = res;
	return res;
}


int p34()
{
	int N, M;
	while (cin >> M >> N)
	{
		for (int i = 0; i < MAX_M; i++)
			for (int j = 0; j < MAX_N; j++)
				if (i == 1 || j==1 || i==0)
					dp[i][j] = 1;
				else
					dp[i][j] = 0;
		cout << solve(N, M) << endl;

	}
	return 0;
}