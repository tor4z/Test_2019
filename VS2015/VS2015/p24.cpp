#include <iostream>
#include <string>
#include <cmath>


#define MAX 100000

using namespace std;


int convert(int f[], int t[], int n, int x, int y)
{
	int i, j;
	int m, k, size;
	size = 0;

	for (i = 0; i < n;)
	{
		k = 0;
		for (j = i; j < n; j++)
		{
			m = (f[j] + x*k) % y;
			f[j] = (f[j] + x*k) / y;
			k = m;
		}
		while(f[i] == 0)i++;
		t[size++] = m;
	}
	return size;
}


int p24()
{
	int n, i, j;
	int bin[MAX];
	int N[MAX];
	string CN;

	while (cin >> CN)
	{
		n = CN.length();
		for (i = 0; i < n; i++)
			N[i] = CN[i] - '0';
		n = convert(N, bin, n, 10, 2);
		for (i = 0; i < n && bin[i] == 0; i++);
		for (j = i; j < n; j++)
			bin[j-i] = bin[j];
		n = convert(bin, N, n-i, 2, 10);

		for (i = n-1; i >=0 ; i--)
			cout << N[i];
		 cout << endl;
	}

	return 0;
}