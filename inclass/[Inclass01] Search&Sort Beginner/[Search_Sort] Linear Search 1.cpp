/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n; // So phan tu trong mang

    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m; // So luong gia tri can phai tim

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        int j;
        for (j = 0; j < n; j++)
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
    return 0;
}
