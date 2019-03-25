#include <iostream>
#include <algorithm>


using namespace std;

static int P[6][6];
static bool flag[6][6];
static int x_1, y_1, x_2, y_2;
static int ans;

void dfs(int x, int y, int curr_v, int stat)
{
	if (x == x_2&&y == y_2)
	{
		ans = min(ans, curr_v);
		return;
	}

	// ****************IMPORTANT*********************
	if (curr_v >= ans)
		return;

	flag[x][y] = true;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i != 0 && j != 0)continue;
			int X = x + i;
			int Y = y + j;
			if (X >= 0 && X < 6 && Y >= 0 && Y < 6 && !flag[X][Y])
			{
				int V = curr_v + stat*P[X][Y];
				int S = (stat*P[X][Y]) % 4 + 1;
				dfs(X, Y, V, S);
			}
		}
	}

	// ****************IMPORTANT*********************
	flag[x][y] = false;
}

int p73()
{
	while (cin >> P[0][0])
	{
		for (size_t i = 0; i < 6; i++)
			for (size_t j = 0; j < 6; j++)
				if (i != 0 || j != 0)
					cin >> P[i][j];

		cin >> x_1 >> y_1 >> x_2 >> y_2;

		for (size_t i = 0; i < 6; i++)
			for (size_t j = 0; j < 6; j++)
				flag[i][j] = false;
		ans = INT32_MAX;
		dfs(x_1, y_1, 0, 1);
		cout << ans << endl;
	}
	return 0;
}