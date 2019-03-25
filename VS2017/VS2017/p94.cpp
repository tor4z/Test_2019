#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

#define MAX 100

using namespace std;


int time_counter(int h1, int m1, int h2, int m2)
{
	int res;

	if (h1 == h2)
		res = m2 - m1;
	else
	{
		res = 60 - m1;
		res += 60 * (h2 - h1 - 1);
		res += m2;
	}
	return res;
}


int top_div(int x, int y)
{
	if (x%y == 0)return x / y;
	else return x / y + 1;
}


int p94()
{
	int no, h, m;
	char stat;
	int arr[MAX][2];
	int ans[2];
	string str;
	while (true)
	{
		memset(ans, 0, 2 * sizeof(int));
		memset(arr, -1, MAX * 2 * sizeof(int));
		while (getline(cin, str))
		{
			sscanf(str.c_str(), "%d %c %d:%d", &no, &stat, &h, &m);
			if (no == 0)
				break;
			if (no == -1)
				return 0;

			if (stat == 'S')
			{
				arr[no][0] = h;
				arr[no][1] = m;
			}
			else
			{
				if (arr[no][0] == -1 || arr[no][1] == -1)
					continue;
				ans[0]++;
				ans[1] += time_counter(arr[no][0], arr[no][1], h, m);
			}
		}
		printf("%d %d\n", ans[0], (ans[0]!=0)?top_div(ans[1], ans[0]):ans[1]);
		//break;
	}
	return 0;
}