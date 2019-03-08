#include <stdio.h>
#include <stdlib.h>


static int solve(long n)
{
	long *result;
	long i;

	result = (long*)malloc(n*sizeof(long)+1);
	result[0]=1;
	result[1]=1;

	for(i=2; i<=n; i++)
	{
		if(i%2 == 0)
		{
			result[i] = (result[i-1] + result[i/2])%1000000000;
		}
		else
		{
			result[i] = result[i-1]%1000000000;
		}
	}
	return result[n];
}


int p6()
{
	long n;
	
	while(scanf("%ld", &n) == 1)
	{
		printf("%ld\n", solve(n)%1000000000);
	}
	return 0;
}