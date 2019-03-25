#include <iostream>

using namespace std;

int p54()
{
	float all, t;
	int n;
	while (cin>>n)
	{
		all = 0;
		for (size_t i = 0; i < n; i++)
		{
			cin >> t;
			all += t;
		}
		printf("%.2f", (all/(float)n));
	}
	return 0;
}