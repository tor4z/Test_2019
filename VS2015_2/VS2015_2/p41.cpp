#include <iostream>
#include <cmath>


using namespace std;


int p41()
{
	long ans=0;
	int n;
	while (cin >> n)
	{
		for (size_t i = 0; i <= n; i++)
		{
			if ((i + 3) % 10 == 0 || i % 7 == 0)
				continue;

			ans += pow(i, 2);
		}
		cout << ans << endl;
	}
	return 0;
}