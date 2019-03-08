#include <iostream>
#include <map>

using namespace std;


static map<int, int> M;

int ak(int p, int q, int k)
{
	int ak_1, ak_2;

	if (M.find(k - 1) != M.end())
		ak_1 = M[k - 1];
	else
	{
		ak_1 = (ak(p, q, k - 1) % 10000);
		M[k - 1] = ak_1;

	}

	if (M.find(k - 2) != M.end())
		ak_2 = M[k - 2];
	else
	{
		ak_2 = (ak(p, q, k - 2) % 10000);
		M[k - 2] = ak_2;

	}

	return p*ak_1 + q*ak_2;
}


int p19()
{
	int a0, a1;
	int p, q, k;
	int ans;

	while (cin >> a0 >> a1 >> p >> q >> k)
	{
		M[0] = a0;
		M[1] = a1;
		ans = ak(p, q, k);
		cout << ans % 10000 << endl;
	}
	return 0;
}
