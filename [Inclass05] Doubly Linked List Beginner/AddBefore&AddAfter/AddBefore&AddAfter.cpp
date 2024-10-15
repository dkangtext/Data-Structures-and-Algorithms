/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include  <iostream>
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

//###INSERT CODE HERE -

void init (DList &DL)
{
    DL.pHead = DL.pTail = NULL;
}

DNode *getNode (int x)
{
    DNode *newNode = new DNode;
    newNode->info = x;
    newNode->pNext = newNode->pPrev = NULL;
    return newNode;
}

void addTail (DList &DL, int x)
{
    DNode *newNode = getNode(x);
    if (DL.pHead == NULL)
    {
        DL.pHead = DL.pTail = newNode;
    }
    else
    {
        newNode->pPrev = DL.pTail;
        DL.pTail->pNext = newNode;
        DL.pTail = newNode;
    }
}

void createList (DList &DL)
{
    int x;

    while (true)
    {
        cin >> x;
        if (x == -1) break;
        addTail(DL, x);
    }
}

void printList (DList &DL)
{
    if (DL.pHead == NULL)
    {
        cout << "List is empty";
        return;
    }

    DNode *p = DL.pHead;
    while (p)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void addHead (DList &DL, int x)
{
    DNode *newNode = getNode(x);
    if (DL.pHead == NULL)
    {
        DL.pHead = DL.pTail = newNode;
    }
    else
    {
        DL.pHead->pPrev = newNode;
        newNode->pNext = DL.pHead;
        DL.pHead = newNode;
    }
}

void addAfter (DList &DL, int x, int y)
{
    DNode *p = DL.pHead;

    if (p == NULL)
    {
        cout << "\nCan't find the value " << x << endl;
        return;
    }

    while (p)
    {
        if (p->info == x)
        {
            DNode *newNode = getNode(y);
            newNode->pNext = p->pNext;
            newNode->pPrev = p;
            p->pNext = newNode;

            if (newNode->pNext)
            {
                newNode->pNext->pPrev = newNode;
            }

            if (p == DL.pTail)
            {
                DL.pTail = newNode;
            }
            return;
        }
        p = p->pNext;
    }
    addTail(DL, y);
}

void addBefore (DList &DL, int x, int y)
{
    DNode *p = DL.pHead;

    if (p == NULL)
    {
        cout << "\nCan't find the value " << x << endl;
        return;
    }

    while (p)
    {
        if (p->info == x)
        {
            DNode *newNode = getNode(y);
            newNode->pNext = p;
            newNode->pPrev = p->pPrev;

            if (p == DL.pHead)
            {
                DL.pHead = newNode;
            }
            else
            {
                p->pPrev->pNext = newNode;
            }

            p->pPrev = newNode;

            return;
        }
        p = p->pNext;
    }
    addHead(DL, y);
}

int main()
{
	DList L;
	init(L);
	int x,y,choice;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n20. Exit"<<endl;

	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
