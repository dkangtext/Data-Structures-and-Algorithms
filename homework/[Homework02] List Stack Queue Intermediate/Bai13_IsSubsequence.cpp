/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
new
delete
using
###End banned keyword*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    int val;
    Node *next;
};

struct List
{
    Node *head, *tail;
    int x;
};

void list_initializing(List &l)
{
    l.head = l.tail = NULL;
}
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

void xuat(List &l)
{
    for (Node *p = l.head; p != NULL; p = p->next)
    {
        cout << p->val << " ";
    }
    cout << endl;
}

// ###INSERT CODE HERE -

int is_subsequence(List l1, List l2)
{
    Node *p1 = l1.head;
    Node *p2 = l2.head;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->val == p2->val)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        else
        {
            p2 = p2->next;
        }
    }
    if (p1 == NULL)
        return true;
    return false;
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List lists[2];

    for (int i = 0; i < 2; i++)
    {
        list_initializing(lists[i]);
        int x;
        do
        {
            cin >> x;
            if (x != -1)
                add_tail(lists[i], x);
            else
                break;
        } while (true);
    }

    if (is_subsequence(lists[0], lists[1]))
        cout << "TRUE";
    else
        cout << "FALSE";

    return 0;
}
