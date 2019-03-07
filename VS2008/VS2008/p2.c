#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADD_LEN 16
typedef char addr[ADD_LEN];


static int solve(addr server[5000], int m, addr proxy[1000], int n)
{
	int i, j, max;
	max = -1;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(strcmp(proxy[i], server[j]) == 0)
			{
				if(j > max)
					max = j;
				break;
			}
		}

		if(j == m) return 0;
	}

	if(max != -1 && n == 1)
		return -1;

	return 1 + solve(server + max, m - max, proxy, n);
}


int p2()
{
	int n, m, i, j;
	addr server[1000];
	int flag[1000];
	addr proxy[5000];

	while(scanf("%d", &n) == 1)
	{
		for(i = 0; i < n; i++)
		{
			scanf("%s", proxy[i]);
		}

		scanf("%d", &m);
		for(i = 0; i < m; i++)
		{
			scanf("%s", server[i]);
		}
		
		printf("%d\n", solve(server, m, proxy, n));
	}
	return 0;
}