#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // Bước 1: Tìm a[min]
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        // Bước 2: Hoán vị
        swap (a[min], a[i]);
    }
}

void outputArray(int a[], int n)
{
   int i;
   for (i = 0; i < n; i++)
   {
       cout << a[i] << " ";
   }
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    selectionSort(a, n);

    outputArray(a, n);
}
