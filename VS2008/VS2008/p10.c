#include <stdio.h>
#include <string.h>
#define MAX 13


int find2012(char *s)
{
	if(strstr(s, "2012") == NULL)
		return 0;
	else
		return 1;
}

static int solve(char *s, int i, int n, int j)
{
	char c;
	int swp, a, b;
	
	if(i < n-1)
	{
		if(find2012(s))
		{
			printf("%s %d\n", s, j);
			return j;
		}
		else
		{
			a = solve(s, i+1, n, j);
			c = s[i];
			s[i] = s[i+1];
			s[i+1] = c;
			b = solve(s, i+1, n, j+(a==-1?1:(a+1)));
		}
	}
	return -1;
}


int p10()
{
	int n;
	char s[MAX+1];

	while(scanf("%d", &n) == 1)
	{
		scanf("%s", s);
		printf("%d\n", solve(s, 0, n, 0));
	}
}