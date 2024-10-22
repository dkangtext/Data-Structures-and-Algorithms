/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
###End banned keyword*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

struct List
{
    Node *head, *tail;
};

void list_initializing(List &l)
{
    l.head = l.tail = NULL;
}

// ###INSERT CODE HERE -

void add_tail(List &l, int x)
{
    Node *p = new Node;
    p->val = x;
    p->next = NULL;
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void copy(List l, List &l2)
{
    Node *p = l.head;
    while (p != NULL)
    {
        add_tail(l2, p->val);
        p = p->next;
    }
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    List l;
    list_initializing(l);
    // Read list
    int x;
    do
    {
        cin >> x;
        add_tail(l, x);
    } while (x != 0);

    List l2;
    list_initializing(l2);
    copy(l, l2);

    Node *p = l.head, *q = l2.head;
    while (p != NULL)
    {
        if (p == q || p->val != q->val)
            cout << "WRONG";
        cout << p->val << endl;
        p = p->next;
        q = q->next;
    }

    return 0;
}
