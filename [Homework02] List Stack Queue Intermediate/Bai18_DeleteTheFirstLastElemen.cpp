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

void createList(DList &L)
{
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        DNode *p = new DNode;
        p->info = x;
        p->pNext = NULL;
        p->pPrev = NULL;
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
}

void printList(DList L)
{
    if (L.pHead == NULL)
    {
        cout << "List is empty";
        return;
    }

    for (DNode *p = L.pHead; p != NULL; p = p->pNext)
    {
        cout << p->info << " ";
    }
}

void addHead(DList &L, int x)
{
    DNode *p = new DNode;
    p->info = x;
    p->pNext = L.pHead;
    p->pPrev = NULL;
    if (L.pHead == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        L.pHead->pPrev = p;
        L.pHead = p;
    }
}

void addTail(DList &L, int x)
{
    DNode *p = new DNode;
    p->info = x;
    p->pNext = NULL;
    p->pPrev = L.pTail;
    if (L.pHead == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void addAfter(DList &L, int x, int y)
{
    for (DNode *q = L.pHead; q != NULL; q = q->pNext)
    {
        if (q->info == x)
        {
            DNode *p = new DNode;
            p->info = y;
            p->pNext = q->pNext;
            p->pPrev = q;
            if (q->pNext == NULL)
            {
                L.pTail = p;
            }
            else
            {
                q->pNext->pPrev = p;
            }
            q->pNext = p;
            break;
        }
    }
}

void addBefore(DList &L, int x, int y)
{
    for (DNode *q = L.pHead; q != NULL; q = q->pNext)
    {
        if (q->info == x)
        {
            DNode *p = new DNode;
            p->info = y;
            p->pNext = q;
            p->pPrev = q->pPrev;
            if (q->pPrev == NULL)
            {
                L.pHead = p;
            }
            else
            {
                q->pPrev->pNext = p;
            }
            q->pPrev = p;
            break;
        }
    }
}

void addAfterMulti(DList &L, int x, int y)
{
    for (DNode *q = L.pHead; q != NULL; q = q->pNext)
    {
        if (q->info == x)
        {
            DNode *tmp = new DNode;
            tmp->info = y;
            tmp->pNext = q->pNext;
            tmp->pPrev = q;
            if (q->pNext == NULL)
            {
                L.pTail = tmp;
            }
            else
            {
                q->pNext->pPrev = tmp;
            }
            q->pNext = tmp;
            q = tmp;
        }
    }
}

void addBeforeMulti(DList &L, int x, int y)
{
    for (DNode *q = L.pHead; q != NULL; q = q->pNext)
    {
        if (q->info == x)
        {
            DNode *tmp = new DNode;
            tmp->info = y;
            tmp->pNext = q;
            tmp->pPrev = q->pPrev;
            if (q->pPrev == NULL)
            {
                L.pHead = tmp;
            }
            else
            {
                q->pPrev->pNext = tmp;
            }
            q->pPrev = tmp;
        }
    }
}

void removeHead(DList &L)
{
    if (L.pHead == NULL)
    {
        cout << "\nList is empty. Can't delete";
        return;
    }

    char confirm;
    cout << "\nDo you want to delete the first element?(y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y')
    {
        DNode *p = L.pHead;
        L.pHead = L.pHead->pNext;
        if (L.pHead == NULL)
        {
            L.pTail = NULL;
            cout << "\nThe list becomes empty";
        }
        else
        {
            L.pHead->pPrev = NULL;
        }
        delete p;
    }
}

void removeTail(DList &L)
{
    if (L.pTail == NULL)
    {
        cout << "\nList is empty. Can't delete";
        return;
    }

    char confirm;
    cout << "\nDo you want to delete the last element?(y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y')
    {
        DNode *p = L.pTail;
        L.pTail = L.pTail->pPrev;
        if (L.pTail == NULL)
        {
            L.pHead = NULL;
            cout << "\nThe list becomes empty";
        }
        else
        {
            L.pTail->pNext = NULL;
        }
        delete p;
    }
}

int main()
{
    DList L;
    init(L);
    int x, y, choice;

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
        case 20:
            cout << "\nGOOD BYE";
            return 0;
        }
    }

    return 0;
}
