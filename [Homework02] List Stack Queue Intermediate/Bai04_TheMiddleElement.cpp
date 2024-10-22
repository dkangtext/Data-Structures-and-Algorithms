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

node *getnode(int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void Init(List &L)
{
    L.pHead = L.pTail = NULL;
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
    while (p)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

node *findMiddle(List L)
{
    node *p = L.pHead;
    node *q = L.pHead;
    if (p == NULL)
        return NULL;
    while (q && q->next)
    {
        p = p->next;
        q = q->next->next;
    }
    return p;
}

int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    node *p=findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if(p)cout<<"The middle element is "<<p->info;

    return 0;
}
