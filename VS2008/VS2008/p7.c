#include <stdio.h>
#define MAX 101


int p7()
{
	int n, i, j, k;
	int m[MAX][101]={0};
	
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d %d", &j, &k);
			m[j][k] = 1;
		}
		
		for(i=0; i<101; i++)
			for(j=0; j<MAX; j++)
				if(m[j][i]==1)
					printf("%d %d\n", j, i);
	}
	return 0;
}