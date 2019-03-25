#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1000000

using namespace std;

int arr1[MAX], arr2[MAX];

int p81()
{
	int n, m;
	int a,b,c,d;
	vector<int> v;

	while(cin>>n>>m)
	{
		for(long i=0; i<n; i++)
			cin>>arr1[i];
		for(long i=0; i<m; i++)
			cin>>arr2[i];
		cin>>a>>b>>c>>d;

		for(long i=a-1; i<b; i++)
			v.push_back(arr1[i]);
		for(long i=c-1; i<d; i++)
			v.push_back(arr2[i]);

		if(v.size()%2==0)cout << v[v.size()/2-1] << endl;
		else cout << v[v.size()/2] << endl;
	}

	return 0;
}

