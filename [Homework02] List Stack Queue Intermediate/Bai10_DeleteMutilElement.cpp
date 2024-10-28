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

void InitList(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}

Node *GetNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void AddHead(List &L, int x)
{
    Node *p = GetNode(x);
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

void AddTail(List &L, int x)
{
    Node *p = GetNode(x);
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

void AddAfter(List &L, int a, int b)
{
    Node *p = L.head;

    while (p != NULL && p->data != a)
    {
        p = p->next;
    }

    if (p != NULL)
    {
        Node *newNode = GetNode(b);
        newNode->next = p->next;
        p->next = newNode;
        if (p == L.tail)
        {
            L.tail = newNode;
        }
    }
    else
    {
        AddHead(L, b);
    }
}

void DeleteHead(List &L)
{
    if (L.head == NULL)
    {
        return;
    }

    Node *p = L.head;
    L.head = L.head->next;
    delete p;

    if (L.head == NULL)
    {
        L.tail = NULL;
    }
}

void DeleteFirst(List &L, int n)
{
    if (L.head == NULL)
    {
        return;
    }

    if (L.head->data == n)
    {
        DeleteHead(L);
        return;
    }

    Node *p = L.head;
    while (p->next != NULL && p->next->data != n)
    {
        p = p->next;
    }

    if (p->next != NULL)
    {
        Node *temp = p->next;
        p->next = temp->next;
        if (temp == L.tail)
        {
            L.tail = p;
        }
        delete temp;
    }
}

void DeleteAll(List &L, int n)
{
    while (L.head != NULL && L.head->data == n)
    {
        DeleteHead(L);
    }

    Node *p = L.head;

    while (p != NULL && p->next != NULL)
    {
        if (p->next->data == n)
        {
            Node *temp = p->next;
            p->next = temp->next;
            if (temp == L.tail)
            {
                L.tail = p;
            }
            delete temp;
        }
        else
        {
            p = p->next;
        }
    }
}

void inputList(List &L, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        AddTail(L, x);
    }
}

void outputList(List L)
{
    Node *p = L.head;

    if (p == NULL)
    {
        cout << "blank" << endl;
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
    InitList(L);
    
    int n;

    while (cin >> n)
    {
        if (n == 0)
        {
            int x;
            cin >> x;
            AddHead(L, x);
        }
        else if (n == 1)
        {
            int x;
            cin >> x;
            AddTail(L, x);
        }
        else if (n == 2)
        {
            int a, b;
            cin >> a >> b;
            AddAfter(L, a, b);
        }
        else if (n == 3)
        {
            int x;
            cin >> x;
            DeleteFirst(L, x);
        }
        else if (n == 4)
        {
            int x;
            cin >> x;
            DeleteAll(L, x);
        }
        else if (n == 5)
        {
            DeleteHead(L);
        }
        else if (n == 6)
        {
            break;
        }
    }
    outputList(L);
    return 0;
}