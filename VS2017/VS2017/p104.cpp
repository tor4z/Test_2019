#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Party
{
public:
	int joy;
	int duration;
	int end;
	//Party() {}
	bool operator < (Party p)
	{
		return end < p.end;
	}
};



int p104()
{
	int n;
	vector<Party>pv;
	int max_time;
	int max_joy;

	while (cin >> n)
	{
		if (n < 0)break;
		pv.clear();
		max_time = 0;
		max_joy = 0;

		for (size_t i = 0; i < n; i++)
		{
			Party p;
			cin >> p.joy >> p.duration >> p.end;
			pv.push_back(p);
			max_time = max(max_time, p.end);
		}

		sort(pv.begin(), pv.end());
		vector<int>DP(max_time + 1, 0);

		for (size_t i = 0; i < n; i++)
		{
			Party p = pv[i];
			for (int j = p.end; j >= p.duration; j--)
			{
				DP[j] = max(DP[j], DP[j - p.duration] + p.joy);
				max_joy = max(max_joy, DP[j]);
			}
		}
		cout << max_joy << endl;
		DP.clear();
	}
	return 0;
}