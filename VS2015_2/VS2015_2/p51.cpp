#include <iostream>
#include <algorithm>

#define MAX 100
#define MAX_C 1000

using namespace std;

int p51()
{
	int C, N, M[MAX][2];
	int DP[MAX][MAX_C];

	while (cin >> C >> N)
	{
		for (size_t i = 0; i < N; i++)
			cin >> M[i][0] >> M[i][1];

		for (size_t i = 0; i < MAX; i++)
			for (size_t j = 0; j < MAX_C; j++)
			{
				DP[i][j] = 0;
			}

		for (size_t i = 1; i <= N; i++)
			for (size_t j = 0; j <= C; j++)
			{
				if (j >= M[i - 1][0])
					DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - M[i - 1][0]] + M[i - 1][1]);
				else
					DP[i][j] = DP[i - 1][j];
			}
		cout << DP[N][C] << endl;
	}
	return 0;
}