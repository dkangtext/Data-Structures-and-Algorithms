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
	int info;
	Node *pLeft;
	Node *pRight;
};
typedef struct Node *Tree;

Node *getNode(int x)
{
	Node *p = new Node;
	p->info = x;
	p->pLeft = NULL;
	p->pRight = NULL;

	return p;
}

void insertNode(Tree &T, int x)
{
	if (T == NULL)
	{
		T = getNode(x);
	}
	else if (x < T->info)
	{
		insertNode(T->pLeft, x);
	}
	else if (x > T->info)
	{
		insertNode(T->pRight, x);
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
		insertNode(T, x);
	}
}

void NLR(Tree T)
{
	if (T)
	{
		cout << T->info << " ";
		NLR(T->pLeft);
		NLR(T->pRight);
	}
}

void findSecondLargest(Tree T, Tree &parent, Tree &largest)
{
	if (T == NULL)
		return;

	if (T->pRight != NULL)
	{
		parent = T;
		findSecondLargest(T->pRight, parent, largest);
	}
	else
	{
		largest = T;
	}
}

void secondLargest(Tree T)
{
	if (T == NULL || (T->pLeft == NULL && T->pRight == NULL))
		return;

	Tree parent = NULL, largest = NULL;
	findSecondLargest(T, parent, largest);

	if (largest->pLeft != NULL)
	{
		Tree secondLargest = largest->pLeft;
		while (secondLargest->pRight != NULL)
		{
			secondLargest = secondLargest->pRight;
		}
		cout << "2nd largest value is " << secondLargest->info << endl;
	}
	else if (parent != NULL)
	{
		cout << "2nd largest value is " << parent->info << endl;
	}
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	secondLargest(T);
	return 0;
}
