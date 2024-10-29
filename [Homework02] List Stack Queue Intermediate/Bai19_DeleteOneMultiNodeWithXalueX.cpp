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
    DNode *q = L.pHead;
    bool found = false;
    while (q != NULL)
    {
        if (q->info == x)
        {
            DNode *p = new DNode;
            p->info = y;
            p->pNext = q->pNext;
            p->pPrev = q;
            if (q->pNext != NULL)
                q->pNext->pPrev = p;
            else
                L.pTail = p;
            q->pNext = p;
            found = true;
            break;
        }
        q = q->pNext;
    }
    if (!found)
    {
        cout << "\nCan't find the value " << x;
    }
}

void addBefore(DList &L, int x, int y)
{
    DNode *q = L.pHead;
    bool found = false;
    while (q != NULL)
    {
        if (q->info == x)
        {
            DNode *p = new DNode;
            p->info = y;
            p->pNext = q;
            p->pPrev = q->pPrev;
            if (q->pPrev != NULL)
                q->pPrev->pNext = p;
            else
                L.pHead = p;
            q->pPrev = p;
            found = true;
            break;
        }
        q = q->pNext;
    }
    if (!found)
    {
        cout << "\nCan't find the value " << x;
    }
}

void addAfterMulti(DList &L, int x, int y)
{
    bool found = false;
    for (DNode *q = L.pHead; q != NULL; q = q->pNext)
    {
        if (q->info == x)
        {
            DNode *p = new DNode;
            p->info = y;
            p->pNext = q->pNext;
            p->pPrev = q;
            if (q->pNext != NULL)
                q->pNext->pPrev = p;
            else
                L.pTail = p;
            q->pNext = p;
            found = true;
            q = p;
        }
    }
    if (!found)
    {
        cout << "\nCan't find the value " << x;
    }
}

void addBeforeMulti(DList &L, int x, int y)
{
    bool found = false;
    for (DNode *q = L.pHead; q != NULL; q = q->pNext)
    {
        if (q->info == x)
        {
            DNode *p = new DNode;
            p->info = y;
            p->pNext = q;
            p->pPrev = q->pPrev;
            if (q->pPrev != NULL)
                q->pPrev->pNext = p;
            else
                L.pHead = p;
            q->pPrev = p;
            found = true;
        }
    }
    if (!found)
    {
        cout << "\nCan't find the value " << x;
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

void removeNode(DList &L, int x)
{
    if (L.pHead == NULL)
    {
        cout << "\nList is empty. Can't delete";
        return;
    }

    DNode *q = L.pHead;
    while (q != NULL)
    {
        if (q->info == x)
        {
            char c;
            cout << "\nDo you want to delete " << x << " ?(y/n): ";
            cin >> c;
            if (c == 'y' || c == 'Y')
            {
                if (q->pPrev == NULL)
                {
                    L.pHead = q->pNext;
                    if (L.pHead == NULL)
                        L.pTail = NULL;
                    else
                        L.pHead->pPrev = NULL;
                }
                else if (q->pNext == NULL)
                {
                    L.pTail = q->pPrev;
                    L.pTail->pNext = NULL;
                }
                else
                {
                    q->pPrev->pNext = q->pNext;
                    q->pNext->pPrev = q->pPrev;
                }
                delete q;
                if (L.pHead == NULL)
                    cout << "\nThe list becomes empty";
                return;
            }
            break;
        }
        q = q->pNext;
    }
    if (q == NULL)
        cout << "\nCan't find the value " << x;
}

void removeMultiNodeS(DList &L, int x)
{
    if (L.pHead == NULL)
    {
        cout << "\nList is empty. Can't delete";
        return;
    }

    DNode *p = L.pHead;
    bool found = false;
    bool deleteAll = false;

    while (p != NULL)
    {
        DNode *nextNode = p->pNext;

        if (p->info == x)
        {
            if (!found)
            {
                found = true;
                char c;
                cout << "\nDo you want to delete " << x << "s ?(y/n): ";
                cin >> c;
                if (c == 'y' || c == 'Y')
                {
                    deleteAll = true;
                }
                else
                {
                    return;
                }
            }

            if (deleteAll)
            {
                if (p->pPrev == NULL)
                {
                    L.pHead = p->pNext;
                    if (L.pHead == NULL)
                        L.pTail = NULL;
                    else
                        L.pHead->pPrev = NULL;
                }
                else if (p->pNext == NULL)
                {
                    L.pTail = p->pPrev;
                    L.pTail->pNext = NULL;
                }
                else
                {
                    p->pPrev->pNext = p->pNext;
                    p->pNext->pPrev = p->pPrev;
                }

                delete p;
            }
        }
        p = nextNode;
    }

    if (!found)
        cout << "\nCan't find the value " << x;
    else if (L.pHead == NULL)
        cout << "\nThe list becomes empty";
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

        case 20:
            cout << "\nGOOD BYE";
            return 0;
        }
    }

    return 0;
}
