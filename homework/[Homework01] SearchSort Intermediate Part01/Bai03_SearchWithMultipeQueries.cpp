// /*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
// define
// include
// ###End banned keyword*/

#include <iostream>
using namespace std;


// //###INSERT CODE HERE -

void inputArray(int*& a, int& n, int*& b, int& m)
{
    cin >> n >> m;
    
    a = new int[n]; 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    b = new int[m];
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
    }
}

void swap(int* a, int* b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

void quickSort(int *&a, int left, int right)
{
    int x = a[(left + right)/2];

	int i = left;
	int j = right;

    if (left >= right) return;

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

int binarySearch(int *a, int n, int x)
{
    int left = 0;
    int right = n -1;

    while (left <= right)
    {
        int mid = (left + right)/2;

        if (x == a[mid]) 
        {
            return mid;
        }
        else if (x > a[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1; 
        }
    }
    return -1;
}


int main()
{
    int *a, *b, N, Q;

    inputArray(a, N, b, Q);

    quickSort(a, 0, N - 1);

    for (int i = 0; i < Q; i++)
    {
        int x = b[i];

        int viTri = binarySearch(a, N, x);

        if (viTri != -1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    delete[] a;
    delete[] b;
    return 0;
}
