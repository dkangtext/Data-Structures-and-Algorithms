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

void deleteNode(Tree &T, int x)
{
    if (T)
    {
        if (T->Data == x)
        {
            if (T->Left == NULL)
            {
                Node *p = T;
                T = T->Right;
                delete p;
            }
            else if (T->Right == NULL)
            {
                Node *p = T;
                T = T->Left;
                delete p;
            }
            else
            {
                Node *p = T->Right;
                while (p->Left)
                    p = p->Left;
                T->Data = p->Data;
                deleteNode(T->Right, p->Data);
            }
        }
        else if (x < T->Data)
            deleteNode(T->Left, x);
        else
            deleteNode(T->Right, x);
    }
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
    int x; cout<<"\nEnter the element you want to delete: ";cin>>x;
    deleteNode(T,x);
    cout<<"\nNLR: "; NLR(T);

	return 0;
}
