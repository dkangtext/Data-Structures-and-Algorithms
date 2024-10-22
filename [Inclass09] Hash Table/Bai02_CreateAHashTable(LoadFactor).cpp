/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};
struct List
{
    node *head, *tail;
};
struct Hash
{
    int m;      // kich thuoc bang bam
    int n;      // so phan tu hien tai trong bang
    float load; // he so tai toi da
    List *pL;   // con tro quan ly 1 mang chua cac List
};

// ###INSERT CODE HERE -

void initHash(Hash &H)
{
    H.pL = new List[H.m];
    H.n = 0; // Khoi tao so phan tu trong bang bam la 0
    for (int i = 0; i < H.m; i++)
    {
        H.pL[i].head = H.pL[i].tail = NULL;
    }
}

int HashFunction(Hash H, int key)
{
    return key % H.m;
}

node *getNode(int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void addTail(List &L, int x)
{
    node *p = getNode(x);
    if (L.head == NULL)
    {
        L.head = L.tail = p;
    }
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}

float getLoadFactor(Hash &H)
{
    return (float)(H.n + 1) / H.m;
}

void insertHash(Hash &H, int key)
{
    int index = HashFunction(H, key);

    addTail(H.pL[index], key);
    H.n++;
}

void inputHash(Hash &H, int n)
{
    initHash(H);

    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        if (getLoadFactor(H) <= H.load)
        {
            insertHash(H, key);
        }
    }
}

void printHash(Hash H)
{
    for (int i = 0; i < H.m; i++)
    {
        cout << "List " << i << ": ";
        node *p = H.pL[i].head;
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;
    }
}

void searchHash(Hash H, int key)
{
    int index = HashFunction(H, key);
    node *p = H.pL[index].head;
    int pos = 0;
    while (p != NULL)
    {
        pos++;
        if (p->info == key)
        {
            cout << pos << endl;
            return;
        }
        p = p->next;
    }
    cout << "KHONG" << endl;
}

int main()
{
    Hash H;
    cin >> H.m >> H.load;
    int n;
    cin >> n;
    inputHash(H, n);
    printHash(H);
    int nkey, key;
    cin >> nkey;

    for (int i = 0; i < nkey; i++)
    {
        cin >> key;
        searchHash(H, key);
    }
    return 0;
}
