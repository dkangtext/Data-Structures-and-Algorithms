#include <iostream>
using namespace std;

struct node
{
    int info;
    node *left, *right;
};

typedef node *Tree;

node *getnode(int x)
{
    node *p = new node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertTree(node *&T, int x)
{
    if (T)
    {
        if (T->info == x)
            return;
        if (x < T->info)
            insertTree(T->left, x);
        else
            insertTree(T->right, x);
    }
    else
        T = getnode(x);
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
        cout << T->info << " ";
        NLR(T->left);
        NLR(T->right);
    }
}

void rotateLeft(Tree &T)
{
    if (T == NULL)
    {
        cout << "Khong the xoay vi cay rong" << endl;
        return;
    }

    if (T->right == NULL)
    {
        cout << "Khong the xoay trai vi khong co nut con ben phai" << endl;
        return;
    }
    
    node *p = T->right;
    T->right = p->left;
    p->left = T;
    T = p;
}

int main()
{
    Tree T = NULL;
    inputTree(T);

    cout << "NLR: ";
    NLR(T);
    cout << endl;

    rotateLeft(T);
    cout << "NLR: ";
    NLR(T);

    return 0;
}