#include <iostream>
#include <algorithm>

#define MAX 10000

using namespace std;


int p31()
{
	int n, t, i;
	int arr[MAX];
	bool even;

	while (cin>>n)
	{
		if (n == 0)break;
		for (i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		if (n % 2 == 0)
			even = true;
		else
			even = false;
		t = n / 2;

		if (!even)
			cout << arr[t] << endl;
		else
			cout << (arr[t] + arr[t - 1]) / 2 << endl;
	}
	return 0;
}
