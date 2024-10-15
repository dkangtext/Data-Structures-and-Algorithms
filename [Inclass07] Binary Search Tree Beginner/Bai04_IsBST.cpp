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

Node* getNode(int x)
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
        T = getNode(x);
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

void SetLeft()
{
    
}
int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break; // Neu khong phai L hoac R thi ket thuc viec tao cay
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c); // chen c vao ben trai b
        else if (a=='R') SetRight(Search(T,b),c); // chen c vao ben phai b
    }
	cout<<"\nLNR: "; LNR(T); cout<<endl;
    if(isBST(T)) cout<<"\Cay vua tao la cay BST";
    else cout<<"\Cay vua tao khong phai la cay BST";

	return 0;
}