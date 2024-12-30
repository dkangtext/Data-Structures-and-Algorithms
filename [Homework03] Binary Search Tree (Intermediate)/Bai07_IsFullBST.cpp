/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

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

void LNR(Tree T)
{
	if (T)
	{
		LNR(T->pLeft);
		cout << T->info << " ";
		LNR(T->pRight);
	}
}

int isFullBinaryTree(Tree T)
{
	if (T == NULL)
		return 1;

	if (T->pLeft == NULL && T->pRight == NULL)
		return 1;
	
	if ((T->pLeft) && (T->pRight))
		return (isFullBinaryTree(T->pLeft) && isFullBinaryTree(T->pRight));
	
	return 0;
}


int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isFullBinaryTree (T);
	if(i==0) cout<<"\nThe tree is not a Full Binary Tree";
    else cout<<"\nThe tree is a Full Binary Tree";
	return 0;
}

