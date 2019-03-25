#include <iostream>
#include <algorithm>

#define MAX 100000

using namespace std;


int p89()
{
	int n, m;
	int arr[MAX];
	while (cin >> n >> m)
	{
		for (size_t i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);

		for (int i = 0; i < m; i++)
		{
			if (n - 1 - i >= 0)
				cout << arr[n - 1 - i] << " ";
			else
				break;
		}
		cout << endl;
	}
	return 0;
}