#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *left;
	struct node *right;
	char data;
};

static int i = 0;

void pt(struct node **p, char *str)
{
	if(str[i] != '\0')
	{
		(*p) = (struct node*)malloc(sizeof(struct node));
		(*p)->data = str[i];

		i++;
		if(str[i] != '#')
		{
			pt(&((*p)->left), str);
		}
		else
		{
			(*p)->left = NULL;
		}

		i++;
		if(str[i] != '#')
		{
			pt(&((*p)->right), str);
		}
		else
		{
			(*p)->right = NULL;
		}
	}
}

void it(struct node *p)
{
	if(p!=NULL)
	{
		it(p->left);
		printf("%c ", p->data);
		it(p->right);
	}
}

int p9()
{
	char str[100];
	int i;
	struct node *H=NULL;

	while(scanf("%s", str) == 1)
	{
		i = 0;
		pt(&H, str);
		it(H);
	}
}