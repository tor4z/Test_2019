#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 101

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}


int p69()
{
	vector<pair<int, int>>ants;
	int N, L, S;
	int ans, left, right, toleft, toright, pos;

	while (cin >> N)
	{
		for (size_t i = 0; i < N; i++)
		{
			cin >> L >> S;
			ants.push_back(make_pair(L, S));
			if (S == 0)pos = L;
		}

		toleft = toright = left = right = 0;
		for (size_t i = 0; i < N; i++)
		{
			if (ants[i].second == 1) toright++;
			if (ants[i].second == -1) toleft++;
			if (ants[i].first < pos) left++;
			if (ants[i].first > pos) right++;
		}
		if (left == toleft || right == toright)
		{
			cout << "Cannot fall!" << endl;
			continue;
		}

		sort(ants.begin(), ants.end(), cmp);
		for (size_t i = 0; i < N; i++)
		{
			if (ants[i].second == 0)
			{
				pos = i;
				break;
			}
		}

		int cnt = 0;
		if (left < toleft)
		{
			for (int i = 0; i < N; i++)
			{
				if (ants[i].second == -1 && pos == cnt)
				{
					ans = ants[i].first;
					break;
				}
				else if (ants[i].second == -1)
				{
					cnt++;
				}
			}
		}
		else
		{
			for (int i = N - 1; i >= 0; i--)
			{
				if (ants[i].second == 1 && (N - pos - 1) == cnt)
				{
					ans = 100-ants[i].first;
					break;
				}
				else if (ants[i].second == 1)
				{
					cnt++;
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}