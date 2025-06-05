#include <iostream>

using namespace std;

void inputArray(int *&a, int n)
{
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void outputArray(int *a, int n)
{
   for (int i = 0; i < n; i++)
   {
       cout << a[i] << " ";
   }
   cout << endl;
}

void Merge(int *&a, int left, int mid, int right)
{
    int n = mid - left + 1;
    int m = right - mid;

    int *MangA = new int[n];
    int *MangB = new int[m];

    for (int i = 0; i < n; i++)
        MangA[i] = a[left + i];

    for (int j = 0; j < m; j++)
        MangB[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n && j < m)
    {
        if (MangA[i] <= MangB[j])
        {
            a[k] = MangA[i];
            i++;
        }
        else
        {
            a[k] = MangB[j];
            j++;
        }
        k++;
    }

    while (i < n)
    {
        a[k] = MangA[i];
        i++;
        k++;
    }

    while (j < m)
    {
        a[k] = MangB[j];
        j++;
        k++;
    }

    delete[] MangA;
    delete[] MangB;
}

void MergeSort(int *&a, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        MergeSort(a, left, mid);

        MergeSort(a, mid + 1, right);

        Merge(a, left, mid, right);
    }
}

int binarySearch(int *a, int n, int left, int right, int x)
{
    int result = -1;

    if (x == a[right])
        return right;

    while (left <= right)
    {
        int mid = (left + right) / 2;

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
    int n; cin>>n;

    int *a = new int[n];

    inputArray(a,n);

    MergeSort(a,0,n-1);

    cout<<"Sorted Array: ";

    outputArray(a,n);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";

    int x; cin >> x;
    cout << x << endl;

    int result = binarySearch(a,n,0,n-1,x);

    if (result == -1)
        cout<<x<<" is not found";
    else
        cout<<x<<" is found at the position " << result;

	return 0;
}

