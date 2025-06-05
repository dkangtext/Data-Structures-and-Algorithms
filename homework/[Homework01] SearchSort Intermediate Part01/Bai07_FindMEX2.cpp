/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multiset
map
unordered_map
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

void findMEX(const vector<int>& a, int n)
{
    vector<bool> present(n + 1, false);
    int currentMEX = 0;

    for (int i = 0; i < n; i++)
    {
        if(a[i] >= 0 && a[i] <= n)
        {
            present[a[i]] = true;
        }

        while(currentMEX <= n && present[currentMEX])
        {
            currentMEX++;
        }

        cout << currentMEX << " ";
    }

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    vector<int> a;

    inputArray(a, n);
    
    findMEX(a, n);

    return 0;
}