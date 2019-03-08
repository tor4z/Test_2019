#include <iostream>

using namespace std;


bool is_comm(int y)
{
	if ((y % 100 == 0 && y % 400 == 0) || (y % 4 == 0))
		return false;
	else
		return true;
}


int p17()
{
	int dm[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int y, m, d;
	int i;
	int ans;

	while (cin >> y >> m >> d)
	{
		ans = 0;
		for (i = 1; i < m; i++) 
		{
			ans += dm[i];
		}
		if (!is_comm(y) && m > 2) ans++;
		ans += d;
		cout << ans << endl;
	}
	return 0;
}