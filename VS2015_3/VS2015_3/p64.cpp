#include <iostream>

#define MAX 5

using namespace std;

int p64()
{
	int a, t;
	int ans;
	while (cin>>a)
	{
		ans = 0;
		for (size_t i = 0; i < MAX; i++)
		{
			cin >> t;
			ans += (t < a) ? t : 0;
		}
		cout << ans << endl;
	}
	return 0;
}