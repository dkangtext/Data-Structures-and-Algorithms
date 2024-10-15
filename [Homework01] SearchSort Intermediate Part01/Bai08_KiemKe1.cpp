/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
map
multi_set
unordered_map
merge
define
include
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;


//###INSERT CODE HERE -

void inputArray(vector<string>& a, int& n) 
{
    cin >> n; 
    a.resize(n);  

    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
}

bool maHangDaTonTai(const vector<string>& a, const string& n) 
{
    for (int i = 0; i < a.size(); i++) 
    {
        if (a[i] == n) 
        {
            return true;
        }
    }
    return false;
}

int demMaHangKhacNhau(const vector<string>& a) 
{
    vector<string> maHangKhacNhau;  

    for (int i = 0; i < a.size(); i++) 
    {
        if (!maHangDaTonTai(maHangKhacNhau, a[i])) 
        {
            maHangKhacNhau.push_back(a[i]);
        }
    }

    return maHangKhacNhau.size();  
}

int main() 
{
    int n;
    vector<string> a;

    inputArray(a, n);

    int soLuongKhacNhau = demMaHangKhacNhau(a);

    cout << soLuongKhacNhau << endl;

    return 0;
}