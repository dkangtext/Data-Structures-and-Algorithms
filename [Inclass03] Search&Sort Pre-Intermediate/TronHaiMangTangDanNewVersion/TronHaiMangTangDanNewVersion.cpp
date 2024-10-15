#include <iostream>

using namespace std;

void Merge(int *a, int *b, int n , int m)
{
    int *c = new int[n + m];

    int k = 0;

    int i = 0; int j = 0;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i];
            i++;
        }
        else
        {
            c[k++] = b[j];
            j++;
        }
    }

    while (i < n)
    {
        c[k++] = a[i];
        i++;
    }

    while (j < m)
    {
        c[k++] = b[j];
        j++;
    }

    for (int i = 0; i < k; i++)
    {
        cout << c[i] << " ";
    }

    delete []c;
    delete []a;
    delete []b;
}

int main()
{

    int soCase;
    cin >> soCase;

    for (int f = 0; f < soCase; f++)
    {

        int n, m;

        cin >> n;
        cin >> m;

        int *a;
        a = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int *b;
        b = new int[m];

        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        Merge(a, b, n, m);
        cout << endl;
    }

    return 0;
}

