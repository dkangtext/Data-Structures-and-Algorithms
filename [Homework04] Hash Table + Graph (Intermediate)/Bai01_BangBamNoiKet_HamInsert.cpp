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

int Hash(Hashtable H, int maso)
{
    return maso % H.M;
}

void Input(Hocsinh &x)
{
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}

/*
MỘT SỐ GỢI Ý:
    Hàm CreateHashtable(hashtable, m) khởi tạo bảng băm
    {
        Bước 1: vì table được hiểu là 1 con trỏ quản lý 1 mảng động nên cần cấp phát vùng nhớ cho mảng các List
        lúc này, ở mỗi List đã có 2 con trỏ head và tail nhưng các con trỏ chưa khởi tạo
        Bước 2: Lần lượt khởi tạo con trỏ head, tail của mỗi List, nên viết hàm initList riêng
        Bước 3: khởi tạo các thuộc tính còn lại của bảng băm là M,n
    }
    Hàm Insert(hashtable, hs) thêm 1 học sinh hs vào bảng băm. Có thể thiết kế Hàm Insert sẽ trả về kết quả 1 nếu thêm phần tử thành công và trả về 0 nếu không thêm phần tử được
    {
        Kiểm tra hệ số tải. Hệ số tải của bảng băm được ấn định là 0.7, nghĩa là bảng băm luôn đảm bảo số phần tử được lưu trong bảng băm không quá 70% kích thước của bảng băm.
        Tìm địa chỉ phù hợp cho hs
        Từ địa chỉ này sẽ xác định được List mà hs thuộc về
        Gọi hàm thêm 1 phần tử vào List, nên viết hàm addHead hay addTail riêng
        Nhớ tăng số lượng phần tử của bảng băm
    }
    Hàm  PrintHashtable(hashtable) in bảng băm
    {
        Duyệt từng địa chỉ hay còn hiểu là duyệt từng List
            Ứng với mỗi List, xuất tất cả các phần tử trong List theo 1 format quy ước (ghi trong đề)
    }
    Hàm DeleteHashtable(hashtable) xóa toàn bộ bảng băm
    {
        Duyệt từng địa chỉ hay còn hiểu là duyệt từng List
            Ứng với mỗi List, xóa toàn bộ node trong danh sách, vì 2 con trỏ head, tail là biến tĩnh nên chỉ có thể gán về NULL
        Xóa vùng nhớ của mảng các List (vì cũng là mảng động), cũng nên gán lại con trỏ table về NULL cho an toàn
        Reset các thuộc tính còn lại của bảng băm

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

void addTail(List &L, Hocsinh hs)
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

bool Insert(Hashtable &H, Hocsinh hs)
{
    if (H.n + 1 >= H.M * LOAD)
        return false;
    int index = Hash(H, hs.Maso);
    addTail(H.table[index], hs);
    H.n++;
    return true;
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

    int m, n;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Input(hs);
        Insert(hashtable, hs);
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}
