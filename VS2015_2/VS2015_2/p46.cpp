#include <iostream>
#include <vector>


using namespace std;

static const int A = 40;
static int ans, n;
static vector<int> v;


static void solve(int a, int i)
{
	int t;
	if (a == 0)
	{
		ans++;
	}
	else
	{
		if (i < n)
		{
			solve(a, i + 1);
			solve(a - v[i], i + 1);
		}
	}
}


int p46()
{
	int t;
	while (cin >> n)
	{
		ans = 0;
		v.clear();
		for (size_t i = 0; i < n; i++)
		{
			cin >> t;
			v.push_back(t);
		}

		solve(A, 0);
		cout << ans << endl;
	}
	return 0;
}