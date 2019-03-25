#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(string a, string b)
{
	int na, nb, n, i;
	na = a.length();
	nb = b.length();
	n = na<nb?na:nb;

	for(i=0; i<n; i++)
	{
		if(a[i]<b[i])
			return true;
		else if(a[i]>b[i])
			return false;
	}
	if(i==n)
		return na<nb;
}

int p83()
{
	string str;
	vector<string>v;
	int n;
	while(cin>>str)
	{
		n = str.length();
		for(int i=0; i<n;i++)
			v.push_back(str.substr(i));

		n = v.size();
		for(int i=n-1; i>=0; i--)
			for(int j=0; j<i; j++)
				if(cmp(v[j+1], v[j]))
				{
					str = v[j];
					v[j] = v[j+1];
					v[j+1]=str;
				}

		// sort(v.begin(), v.end(), cmp);
		for(int i=0; i<n; i++)
			cout << v[i] <<  endl;
	}
	return 0;
}