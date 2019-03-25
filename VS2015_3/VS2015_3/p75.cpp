#include <iostream>
#include <string>

#define MAX 500

using namespace std;


static int start = 0;
static int addsub = 1;
static int muldiv = 2;
static int number = 3;
static int End = 4;

static bool isnum(char c)
{
	if (c >= '0'&&c <= '9')
		return true;
	else
		return false;
}


int p75()
{
	double ans, arr[MAX], num;
	int k;
	char op;
	string str;
	while (scanf_s("%lf", &num) == 1)
	{
		k = 0;
		arr[k] = num;
		while (scanf_s("%c", &op) == 1 && op != '\n')
		{
			scanf_s("%lf", &num);
			switch (op)
			{
			case '+':arr[++k] = num; break;
			case '-':arr[++k] = num*-1; break;
			case '*':arr[k] *= num; break;
			case '/':arr[k] /= num; break;
			default:
				break;
			}
		}

		ans = 0;
		for (size_t i = 0; i <= k; i++)
		{
			ans += arr[i];
		}
		cout << ans << endl;
	}
	return 0;
}


int p75_2()
{
	string str;
	double tmp[MAX];
	int k, n;
	while (getline(cin, str))
	{
		n = str.length();
		double pre = 0;
		char pre_s;
		int state = start;
		k = 0;
		for (size_t i = 0; i <= n; i++)
		{
			char c = str[i];
			if (isnum(c))
			{
				string s;
				while (i <= n&&isnum(c))
				{
					s += c;
					c = str[++i];
				}
				i--;
				if (state != muldiv)
					pre = stof(s);
				else
				{
					if (pre_s == '*')
						pre *= stof(s);
					else
						pre /= stof(s);
				}
				state = number;
			}
			else if (c == '+' || c == '-')
			{
				tmp[k] = pre;
				k++;
				tmp[k] = c;
				k++;
				state = addsub;
			}
			else if (c == '*' || c == '/')
			{
				pre_s = c;
				state = muldiv;
			}
			else if (c == '\0')
			{
				tmp[k] = pre;
				state = End;
			}

		}

		double ans = 0;
		char sign;
		for (size_t i = 0; i <= k; i++)
		{
			if (i == 0)
				ans += tmp[i];
			else if (i % 2 != 0)
			{
				sign = (char)tmp[i];
			}
			else
			{
				if (sign == '+')
					ans += tmp[i];
				else
					ans -= tmp[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}