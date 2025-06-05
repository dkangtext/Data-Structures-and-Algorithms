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

int countNodes(Tree &T)
{
    if (T == NULL)
        return 0;
    return 1 + countNodes(T->Left) + countNodes(T->Right);
}

int countLeafs(Tree &T)
{
    if (T == NULL)
        return 0;
    if (T->Left == NULL && T->Right == NULL)
        return 1;
    return countLeafs(T->Left) + countLeafs(T->Right);
}

bool check = true;

int countInternalNodes(Tree &T)
{
    if (check)
    {
        check = false;
        return 0 + countInternalNodes(T->Left) + countInternalNodes(T->Right);
    }
    if (T == NULL || (T->Left == NULL && T->Right == NULL))
        return 0;
    return 1 + countInternalNodes(T->Left) + countInternalNodes(T->Right);
}

int countOneChild(Tree &T)
{
    if (T == NULL)
        return 0;
    if (T->Left == NULL && T->Right != NULL)
        return 1 + countOneChild(T->Right);
    if (T->Left != NULL && T->Right == NULL)
        return 1 + countOneChild(T->Left);
    return countOneChild(T->Left) + countOneChild(T->Right);
}

int countTwoChildren(Tree &T)
{
    if (T == NULL)
        return 0;
    if (T->Left != NULL && T->Right != NULL)
        return 1 + countTwoChildren(T->Left) + countTwoChildren(T->Right);
    return countTwoChildren(T->Left) + countTwoChildren(T->Right);
}

int countLess(Tree &T, int x)
{
    if (T == NULL)
        return 0;
    if (T->Data < x)
        return 1 + countLess(T->Left, x) + countLess(T->Right, x);
    return countLess(T->Left, x) + countLess(T->Right, x);
}

int countBetweenValues(Tree &T, int x, int y)
{
    if (T == NULL)
        return 0;
    if (T->Data > x && T->Data < y)
        return 1 + countBetweenValues(T->Left, x, y) + countBetweenValues(T->Right, x, y);
    return countBetweenValues(T->Left, x, y) + countBetweenValues(T->Right, x, y);
}

int main()
{
    Tree T = NULL;
    inputTree(T);

    cout << "Number of nodes: " << countNodes(T) << endl;
    cout << "Number of leaf nodes: " << countLeafs(T) << endl;
    cout << "Number of internal nodes: " << countInternalNodes(T) << endl;
    cout << "Number of nodes with one child: " << countOneChild(T) << endl;
    cout << "Number of nodes with two children: " << countTwoChildren(T) << endl;

    int x;
    cout << "Enter x: ";
    cin >> x;
    cout << "\nNumber of nodes less than " << x << ": " << countLess(T, x) << endl;
    int y;
    cout << "Enter x,y: ";
    cin >> x >> y;
    cout << "\nNumber of nodes greater than " << x << " and less than " << y << ": " << countBetweenValues(T, x, y) << endl;

    return 0;
}
