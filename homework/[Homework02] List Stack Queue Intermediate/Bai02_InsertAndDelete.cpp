/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

void initList(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}

Node *getNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void addHead(List &L, int x)
{
    Node *p = getNode(x);
    if (L.head == NULL)
    {
        L.head = p;
        L.tail = p;
    }
    else
    {
        p->next = L.head;
        L.head = p;
    }
}

void addTail(List &L, int x)
{
    Node *p = getNode(x);
    if (L.head == NULL)
    {
        L.head = p;
        L.tail = p;
    }
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}

void deleteHead(List &L)
{
    if (L.head == NULL)
    {
        return;
    }
    Node *p = L.head;
    L.head = L.head->next;
    delete p;
}

void deleteTail(List &L)
{
    if (L.head == NULL)
    {
        return;
    }
    if (L.head == L.tail)
    {
        delete L.head;
        L.head = NULL;
        L.tail = NULL;
        return;
    }
    Node *p = L.head;
    while (p->next != L.tail)
    {
        p = p->next;
    }
    delete L.tail;
    L.tail = p;
    L.tail->next = NULL;
}

void inputList(List &L, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        addTail(L, x);
    }
}

void outputList(List L)
{
    Node *p = L.head;
    if (p == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    List L;
    initList(L);

    char x, y;
    int z, n;
    cin >> n;

    while (n)
    {
        cin >> x;
        switch (x)
        {
        case '+':
            cin >> y >> z;
            if (y == 'H')
            {
                addHead(L, z);
            }
            else
            {
                addTail(L, z);
            }
            break;
        case '-':
            cin >> y >> z;
            if (y == 'H')
            {
                deleteHead(L);
            }
            else
            {
                deleteTail(L);
            }
            break;
        }
        n--;
    }
    outputList(L);
    return 0;
}