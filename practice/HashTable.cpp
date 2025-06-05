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

// Hàm băm
int HashFunction(Hash H, int key)
{
    return key % H.m;
}

// Hàm tạo một Node mới
Node *getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

// Hàm chèn một phần tử vào đầu danh sách
void addHead(Node *&L, int x)
{
    Node *p = getNode(x);
    p->next = L;
    L = p;
}

// Hàm chèn một phần tử vào danh sách
void addAfter(Node *&L, Node *q, int x)
{
    Node *p = getNode(x);
    p->next = q->next;
    q->next = p;
}

// Hàm chèn một phần tử vào danh sách
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

// Hàm chèn một phần tử vào Hash
void insertHash(Hash &H, int x)
{
    int index = HashFunction(H, x);
    insertList(H.bucket[index], x);
}

// Hàm duyệt tất cả các phần tử trong Hash
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
    cin >> H.m;  
    initHash(H); 

    int n, x;
    cin >> n; 
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        insertHash(H, x); 
    }
    cout << "Created Hash:" << endl;
    traverseAllHash(H); 

    return 0;
}

