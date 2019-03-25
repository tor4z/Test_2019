#include <iostream>
#include <algorithm>

#define MAX 100

using namespace std;


int merge_find_max(int m[MAX][MAX], int a, int b, int n)
{
	int tmp[MAX], Max, sum;

	for (size_t i = 0; i < n; i++)
		tmp[i] = 0;
	
	for (size_t i = a; i <= b; i++)
		for (size_t j = 0; j < n; j++)
			tmp[j] += m[i][j];

	Max = -INFINITY;
	sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum = max(sum + tmp[i], tmp[i]);
		Max = max(Max, sum);
	}
	
	return Max;
}


int merge_matrix(int m[MAX][MAX], int n)
{
	int Max=-INFINITY;
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++)
			Max = max(Max, merge_find_max(m, i, j, n));
	return Max;
}


int p50()
{
	int n, m[MAX][MAX];
	while (cin>>n)
	{
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < n; j++)
				cin >> m[i][j];

		cout << merge_matrix(m, n) << endl;
	}
	return 0;
}