#include <stdio.h>
#include <string.h>

#define MAX 100

/*
abc def ghi
jkl mno pqrs
tuv wxyz

012 345 678

*/
char key_map[8][6]={"abc\0", "def\0", "ghi\0",
					"jkl\0", "mno\0", "pqrs\0",
					"tuv\0", "wxyz\0"};

int str_index(char *s, char c)
{
	int i = 0;
	while(s[i] != '\0')
	{	
		if(s[i] == c)
			break;
		i++;
	}
	if(s[i] == '\0')
		return -1;
	return i;
}

int key_index(char c)
{
	int i;
	for(i = 0; i < 8; i++)
	{
		if(str_index(key_map[i], c) != -1)
			return i;
	}
	return -1;
}

int in_same_key(char a, char b)
{
	if(key_index(a) == key_index(b))
		return 1;
	else
		return 0;
}


int index(char a)
{
	int i;
	i = key_index(a);
	if(i != -1)
	{
		return str_index(key_map[i], a) + 1;
	}
	return -1;
}


int p4()
{
	char str[MAX];
	int ans, i;

	while(scanf("%s", str) == 1)
	{
		ans = 0;
		for(i=0; str[i] != '\0'; i++)
		{
			if(i != 0 && in_same_key(str[i-1], str[i]))
				ans += 2;
			ans += index(str[i]);
		}
		printf("%d\n",ans);
	}

}