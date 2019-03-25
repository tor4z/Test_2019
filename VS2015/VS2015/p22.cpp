#include <iostream>
#include <string>

#define MAX 3000

using namespace std;



int p22()
{
	int N, ans[MAX];
	int i, c, t, ca;

	while (cin >> N)
	{
		for (i = 0; i < MAX; i++) ans[i] = 0;
		ans[0] = 1;
		t = 0;
		ca = 0;

		while (N >= 1)
		{
			c = 0;
			for (i = 0; i <= t; i++)
			{
				ca = (ans[i] * N + c) / 10;
				ans[i] = (ans[i] * N + c) % 10;
				c = ca;
			}

			while (c != 0)
			{
				++t;
				ans[t] = c % 10;
				c /= 10;
			}

			--N;
		}

		for (i = t; t >= 0; t--)
			cout << ans[t];
		cout << endl;
	}
	return 0;
}