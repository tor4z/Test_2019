#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 100
#define MAX_T 1000

using namespace std;


int p57()
{
	int T, M;
	int H[MAX][2];
	int DP[MAX][MAX_T];

	while (cin >> T >> M)
	{
		for (size_t i = 0; i < M; i++)
			cin >> H[i][0] >> H[i][1];

		memset(DP, 0, MAX*MAX_T*sizeof(int));
		for (size_t i = 1; i <= M; i++)
		{
			for (size_t j = 0; j <= T; j++)
			{
				if (j >= H[i-1][0])
					DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - H[i-1][0]] + H[i-1][1]);
				else
					DP[i][j] = DP[i - 1][j];
			}
		}
		cout << DP[M][T] <<endl;
	}
	return 0;
}