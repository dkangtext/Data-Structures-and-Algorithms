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

void swap(int* a, int* b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

void quickSort(int *&a, int left, int right, int &dem)
{
	int x = a[(left+right)/2]; // giá trị trục

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
            dem++;
            i++;
            j--;
        }
	}

	if (i < right)
	{
		quickSort(a, i, right, dem);
	}

	if (left < j)
	{
		quickSort(a, left, j, dem);
	}
}

int main()
{
    int *a = NULL, n;
    int dem = 0;

    inputArray(a,n);

    quickSort(a, 0, n-1, dem);

    cout << "Sorted Array: ";
    outputArray(a, n);

    cout << "Number of times to swap 2 numbers: " << dem;

    delete[] a;
    return 0;
}
