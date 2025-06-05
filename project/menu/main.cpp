#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

// SELECTION SORT
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

// INTERCHANGE SORT
void interchangeSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// INSERTION SORT
void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// BINARY INSERTION SORT
int binarySearch(int *a, int item, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (item == a[mid])
            return mid + 1;
        else if (item > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void binaryInsertionSort(int *a, int n)
{
    int i, locate, j, selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];

        locate = binarySearch(a, selected, 0, j);

        while (j >= locate)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}

// BUBBLE SORT
void BubbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool s = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                s = true;
            }
        }
        if (!s)
            break;
    }
}

// SHAKER SORT
void ShakeSort(int *arr, int size)
{
    int left = 0;
    int right = size - 1;
    bool swapped = true;

    while (swapped)
    {
        swapped = false;

        for (int i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        right--;

        for (int i = right; i > left; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        left++;
    }
}

// COUNTING SORT
void countSort(int *a, int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
}

// QUICK SORT
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int *a, int l, int r)
{
    if (l >= r)
        return;

    int x = a[l + rand() % (r - l + 1)];
    int i = l;
    int j = r;

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

    if (l < j)
        quickSort(a, l, j);
    if (i < r)
        quickSort(a, i, r);
}

// MERGE SORT
void Merge(int *a, int left, int mid, int right)
{
    int *temp = new int[right - left + 1];

    int m = 0;
    int i = left;
    int j = mid + 1;

    while (!(i > mid && j > right))
    {
        if ((i <= mid && j <= right && a[i] < a[j]) || j > right)
            temp[m++] = a[i++];
        else
            temp[m++] = a[j++];
    }

    for (int i = 0; i < m; i++)
        a[left + i] = temp[i];
    delete[] temp;
}

void mergeSort(int *a, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        Merge(a, l, mid, r);
    }
}

// HEAP SORT
void Heapify(int *a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        Heapify(a, n, largest);
    }
}

void heapSort(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        Heapify(a, i, 0);
    }
}

// SHELL SORT
void shellSort(int *a, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int j = i;
            int temp = a[i];
            for (j = i; j >= gap && temp < a[j - gap]; j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}

// RADIX SORT
int getMax(int *a, int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void radixSort(int *a, int n)
{
    int m = getMax(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

int getInteger()
{
    int n;
    cout << "Please enter a number in range 1 to 1 000 000: ";
    while (true)
    {
        cin >> n;
        if (n >= 1 && n <= 1000000)
            break;
        cout << "Invalid input. Please enter a number in range 1 to 1 000 000: ";
    }
    return n;
}

void generateArray(int *a, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000000;
}

void copyArray(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

void Menu()
{
    cout << "\n-- -- -- -MENU-- -- -- -" << endl;
    cout << " 1.Selection Sort " << endl;
    cout << " 2.Interchange Sort " << endl;
    cout << " 3.Insertion Sort " << endl;
    cout << " 4.Binary Insertion Sort " << endl;
    cout << " 5.Bubble Sort " << endl;
    cout << " 6.Shaker Sort " << endl;
    cout << " 7.Counting Sort " << endl;
    cout << " 8.Quick Sort " << endl;
    cout << " 9.Merge Sort " << endl;
    cout << " 10.Heap Sort " << endl;
    cout << " 11.Shell Sort " << endl;
    cout << " 12.Radix Sort " << endl;
    cout << " Please choose an algorithm (Enter an interger): " << endl;
}

int main()
{
    int n = getInteger();
    int *a = new int[n];
    generateArray(a, n);

    while (true)
    {
        int *b = new int[n];
        copyArray(a, b, n);

        Menu();

        int choose;
        cin >> choose;

        if (choose < 1 || choose > 12)
        {
            cout << "See you again!" << endl;
            delete[] b;
            break;
        }

        clock_t start = clock();

        switch (choose)
        {
        case 1:
            selectionSort(b, n);
            break;
        case 2:
            interchangeSort(b, n);
            break;
        case 3:
            insertionSort(b, n);
            break;
        case 4:
            binaryInsertionSort(b, n);
            break;
        case 5:
            BubbleSort(b, n);
            break;
        case 6:
            ShakeSort(b, n);
            break;
        case 7:
            countSort(b, n, 1);
            break;
        case 8:
            quickSort(b, 0, n - 1);
            break;
        case 9:
            mergeSort(b, 0, n - 1);
            break;
        case 10:
            heapSort(b, n);
            break;
        case 11:
            shellSort(b, n);
            break;
        case 12:
            radixSort(b, n);
            break;
        }

        clock_t end = clock();
        cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

        delete[] b;
        
        cout << "Do you want to continue? (y/n): ";
        char c;
        cin >> c;

        if (c == 'n' || c == 'N')
        {
            cout << "See you again!" << endl;
            break;
        }
        else if (c != 'y' && c != 'Y')
        {
            cout << "Invalid input. See you again!" << endl;
            break;
        }

        generateArray(a, n);
    }

    delete[] a;
    return 0;
}