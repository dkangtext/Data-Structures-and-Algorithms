/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// ###INSERT CODE HERE -

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

node *findElementFromEnd(List L, int i)
{
    if (L.pHead == NULL)
    {
        cout << "List is empty";
        return NULL;
    }

    node *p = L.pHead;
    node *q = L.pHead;

    for (int j = 0; j < i; j++)
    {
        if (q == NULL)
        {
            cout << "The index is invalid";
            return NULL;
        }
        q = q->next;
    }

    while (q)
    {
        p = p->next;
        q = q->next;
    }
    return p;
}

int main()
{
    List L;
    Init(L);
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "\nEnter a sequence of " << n << " numbers: ";
    inputList(L, n);
    cout << "\nThe created Linked List: ";
    outputList(L);

    int i;
    cout << "\nEnter a number: ";
    cin >> i;
    cout << "\nThe element at index " << i << " (from the end of L): ";
    node *p = findElementFromEnd(L, i);
    if (p)
        cout << p->info;

    return 0;
}
