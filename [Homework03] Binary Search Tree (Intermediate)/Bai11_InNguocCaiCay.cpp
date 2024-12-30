#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
typedef Node *Tree;

Node *getNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(Tree &T, int x)
{
    if (T != NULL)
    {
        if (x < T->data)
        {
            insertNode(T->left, x);
        }
        else if (x > T->data)
        {
            insertNode(T->right, x);
        }
    }
    else
    {
        T = getNode(x);
    }
}

int heightOfTree(Tree T)
{
    if (T == NULL)
    {
        return 0;
    }

    int leftHeight = heightOfTree(T->left);
    int rightHeight = heightOfTree(T->right);

    return max(leftHeight, rightHeight) + 1;
}

void printTreeWithHeight(Tree T, int height, int currentHeight)
{
    if (T == NULL)
    {
        return;
    }

    if (currentHeight == height)
    {
        cout << T->data << " ";
        return;
    }

    printTreeWithHeight(T->right, height, currentHeight + 1);
    printTreeWithHeight(T->left, height, currentHeight + 1);
}

void printTree(Tree T)
{
    int height = heightOfTree(T);

    for (int i = height; i >= 1; i--)
    {
        printTreeWithHeight(T, i, 1);
    }
}

void inputTree(Tree &T)
{
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insertNode(T, x);
    }
}

int main()
{
    Tree T = NULL;
    inputTree(T);
    printTree(T);
    return 0;
}