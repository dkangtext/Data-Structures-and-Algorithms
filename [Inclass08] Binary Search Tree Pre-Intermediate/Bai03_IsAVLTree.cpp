/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

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

int depthOfTree(Tree T)
{
    if (T == NULL)
        return -1;
    int leftDepth = depthOfTree(T->left);
    int rightDepth = depthOfTree(T->right);
    return max(leftDepth, rightDepth) + 1;
}

int isAVL (Tree T)
{
    if (T == NULL)
        return 1;
        
    int leftDepth = depthOfTree(T->left);
    int rightDepth = depthOfTree(T->right);

    if (abs(leftDepth - rightDepth) > 1)
        return 0;
    return isAVL(T->left) && isAVL(T->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<isAVL(T);
	return 0;
}
