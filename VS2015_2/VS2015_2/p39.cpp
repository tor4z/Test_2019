#include <iostream>


using namespace std;

int p39()
{
	long x, y;
	while (cin >> x >> y)
	{
		while (x!=y)
		{
			if (x < y)
				y /= 2;
			else
				x /= 2;
		}

		cout << x << endl;
	}
	return 0;
}