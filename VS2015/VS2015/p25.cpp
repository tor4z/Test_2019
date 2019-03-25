#include <iostream>
#include <string>
#include <map>

#define MAX 1000

using namespace std;

typedef struct student
{
	string no;
	string name;
	string gender;
	int age;
} student;



int p25()
{
	int N, M, i;
	student students[MAX], tmp;
	map<string, student> dict;
	string no;

	while (cin >> N)
	{
		for (i = 0; i < N; i++)
		{
			cin >> students[i].no >> students[i].name >> students[i].gender >> students[i].age;
			dict[students[i].no] = students[i];
		}
		cin >> M;
		for (i = 0; i < M; i++)
		{
			cin >> no;
			if (dict.find(no) == dict.end())
				cout << "No Answer!" << endl;
			else
			{
				tmp = dict[no];
				cout << tmp.no << " " << tmp.name << " " << tmp.gender << " " << tmp.age << endl;
			}
		}
	}

	return 0;
}