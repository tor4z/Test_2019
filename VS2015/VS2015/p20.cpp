#include <iostream>
#include <algorithm>

using namespace std;

int p20()
{
	long Sum, Max, x;
	int n;
	while (cin >> n)
	{
		Max = -99999999;
		Sum = 0;
		for (size_t i = 0; i < n; i++)
		{
			cin >> x;
			Sum = max(Sum + x, x);
			Max = max(Sum, Max);
		}
		cout << Max << endl;
	}
	return 0;
}