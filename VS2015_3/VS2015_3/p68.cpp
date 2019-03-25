#include <iostream>

using namespace std;


long f(int n)
{
	long ans = 1;
	while (n > 0)
	{
		ans *= n;
		n--;
	}
	return ans;
}


int p68()
{
	int a, b;
	char c;
	while (cin >> a)
	{
		cin >> c;
		switch (c)
		{
		case '+':
			cin >> b;
			cout << a + b << endl;
			break;
		case '-':
			cin >> b;
			cout << a - b << endl;
			break;
		case '*':
			cin >> b;
			cout << a * b << endl;
			break;
		case '/':
		case '%':
			cin >> b;
			if (b == 0)
			{
				cout << "error" << endl;
				break;
			}
			if (c == '/') cout << a / b << endl;
			else cout << a%b << endl;
			break;
		case '!':
			cout << f(a) << endl;
			break;
		default:
			cout << "error" << endl;
			break;
		}
	}
	return 0;
}