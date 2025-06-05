#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void inputArray(int *&a, int &n)
{
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void outputArray(int *a, int n)
{
   cout << "Sorted Array: ";
   for (int i = 0; i < n; i++)
   {
       cout << a[i] << " ";
   }
   cout << endl;
}

// Sắp xếp các phần tử tăng dần

void quickSort_Tang(int *&a, int left, int right)
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
		quickSort_Tang(a, i, right);
	}

	if (left < j)
	{
		quickSort_Tang(a, left, j);
	}
}

// Các phần tử chẵn

void sortChan(int *a, int n)
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
        quickSort_Tang(b, 0, sophantuChan - 1);
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

// Sắp xếp các phần tử giảm dần

void quickSort_Giam(int *&a, int left, int right)
{
	int x = a[(left+right)/2];

	int i = left;
	int j = right;

	while (i <= j)
    {
		while (a[i] > x)
		{
			i++;
		}

		while (a[j] < x)
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
		quickSort_Giam(a, i, right);
	}

	if (left < j)
	{
		quickSort_Giam(a, left, j);
	}
}

// Các phần tử lẻ

void sortLe(int *a, int n)
{
    int *c = new int[n];
    int sophantuLe = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            c[sophantuLe++] = a[i];
        }
    }

    if (sophantuLe > 1)
    {
        quickSort_Giam(c, 0, sophantuLe - 1);
    }

    int vitrisoLe = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            a[i] = c[vitrisoLe++];
        }
    }
}

int main()
{
    int *a, n;

    inputArray(a, n);

    sortChan(a, n);

    sortLe(a, n);

    outputArray(a,n);

    return 0;
}
