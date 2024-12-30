/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <string>

#define LOAD 0.7
#define EMPTY 0
#define DELETE -1
using namespace std;

struct Hocsinh
{
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Hashtable
{
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh *table;
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

void InitList(Hashtable &H)
{
    H.table = new Hocsinh[H.M];
    for (int i = 0; i < H.M; i++)
    {
        H.table[i].Maso = EMPTY;
    }
}

void CreateHashtable(Hashtable &H, int m)
{
    H.M = m;
    H.n = 0;
    InitList(H);
}

int Hash(int key, int M)
{
    return key % M;
}

int Insert(Hashtable &H, Hocsinh hs)
{
    if (H.n + 1 >= LOAD * H.M)
        return 0;

    int i = 0;
    int index = (Hash(hs.Maso, H.M) + i) % H.M;
    while (H.table[index].Maso != EMPTY && H.table[index].Maso != DELETE)
    {
        i++;
        index = (Hash(hs.Maso, H.M) + i) % H.M;
        if (i >= H.M)
            return 0;
    }
    H.table[index] = hs;
    H.n++;
    return 1;
}

int Delete(Hashtable &H, int key, int &nprob)
{
    nprob = 0;
    int i = 0;
    int index = (key % H.M + i * i) % H.M;

    while (H.table[index].Maso != EMPTY)
    {
        if (H.table[index].Maso == key)
        {
            H.table[index].Maso = DELETE;
            H.n--;
            return 1;
        }
        i++;
        nprob++;
        index = (key % H.M + i * i) % H.M;
    }
    return 0;
}

void PrintHashtable(Hashtable H)
{
    for (int i = 0; i < H.M; i++)
    {
        Hocsinh hs = H.table[i];
        if (hs.Maso > 0)
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "]\n";
        else
            cout << "[" << hs.Maso << ",  " << "  , " << ", " << ", " << "]\n";
    }
}

void DeleteHashtable(Hashtable &H)
{
    delete[] H.table;
    H.table = NULL;
    H.M = 0;
    H.n = 0;
}

int main()
{
    Hashtable hashtable;

    int m, n, k, nprob;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++)
    {
        Input(hs);
        hashtable.table[i] = hs;
        if (hs.Maso > 0)
            hashtable.n++;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (Delete(hashtable, k, nprob))
        {
            cout << "THAM DO " << nprob << endl;
        }
        else
        {
            cout << "KHONG XOA DUOC" << endl;
        }
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}
