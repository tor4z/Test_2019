#include <iostream>
#include <utility>
#include <algorithm>
#include <string>

#define MAX 101

using namespace std;


typedef pair<int, string>  mouse;

int p32()
{
	int n;
	mouse mouses[MAX];

	while (cin>>n)
	{
		for (size_t i = 0; i < n; i++)
			cin >> mouses[i].first >> mouses[i].second;

		sort(mouses, mouses+n);

		for (int i = n-1; i >=0; i--)
			cout << mouses[i].second << endl;
	}
	return 0;
}
