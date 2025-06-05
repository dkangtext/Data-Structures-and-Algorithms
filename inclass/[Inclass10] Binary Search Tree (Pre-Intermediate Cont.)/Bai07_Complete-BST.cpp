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

void LNR(Tree T)
{
    if (T)
    {
        LNR(T->Left);
        cout << T->Data << " ";
        LNR(T->Right);
    }
}

int height(Tree T)
{
    if (T == NULL)
    {
        return 0;
    }
    return 1 + max(height(T->Left), height(T->Right));
}

bool isCompleteBST(Tree T, int level, int height)
{
    if (T->Left == NULL && T->Right == NULL)
    {
        return level == height; 
    }
    if (T->Left == NULL || T->Right == NULL)
    {
        return false; 
    }
    return isCompleteBST(T->Left, level + 1, height) && isCompleteBST(T->Right, level + 1, height);
}

int isCompleteBinaryTree(Tree T)
{
    int h = height(T);
    return isCompleteBST(T, 1, h) ? 1 : 0;
}

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "LNR: ";
    LNR(T);
    int i = isCompleteBinaryTree(T);
    if (i == 0)
        cout << "\nThe tree is not a Complete Binary Tree";
    else
        cout << "\nThe tree is a Complete Binary Tree";
    return 0;
}
