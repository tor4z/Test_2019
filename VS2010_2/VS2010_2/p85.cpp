#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct info
{
	int id;
	float s[5];
} Info;


typedef struct res
{
	int seq;
	int w;
} Res;

int w;

bool cmp(Info a, Info b)
{
	return a.s[w]>b.s[w];
}


int p85()
{
	vector<Info>v;
	vector<Res>result;
	vector<int>ns;
	vector<int>s;
	int N, M, tmp, m;
	float a,b,c;

	while(cin>>N>>M)
	{
		ns.clear();
		v.clear();
		result.clear();
		s.clear();

		for(int i=0; i<N; i++)
		{
			Info inf;
			inf.id=i;
			cin >> a >> b >> c;
			inf.s[1] = a;
			inf.s[2] = b;
			inf.s[3] = a/c;
			inf.s[4] = b/c;
			v.push_back(inf);
		}
		for(int i=0; i<M; i++)
		{
			cin >> tmp;
			ns.push_back(tmp);
		}

		result.resize(N);
		for(int j=0; j < result.size(); j++)
		{
			result[j].seq=N;
			result[j].w=0;
		}

		s.resize(N);
		for(int i=1; i <= 4; i++)
		{
			w=i;
			sort(v.begin(), v.end(), cmp);
			for(int j=0; j < v.size(); j++)
			{
				if(j>0)
				{
					if(v[j].s[w]==v[j-1].s[w])
					{
						m++;
						s[j]=s[j-1];
					}
					else
					{
						s[j]=s[j-1]+m;
						m=1;
					}
				}
				else
				{
					m=1;
					s[j] = j;
				}
			}

			for(int j=0; j < v.size(); j++)
			{
				if(result[v[j].id].seq > s[j])
				{
					result[v[j].id].seq=s[j];
					result[v[j].id].w=w;
				}
			}
		}

		for(int j=0; j < M; j++)
		{
			cout << result[ns[j]].seq+1 << ":" << result[j].w << endl;
		}
		cout << endl;

	}
	return 0;
}
