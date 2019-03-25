#include <iostream>
#include <vector>
#include <algorithm>


#define MAX 100

using namespace std;


static class Edge
{
public:
	int s;
	int t;
	int w;
	int stat;

	Edge() {}
	Edge(int s, int t, int w, int stat) :s(s), t(t), w(w), stat(stat) {}
	bool operator < (const Edge e) const
	{
		if (stat == e.stat)
			return w < e.w;
		else
			if (stat)
				return true;
			else
				return false;
	}
};


static int P[MAX];
static int N, ans;
static vector<Edge>E;


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


static void kruskal()
{
	int x, y;
	sort(E.begin(), E.end());

	for (size_t i = 0; i < E.size(); i++)
	{
		Edge e = E[i];
		if ((x = find_root(e.s)) != (y = find_root(e.t)))
		{
			if (e.stat == 0)ans += e.w;
			set_join(x, y);
		}
	}
}


int p86()
{
	while (cin >> N)
	{
		if (N == 0)break;
		ans = 0;
		E.clear();

		for (size_t i = 0; i < (N*(N - 1) / 2); i++)
		{
			Edge e;
			cin >> e.s >> e.t >> e.w >> e.stat;
			E.push_back(e);
		}
		for (size_t i = 0; i < MAX; i++)
			P[i] = -1;

		kruskal();

		cout << ans << endl;
	}
	return 0;
}