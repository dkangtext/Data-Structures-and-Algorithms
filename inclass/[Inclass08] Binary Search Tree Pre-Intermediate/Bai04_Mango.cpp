#include <iostream>
#include <algorithm>
#include <memory>

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
        if (x < T->info)
            insertTree(T->left, x);
        else if (x > T->info)
            insertTree(T->right, x);
    }
    else
    {
        T = getnode(x);
    }
}

void inputTree(Tree &T, int n)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertTree(T, x);
    }
}

void traverseVisible(node *T, int visible[], int &index, int level, int &maxLevel)
{
    if (!T)
        return;

    if (level > maxLevel)
    {
        visible[index++] = T->info;
        maxLevel = level;
    }

    traverseVisible(T->right, visible, index, level + 1, maxLevel);
    traverseVisible(T->left, visible, index, level + 1, maxLevel);
}

int main()
{
    Tree T = NULL;
    int n;
    cin >> n;
    inputTree(T, n);

    unique_ptr<int[]> visible(new int[n]);
    int index = 0;
    int maxLevel = -1;

    traverseVisible(T, visible.get(), index, 0, maxLevel);

    sort(visible.get(), visible.get() + index);

    for (int i = 0; i < index; i++)
    {
        cout << visible[i] << " ";
    }
    cout << endl;

    return 0;
}
