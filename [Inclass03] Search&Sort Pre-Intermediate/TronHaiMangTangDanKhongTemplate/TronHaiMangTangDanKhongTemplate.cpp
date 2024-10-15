#include <iostream>

using namespace std;

void inputArray(int *&a, int &n)
{
    cin >> n;
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

void Merge(int *a, int n, int *b, int m, int *&c, int &sizeC)
{
    sizeC = n + m;
    c = new int[sizeC];

    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }

    while (i < n)
    {
        c[k++] = a[i++];
    }

    while (j < m)
    {
        c[k++] = b[j++];
    }
}

int main()
{
    int n, m;

    int *a, *b, *c;

    inputArray(a, n);

    inputArray(b, m);

    int sizeC;
    Merge(a, n, b, m, c, sizeC);

    outputArray(c, sizeC);

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}

