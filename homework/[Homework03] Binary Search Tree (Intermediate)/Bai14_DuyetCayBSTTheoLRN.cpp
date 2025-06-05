/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
LRN
###End banned keyword*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node
{
    int info;
    node *left, *right;
};
typedef node *Tree;

node *getNode(int x)
{
    node *p = new node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void insertTree(Tree &T, int x)
{
    if (!T)
        T = getNode(x);
    else
    {
        if (T->info == x)
            return;
        if (x < T->info)
            insertTree(T->left, x);
        else
            insertTree(T->right, x);
    }
}

void inputTree(Tree &T)
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertTree(T, x);
    }
}

void LRN(Tree T)
{
    stack<node *> s;
    stack<node *> s2;
    node *cur = T;

    while (cur != NULL || s.empty() == false)
    {
        while (cur != NULL)
        {
            s.push(cur);
            s2.push(cur);
            cur = cur->right;
        }
        cur = s.top();
        s.pop();
        cur = cur->left;
    }
    
    while (s2.empty() == false)
    {
        cout << s2.top()->info << " ";
        s2.pop();
    }
}

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "\nLRN: ";
    LRN(T);
    return 0;
}
