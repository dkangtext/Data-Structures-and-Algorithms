#include <iostream>

using namespace std;

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
