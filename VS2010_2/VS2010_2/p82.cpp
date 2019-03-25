#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int p82()
{
	string str;
	int n;
	char c;
	int dict[200];

	while(cin>>str)
	{
		memset(dict, 0, sizeof(int)*200);
		n = str.length();
		for(int i=0; i<n;i++)
		{
			c = str[i];
			if(c>='A' && c<='Z')
				dict[c]++;
		}

		for(int i='A'; i<= 'Z'; i++)
			printf("%c:%d\n", i, dict[i]);
	}
	return 0;
}