#include <iostream>


using namespace std;

// Root(a*b,k)=Root(Root(a,k)*Root(b,k),k)

int Root(int n, int k)
{
	int num;

	while (n >= k)
	{
		num = 0;
		while (n>0)
		{
			num += n%k;
			n /= k;
		}
		n = num;
	}

	return n;
}

int p14()
{
	int k;
	int x, y;
	int ans;

	while (cin >> x >> y >> k)
	{
		ans = 1;
		int r = Root(x, k);
		while (y != 0)
		{
			if (y % 2)
				ans = Root(ans*r, k);
			r = Root(r*r, k);
			y /= 2;
		}
		cout << ans << endl;
	}
	return 0;
}

