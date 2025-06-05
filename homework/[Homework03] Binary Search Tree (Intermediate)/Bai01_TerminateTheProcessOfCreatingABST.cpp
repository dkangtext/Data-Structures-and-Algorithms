/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -

struct Node
{
	int data;
	Node *left;
	Node *right;
};

typedef Node *Tree;

Tree getNode(int x)
{
	Tree p = new Node;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

bool insertTree(Tree &T, int x)
{
	if (T)
	{
		if (T->data == x)
			return false;
		if (x < T->data)
			return insertTree(T->left, x);
		else
			return insertTree(T->right, x);
	}
	else
	{
		T = getNode(x);
		return true;
	}
}

void inputTree(Tree &T)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (!insertTree(T, x))
		{
			cout << "Bi trung gia tri, ket thuc qua trinh tao cay" << endl;
			break;;
		}
	}
}

void NLR(Tree T)
{
	if (T)
	{
		cout << T->data << " ";
		NLR(T->left);
		NLR(T->right);
	}
}

int main()
{
	Tree T = NULL;
	inputTree(T); // Khi bi trung gia tri thi ket thuc qua trinh tao cay, khong nhap tiep nua
	cout << "NLR: ";
	NLR(T);
	return 0;
}