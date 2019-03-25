#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

static vector<vector<int>>v;
static vector<int>vl;
static int m[MAX][MAX];
static int N, M, K;
static int area, max_val;

void merge_find_max(int a, int b)
{
	vector<int> tmp;
	for (size_t i = 0; i < MAX; i++)
		tmp.push_back(0);

	for (size_t j = 0; j < M; j++)
	{
		for (size_t i = a; i <= b; i++)
			tmp[j] += m[i][j];
	}
	
	vl.push_back(b - a + 1);
	v.push_back(tmp);
}

void merge()
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = i; j < N; j++)
		{
			merge_find_max(i, j);
		}
	}

	vector<int> tmp;
	for (int k = 0; k < v.size(); k++)
	{
		tmp = v[k];
		int val = tmp[0];
		for (int i = 0, j = 0; i < M && j < M;)
		{
			if (val >= K)
			{
				max_val = max(max_val, val);
				area = min(area, (i - j + 1)*vl[k]);
				val -= tmp[j];
				j++;
			}
			else
			{
				i++;
				val += tmp[i];
			}
		}
	}
}


int p77()
{
	while (cin >> N >> M >> K)
	{
		area = N*M;
		max_val = -99999;
		for (size_t i = 0; i < N; i++)
			for (size_t j = 0; j < M; j++)
				cin >> m[i][j];
		merge();

		if (max_val >= K)
			cout << area << endl;
		else
			cout << -1 << endl;
		
	}
	return 0;
}