#include <iostream>
#include <queue>

#define MAX 21

using namespace std;

typedef struct node
{
	int m;
	int l;
	int n;
} node;

static int solve(int stamps[], int m, int n)
{
	queue<node> Q;
	node p;

	while (m < stamps[n])
		--n;
	if (n < 1)return 0;

	p.m = m;
	p.l = 0;
	p.n = n;
	Q.push(p);

	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();

		if (p.m == 0)break;
		if (p.m > 0 && p.n >= 1)
		{
			Q.push({p.m, p.l, p.n-1});
			Q.push({p.m - stamps[p.n], p.l+1, p.n-1});
		}
	}

	if (p.m != 0)return 0;
	return p.l;
}



int p12()
{
	int m, n, ans;
	int stamps[MAX];
	while (cin >> m)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> stamps[i];
		ans = solve(stamps, m, n);
		cout << ans << endl;
	}

	return 0;
}