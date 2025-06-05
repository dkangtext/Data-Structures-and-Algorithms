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

bool soSanh(string a, string b)
{
    if (a.length() > b.length()) return true;
    if (a.length() < b.length()) return false;
    if (a.length() == b.length())
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] > b[i]) return true;
            if (a[i] < b[i]) return false;
        }
    }
    
}

int timChiSo(const vector<pair<int, string>>& b, const string& maHang) 
{
    for (int i = 0; i < b.size(); i++) 
    {
        if (b[i].second == maHang) 
        {
            return i;
        }
    }
    return -1; 
}

void sapXep(const vector<string>& danhSachMaHang, vector<pair<int, string>>& b) 
{

    for (int i = 0; i < danhSachMaHang.size(); i++) 
    {
        int chiSo = timChiSo(b, danhSachMaHang[i]);
        if (chiSo != -1) 
        {
            b[chiSo].first++;
        } else 
        {

            b.push_back(make_pair(1, danhSachMaHang[i]));
        }
    }

    for (int i = 1; i < b.size(); i++) 
    {
        pair<int, string> x = b[i];
        int j = i - 1;

 
        while (j >= 0 && (b[j].first < x.first || (b[j].first == x.first && soSanh(b[j].second, x.second)))) 
        {
            b[j + 1] = b[j];
            j = j - 1;
        }
        b[j + 1] = x;
    }
}

void outputArray(const vector<pair<int, string>>& b) 
{
    for (int i = 0; i < b.size(); i++) 
    {
        cout << b[i].second << " " << b[i].first << endl;
    }
}

int main() 
{
    int n;
    vector<string> MaHang;
    vector<pair<int, string>> b;  
    
    inputArray(MaHang, n);

    sapXep(MaHang, b);

    outputArray(b);

    return 0;
}