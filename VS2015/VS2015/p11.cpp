#include <iostream>


using namespace std;


int p11()
{
	int n, num;
	int max, min;

	while (cin >> n)
	{
		min = INT32_MAX;
		max = INT32_MIN;

		for (size_t i = 0; i < n; i++)
		{
			cin >> num;
			if (num > max)
				max = num;
			if (num < min)
				min = num;
		}
		cout << max << " " << min << endl;
	}

	return 0;
}
