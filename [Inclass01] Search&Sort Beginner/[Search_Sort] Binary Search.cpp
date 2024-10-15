#include <iostream>
using namespace std;

int binarySearch(int *a, int n, int x)
{
    int left = 0;
    int right = n -1;
    int result = -1;
    
    if(x == a[right])
        return right;

    while (left <= right)
    {
        int mid = (left + right)/2;
        if (x == a[mid]) 
        {
            result = mid;
            left = mid + 1;
        }
        else if (x >= a[mid])
            left = mid + 1;
        else
            right = mid - 1; 
    }
    return result;
}

void inputArray(int*& a, int& n)
{
    cin >> n;
    
    a = new int[n]; 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int main()
{
    int n;

    int* a = NULL;
    inputArray(a,n);

    int m;
    cin >> m; 

    for (int j = 0; j < m; j++)
    {
        int x;
        cin >> x;
        cout << binarySearch(a,n,x) << endl;
    }
    return 0;
}
