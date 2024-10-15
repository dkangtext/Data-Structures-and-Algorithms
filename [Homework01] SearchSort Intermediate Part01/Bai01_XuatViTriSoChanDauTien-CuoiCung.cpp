/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nhapMang(vector<int> &a, int &n)
{

//###INSERT CODE HERE -

    cin >> n; 
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; 
    }
    cout << endl;
}

void xuatMang(const vector<int> &a, int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int viTriSoChanDauTien(const vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            return i;
        }
    }
    return -1;
}

int viTriSoChanCuoiCung(const vector<int> &a, int n) 
{
    for (int i = n - 1; i >= 0; i--) 
    {
        if (a[i] % 2 == 0) 
        {
            return i; 
        }
    }
    return -1; 
}

int soChanLonNhat(const vector<int> &a, int n)
{
    int max = INT32_MIN;

    for (int i = 0; i < n; i++) 
    {
        if (a[i] % 2 == 0) 
        {
            max = (a[i] > max) ? a[i] : max;
        }
    }
    
    return max;
} 

int main()
{
    vector<int> a;
    
    int n;

    nhapMang(a, n);

    cout << "Mang vua nhap:\n";
    xuatMang(a, n);

    int viTriDau = viTriSoChanDauTien(a, n);
    int viTriCuoi = viTriSoChanCuoiCung(a, n);
    int maxChan = soChanLonNhat(a, n);

    if (viTriDau != -1) 
    {
        cout << a[viTriDau] << " la so chan dau tien, co chi so " << viTriDau << " trong mang\n";
    } 
    
    if (viTriCuoi != -1) 
    {
        cout << a[viTriCuoi] << " la so chan cuoi cung, co chi so " << viTriCuoi << " trong mang\n";
    }

    if (maxChan != INT32_MIN) 
    {
        cout << "So chan lon nhat: " << maxChan << endl;
    } 
    else 
    {
        cout << "Mang khong co so chan" << endl;
    }
    
    return 0;
}