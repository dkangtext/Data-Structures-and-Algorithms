/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -

typedef struct node
{
    int info;
    node *next;
};

struct List
{
    node *pHead;
    node *pTail;
};

node *getNode(int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void Init (List &L)
{
    L.pHead = L.pTail = NULL;
}

void addHead (List &L, int x)
{
    node *p = getNode(x);
    if (L.pHead == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        p->next = L.pHead;
        L.pHead = p;
    }
}

void addTail (List &L, int x)
{
    node *p = getNode(x);
    if (L.pTail == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        L.pTail->next = p;
        L.pTail = p;
    }
}

void addAfter (List &L, int x, int y)
{
    node *p = L.pHead;
    while (p)
    {
        if (p->info == x)
        {
            node *newNode = getNode(y);
            newNode->next = p->next;
            p->next = newNode;

            if (p == L.pTail)
            {
                L.pTail = newNode;
            }
            return;
        }
        p = p->next;
    }
    addHead(L, y);
}

void deleteHead (List &L)
{
    if (L.pHead == NULL)
        return;

    node *p = L.pHead;

     if (L.pHead == L.pTail)
    {
        L.pHead = L.pTail = NULL;
    }
    else
    {
        L.pHead = L.pHead->next;
    }

    delete p;
}

void printList (List L)
{
    if (L.pHead == NULL)
    {
        cout << "blank";
        return;
    }

    node *p = L.pHead;
    while (p)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

void deleteNode (List &L, int x)
{
    if (L.pHead == NULL)
        return;

    if (L.pHead->info == x)
    {
        deleteHead(L);
        return;
    }

    node *p = L.pHead;
    while (p->next != NULL && p->next->info != x)
    {
        p = p->next;
    }

    if (p->next != NULL)
    {
        node *temp = p->next;
        p->next = p->next->next;

        if (temp == L.pTail)
        {
            L.pTail = p;
        }

        delete temp;
    }
}

int main()
{
    int x, y, z;

    List L;
    Init(L);

    while (1)
    {
        cin >> x;

        if (x == 6) break;

        switch (x)
        {
        case 0:
            {
                cin >> y;
                addHead(L, y);
                break;
            }
        case 1:
            {
                cin >> y;
                addTail(L, y);
                break;
            }
        case 2:
            {
                cin >> x >> y;
                addAfter(L, x, y);
                break;
            }

        case 3:
            {
                cin >> y;
                deleteNode(L, y);
                break;
            }

        case 5:
            {
                deleteHead(L);
                break;
            }
        }
    }
    printList(L);

    return 0;
}
