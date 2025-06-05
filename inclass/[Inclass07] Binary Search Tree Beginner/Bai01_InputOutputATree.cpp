#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct node
{
    int info;
    node *left, *right;
};

typedef node* Tree;

node* getnode(int x)
{
    node* p = new node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertTree(node* &T, int x)
{
    if (T)
    {
        if (T->info == x) return;
        if (x<T->info) 
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
        cout<< T->info << " ";
        NLR(T->left);
        NLR(T->right);
    }
}

void LNR(Tree T)
{
    if (T)
    {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
    }
}

void LRN(Tree T)
{
    if (T)
    {
        LRN(T->left);
        LRN(T->right);
        cout << T->info << " ";
    }
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	return 0;
}
