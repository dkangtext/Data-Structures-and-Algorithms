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
    }
    else
    {
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
    }
}

void moveLastToFront(List &L)
{
    if (L.pHead == NULL || L.pHead == L.pTail)
    {
        return;
    }

    node *p = L.pHead;
    while (p->next != L.pTail)
    {
        p = p->next;
    }

    p->next = NULL;
    L.pTail->next = L.pHead;
    L.pHead = L.pTail;
    L.pTail = p;
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

    moveLastToFront(L); //di chuyen node cuoi ve dau danh sach
    cout<<"Updated List after moving the last element to front of L: "<<endl;
    outputList(L);
    return 0;
}
