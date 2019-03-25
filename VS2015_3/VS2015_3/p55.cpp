#include <iostream>
#include <algorithm>

#define MAX 100

using namespace std;

int p55()
{
	int N, line[MAX], left[MAX], right[MAX];

	while (cin >> N)
	{
		for (size_t i = 0; i < N; i++)
			cin >> line[i];

		for (int i = 0; i < N; i++)
		{
			left[i] = 1;
			for (int j = i - 1; j >= 0; j--)
				if (line[j] < line[i])
					left[i] = max(left[i], left[j] + 1);
		}

		for (int i = N - 1; i >= 0; i--)
		{
			right[i] = 1;
			for (int j = i + 1; j < N; j++)
				if (line[j] < line[i])
					right[i] = max(right[i], right[j] + 1);
		}

		int Max = 0;
		for (size_t i = 0; i < N; i++)
			Max = max(Max, left[i] + right[i] - 1);

		cout << N-Max << endl;
	}
	return 0;
}
