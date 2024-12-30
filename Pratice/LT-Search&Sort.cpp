#include <iostream>

using namespace std;

// Input array

void inputArray(int*& a, int& n)
{
    cin >> n;
    
    a = new int[n]; 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

// Output array

void outputArray(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Viết chương trình tìm kiếm một số trong MẢNG TĂNG DẦN - BINARY SEARCH

int binaraySearch(int *a, int n, int x)
{
    int left = 0;
    int right = n - 1;
    int result = -1;
    
    if (x == a[right])
        return right;
    
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (x == a[mid])
        {
            result = mid;
            left = mid + 1;
        }
        else if (x >= a[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return result;
}

// Viết chương trình tìm kiếm một số trong MẢNG BẤT KỲ - LINEAR SEARCH

void LinearSearch(int* a, int n, int m)
{
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        for (int j = 0; j < n; j++)
        {
            if (x == a[j])
            {
                cout << j << endl;
                break;
            }
            else if (j == (n-1))
            {
                cout << -1 << endl;
            }
        }

    }
} 

// Sắp xếp mảng số nguyên theo thứ tự TĂNG DẦN - SELECTION SORT.

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
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        swap (a[min], a[i]);
    }
}

// Thuật toán sắp xếp chèn - INSERTION SORT

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

// Sắp xếp mảng số nguyên theo thứ tự GIẢM DẦN - QUICK SORT
// Đếm số lần hoán đổi trong quá trình sắp xếp

void quickSort(int *&a, int left, int right) // int &dem
{
	int x = a[(left+right)/2]; 

	int i = left;
	int j = right;

	while (i <= j)
    {
        // Nếu tăng dần thì đổi dấu > thành <
		while (a[i] > x)
		{
			i++;
		}

        // Nếu tăng dần thì đổi dấu < thành >
		while (a[j] < x)
		{
			j--;
		}

        if (i <= j)
        {
            swap(a[i], a[j]);
            // dem++;
            i++;
            j--;
        }
	}

	if (i < right)
	{
		quickSort(a, i, right); //dem
	}

	if (left < j)
	{
		quickSort(a, left, j); //dem
	}
}

// Sắp xếp mảng số nguyên theo thứ tự TĂNG DẦN - MERGE SOT 

void Merge(int *&a, int left, int mid, int right)
{
    int n = mid - left + 1;
    int m = right - mid;

    int *MangA = new int[n];
    int *MangB = new int[m];

    for (int i = 0; i < n; i++)
        MangA[i] = a[left + i];

    for (int j = 0; j < m; j++)
        MangB[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n && j < m)
    {
        if (MangA[i] <= MangB[j])
        {
            a[k] = MangA[i];
            i++;
        }
        else
        {
            a[k] = MangB[j];
            j++;
        }
        k++;
    }

    while (i < n)
    {
        a[k] = MangA[i];
        i++;
        k++;
    }

    while (j < m)
    {
        a[k] = MangB[j];
        j++;
        k++;
    }

    delete[] MangA;
    delete[] MangB;
}

void MergeSort(int *&a, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        MergeSort(a, left, mid);

        MergeSort(a, mid + 1, right);

        Merge(a, left, mid, right);
    }
}

// Thuật toán tìm kiếm nổi bọt - BUBBLE SORT

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                outputArray(a,n);
            }
        }
    }
}

// Sắp xếp các SỐ CHẴN mảng số nguyên theo thứ tự TĂNG DẦN, GIỮ NGUYÊN vị trí các SỐ LẺ

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

// Sắp xếp các SỐ CHẴN của mảng số nguyên theo thứ tự TĂNG DẦN, các SỐ LẺ theo thứ tự GIẢM DẦN, giữ nguyên vị trí chẵn lẻ.

void quickSort_Tang(int *&a, int left, int right)
{}

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

void quickSort_Giam(int *&a, int left, int right)
{}

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

// Trộn hai mảng tăng dần

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

// Tìm điểm trong không gian 3 chiều

typedef struct point3D
{
    float x, y, z;
}p3;

// Hàm so sánh hai điểm trong không gian 3 chiều

void inputArray(p3 *&a, int n)
{
    a = new p3[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
}

int compareP3(p3 a, p3 b)
{
    if (a.x < b.x) return -1;
    if (a.x > b.x) return 1;
    if (a.y < b.y) return -1;
    if (a.y > b.y) return 1;
    if (a.z < b.z) return -1;
    if (a.z > b.z) return 1;
    return 0;
}

// Thuật toán tìm nhị phân trên danh sách các điểm

int binarySearch(p3 *a, int n, p3 x)
{
    int left = 0;
    int right = n - 1;
    int steps = 0; // Đếm số bước

    while(left <= right)
    {
        steps++;
        int mid = (left + right)/2;
        int i = compareP3(x, a[mid]);

        if (i == 0) return steps; // Tìm thấy điểm
        if (i < 0)
            right = mid -1; // Tìm bên trái
        else
            left = mid + 1; // Tìm bên phải
    }
    return -1;
}

int main()
{
    int n, m;

    cin >> n;
    p3 *a;
    inputArray(a, n);

    cin >> m;
    p3 *b;
    inputArray(b, m);

    // Kiểm tra từng điểm
    for (int i = 0; i < m; i++)
    {
        int steps = binarySearch(a, n, b[i]);
        if (steps == -1)
            cout << "KHONG" << endl;
        else
            cout << steps << endl;
    }

    delete[] a;
    delete[] b;

    return 0;
}

// Ca

typedef struct Ca
{
    string loai_ca;
    float can_nang;
    string mau_sac;
    float chieu_dai;
    float nam_tuoi;

    float trung_binh() const
    {
        return (can_nang + chieu_dai)/2;
    }
};

void inputArray (Ca *&a, int n)
{
    a = new Ca[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].loai_ca >> a[i].can_nang >> a[i].mau_sac >> a[i].chieu_dai >> a[i].nam_tuoi;
}

void outputCa(const Ca &a)
{
    cout << a.loai_ca << " " << a.can_nang << " " << a.mau_sac << " " << a.chieu_dai << " " << a.nam_tuoi << endl;
}

void swap(Ca &a, Ca &b)
{
    Ca temp = a;
    a = b;
    b = temp;
}

void bubbleSort(Ca *a, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].trung_binh() > a[j + 1].trung_binh())
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

float myAbs(float x)
{
    return x < 0 ? -x : x;
}

int findMin(Ca *a, int n, float m)
{
    int viTri = 0;
    float khoangCachNhoNhat = myAbs(a[0].trung_binh() - m);

    for (int i = 1; i < n; i++)
    {
        float khoangCachHienTai = myAbs(a[i].trung_binh() - m);
        if (khoangCachHienTai < khoangCachNhoNhat)
        {
            khoangCachNhoNhat = khoangCachHienTai;
            viTri = i;
        }
    }
    return viTri;
}

int main()
{
    int n;
    cin >> n;

    Ca *a;
    inputArray(a, n);

    int k;
    cin >> k;

    float m;
    cin >> m;

    bubbleSort(a, n);

    outputCa(a[k]);

    int minIndex = findMin(a, n, m);
    outputCa(a[minIndex]);

    delete[] a;
    return 0;
}

