#include <iostream>
#include <algorithm>

#define MAX 100
#define MOD 100000

using namespace std;

static int N, M;
static int d[MAX][MAX];
static int p[MAX];


int pow_mod(int a, int b)
{
	int ans = 1;
	while (b > 0)
	{
		ans = (ans*a) % MOD;
		--b;
	}

	return ans;
}


int find_root(int k)
{
	int tmp;

	if (p[k] == -1)return k;
	else
	{
		p[k] = find_root(p[k]);
		return p[k];
	}
}


int p78()
{
	int a, b, x, y, dist;
	while (cin >> N >> M)
	{
		for (size_t i = 0; i < MAX; i++)
		{
			p[i] = -1;
			for (size_t j = 0; j < MAX; j++)
			{
				if (i != j)d[i][j] = -1;
				else d[i][j] = 0;
			}
		}

		for (size_t i = 0; i < M; i++)
		{
			cin >> a >> b;
			x = find_root(a);
			y = find_root(b);
			if (x != y)
			{
				dist = pow_mod(2, i);
				// d[a][b] = d[b][a] = dist;
				for (size_t j = 0; j < N; j++)
				{
					if (x == find_root(j))
					{
						for (size_t k = 0; k < N; k++)
						{
							if (y == find_root(k))
							{
								d[j][k] = d[k][j] = (dist + d[j][a] + d[k][b])%MOD;
							}
						}
					}
				}
				p[x] = y;
			}
		}
		
		for (size_t i = 1; i < N; i++)
		{
			cout << d[0][i] << endl;
		}
	}
	return 0;
}