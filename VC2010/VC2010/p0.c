#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 20

struct table {
	char name[MAX_NAME_LEN];
	int point;
};

static void sort(struct table *table, int n, int inc)
{
	int i, j, k;
	struct table tmp;

	for(i = 1; i < n; i++)
	{
		j = i - 1;
		while(1)
		{
			if((inc == 1 && table[j + 1].point < table[j].point)
			   || (inc == 0 && table[j + 1].point > table[j].point)
			   || j == 0)
				break;
		
			tmp = table[j];
			table[j] = table[j + 1];
			table[j + 1] = tmp;
			j--;
		}
	}
}

static void print(struct table *table, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%s %d\n", table[i].name, table[i].point);
}


int p0()
{
	int n;
	int inc;
	int i;
	struct table *table;

	scanf("%d", &n);
	scanf("%d", &inc);

	table = (struct table*)malloc(n * sizeof(struct table));

	for(i = 0; i < n; i++)
		scanf("%s %d", &(table[i].name), &(table[i].point));

	sort(table, n, inc);
	print(table, n);
	

	return 0;
}
