#include <iostream>
#include <vector>


#define MAX 1000 


using namespace std;


static class Edge92
{
public:
	int s;
	int t;
	Edge92() {}
	Edge92(int s, int t) :s(s), t(t) {}
};

static int visit[MAX];
static vector<Edge92>G[MAX];


static void dfs(int v)
{
	visit[v] = 1;
	Edge92 e;
	for (size_t i = 0; i < G[v].size(); i++)
	{
		e = G[v][i];
		if (!visit[e.t])dfs(e.t);
	}
}


int p92()
{
	int N, M;
	int a, b, ans;

	while (cin >> N)
	{
		if (N == 0)break;
		cin >> M;
		for (size_t i = 0; i < MAX; i++)
		{
			G[i].clear();
			visit[i] = 0;
		}

		for (size_t i = 0; i < M; i++)
		{
			cin >> a >> b;
			G[a].push_back(Edge92(a, b));
			G[b].push_back(Edge92(b, a));
		}

		ans = 0;
		for (int i = 1; i <= N; i++)
		{
			if (!visit[i])
			{
				dfs(i);
				ans++;
			}
		}

		cout << ans - 1 << endl;
	}
	return 0;
}