#include <iostream>
#include <string>
#include <queue>
#include <map>


using namespace std;


bool judge(string s)
{
	if (s.find("2012") == string::npos)
		return false;
	else
		return true;
}


string swap(string s, int i)
{
	char c;
	string s2 = s;
	c = s2[i];
	s2[i] = s2[i+1];
	s2[i+1] = c;
	return s2;
}


int bfs(string str)
{
	string s, s2;
	int n = str.size();
	int i;
	map<string, int> M;
	queue<string> Q;
	Q.push(str);
	M[str] = 0;
	if (judge(str)) return 0;

	while (!Q.empty())
	{
		s = Q.front();
		Q.pop();

		for (i = 0; i < n - 1; i++)
		{
			s2 = swap(s, i);
			if (M.find(s2) == M.end())
			{
				M[s2] = M[s] + 1;
				if (judge(s2)) return M[s2];
				else Q.push(s2);
			}
		}
	}
	return -1;
}


int p10()
{
	int n;
	string str;
	int ans;

	while (cin >> n)
	{
		cin >> str;
		ans = bfs(str);
		cout << ans << endl;
	}
	return 0;
}