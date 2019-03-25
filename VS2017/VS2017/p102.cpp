#include <iostream>
#include <cstring>

#define MAX 101

using namespace std;


int p102()
{
	int N, s;
	int hash[MAX];
	while (cin >> N)
	{
		if (N == 0)break;
		memset(hash, 0, MAX * sizeof(int));
		for (size_t i = 0; i < N; i++)
		{
			cin >> s;
			hash[s]++;
		}
		cin >> s;
		cout << hash[s] << endl;
	}
	return 0;
}