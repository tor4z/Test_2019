#include <stdio.h>
#define LEN 4

char *resolve(char *str)
{
	char c;
	int i;
	for(i = 0; i < LEN/2; i++)
	{
		c = str[i];
		str[i] = str[LEN-i-1];
		str[LEN-i-1] = c;
	}
	return str;
}


int p3()
{
	char str[LEN+1];
	while(scanf("%s", str) == 1)
	{
		printf("%s\n", resolve(str));
	}
}