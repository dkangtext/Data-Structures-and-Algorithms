#include <iostream>
using namespace std;

int main()
{
    int v, e, n; // v: số đỉnh, e: số cạnh, n: số thao tác
    cin >> v >> e >> n;

    bool **G; // ma trận toàn số 0, 1 nên kiểu bool hay int đều được

    // Bước 1: Cấp phát vùng nhớ cho ma trận kề và khởi tạo ma trận toàn 0

    G = new bool *[v]; // Cấp phát vùng nhớ cho mảng hai chiều

    for (int i = 0; i < v; i++)
    {
        G[i] = new bool[v]{0}; // Khởi tạo mỗi hàng trong mảng hai chiều với giá trị 0
    }

    // Bước 2: Nhập danh sách cạnh và lưu thông tin cạnh vào ma trận

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a - 1][b - 1] = 1; // Đánh dấu cạnh từ đỉnh a sang đỉnh b
        G[b - 1][a - 1] = 1; // Đánh dấu cạnh từ đỉnh b sang đỉnh a
    }

    // Bước 3: Xử lý bài toán

    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;

        if (type == 1) // Kiểm tra tính kề của hai đỉnh
        {
            int u, w;
            cin >> u >> w;
            if (G[u - 1][w - 1] == 1)
            {
                cout << "TRUE" << endl;
            }
            else
            {
                cout << "FALSE" << endl;
            }
        }
        else if (type == 2) // Tìm kiếm các đỉnh kề của đỉnh u
        {
            int u;
            cin >> u;
            bool flag = false;
            for (int j = 0; j < v; j++)
            {
                if (G[u - 1][j])
                {
                    if (flag)
                    {
                        cout << " ";
                    }
                    cout << j + 1;
                    flag = true;
                }
            }

            if (!flag) // Nếu không có đỉnh nào kề
            {
                cout << "NONE";
            }
            cout << endl;
        }
    }

    // Bước 4: Giải phóng vùng nhớ

    for (int i = 0; i < v; i++)
    {
        delete[] G[i]; // Giải phóng mỗi hàng trong mảng hai chiều
    }
    delete[] G; // Giải phóng con trỏ chính

    return 0;
}