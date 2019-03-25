#include <iostream>
#include <string>
#include <cstdio>

#define MAX 100

using namespace std;

static int start = 5;
static int oper = 0;
static int space = 1;
static int number = 2;

int p96()
{
	int idx;
	char c, op;
	string str;
	float arr[MAX], n, ans;
	int state;
	while (getline(cin, str))
	{
		for (size_t i = 0; i < MAX; i++)arr[i] = 0;
		idx = 0;
		state = start;
		for (size_t i = 0; i <= str.length(); i++)
		{
			c = str[i];
			if (i == 0 && c == '0')return 0;

			switch (c)
			{
			case '+':
			case '-':
			case '*':
			case '/':
				op = c;
				state = oper;
				break;
			case '\0':
			case ' ':
				state = space;
				break;
			default: // number
				n = 0;
				for (; i <= str.length(); i++)
				{
					if (str[i] <= '9' && str[i] >= '0')
					{
						n *= 10;
						n += str[i] - '0';
					}
					else
						break;
				}
				i--;
				if (state == start)
					arr[idx] = n;
				else
				{
					if (op == '+')
						arr[++idx] = n;
					else if (op == '-')
						arr[++idx] = -1 * n;
					else if (op == '*')
						arr[idx] *= n;
					else if (op == '/')
						arr[idx] /= n;
				}
				state = number;
				break;
			}
		}
		ans = 0;
		for (size_t i = 0; i <= idx; i++)
		{
			ans += arr[i];
		}
		printf("%.2f\n", ans);
	}
	return 0;
}