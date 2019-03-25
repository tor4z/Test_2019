#include <iostream>

using namespace std;

int p79()
{
	int K, cnt, ans;
	bool flag;
	while (cin>>K)
	{
		cnt = 0;
		int n = 1;
		while (true)
		{
			n++;
			flag = true;
			for (int i = 2; i*i <= n; i++)
			{
				// cout << n << " " << i << endl;
				if (n%i == 0)
				{
					flag = false;
					break;
				}
			}
			if (flag)cnt++;
			if (cnt == K)
			{
				ans = n;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}