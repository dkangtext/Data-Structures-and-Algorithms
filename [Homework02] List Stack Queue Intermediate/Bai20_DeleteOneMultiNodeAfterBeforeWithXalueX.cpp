/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

struct DNode
{
    int info;
    DNode *pNext, *pPrev;
};

struct DList
{
    DNode *pHead, *pTail;
};

// ###INSERT CODE HERE -

void init(DList &L)
{
    L.pHead = L.pTail = NULL;
}

DNode *createNode(int x)
{
    DNode *p = new DNode;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = p->pPrev = NULL;
    return p;
}

void addHead(DList &L, int x)
{
    DNode *p = createNode(x);
    if (L.pHead == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead->pPrev = p;
        L.pHead = p;
    }
}

void addTail(DList &L, int x)
{
    DNode *p = createNode(x);
    if (L.pHead == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        L.pTail->pNext = p;
        p->pPrev = L.pTail;
        L.pTail = p;
    }
}

void addAfter(DList &L, int x, int y)
{
    DNode *p = createNode(y);
    DNode *q = L.pHead;
    while (q != NULL && q->info != x)
        q = q->pNext;
    if (q == NULL)
        return;
    p->pNext = q->pNext;
    p->pPrev = q;
    if (q->pNext != NULL)
        q->pNext->pPrev = p;
    q->pNext = p;
    if (q == L.pTail)
        L.pTail = p;
}

void addBefore(DList &L, int x, int y)
{
    DNode *p = createNode(y);
    DNode *q = L.pHead;
    while (q != NULL && q->info != x)
        q = q->pNext;
    if (q == NULL)
        return;
    p->pNext = q;
    p->pPrev = q->pPrev;
    if (q->pPrev != NULL)
        q->pPrev->pNext = p;
    q->pPrev = p;
    if (q == L.pHead)
        L.pHead = p;
}

void addAfterMulti(DList &L, int x, int y)
{
    DNode *p = createNode(y);
    DNode *q = L.pHead;
    while (q != NULL)
    {
        if (q->info == x)
        {
            p->pNext = q->pNext;
            p->pPrev = q;
            if (q->pNext != NULL)
                q->pNext->pPrev = p;
            q->pNext = p;
            if (q == L.pTail)
                L.pTail = p;
        }
        q = q->pNext;
    }
}

void addBeforeMulti(DList &L, int x, int y)
{
    DNode *p = createNode(y);
    DNode *q = L.pHead;
    while (q != NULL)
    {
        if (q->info == x)
        {
            p->pNext = q;
            p->pPrev = q->pPrev;
            if (q->pPrev != NULL)
                q->pPrev->pNext = p;
            q->pPrev = p;
            if (q == L.pHead)
                L.pHead = p;
        }
        q = q->pNext;
    }
}

void removeHead(DList &L)
{
    if (L.pHead == NULL)
        return;
    DNode *p = L.pHead;
    L.pHead = L.pHead->pNext;
    if (L.pHead != NULL)
        L.pHead->pPrev = NULL;
    delete p;
    if (L.pHead == NULL)
        L.pTail = NULL;
}

void removeTail(DList &L)
{
    if (L.pHead == NULL)
        return;
    DNode *p = L.pTail;
    L.pTail = L.pTail->pPrev;
    if (L.pTail != NULL)
        L.pTail->pNext = NULL;
    delete p;
    if (L.pTail == NULL)
        L.pHead = NULL;
}

void removeNode(DList &L, int x)
{
    DNode *p = L.pHead;
    while (p != NULL && p->info != x)
        p = p->pNext;
    if (p == NULL)
        return;
    if (p == L.pHead)
        removeHead(L);
    else if (p == L.pTail)
        removeTail(L);
    else
    {
        p->pPrev->pNext = p->pNext;
        p->pNext->pPrev = p->pPrev;
        delete p;
    }
}

void removeMultiNodeS(DList &L, int x)
{
    DNode *p = L.pHead;
    while (p != NULL)
    {
        if (p->info == x)
        {
            if (p == L.pHead)
                removeHead(L);
            else if (p == L.pTail)
                removeTail(L);
            else
            {
                p->pPrev->pNext = p->pNext;
                p->pNext->pPrev = p->pPrev;
                delete p;
            }
        }
        p = p->pNext;
    }
}

void removeAfter(DList &L, int x)
{
    DNode *p = L.pHead;
    while (p != NULL && p->info != x)
        p = p->pNext;
    if (p == NULL || p == L.pTail)
        return;
    DNode *q = p->pNext;
    p->pNext = q->pNext;
    if (q->pNext != NULL)
        q->pNext->pPrev = p;
    delete q;
    if (p->pNext == NULL)
        L.pTail = p;
}

