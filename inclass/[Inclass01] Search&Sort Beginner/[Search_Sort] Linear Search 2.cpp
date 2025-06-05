/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

void inputArray(int*& a, int& n)
{
    cin >> n;
    
    a = new int[n]; // a trong hàm main và a ở inputarray là khác nhau 
                    // (a ở đây đang quản lý 1 vùng nhớ động vừa được cấp phát còn a ở trong hàm main không ảnh hưởng gì nên vẫn đang là NULL)
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void findElements(int* a, int n, int m)
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

int main()
{
    int n,m;
    int *a=NULL;
    inputArray(a,n);
    findElements(a,n,m);

    return 0;
}
