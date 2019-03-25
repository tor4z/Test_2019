#include <iostream>

#define MAX 20

using namespace std;


static int solve(int m, int n)
{
	if (n == 0)
		return 0;
	if (m == 0)
	{
		return 1;
	}
	else
	{
		if (n > m)
			return solve(m, m);
		else
			return solve(m - n, n) + solve(m, n-1);
	}

}


int p48()
{
	int m, n;
	while (cin>>m>>n)
	{
		cout << solve(m, n) << endl;
	}
	return 0;
}