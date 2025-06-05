/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;

// ###INSERT CODE HERE -

int partition(vector<int> &a, int left, int right)
{
    int pivot = a[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++)
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    
    swap(a[i + 1], a[right]);
    
    return (i + 1);
}

void quickSort(vector<int> &a, int left, int right)
{
    if (left < right)
    {
        int index = partition(a, left, right);
        quickSort(a, left, index - 1);
        quickSort(a, index + 1, right);
    }
}

bool calculate(vector<int> a, int k)
{
    int length = 1, length_tmp = 0;
    
    quickSort(a, 0, a.size() - 1);

    vector<int> tmp;
    
    for (auto current = a.begin(), prev = a.begin(); ++current != a.end(); ++prev)
    {
        if (*prev != *current)
            ++length;
        else
            tmp.push_back(*prev);
    }
    
    if (tmp.size() != 0)
        length_tmp++;
    
    if (tmp.size() > 1)
        for (auto current = tmp.begin(), prev = tmp.begin(); ++current != tmp.end(); ++prev)
        {
            if (*prev != *current)
                ++length_tmp;
        }
    
    return (k * 2 >= length && k * 2 <= length + length_tmp);
}

vector<int> input(int n)
{
    vector<int> in;
    int tmp;
    
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        in.push_back(tmp);
    }

    return in;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, k;
    vector<bool> output;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        output.push_back(calculate(input(n), k));
    }
    
    for (int i = 0; i < output.size(); i++)
    {
        if (output[i] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}