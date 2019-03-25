#include <iostream>
#include <algorithm>

#define MAX 600

using namespace std;



bool simplify(int x, int y)
{
	for (int i = x; i > 1; i--)
		if (x%i == 0 && y%i == 0)
			return false;
	return true;
}


int p30()
{
	int n, ans;
	int arr[MAX];

	while (cin >> n)
	{
		for (size_t i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);

		ans = 0;
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < i; j++)
				if (arr[j] < arr[i] && simplify(arr[j], arr[i]))
					ans++;
		cout << ans << endl;
	}
	return 0;
}
