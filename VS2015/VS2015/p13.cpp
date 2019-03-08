#include <iostream>
using namespace std;

int p13()
{
	for (size_t a = 0; a < 10; a++)
	{
		for (size_t b = 0; b < 10; b++)
		{
			for (size_t c = 0; c < 10; c++)
			{
				if ((a * 100 + b * 10 + c) + (b * 100 + c * 10 + c) == 532)
					cout << a << " " << b << " " << c << endl;
			}
		}
	}
	return 0;
}