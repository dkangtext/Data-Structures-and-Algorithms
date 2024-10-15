/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct Node
{
    int info;
    Node *left, *right;
};

typedef Node* Tree;

Node* getnode(int x)
{
    Node* p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertTree(Node* &T, int x)
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

void LNR(Tree T)
{
    if (T)
    {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
    }
}

Node * Search(Tree T, int x)
{
    if (!T) 
        return NULL;

    if (T->info == x) 
        return T;
    else if (x < T->info) 
        return Search(T->left,x);
    else 
        return Search(T->right,x);
}

int maxValue(Tree T)
{
    if (T->right == NULL) 
        return T->info;
    return 
        maxValue(T->right);
}

int minValue(Tree T)
{
    if (T->left == NULL) 
        return T->info;
    return 
        minValue(T->left);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T); cout<<endl;


    int x; cout<<"\nEnter the element you want to find: ";cin>>x;
    Node *p=Search(T,x);
    if (p) cout<< "Found";
    else cout<<"Not found";
    cout<<"\nMinimum value in BTS is "<<minValue(T);
    cout<<"\nMinimax value in BTS is "<<maxValue(T);


	return 0;
}
