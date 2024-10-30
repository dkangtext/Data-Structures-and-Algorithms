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

void deleteRoot(Tree &T, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (!T)
            return; 

        if (T->Left == NULL)
            T = T->Right;

        else if (T->Right == NULL)
            T = T->Left;
        
        else
        {
            Node *p = T->Right;
            Node *parent = T;

            while (p->Left)
            {
                parent = p;
                p = p->Left;
            }
            T->Data = p->Data; 

            if (parent->Left == p)
                parent->Left = p->Right;
            else
                parent->Right = p->Right;
            delete p;
        }
    }
}

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "NLR: ";
    NLR(T);
    int m;
    cout << "\nEnter m: ";
    cin >> m;
    deleteRoot(T, m);
    cout << "\nNLR: ";
    NLR(T);

    return 0;
}
