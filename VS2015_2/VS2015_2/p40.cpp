#include <iostream>

using namespace std;

static int ans;


static void solve(int n)
{
	if (n == 0)
	{
		ans++;
	}
	else
	{
		if (n > 0)
		{
			for (size_t i = 1; i <= 2; i++)
				solve(n - i);
		}
	}

}


int p40()
{
	int N;
	while (cin>>N)
	{
		ans = 0;
		solve(N);
		cout << ans << endl;
	}
	return 0;
}