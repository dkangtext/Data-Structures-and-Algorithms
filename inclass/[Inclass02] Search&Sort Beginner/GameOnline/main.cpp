#include <iostream>

using namespace std;

// Sắp xếp mảng mã số game thủ bằng Insertion Sort

void InsertionSort2(int *&a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int j;
        for (j = i - 1; j >= 0 && x < a[j]; j--)
       {

            a[j + 1] = a[j];
        }
        a[j + 1]= x;
    }
}

int main()
{
    const int MAX_SIZE = 10000000;
    int *a = new int[MAX_SIZE];
    int *b = new int[MAX_SIZE];
    int pt = 0;

    while(1)
    {
        int x;
        cin >> x;

        if (x == 0) break; // Kết thúc khi nhập 0

        if (x == 1) // Game thủ đăng nhập
        {
            int y;
            cin >> y;
            a[pt] = x;
            b[pt] = y;
            pt++;
        }
        else if (x == 2) // Kiểm tra game thủ
        {

            int y;
            cin >> y;

            // Sắp xếp và loại bỏ các game thủ trùng hợp
            InsertionSort2(b,pt);

            int xoa = 0;

            while (xoa < pt-1)
            {
                if (b[xoa] == b[xoa+1])
                {
                    for (int i = xoa; i < pt - 1; i++)
                    {
                        b[i] = b[i+1];
                        a[i]= a[i+1];
                    }
                    pt--;
                }
                xoa++;
            }


            for (int i = 0; i < pt; i++)
            {
                if (y == b[i])
                {
                    cout << i + 1 << endl;
                    break;
                }
                else if (i == pt - 1)
                {
                    cout << 0 << endl;
                }
            }

            continue;
        }
    }

    return 0;
}
