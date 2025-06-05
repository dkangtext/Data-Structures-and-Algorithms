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

node *swapData(List &L, int x, int y)
{
    node *p = L.pHead;

    node *px = NULL;
    node *py = NULL;

    while (p != NULL)
    {
        if (p->info == x && px == NULL)
        {
            px = p;
        }
        if (p->info == y && py == NULL)
        {
            py = p;
        }
        p = p->next;
    }

    if (px == NULL || py == NULL)
    {
        return NULL;
    }

    int temp = px->info;
    px->info = py->info;
    py->info = temp;
    
    return px;
}

int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L); // Neu ds rong thi xuat "List is empty"
    cout<<endl;

    int x, y; cin>>x>>y;
    node *p = swapData(L,x,y);
    /* Tim 2 node chua x va y,
    Hoan vi gia tri cua 2 node do,
    nghia la: Lien ket giua cac node khong thay doi, node ban dau chua x se doi lai la chua y
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout<<"Updated List after swapping "<<x<<" and "<<y<<": "<<endl;
    outputList(L);
    cout<<endl;

    /* Kiem tra xem co that su hoan vi info cua 2 node khong
    Neu hoan vi info thi node chua x ban dau se doi lai chua y*/

    if(p) // co hoan vi
    {
        cout<<"At the address of "<<x<< ": ";
        cout<<p->info;
    }
    else cout<<"Can not swap";
    return 0;
}
