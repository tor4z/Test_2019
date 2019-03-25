#include <iostream>
#include <vector>

#define MAX 1000

using namespace std;

int p84()
{
	int N, M, i;
	int a,b;
	int arr[MAX];

	while(cin>>N)
	{
		if(N==0)break;
		cin>>M;
		for(i=0; i<MAX; i++)
			arr[i]=0;

		for(i=0; i<M; i++)
		{
			cin >> a>>b;
			arr[a]++;
			arr[b]++;
		}

		for(i=0; i<=N; i++)
			if(arr[i]%2!=0)break;

		if(i<=N) cout << 0<<endl;
		else cout << 1<<endl;
	}
	return 0;
}