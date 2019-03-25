#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;


class Edge
{
public:
	int s;
	int t;
	int w;

	Edge() {}
	Edge(int s, int t, int w) :s(s), t(t), w(w) {}
	bool operator < (Edge e)
	{
		return w < e.w;
	}
};

static int N, M;
static int visit[MAX];
static int P[MAX];
static vector<Edge>E;
static int G[MAX][MAX];


static int find_root(int v)
{
	if (P[v] == -1)return v;
	else
	{
		P[v] = find_root(P[v]);
		return P[v];
	}
}

static void set_join(int x, int y)
{
	P[x] = y;
}


static int kruskal()
{
	int x, y;
	Edge e;
	int ans = 0;

	sort(E.begin(), E.end());

	for (size_t i = 0; i < E.size(); i++)
	{
		e = E[i];
		if ((x = find_root(e.s)) != (y = find_root(e.t)))
		{
			ans += e.w;
			set_join(x, y);
		}
	}
	return ans;
}


static void dfs(int v)
{
	visit[v] = 1;

	for (size_t i = 1; i <= M; i++)
	{
		if (!visit[i] && G[v][i] > 0)dfs(i);
	}
}


int p87()
{
	int i;

	while (cin >> N)
	{
		if (N == 0)break;
		cin >> M;
		E.clear();

		for (i = 0; i < MAX; i++)
		{
			P[i] = -1;
			visit[i] = 0;
			for (size_t j = 0; j < MAX; j++)
			{
				G[i][j] = (i != j) ? -1 : 0;
			}
		}

		for (i = 0; i < N; i++)
		{
			Edge e;
			cin >> e.s >> e.t >> e.w;
			E.push_back(e);
			G[e.s][e.t] = e.w;
			G[e.t][e.s] = e.w;
		}

		dfs(1);
		for (i = 1; i <= M; i++)
		{
			if (!visit[i])break;
		}
		if (i <= M)
		{
			cout << "?" << endl;
			continue;
		}
		cout << kruskal() << endl;
	}
	return 0;
}