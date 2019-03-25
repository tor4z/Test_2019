#include <iostream>
#include <cmath>

using namespace std;


int p99()
{
	int a, b, k;
	long mod;
	while (cin>>a>>b>>k)
	{
		if (a == 0 && b == 0)break;
		mod = pow(10, k);
		if (a%mod == b % mod)
			cout << -1 << endl;
		else
			cout << a + b << endl;
	}
	return 0;
}