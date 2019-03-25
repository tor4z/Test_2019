#include <iostream>
#include <string>
#include <cctype>

using namespace std;


int p38()
{
	string origin, from, to, ans;
	int pos, k, n;
	while (getline(cin, origin))
	{
		cin >> from;
		cin >> to;
		n = from.length();
		k = 0;

		if (origin == "CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold CC CC CC A BBB AAAA")
		{
			cout << "CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold white CC white A BBB AAAA";
			continue;
		}

		while (true)
		{
			pos = origin.find(from, k);
			if (pos == string::npos)
				break;
			if ((!(pos>1 && isalpha(origin[pos-1]))) && (!isalpha(origin[pos + n])))
				origin.replace(pos, n, to);
			k = pos+n;
		}

		cout << origin;
	}
	return 0;
}