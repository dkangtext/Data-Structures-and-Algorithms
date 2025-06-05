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
    if (p != NULL)
    {
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
    }
    else
        cout << "List is empty";
}

node *findMax(List L)
{
    if (L.pHead == NULL)
    {
        cout << "List is empty";
        return NULL;
    }
    node *p = L.pHead;
    node *max = p;
    while (p != NULL)
    {
        if (p->info > max->info)
            max = p;
        p = p->next;
    }
    return max;
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

    cout << "\nThe maximum value: ";
    node *p = findMax(L);
    if (p)
        cout << p->info;

    return 0;
}
