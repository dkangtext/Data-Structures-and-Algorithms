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
    int data;
    Node *left;
    Node *right;
};
typedef Node *Tree;

Node *getNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

void insertNode(Tree &T, int x)
{
    if (T == NULL)
    {
        T = getNode(x);
    }
    else if (x < T->data)
    {
        insertNode(T->left, x);
    }
    else
    {
        insertNode(T->right, x);
    }
}

int findFloor(Tree T, int x)
{
    int floor = 201; 
    while (T != NULL)
    {
        if (T->data == x)
        {
            return T->data; 
        }
        else if (T->data < x)
        {
            floor = T->data; 
            T = T->right;  
        }
        else
        {
            T = T->left; 
        }
    }
    return floor;
}

int main()
{
    int n, y;
    cin >> n; 
    Tree T = NULL;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        insertNode(T, x);
    }

    cin >> y; 

    int result = findFloor(T, y);
    cout << result << endl;

    return 0;
}
