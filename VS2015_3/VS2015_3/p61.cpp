#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;


int sadd(string A, string B, string &L, int c, int flag)
{
	int a, b, n, m, t, j;
	string S;
	a = A.length();
	b = B.length();
	L = a > b ? A : B;
	S = a > b ? B : A;
	n = min(a, b);
	m = max(a, b);
	reverse(L.begin(), L.end());
	reverse(S.begin(), S.end());
	for (size_t i = 0; i < m; i++)
	{
		if (flag == 0 && i<m-n)continue;
		if (flag == 0)
			j=i-(m-n);
		else
			j = i;
		if (i < n || flag==0)
		{
			t = (c + L[i] + S[j] - 2 * '0') / 10;
			L[i] = (c + L[i] + S[j] - 2 * '0') % 10 + '0';
			c = t;
		}
		else if(flag==1)
		{
			if (c == 0)break;
			if (i < m)
			{
				t = (c + L[i] - '0') / 10;
				L[i] = (c + L[i] - '0') % 10 + '0';
				c = t;
			}
		}
	}
	reverse(L.begin(), L.end());
	return c;
}


int p61()
{
	string s1, s2;
	string S1[2], S2[2], ans[2];
	int c;
	while (cin >> s1 >> s2)
	{
		S1[0] = string(s1, 0, s1.find('.'));
		S1[1] = string(s1, s1.find('.')+1, s1.length());
		S2[0] = string(s2, 0, s2.find('.'));
		S2[1] = string(s2, s2.find('.') + 1, s2.length());
		
		c = sadd(S1[1], S2[1], ans[1], 0, 0);
		c = sadd(S1[0], S2[0], ans[0], c, 1);
		if (c > 0)printf("%c", c+'0');
		cout << ans[0];
		cout << ".";
		cout << ans[1];
	}
	return 0;
}