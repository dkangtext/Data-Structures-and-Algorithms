#include <iostream>

using namespace std;

void inputArray(int *&a, int &n)
{
    a = new int[n];
    cin >> n;
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

void insertionSort(int *&a, int &n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int j;

        for (j = i - 1; j >= 0 && x < a[j]; j--)
        {
            a[j + 1] = a[j];
            outputArray(a, n);
        }
        a[j + 1] = x;
        outputArray(a, n);
    }
}

int main()
{
    int *a = NULL, n;

    inputArray(a,n);

    insertionSort(a, n);

    return 0;
}


