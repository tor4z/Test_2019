#include <iostream>
#include <string>

#define MAX 300

using namespace std;

static int R[MAX];

static int solve_relative(char a, char b)
{
	if (R[b] == a)
		return 1;

	else if (R[b] == 0)
		return -99999;
	else
		return solve_relative(a, R[b]) + 1;
}


int solve(char a, char b)
{
	int n;
	n = solve_relative(a, b);
	if (n > 0)return n;
	n = solve_relative(b, a);
	if (n > 0)return n*-1;
	return 0;
}

void show_relative(int n)
{
	// cout << n << endl;
	string str;
	if (n == 0)
	{
		cout << "-" << endl;
		return;
	}
	else if(n>0)
	{
		switch (n)
		{
		case 1:
			str = "child";
			break;
		case 2:
			str = "grandchild";
			break;
		default:
			n -= 2;
			while (n > 0)
			{
				str += "great-";
				n--;
			}
			str += "grandchild";
			break;
		}
	}
	else
	{
		n *= -1;
		switch (n)
		{
		case 1:
			str = "parent";
			break;
		case 2:
			str = "grandparent";
			break;
		default:
			n -= 2;
			while (n > 0)
			{
				str += "great-";
				n--;
			}
			str += "grandparent";
			break;
		}
	}
	cout << str << endl;
}

int p88()
{
	int n, m;
	char a, b, c;

	while (cin >> n >> m)
	{
		for (size_t i = 0; i < MAX; i++)
			R[i] = 0;

		for (size_t i = 0; i < n; i++)
		{
			cin >> a >> b >> c;
			R[b] = a;
			R[c] = a;
		}

		for (size_t i = 0; i < m; i++)
		{
			cin >> a >> b;
			show_relative(solve(a, b));
		}
	}
	return 0;
}