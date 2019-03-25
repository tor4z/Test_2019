#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

bool isnum(char c)
{
	if (c >= '0' && c <= '9')return true;
	return false;
}

void parse_e(string str, int cof[3])
{
	string s = "";
	int si = 1, res;

	// cout << str << endl;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '+')si = 1;
		if (str[i] == '-')si = -1;
		if (isnum(str[i]))
		{
			s += str[i];
		}
		else
		{
			// cout << "s" << s << endl;
			res = (s == "" ? 1 : stoi(s))*si;
			if (str[i] == 'x')
			{
				if (i + 1 < str.length() && str[i + 1] == '^')
				{
					cof[2] += res;
					i += 2;
				}
				else
				{
					cof[1] += res;
				}
			}
			s = "";
		}
	}
	//cout << "s:" << s << endl;
	cof[0] = (s == "" ? 0 : stoi(s))*si;
	// cout << cof[2] << " " << cof[1] << " " << cof[0] << endl;
}

void parser(string str, int cof[2][3])
{
	int eq = str.find('=');
	string L = str.substr(0, eq);
	string R = str.substr(eq + 1);
	parse_e(L, cof[0]);
	parse_e(R, cof[1]);
}


int p71()
{
	string str;
	int cof[2][3], COF[3], judge;
	while (cin >> str)
	{
		memset(cof, 0, 2 * 3 * sizeof(int));
		parser(str, cof);
		COF[0] = cof[0][0] - cof[1][0];
		COF[1] = cof[0][1] - cof[1][1];
		COF[2] = cof[0][2] - cof[1][2];

		judge = (pow(COF[1], 2) - 4 * COF[2] * COF[0]);

		if (judge < 0)
		{
			cout << "No Solution" << endl;
			continue;
		}
		else if (judge == 0)
		{
			printf("%.2f\n", (float)(-1*COF[1])/(float)(2*COF[2]));
		}
		else
		{
			float f1, f2;
			f1 = (float)(-1 * COF[1] - sqrt(judge)) / (float)(2 * COF[2]);
			f2 = (float)(-1 * COF[1] + sqrt(judge)) / (float)(2 * COF[2]);
			if (f2 < f1)swap(f1, f2);
			printf("%.2f %.2f\n", f1, f2);
		}
	}
	return 0;
}