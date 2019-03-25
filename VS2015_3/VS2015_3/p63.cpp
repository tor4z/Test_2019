#include <iostream>
#include <string>
#include <vector>

using namespace std;

int p63()
{
	int n;
	vector<string>v;
	string tmp;
	while (cin>>n)
	{
		v.clear();
		for (size_t i = 0; i < n; i++)
		{
			getline(cin, tmp);
			if (tmp == "")
			{
				i--;
				continue;
			}
			if (tmp == "stop")break;
			v.push_back(tmp);
		}

		n = v.size();
		for (int i = n-1; i >= 0; i--)
		{
			for (size_t j = 0; j < i; j++)
			{
				if (v[j].length() > v[j + 1].length())
					swap(v[j], v[j+1]);
			}
		}

		for (size_t i = 0; i < n; i++)
			cout << v[i] << endl;
		
	}
	return 0;
}