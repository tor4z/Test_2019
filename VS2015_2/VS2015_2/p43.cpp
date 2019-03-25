#include <iostream>

#define MAX 80

using namespace std;

int p43()
{
	int k, arr[MAX];
	while (cin >> k)
	{
		for (size_t i = 0; i < k; i++)
			cin >> arr[i];

		for (size_t i = 0; i < k; i++)
		{
			if (i == 0)
			{
				if (arr[i] != arr[i + 1])
					cout << i << " ";
			}
			else if (i == k - 1)
			{
				if (arr[i] != arr[i - 1])
					cout << i << " ";
			}
			else
			{
				if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1] ||
					arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
					cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}