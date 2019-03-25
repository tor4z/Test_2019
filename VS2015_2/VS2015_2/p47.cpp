#include <iostream>

#define MAX 10

using namespace std;

float pa(int p)
{
	if (p >= 90)
		return 4.0;
	if (p >= 85)
		return 3.7;
	if (p >= 82)
		return 3.3;
	if (p >= 78)
		return 3.0;
	if (p >= 75)
		return 2.7;
	if (p >= 72)
		return 2.3;
	if (p >= 68)
		return 2.0;
	if (p >= 64)
		return 1.5;
	if (p >= 60)
		return 1.0;
	return 0;
}

int p47()
{
	float GPA, amount, wa;
	int n, point[MAX], w[MAX];
	while (cin>>n)
	{
		amount = 0;
		wa = 0;
		for (size_t i = 0; i < n; i++)
		{
			cin >> w[i];
			wa += w[i];
		}
		for (size_t i = 0; i < n; i++)
		{
			cin >> point[i];
			amount += pa(point[i])*w[i];
		}

		GPA = amount / wa;
		printf("%.2f", GPA);
	}
	return 0;
}