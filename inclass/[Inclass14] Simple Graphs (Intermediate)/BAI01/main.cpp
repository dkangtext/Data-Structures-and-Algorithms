/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
// ###INSERT CODE HERE -

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> degree(m, 0);

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        degree[u]++;
        degree[v]++;
    }

    int isolatedVertices = 0;
    for (int i = 0; i < m; i++)
    {
        if (degree[i] == 0)
        {
            isolatedVertices++;
        }
    }

    cout << isolatedVertices << endl;

    return 0;
}
