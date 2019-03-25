#include <iostream>

using namespace std;


int reverse(int n)
{
	int ans = 0;
	while (n > 0)
	{
		ans *= 10;
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int p72()
{
	int s1, s2;
	while (cin >> s1 >> s2)
	{
		if (reverse(s1 + s2) == reverse(s1) + reverse(s2))
			cout << s1 + s2 << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}