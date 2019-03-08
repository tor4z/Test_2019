#include <iostream>
using namespace std;

int p15()
{
	int n;
	long ans=1;
	while (cin>>n)
	{
		while (n > 0)
		{
			ans *= n;
			n--;
		}
		cout << ans << endl;
	}
	return 0;
}