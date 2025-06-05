/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};

typedef struct Node *Tree;

Node *getNode(int x);

void insertNode(Tree &T, int x);

void inputTree(Tree &T);

void NLR(Tree T);

int nodesWithLevel(Tree T, int k, int c);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "\nNLR: ";
    NLR(T);
    int k;
    cout << "\nEnter k: ";
    cin >> k;
    cout << nodesWithLevel(T, k, 0); // neu tham so thu 3 khong can dung thi trong ham khong can xu ly

    return 0;
}

// ###INSERT CODE HERE -

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

int nodesLevel(Tree T, int k, int c)
{
    if (T == NULL)
    {
        return 0;
    }

    if (c == k)
    {
        cout << T->info << " ";
        return 1;
    }
    
    return nodesLevel(T->pRight, k, c + 1) + nodesLevel(T->pLeft, k, c + 1);
}

int nodesWithLevel(Tree T, int k, int c)
{
    int count = 0;
    cout << "\nList of nodes with level " << k << " (R->L): ";
    count = nodesLevel(T, k, c);

    cout << "\nNumber of nodes with level " << k << ": ";
    return count;
}