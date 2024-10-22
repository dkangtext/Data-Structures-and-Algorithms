/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -

struct node
{
    int info;
    node *next;
}; 

struct List
{
    node *pHead;
    node *pTail;
};

void Init(List &L)
{
    L.pHead = L.pTail = NULL;
}

node *getnode(int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void inputList(List &L, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        node *p = getnode(x);
        if (L.pHead == NULL)
        {
            L.pHead = L.pTail = p;
        }
        else
        {
            L.pTail->next = p;
            L.pTail = p;
        }
    }
}

void outputList(List L)
{
    node *p = L.pHead;
    if (p == NULL)
    {
        cout << "List is empty";
        return;
    }
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

void concate(List &L1, List L2)
{
    if (L1.pHead == NULL)
    {
        L1 = L2;
        return;
    }
    L1.pTail->next = L2.pHead;
    L1.pTail = L2.pTail;
}

int main()
{
    List L1, L2;
    Init(L1);Init(L2);

    int n; cin>>n;
    inputList(L1,n);
    cout<<"Created 1st List: "<<endl;
    outputList(L1);
    cout<<endl;

    cin>>n;
    inputList(L2,n);
    cout<<"Created 2nd List: "<<endl;
    outputList(L2);
    cout<<endl;

    concate(L1,L2); // Noi L2 vao L1
    cout<<"Updated L1: "<<endl;
    outputList(L1);

    return 0;
}
