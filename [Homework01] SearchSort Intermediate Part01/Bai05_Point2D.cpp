/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
###End banned keyword*/

//###INSERT CODE HERE -

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Diem
{
    int x;
    int y;
};

void inputArray(vector<Diem>& a, int& n)
{
    cin >> n;
    
    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
}

void swap(Diem& a, Diem& b) 
{
    Diem temp = a;
    a = b;
    b = temp;
}

int phanHoach(vector<Diem>& a, int left, int right)
{
    int chiSoX = left + rand()%(right - left + 1);
    swap(a[chiSoX], a[right]);

    Diem x = a[right];  

    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (a[j].x < x.x || (a[j].x == x.x && a[j].y > x.y))
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);
    return i + 1;

}

void quickSort(vector<Diem>& a, int left, int right)
{
    if (left < right)
    {
        int diemPhanHoach = phanHoach(a, left, right);  

        quickSort(a, left, diemPhanHoach - 1);  
        
        quickSort(a, diemPhanHoach + 1, right); 
    }
}
void outputArray(const vector<Diem>&a, int n)
{
   for (int i = 0; i < n; i++)
   {
       cout << a[i].x << " " << a[i].y << endl;
   }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<Diem> a;
    int n;

    inputArray(a, n);
    quickSort(a, 0, n - 1);
    outputArray(a, n);

    return 0;
}