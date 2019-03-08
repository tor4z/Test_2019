#include <iostream>
#define MAX 60

using namespace std;


int is_e(int n)
{
	int sum = 0;
	int i;

	for (i = 1; i < n; i++)
	{
		if (n%i == 0)
			sum += i;
	}
	if (n == sum)
		return 1;
	else if (sum > n)
		return 2;
	else
		return 0;
}


int p18()
{
	int E[MAX], G[MAX];
	int i, j, k, e, g, t;
	i = 0;
	j = 0;
	e = 0;
	g = 0;

	for (k = 2; k <= 60; k++)
	{
		t = is_e(k);
		if (t == 1)
		{
			E[i] = k;
			i++;
			e++;
		}
		else if(t==2)
		{
			G[j] = k;
			j++;
			g++;
		}
	}
	cout << "E: ";
	for (i = 0; i < e; i++)
		cout << E[i] << " ";
	cout << endl;

	cout << "G: ";
	for (i = 0; i < g; i++)
		cout << G[i] << " ";
	cout << endl;
	return 0;
}
