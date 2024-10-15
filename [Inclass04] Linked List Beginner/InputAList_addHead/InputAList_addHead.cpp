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
    int x, y;

    List L;
    L.pHead = NULL;
    L.pTail = NULL;

    while (1)
    {
        cin >> x;

        if (x == 3) break;

        cin >> y; // Thêm y vào đầu

        if (x == 0)
            addHead(L, y);

    }
    printList(L);
}
