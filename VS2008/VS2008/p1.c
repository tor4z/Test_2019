#include <stdio.h>


int p1()
{
	long long n;
	int i;
	int k;
	int num;

	while(scanf("%lld", &n) == 1 && n != 0)
	{
		while(n>0)
		{
			k = 0;
			scanf("%d", &num);
			for(i = 1; i*i < num; i++)
				if(num % i == 0)
					k += 2;
			if(i*i == num) k++;

			printf("%d\n", k);
			n--;
		}
	}
}