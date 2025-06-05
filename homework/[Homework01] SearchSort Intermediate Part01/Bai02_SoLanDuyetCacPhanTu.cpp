#include <iostream>

using namespace std;

void inputArray(int*& a, int& n)
{
    cin >> n;
    
    a = new int[n]; 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int binarySearch(int *a, int n, int x, int &Dem)
{
    int left = 0;
    int right = n -1;
    
    Dem = 0;

    while (left <= right)
    {
        Dem++;

        int mid = (left + right)/2;
        
        if (x == a[mid]) 
        {
            return mid;
        }
        else if (x >= a[mid])
            left = mid + 1;
        else
            right = mid - 1; 
    }
    return -1;
}

int main()
{
    int *a, n, x;

    inputArray(a, n);

    cin >> x;

    int soLanDuyet;
    int viTri = binarySearch(a, n, x, soLanDuyet);

    if (viTri != -1)
    {
        cout << viTri << endl;
        cout << soLanDuyet << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    delete[] a;
    return 0;
}