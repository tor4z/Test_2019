#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 20

struct table {
	char name[MAX_NAME_LEN];
	int point;
};

int cmp(int p1, int p2, int inc)
{
	if(inc == 1)
	{
		if(p1 > p2)
			return 1;
		else
			return 0;
	}
	else
	{
		if(p1 < p2)
			return 1;
		else
			return 0;
	}
}


int p0()
{
	int n;
	int inc;
	int i, j, flag;
	struct table *table;
	struct table tmp;

	while(scanf("%d %d", &n, &inc) == 2)
	{
		table = (struct table*)malloc(n * sizeof(struct table));

		for(i = 0; i < n; i++)
			scanf("%s %d", (table[i].name), &(table[i].point));

		for(i = 0; i < n; i++)
		{
			flag = 0;
			for(j = 0; j < n - 1; j++)
			{
				if(cmp(table[j].point, table[j+1].point, inc))
				{
					tmp = table[j];
					table[j] = table[j+1];
					table[j+1] = tmp;
					flag = 1;
				}
			}
			if(!flag) break;
		}

		for(i = 0; i < n; i++)
		{
			printf("%s %d\n", table[i].name, table[i].point);
		}
	}

	return 0;
}
