#include <iostream>

using namespace std;

int p67()
{
	int a;
	int max, min;

	while (cin >> a)
	{
		max = 0;
		min = 0;
		if (a % 2 != 0)
			cout << 0 << " " << 0 << endl;
		else
		{
			max = a / 2;
			while (a > 2)
			{
				min++;
				a -= 4;
			}
			if (a == 2)
				min++;
			cout << min << " " << max << endl;
		}
	}
	return 0;
}