/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

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

int binarySearch2(int *a, int n, int x)
{
    int left = 0;
    int right = n - 1;
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

int main()
{
    int n, *a = NULL;
    inputArray(a,n); //Luu y van de tham chieu cho con tro a va n

    // nhap cac gia tri can tim, neu nhap -1 thi ket thuc viec tim kiem
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1)break;
        cout<<binarySearch2(a,n,x)<<endl;

    }

    return 0;
}

