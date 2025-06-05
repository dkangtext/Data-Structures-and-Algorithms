/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multiset
map
unordered_map
define
include
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;

//###INSERT CODE HERE -

void inputArray(vector<int>& a, int& n)
{
    cin >> n;
    
    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int findMEX(const vector<int>& a, int n)
{
    vector<bool> find(n + 1, false);

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0 && a[i] <= n)
        {
            find[a[i]] = true;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        if (!find[i])
        {
            return i;
        }
    }

    return n + 1;
}

int main()
{
    int n;

    vector<int> a(n);

    inputArray(a, n);
    
    cout << findMEX(a, n) << endl;

    return 0;
}