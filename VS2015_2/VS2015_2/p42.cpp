#include <iostream>

#define MAX 16

using namespace std;

void otob(int n, int bin[])
{
	for (size_t i = 0; i < MAX; i++)
		bin[i] = 0;
	int k=1;
	while (n>0)
	{
		bin[MAX-k] = n & 1;
		n >>= 1;
		k++;
	}
}

void shift(int bin[])
{
	int tmp = bin[0];
	for (size_t i = 0; i < MAX-1; i++)
		bin[i] = bin[i + 1];
	bin[MAX - 1] = tmp;
}

bool eq(int A[], int B[])
{
	for (size_t i = 0; i < MAX; i++)
		if (A[i] != B[i])
			return false;
	return true;
}

int p42()
{
	int A[MAX], B[MAX], a,b;
	bool flag;

	while (cin>> a>>b)
	{
		otob(a, A);
		otob(b, B);
		flag = false;
		for (size_t i = 0; i < MAX; i++)
			if (eq(A, B))
			{
				flag = true;
				break;
			}
			else
			{
				shift(A);
			}
		if (flag)
			cout << "YES";
		else
			cout << "NO";
		
	}
	return 0;
}