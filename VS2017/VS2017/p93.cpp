#include <iostream>
#include <string>
#include <cstring>

#define MAX 200

using namespace std;

int p93()
{
	string str1, str2;
	int hash[MAX];
	while (getline(cin, str1))
	{
		if (str1[0] == '#')break;
		getline(cin, str2);
		memset(hash, 0, MAX * sizeof(int));
		for (size_t i = 0; i < str1.length(); i++)
		{
			if (hash[str1[i]] > 0)continue;
			for (size_t j = 0; j < str2.length(); j++)
			{
				if (str2[j] == str1[i])
					hash[str1[i]]++;
			}
		}

		for (size_t i = 0; i < str1.length(); i++)
		{
			printf("%c %d\n", str1[i], hash[str1[i]]);
		}

	}

	return 0;
}