void removeBefore(DList &L, int x)
{
    DNode *p = L.pHead;
    while (p != NULL && p->info != x)
        p = p->pNext;
    if (p == NULL || p == L.pHead)
        return;
    DNode *q = p->pPrev;
    if (q == L.pHead)
        removeHead(L);
    else
    {
        q->pPrev->pNext = p;
        p->pPrev = q->pPrev;
        delete q;
    }
}

void removeMultiAfters(DList &L, int x)
{
    DNode *p = L.pHead;
    while (p != NULL)
    {
        if (p->info == x)
        {
            if (p == L.pTail)
                return;
            DNode *q = p->pNext;
            p->pNext = q->pNext;
            if (q->pNext != NULL)
                q->pNext->pPrev = p;
            delete q;
            if (p->pNext == NULL)
                L.pTail = p;
        }
        p = p->pNext;
    }
}

void removeMultiBefores(DList &L, int x)
{
    DNode *p = L.pHead;
    while (p != NULL)
    {
        if (p->info == x)
        {
            if (p == L.pHead)
                return;
            DNode *q = p->pPrev;
            if (q == L.pHead)
                removeHead(L);
            else
            {
                q->pPrev->pNext = p;
                p->pPrev = q->pPrev;
                delete q;
            }
        }
        p = p->pNext;
    }
}

void removeAll(DList &L)
{
    while (L.pHead != NULL)
        removeHead(L);
}

void createList(DList &L)
{
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        addTail(L, x);
    }
}

void printList(DList L)
{
    DNode *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

int main()
{
    DList L;
    init(L);
    int x, y, choice;
    char c;

    cout << "MENU:";
    cout << "\n1. Create a DList";
    cout << "\n2. Print the DList";
    cout << "\n3. Insert a value at the front";
    cout << "\n4. Insert a value at the end";
    cout << "\n5. Insert a value after a given value (only for the first value found)";
    cout << "\n6. Insert a value before a given value (only for the first value found)";
    cout << "\n7. Insert a value after a given value (for all the same values)";
    cout << "\n8. Insert a value before a given value (for all the same values)";
    cout << "\n9. Delete the first element";
    cout << "\n10. Delete the last element";
    cout << "\n11. Delete the first element containing a specific value";
    cout << "\n12. Delete all elements storing a particular value";
    cout << "\n13. Delete the element after a specific value (only for the first one found)";
    cout << "\n14. Delete the element before a specific value (only for the first one found)";
    cout << "\n15. Delete all elements after a specific value";
    cout << "\n16. Delete all elements before a specific value";
    cout << "\n17. Delete all elements";
    cout << "\n20. Exit" << endl;

    while (true)
    {
        cout << "\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout << "\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout << "\nEnter a number: ";
            cin >> x;
            addHead(L, x);
            break;
        case 4:
            cout << "\nEnter a number: ";
            cin >> x;
            addTail(L, x);
            break;
        case 5:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addAfter(L, x, y);
            break;
        case 6:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addBefore(L, x, y);
            break;
        case 7:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addAfterMulti(L, x, y);
            break;
        case 8:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addBeforeMulti(L, x, y);
            break;
        case 9:
            removeHead(L);
            break;
        case 10:
            removeTail(L);
            break;
        case 11:
            if (L.pHead == NULL)
            {
                cout << "\nList is empty. Can't delete";
                break;
            }
            cout << "\nEnter a number: ";
            cin >> x;
            removeNode(L, x);
            break;
        case 12:
            if (L.pHead == NULL)
            {
                cout << "\nList is empty. Can't delete";
                break;
            }
            cout << "\nEnter a number: ";
            cin >> x;
            removeMultiNodeS(L, x);
            break;
        case 13:
            if (L.pHead == NULL)
            {
                cout << "\nList is empty. Can't delete";
                break;
            }
            cout << "\nEnter a number: ";
            cin >> x;
            removeAfter(L, x);
            break;
        case 14:
            if (L.pHead == NULL)
            {
                cout << "\nList is empty. Can't delete";
                break;
            }
            cout << "\nEnter a number: ";
            cin >> x;
            removeBefore(L, x);
            break;
        case 15:
            if (L.pHead == NULL)
            {
                cout << "\nList is empty. Can't delete";
                break;
            }
            cout << "\nEnter a number: ";
            cin >> x;
            removeMultiAfters(L, x);
            break;
        case 16:
            if (L.pHead == NULL)
            {
                cout << "\nList is empty. Can't delete";
                break;
            }
            cout << "\nEnter a number: ";
            cin >> x;
            removeMultiBefores(L, x);
            break;
        case 17:
            if (L.pHead == NULL)
            {
                cout << "\nList is empty. Can't delete";
                break;
            }
            removeAll(L);
            break;
        case 20:
            cout << "\nGOOD BYE";
            return 0;
        }
    }

    return 0;
}
