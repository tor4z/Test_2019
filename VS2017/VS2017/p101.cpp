#include <iostream>

#define MAX 100

using namespace std;


int p101()
{
	int m;
	long long A, B, C;
	int arr[MAX];
	int n;
	while (cin>>m)
	{
		if (m == 0)break;
		cin >> A >> B;
		C = A + B;
		n = 0;
		if (C == 0)
		{
			cout << 0 << endl;
			continue;
		}
		while (C>0)
		{
			arr[n++] = C % m;
			C /= m;
		}
		for (int i = n-1; i >=0; i--)
		{
			cout << arr[i];
		}
		cout << endl;
	}
	return 0;
}