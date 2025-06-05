/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -


typedef struct node
{
    int info;
    node *next;
};

struct List
{
    node *pHead;
    node *pTail;
};

node *getNode(int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void init (List &L)
{
    L.pHead = L.pTail = NULL;
}

void addTail (List &L, int x)
{
    node *p = getNode(x);
    if (L.pTail == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        L.pTail->next = p;
        L.pTail = p;
    }
}

void inputList (List &L, int n)
{
   for (int i = 0; i < n; i++)
   {
       int x;
       cin >> x;
       addTail (L, x);
   }
}

void outputList(List L)
{
    node *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

void swap(int* a, int* b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

void MySort(List &L)
{
    for (node *i = L.pHead; i != NULL; i = i->next)
    {
        node *minNode = i;
        for (node *j = i->next; j != NULL; j = j->next)
        {
            if (j->info < minNode->info)
            {
                minNode = j;
            }
        }

        if (minNode != i)
        {
            swap (i->info, minNode->info);
        }
    }
}


int MySearch(List &L, int x)
{
    node *p = L.pHead;
    int pos = 0;
    while (p != NULL)
    {
        if (p->info == x)
        {
            return pos;
        }
        p = p->next;
        pos++;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;

    List L;
    init (L);
    inputList(L,n);

    MySort(L);

    cout<<"Sorted List: ";
    outputList(L);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x;
    cin>>x;
    cout<<x<<endl;

    int result = MySearch(L,x);

    if (result ==-1)
        cout<<x<<" is not found";
    else
        cout<<x<<" is found at the position " << result;

	return 0;
}

