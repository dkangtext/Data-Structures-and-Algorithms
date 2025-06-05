#include <iostream>

using namespace std;


struct Node
{
    int info;
    Node *next;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

Node *getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void addHead(List &L, int x)
{
    Node *p = getNode(x);
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

void addTail(List &L, int x)
{
    Node *p = getNode(x);
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

void addAfter(List &L, int x, int y)
{
    Node *p = L.pHead;
    while (p != NULL)
    {
        if (p->info == x)
        {
            Node *newNode = getNode(y);
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

void printList(List L)
{
    Node *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

int main()
{

    int x, y, z;

    List L;
    L.pHead = NULL;
    L.pTail = NULL;

    while (1)
    {
        cin >> x;

        if (x == -1) break;

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
        }
    }
    printList(L);
}
