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

void Input(Hocsinh &x)
{
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}

/*MỘT SỐ LƯU Ý TRONG TEMPLATE NÀY
Trong các bài tập Search, Delete, input là bảng băm đã có.
Tức là trước đó, GV đã thêm các phần tử vào bảng băm (theo đúng kỹ thuật của bài Insert),
sau đó xuất toàn bộ bảng băm đó ra file inputx.txt (lần lượt xuất từng List ứng với mỗi địa chỉ).

Đoạn code bên dưới tái hiện lại bảng băm đã có nên SV không cần viết lại hàm Insert, chỉ cần tập trung vào chức năng Search
for (int i = 0; i < m; i++) { //duyệt từng List ứng với mỗi địa chỉ
        cin >> k; //số phần tử trong List[i]
        hashtable.n += k; //tăng số lượng phần tử trong bảng băm theo số lượng phần tử của List[i]
        for (int j = 0; j < k; j++) { //lần lượt nhập k học sinh và thêm vào cuối danh sách List[i]
            Input(hs);
            AddTail(hashtable.table[i], hs);
        }
}
*/

// ###INSERT CODE HERE -

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

Node *Search(Hashtable H, int key)
{
    int index = key % H.M;
    Node *p = H.table[index].head;
    while (p != NULL)
    {
        if (p->data.Maso == key)
            return p;
        p = p->next;
    }
    return NULL;
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
        Node *p = Search(hashtable, k);

        if (p == NULL)
            cout << "KHONG TIM THAY\n";
        else
        {
            hs = p->data;
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "]\n";
        }
    }
    DeleteHashtable(hashtable);
    return 0;
}
