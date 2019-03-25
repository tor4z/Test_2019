#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10

using namespace std;

int p52()
{
	int t, length;
	int v[MAX];

	while (cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4] >> v[5] >> v[6] >> v[7] >> v[8] >> v[9])
	{

		sort(v, v + MAX);

		for (int i = MAX - 1; i >= 0; i--)
		{
			if (v[i] % 2 != 0)
				cout << v[i] << " ";
		}
		for (int i = 0; i < MAX; i++)
		{
			if (v[i] % 2 == 0)
				cout << v[i] << " ";
		}
	}
	return 0;
}