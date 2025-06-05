/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -

void inputMatrix(int a[50][50], int &n, int &m)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
}

void outputMatrix(int a[50][50], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void uniqueElements(int a[50][50], int n, int m)
{

    int MAX_value = 1000000;
    int *freq = new int[MAX_value + 1]();
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            freq[a[i][j]]++;
        }
    }

    int *unique = new int[n * m];
    int count = 0;

    for (int i = 0; i <= MAX_value; i++)
    {
        if (freq[i] == 1)
        {
            unique[count++] = i;
            found = true;
        }
    }
    
    if (!found)
    {
        cout << "No unique element in the matrix" << endl;
    }
    else
    {
        cout << "Unique elements in the matrix:" << endl;

        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (unique[i] > unique[j])
                {
                    int temp = unique[i];
                    unique[i] = unique[j];
                    unique[j] = temp;
                }
            }
        }

        for (int i = 0; i < count; i++)
        {
            cout << unique[i] << " ";
        }
    }

    delete[] freq;
    delete[] unique;
}

int main()
{
    int m, n, a[50][50];
    inputMatrix(a, n, m);
    cout << "Matrix:\n";
    outputMatrix(a, n, m);
    uniqueElements(a, n, m);
    return 0;
}
