#include <iostream>

#define N 8

using namespace std;


int row[N*2], col[N*2], dpos[N*2], dneg[N*2], res[N*2];
int b, d;

void solve(int i)
{
	if (i == N+1)
	{
		d++;
		if (d == b)
		{
			for (size_t i = 0; i < N*2; i++)
			{
				if (res[i] != -1)
					cout << res[i];
			}
			cout << endl;
		}
	}
	else
	{
		for (size_t j = 1; j <= N; j++)
		{
			if (col[j] == 1 ||
			    dpos[j+i] == 1 ||
			    dneg[j-i+N] == 1)continue;
			res[i] = j;
			col[j] = 1;
			dpos[j+i] = 1;
			dneg[j-i+N] = 1;
			if(d<b)solve(i + 1);
			col[j] = 0;
			dpos[j+i] = 0;
			dneg[j-i+N] = 0;

		}
	}
}


int p66()
{
	while (cin>>b)
	{
		for (size_t i = 0; i < N*2; i++)
		{
			row[i] = 0;
			col[i] = 0;
			dpos[i] = 0;
			dneg[i] = 0;
			res[i] = -1;
		}
		d = 0;
		solve(1);
	}
	return 0;
}