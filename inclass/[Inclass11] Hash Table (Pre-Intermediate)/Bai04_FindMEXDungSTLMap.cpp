/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
###End banned keyword*/

//###INSERT CODE HERE -

#include<map>
#include<iostream>
using namespace std;


int main()
{
    map<int, int> b;

    int n;
    cin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }

    for (int i = 0; i <= n; i++)
    {
        if (b[i] == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;

}


