#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

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

int HashFunction(Hash H, int key)
{
    return key % H.m;
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
    Node *p = getNode(x);
    p->next = L;
    L = p;
}

void addAfter(Node *&L, Node *q, int x)
{
    Node *p = getNode(x);
    p->next = q->next;
    q->next = p;
}

void insertList(Node *&L, int x)
{
    Node *new_ele = getNode(x);
    Node *p = L;
    Node *q = NULL;

    while (p != NULL && x > p->info)
    {
        q = p;
        p = p->next;
    }

    if (q == NULL)
    {
        addHead(L, x);
    }
    else
    {
        addAfter(L, q, x);
    }
}

void insertHash(Hash &H, int x)
{
    // Buoc 1: Bam x de tim ra vi tri index cua x trong bang bam

    int index = HashFunction(H, x);

    // Buoc 2: Them x vao danh sach lien ket tai vi tri index

    insertList(H.bucket[index], x);
}

void deleteNode(Node *&L, int x)
{
    Node *p = L;
    Node *q = NULL;

    while (p != NULL && p->info != x)
    {
        q = p;
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "\nKhong co phan tu co khoa " << x << endl;
        return;
    }

    if (q == NULL)
    {
        L = p->next;
    }
    else
    {
        q->next = p->next;
    }

    delete p;
}

void deleteHash(Hash &H, int x)
{
    int index = HashFunction(H, x);
    deleteNode(H.bucket[index], x);
}

void traverseAllHash(Hash H)
{
    for (int i = 0; i < H.m; i++)
    {
        cout << "Bucket " << i << ": ";
        Node *p = H.bucket[i];
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int main()
{
    Hash H;
    cin >> H.m;  // m la so dia chi co trong bang bam
    initHash(H); // khoi tao cac bucket

    int n, x;
    cin >> n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        insertHash(H, x); // them 1 gia tri du lieu vao bang bam
    }

    cout << "\nCreated Hash:" << endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    int a, b;
    while (true)
    {
        cin >> a;
        if (a != 1 && a != 2)
            break;
        cin >> b;
        if (a == 1)
        {
            cout << "\nInsert " << b << endl;
            insertHash(H, b);
        }
        else if (a == 2)
        {
            cout << "\nDelete " << b << endl;
            deleteHash(H, b);
        }
    }

    cout << "\nUpdated Hash:" << endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam sau khi cap nhat

    return 0;
}