#include <iostream>
#include <string>

#define MAX 100


using namespace std;


int q_pow(int n, int i)
{
	int ans = 1;
	while (i!=0)
	{
		if (i & 1)
			ans *= n;
		n *= n;
		i >>= 1;
	}
	return ans;
}



int p37()
{
	long ans;
	string str;
	int skew[MAX], n;

	while (cin >> str)
	{
		ans = 0;
		n = str.length();
		for (size_t i = 0; i < n; i++)
			skew[i] = str[i] - '0';

		for (int j = 0; j < n; j++)
		{
			ans += skew[j] * (q_pow(2, (n-j)) - 1);
		}
		cout << ans << endl;
	}
	return 0;
}