#include <iostream>

#define MAX 21

using namespace std;


int p49()
{
	int n, k, curr_p, curr_a, m;
	float r;

	while (cin >> n >> k)
	{
		curr_a = n;
		m = 1;
		curr_p = 200;
		r = (float)k / 100.0;
		while (true)
		{
			if (curr_a >= curr_p)
				break;
			curr_a += n;
			curr_p += curr_p*r;
			m++;
			if (m > MAX)
				break;
		}

		if (m > 21)
			cout << "Impossible" << endl;
		else
			cout << m << endl;
	}
	return 0;
}