
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;

// ###INSERT CODE HERE -

struct Node
{
    int info;
    Node *next;
};

struct Hash
{
    int m;        
    Node **bucket; 
};

void initHash(Hash &H)
{
    H.bucket = new Node *[H.m];
    for (int i = 0; i < H.m; i++)
    {
        H.bucket[i] = NULL;
    }
}

int hashFunction(int x, int m)
{
    return x % m;
}

Node *getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void addHead(Node *&L, int x)
{
    Node *new_element = getNode(x);
    if (L == NULL)
        L = new_element;
    else
    {
        new_element->next = L;
        L = new_element;
    }
}

void insertList(Node *&L, int x)
{
    Node *p = L;
    while (p != NULL)
    {
        if (p->info == x)
            return; 
        p = p->next;
    }
    addHead(L, x); 
}

void insertHash(Hash &H, int x)
{
    int idx = hashFunction(x, H.m);   
    insertList(H.bucket[idx], x); 
}

void traverseAllHash(Hash H, int sortArray[], int &count)
{
    count = 0;
    for (int i = 0; i < H.m; i++)
    {
        Node *p = H.bucket[i];
        while (p != NULL)
        {
            sortArray[count++] = p->info; 
            p = p->next;
        }
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (sortArray[i] > sortArray[j])
            {
                int temp = sortArray[i];
                sortArray[i] = sortArray[j];
                sortArray[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        cout << sortArray[i] << " ";
    }
    cout << endl;
}

void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void removeDups(int a[], int n)
{
    Hash H;
    H.m = n;
    initHash(H);

    for (int i = 0; i < n; i++)
    {
        insertHash(H, a[i]);
    }

    int sortArray[1000], count;

    traverseAllHash(H, sortArray, count); 
}

int main()
{
    int a[100], n;
    inputArray(a, n);

    // In mang ban dau
    printArray(a, n);

    /* Goi ham thuc hien xuat mang nhung chi xuat nhung gia tri xuat hien lan dau tien,
     *  khong xuat nhung gia tri bi lap lai/bi trung
     */

    cout << "After removing the duplicate elements:" << endl;

    removeDups(a, n);

    return 0;
}
