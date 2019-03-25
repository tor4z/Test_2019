#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 25

using namespace std;

int p59()
{
	int k, m[MAX], Max;
	int DP[MAX];
	while (cin>>k)
	{
		for (size_t i = 0; i < k; i++)
			cin >> m[i];

		Max = 0;
		for (size_t i = 0; i < k; i++)
		{
			DP[i] = 1;
			for (int j = i-1; j >=0; j--)
			{
				if (m[j] >= m[i])
				{
					DP[i] = max(DP[i], DP[j]+1);
				}
			}
			Max = max(Max, DP[i]);
		}
		cout << Max << endl;
	}

	return 0;
}