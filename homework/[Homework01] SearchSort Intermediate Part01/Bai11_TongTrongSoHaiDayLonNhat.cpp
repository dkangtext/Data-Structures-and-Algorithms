#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void inputArray(vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void maxSum(vector<int> &a, int n)
{
    sort(a.begin(), a.end());

    if (n > 3)
    {
        cout << a[n - 1] - a[0] + a[n - 2] - a[1] << endl;
    }
    else
    {
        cout << a[n - 1] - a[0] << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    
    for (int j = 0; j < n; j++)
    {
        int m;
        cin >> m;

        vector<int> a(m);
        
        inputArray(a, m);

        maxSum(a, m);
    }
    return 0;
}