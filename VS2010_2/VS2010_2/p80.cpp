#include <iostream>
#include <string>
#include <cmath>

using namespace std;

static int y_1, m_1, d_1, y_2, m_2, d_2;


bool isleap(int y)
{
	if(y%100==0 && y%400==0)return true;
	if(y%100!=0 && y%4==0)return true;
	return false;
}

int dayinmonth(int y, int m)
{
	int d;
	if(m==2)
	{
		if(isleap(y)) d = 29;
		else d = 28;
	}
	else
	{
		switch(m)
		{
		case 1:
			d=31;
			break;
		case 3:
			d=31;
			break;
		case 4:
			d=30;
			break;
		case 5:
			d=31;
			break;
		case 6:
			d=30;
			break;
		case 7:
			d=31;
			break;
		case 8:
			d=31;
			break;
		case 9:
			d=30;
			break;
		case 10:
			d=31;
			break;
		case 11:
			d=30;
			break;
		case 12:
			d=31;
			break;
		}
	}
	return d;
}


int dayinyear(int y)
{
	if(isleap(y))return 366;
	else return 365;
}


int solve()
{
	int ans;
	if(y_1==y_2)
	{
		if(m_1==m_2)
		{
			ans = abs(d_2-d_1)+1;
		}
		else
		{
			ans = dayinmonth(y_1, m_1)-d_1+1;
			for(int m = m_1 +1; m<m_2; m++)
				ans += dayinmonth(y_1, m);
			ans += d_2;
		}
	}
	else
	{
			ans = dayinmonth(y_1, m_1)-d_1+1;
			for(int m = m_1 +1; m<=12; m++)
				ans += dayinmonth(y_1, m);
			for(int y = y_1+1; y<y_2; y++)
				ans += dayinyear(y);
			for(int m = 1; m<m_2; m++)
				ans += dayinmonth(y_2, m);
			ans += d_2;
	}
	return ans;
}


int p80()
{
	string str1, str2;

	while(cin >> str1 >> str2)
	{
		y_1 = stoi(str1.substr(0, 4));
		m_1 = stoi(str1.substr(4, 2));
		d_1 = stoi(str1.substr(6, 2));

		y_2 = stoi(str2.substr(0, 4));
		m_2 = stoi(str2.substr(4, 2));
		d_2 = stoi(str2.substr(6, 2));

		cout << solve() << endl;
	}

	return 0;
}