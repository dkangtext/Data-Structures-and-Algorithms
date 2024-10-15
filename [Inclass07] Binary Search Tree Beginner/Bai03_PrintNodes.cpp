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

void listLeafs(Tree T)
{
    if (!T)
        return;

    if(T->left == NULL && T->right == NULL)
        cout << T->info << " ";
    listLeafs(T->left);
    listLeafs(T->right);
}

void listInternalNodes(Tree T, int x)
{
    if (x == 0)
    {
        if (T)
        {
            listInternalNodes(T->left, 1);
            listInternalNodes(T->right, 1);
        }
    }
    else
    {
        if (T)
        {  
            if((T->left != NULL || T->right != NULL))
                cout << T->info << " ";
            listInternalNodes(T->left, 1);
            listInternalNodes(T->right, 1);
        }
    }
}

void listNodesWithOneChild(Tree T)
{
    if (!T)
        return;

    if((T->left != NULL && T->right == NULL) || 
       (T->left == NULL && T->right != NULL))
        cout << T->info << " ";
    listNodesWithOneChild(T->left);
    listNodesWithOneChild(T->right);
}

void listNodesWithTwoChildren(Tree T)
{
    if (!T)
        return;

    if(T->left != NULL && T->right != NULL)
        cout << T->info << " ";
    listNodesWithTwoChildren(T->left);
    listNodesWithTwoChildren(T->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	cout<<"\nLeaf nodes: "; listLeafs(T);
	cout<<"\nInternal nodes: "; listInternalNodes(T,0); //co de san tham so thu 2 cho ai co nhu cau dung, SV khong dung tham so thu 2 nay cung khong sao
	cout<<"\nNodes with one child: "; listNodesWithOneChild(T);
	cout<<"\nNodes with two children: "; listNodesWithTwoChildren(T);

	return 0;
}
