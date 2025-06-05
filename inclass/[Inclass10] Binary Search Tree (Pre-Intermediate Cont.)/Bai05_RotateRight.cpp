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
    int Data;
    Node *Left;
    Node *Right;
};

typedef Node *Tree;

Node *getNode(int x)
{
    Node *p = new Node;
    p->Data = x;
    p->Left = p->Right = NULL;
    return p;
}

void insertTree(Node *&T, int x)
{
    if (T)
    {
        if (T->Data == x)
            return;
        if (x < T->Data)
            insertTree(T->Left, x);
        else
            insertTree(T->Right, x);
    }
    else
        T = getNode(x);
}

void inputTree(Tree &T)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertTree(T, x);
    }
}

void NLR(Tree T)
{
    if (T)
    {
        cout << T->Data << " ";
        NLR(T->Left);
        NLR(T->Right);
    }
}

Tree rotateRight(Tree T)
{
    if (T == NULL)
    {
        cout << "\nKhong the xoay vi cay rong";
        return T;
    }

    if (T->Left == NULL)
    {
        cout << "\nKhong the xoay phai vi khong co nut con ben trai";
        return T;
    }
    
    Node *p = T->Left;
    T->Left = p->Right;
    p->Right = T;
    return p;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	T=rotateRight(T);
	cout<<"\nUpdated Tree: \n";
	cout<<"NLR: "; NLR(T);
	return 0;
}



