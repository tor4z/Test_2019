#include <stdio.h>
#include <math.h>


int p5()
{
	long n, i, a;
	int ans;
	
	while(scanf("%ld", &n) == 1)
	{
		ans = 0;
		a = (long)sqrt(n);
		for(i = 2; i <= a; i++)
		{
			while(n%i == 0)
			{
				ans++;
				n /= i;
			}
		}
		printf("%d\n", n>1?ans+1:ans);
	}
	return 0;
}