#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

#define MAX 10000

using namespace std;


typedef struct loging
{
	string row;
	int year;
	int month;
	int day;
	int h;
	int m;
	int s;
	int ms;
	float duration;
} loging;


bool cmp(loging a, loging b)
{
	if (a.duration < b.duration) return true;
	else if (a.duration > b.duration) return false;
	else
	{
		if (a.year < b.year) return true;
		else if (a.year > b.year) return false;
		else
		{
			if (a.month < b.month) return true;
			else if (a.month > b.month) return false;
			else
			{
				if (a.day < b.day) return true;
				else if (a.day > b.day) return false;
				else
				{
					if (a.h < b.h) return true;
					else if (a.h > b.h) return false;
					else
					{
						if (a.m < b.m) return true;
						else if (a.m > b.m) return false;
						else
						{
							if (a.s < b.s) return true;
							else if (a.s > b.s) return false;
							else
							{
								if (a.ms < b.ms) return true;
								else return false;

							}
						}
					}
				}
			}
		}
	}
}


int p28()
{

	loging logs[MAX];
	char s[20];
	int n = 0;

	while (getline(cin, logs[n].row))
	{
		sscanf_s(logs[n].row.c_str(), "%s %d-%d-%d %d:%d:%d,%d %f", s, &(logs[n].year), &(logs[n].month),
			&(logs[n].day), &(logs[n].h), &(logs[n].m), &(logs[n].s), &(logs[n].ms), &(logs[n].duration));
		n++;
	}

	sort(logs, logs + n, cmp);
	for (int i = 0; i < n; i++)
		cout << logs[i].row << endl;
	return 0;
}