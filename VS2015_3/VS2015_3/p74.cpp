#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;


static enum State
{
	Start,
	End,
	Sp,
	Word
};


typedef struct dir
{
	string curr;
	string p;
	int l;
	bool flag;
	bool operator < (struct dir a)
	{
		return curr < a.curr;
	}
} dir;


static vector<dir>v;
static int n;

void print_dir(string p, int L)
{
	dir t;
	n = v.size();
	for (int i = 0; i < n; i++)
	{
		t = v[i];
		if (t.flag && t.p == p && t.l==L)
		{
			for (int i = 0; i < L; i++)
				cout << " ";

			cout << t.curr << "(" << t.l << ")"<< endl;
			for (int j = 0; j < n; j++)
				if (v[j].curr == t.curr && v[j].l==L)
					v[j].flag = false;

			print_dir(t.curr, L+1);
		}
	}
}

int p74()
{
	int n;
	string str, p;
	dir tmp;
	int m, L;

	while (cin >> n)
	{
		if (n == 0)break;
		v.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			enum State STATE;

			STATE = Start;
			L = 0;
			m = str.length();

			for (int i = 0; i <= m; i++)
			{
				char c = str[i];
				if (isalpha(c))
				{
					string s = "";
					while (i <= m && isalpha(str[i]))
					{
						s += str[i];
						i++;
					}
					i--;
					if (STATE == Start)
						tmp = { s, "", L, true};
					else
						tmp = { s, p, L, true };
					p = s;
					v.push_back(tmp);
					STATE = Word;
				}
				else if (c == '\\')
				{
					L++;
					STATE = Sp;
				}
				else if (c = '\0')
				{
					STATE = End;
				}
			}
		}
		
		sort(v.begin(), v.end());

		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i].curr << "-" << v[i].l << endl;
		}

		print_dir("", 0);
	}
	return 0;
}