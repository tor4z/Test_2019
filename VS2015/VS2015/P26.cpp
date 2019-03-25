#include <iostream>

#define MAX 201

using namespace std;


int p26()
{
	int N, k, M;
	int books[MAX];
	int *students;
	while (cin >> N >> M)
	{
		for (size_t i = 0; i < MAX; i++)
			books[i] = 0;
		students = (int*)malloc(N * sizeof(int));
		for (size_t i = 0; i < N; i++)
		{
			cin >> k;
			books[k]++;
			students[i] = k;
		}
		for (size_t i = 0; i < N; i++)
		{
			k = students[i];
			if (books[k]-1 <= 0)
				cout << "BeiJu" << endl;
			else
				cout << books[k]-1 << endl;
		}
	}
	return 0;
}