#include <iostream>
#include <string>
#include <vector>

#define MAX 10

using namespace std;

typedef struct node
{
	int data;
	struct node *left, *right;
} Node;


static Node mem[9999];
static int loc;

static Node* new_node()
{
	return &(mem[loc++]);
}


static Node* create_tree(Node *p, char data)
{
	if (p == NULL)
	{
		p = new_node();
		p->left = NULL;
		p->right = NULL;
		p->data = data;
	}
	else
	{
		if (p->data < data)
			p->right = create_tree(p->right, data);
		else
			p->left = create_tree(p->left, data);
	}
	return p;
}


static bool pre_order(Node *T1, Node *T2)
{
	if (T1 == NULL && T2 == NULL)
		return true;
	if (T1 == NULL || T2 == NULL)
		return false;
	if (T1->data == T2->data)
		return pre_order(T1->left, T2->left) && pre_order(T1->right, T2->right);
	else
		return false;
}


int p90()
{
	int n;
	string str, tmp;
	vector<string>v;
	Node *T, *VT;
	while (cin >> n)
	{
		if (n == 0)break;
		cin >> str;
		loc = 0;
		for (size_t i = 0; i < n; i++)
		{
			cin >> tmp;
			v.push_back(tmp);
		}

		T = NULL;
		for (size_t i = 0; i < str.length(); i++)
			T = create_tree(T, str[i]);
		
		for (size_t i = 0; i < v.size(); i++)
		{
			tmp = v[i];
			VT = NULL;
			for (size_t j = 0; j < tmp.length(); j++)
			{
				VT = create_tree(VT, tmp[j]);
			}
			if (pre_order(T, VT))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		
	}
	return 0;
}