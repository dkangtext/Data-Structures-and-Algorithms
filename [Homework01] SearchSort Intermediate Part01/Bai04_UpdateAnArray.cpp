#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void addElement(vector<int>& a, int n)
{
    a.push_back(n);
}

void deleteMaxElement(vector<int>& a)
{
    if (!a.empty())
    {
        int max = *max_element(a.begin(), a.end());
        a.erase(remove(a.begin(), a.end(), max), a.end());
    }
}

void printArray(const vector<int>& a)
{
    cout << a.size() << endl;
    vector<int> sortArray = a;
    sort(sortArray.begin(), sortArray.end(), greater<int>());
    for (int i : sortArray)
    {
        cout << i << endl;
    }
}

int main()
{
    vector<int> a;

    int n;
    
    while(true)
    {
        cin >> n;

        if (n == -2) 
        {
            printArray(a);
            break;
        }
        else if (n == -1)
        {
            deleteMaxElement(a);
        }
        else if ( n > 0 && n < 32000)
        {
            addElement(a, n);
        }
    }

    return 0;
}