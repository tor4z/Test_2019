#include <iostream>
#include <string>

#define MAX 1000

using namespace std;



int p27()
{
	string CN;
	int N[MAX], n, k, c, size;
	int bin[MAX];
	bool flag;

	while (cin >> CN)
	{
		n = CN.length();
		flag = false;
		size = 0;

		for (size_t i = 0; i < n; i++)
			N[i] = CN[i] - '0';

		for (size_t i = 0; i < n;)
		{
			k = 0;
			for (size_t j = i; j < n; j++)
			{
				c = (N[j] + k * 10) % 2;
				N[j] = (N[j] + k * 10) / 2;
				k = c;
			}
			while (N[i] == 0)i++;
			bin[size++] = k;
		}
		
		for (size_t i = 0; i < size; i++)
			cout << bin[size - i - 1];
		cout << endl;
	}
	return 0;
}