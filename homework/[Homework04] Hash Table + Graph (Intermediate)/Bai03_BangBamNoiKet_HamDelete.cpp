/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <string>

#define LOAD 0.7
using namespace std;

struct Hocsinh
{
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Node
{
    Hocsinh data;
    Node *next;
};

struct List
{
    Node *head, *tail;
};

struct Hashtable
{
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    List *table;
};

// ###INSERT CODE HERE -

void Input(Hocsinh &x)
{
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}

void InitList(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}

void CreateHashtable(Hashtable &H, int m)
{
    H.M = m;
    H.n = 0;
    H.table = new List[m];
    for (int i = 0; i < m; i++)
    {
        InitList(H.table[i]);
    }
}

void AddTail(List &L, Hocsinh hs)
{
    Node *p = new Node;
    p->data = hs;
    p->next = NULL;
    if (L.head == NULL)
    {
        L.head = p;
        L.tail = p;
    }
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}

int Delete(Hashtable &H, int key)
{
    int index = key % H.M;
    Node *p = H.table[index].head;
    Node *prev = NULL;
    while (p != NULL)
    {
        if (p->data.Maso == key)
        {
            if (prev == NULL)
            {
                H.table[index].head = p->next;
            }
            else
            {
                prev->next = p->next;
            }
            delete p;
            H.n--;
            return 1;
        }
        prev = p;
        p = p->next;
    }
    return 0;
}

void PrintHashtable(Hashtable H)
{
    for (int i = 0; i < H.M; i++)
    {
        Node *p = H.table[i].head;
        while (p != NULL)
        {
            Hocsinh hs = p->data;
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "] ";
            p = p->next;
        }
        cout << endl;
    }
}

void DeleteHashtable(Hashtable &H)
{
    for (int i = 0; i < H.M; i++)
    {
        Node *p = H.table[i].head;
        while (p != NULL)
        {
            Node *temp = p;
            p = p->next;
            delete temp;
        }
    }
    delete[] H.table;
    H.table = NULL;
    H.M = 0;
    H.n = 0;
}

int main()
{
    Hashtable hashtable;

    int m, n, k;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        hashtable.n += k;
        for (int j = 0; j < k; j++)
        {
            Input(hs);
            AddTail(hashtable.table[i], hs);
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;

        if (Delete(hashtable, k) == 0)
            cout << "KHONG XOA DUOC\n";
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}
