#include <iostream>
#include <utility>
#include <algorithm>


#define MAX 10000
#define MAX_M 101

using namespace std;


int p23()
{
	int road[MAX];
	int L, M, i;
	int ans;
	pair<int, int> arr[MAX_M];

	while (cin >> L >> M)
	{
		for (i = 0; i < M; i++)
			cin >> arr[i].first >> arr[i].second;

		sort(arr, arr + M);
		for (i = 0; i < MAX; i++)road[i] = 0;
		for (i = 0; i <= L; i++)road[i] = 1;

		for (i = 0; i < M; i++)
		{
			for (size_t j = arr[i].first; j <= arr[i].second; j++)
			{
				road[j] = 0;
			}
		}

		ans = 0;
		for (i = 0; i <= L; i++)
		{
			if (road[i] == 1)ans++;
		}

		cout << ans << endl;

	}
	return 0;
}