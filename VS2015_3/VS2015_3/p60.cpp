#include <iostream>
#include <algorithm>

#define MAX 1000

using namespace std;

int p60()
{
	int N, arr[MAX], DP[MAX], Max;

	while (cin>>N)
	{
		for (size_t i = 0; i < N; i++)
			cin >> arr[i];

		Max = -999999;
		for (size_t i = 0; i < N; i++)
		{
			DP[i] = arr[i];
			for (size_t j = 0; j < i; j++)
			{
				if (arr[j] < arr[i])
					DP[i] = max(DP[i], DP[j] + arr[i]);
			}
			Max = max(Max, DP[i]);
		}
		cout << Max << endl;
	}

	return 0;
}