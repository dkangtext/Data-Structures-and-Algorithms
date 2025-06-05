/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
map
set
###End banned keyword*/


#include<vector>
#include<iostream>
using namespace std;

int main()
{

//###INSERT CODE HERE -

    int n;
    cin >> n;

    vector<int> b(n);
    vector<bool> c(n + 1, false);

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] <= n)
        {
            c[b[i]] = true;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        if (!c[i])
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;

}



