#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// QuickSort

void quickSort(int *&a, int left, int right)
{
	int x = a[(left+right)/2];

	int i = left;
	int j = right;

	while (i <= j)
    {
		while (a[i] < x)
		{
			i++;
		}

		while (a[j] > x)
		{
			j--;
		}

        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
	}

	if (i < right)
	{
		quickSort(a, i, right);
	}

	if (left < j)
	{
		quickSort(a, left, j);
	}
}

void sort(int *a, int n)
{
    int *b = new int[n];
    int sophantuChan = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            b[sophantuChan++] = a[i];
        }
    }

    if (sophantuChan > 1)
    {
        quickSort(b, 0, sophantuChan - 1);
    }

    int vitrisoChan = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            a[i] = b[vitrisoChan++];
        }
    }
}

int main()
{
    int *a, n;
    cin >> n;
    a = new int [n];


    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }

    sort(a, n);

    for(int i = 0; i < n; i ++)
    {
        cout << a[i] << " ";
    }
}
