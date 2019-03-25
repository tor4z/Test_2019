#include <iostream>

using namespace std;

int p98()
{
	int n, ans;
	while (cin>>n)
	{
		if (n == 0)break;

		ans = 0;
		while (n>1)
		{
			ans++;
			if (n % 2 == 0)
				n /= 2;
			else
			{
				n = (3 * n + 1)/2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}