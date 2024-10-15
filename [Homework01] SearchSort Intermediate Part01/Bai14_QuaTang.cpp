#include <iostream>
#include <vector>

using namespace std;

// Nguon tham khao: https://wiki.vnoi.info/algo/basic/two-pointers

void inputArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void quickSort(int *a, int left, int right)
{
    if (left >= right)
        return;

    int x = a[(left + right) / 2];

    int i = left, j = right;

    while (i <= j)
    {
        while (a[i] < x)
            i++;

        while (a[j] > x)
            j--;

        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j)

        quickSort(a, left, j);
    
    if (i < right)
        quickSort(a, i, right);
}

void maxMoney(int *a, int n, int x)
{
    quickSort(a, 0, n - 1);

    int i = 0, j = n - 1;
    int sum = -1;

    while (i < j)
    {
        if (a[i] + a[j] <= x)
        {
            int sumTemp = a[i] + a[j];

            if (sumTemp > sum)
            {
                sum = sumTemp;
            }
        }

        if (a[i] + a[j] < x)
            i ++;
        else
            j --;
    }
    cout << sum;
}

int main()
{
    int n, x;
    cin >> n >> x;

    int *a = new int[n];
    
    inputArray(a, n);

    maxMoney(a, n, x);

    return 0;
}