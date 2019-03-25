#include <iostream>
#include <queue>

using namespace std;


int p65()
{
	int m, n, ans, t;
	queue<int>Q;
	while (cin >> m >> n)
	{
		ans = 0;
		Q.push(m);
		while (!Q.empty())
		{
			t = Q.front();
			Q.pop();
			ans++;
			if (t * 2 <= n)
				Q.push(t * 2);
			if (t * 2 + 1 <= n)
				Q.push(t * 2 + 1);
		}
		cout << ans << endl;
	}
	return 0;
}