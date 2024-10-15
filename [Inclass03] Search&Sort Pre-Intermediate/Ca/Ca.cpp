/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multi_set
map
unordered_map
include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

typedef struct Ca
{
    string loai_ca;
    float can_nang;
    string mau_sac;
    float chieu_dai;
    float nam_tuoi;

    float trung_binh() const
    {
        return (can_nang + chieu_dai)/2;
    }
};

void inputArray (Ca *&a, int n)
{
    a = new Ca[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].loai_ca >> a[i].can_nang >> a[i].mau_sac >> a[i].chieu_dai >> a[i].nam_tuoi;
}

void outputCa(const Ca &a)
{
    cout << a.loai_ca << " " << a.can_nang << " " << a.mau_sac << " " << a.chieu_dai << " " << a.nam_tuoi << endl;
}

void swap(Ca &a, Ca &b)
{
    Ca temp = a;
    a = b;
    b = temp;
}

void bubbleSort(Ca *a, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].trung_binh() > a[j + 1].trung_binh())
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

float myAbs(float x)
{
    return x < 0 ? -x : x;
}

int findMin(Ca *a, int n, float m)
{
    int viTri = 0;
    float khoangCachNhoNhat = myAbs(a[0].trung_binh() - m);

    for (int i = 1; i < n; i++)
    {
        float khoangCachHienTai = myAbs(a[i].trung_binh() - m);
        if (khoangCachHienTai < khoangCachNhoNhat)
        {
            khoangCachNhoNhat = khoangCachHienTai;
            viTri = i;
        }
    }
    return viTri;
}

int main()
{
    int n;
    cin >> n;

    Ca *a;
    inputArray(a, n);

    int k;
    cin >> k;

    float m;
    cin >> m;

    bubbleSort(a, n);

    outputCa(a[k]);

    int minIndex = findMin(a, n, m);
    outputCa(a[minIndex]);

    delete[] a;
    return 0;
}
