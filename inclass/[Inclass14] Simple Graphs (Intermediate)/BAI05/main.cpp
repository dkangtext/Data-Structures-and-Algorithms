#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph
{
    vector<vector<int>> matrix;

public:
    void inputGraph(int v, int e)
    {
        matrix = vector<vector<int>>(v, vector<int>(v, 0));

        int u, w;
        for (int i = 0; i < e; i++)
        {
            cin >> u >> w;
            matrix[u][w] = 1;
            matrix[w][u] = 1;
        }
    }

    void findReachableVertices(int v)
    {
        vector<int> close(v, 0);
        queue<int> open;
        vector<int> result;

        open.push(0);
        close[0] = 1;

        while (!open.empty())
        {
            int p = open.front();
            open.pop();

            result.push_back(p);

            for (int q = 0; q < v; q++)
            {
                if (matrix[p][q] == 1 && close[q] == 0)
                {
                    close[q] = 1;
                    open.push(q);
                }
            }
        }

        sort(result.begin(), result.end());

        vector<int> reachable;
        for (size_t i = 1; i < result.size(); i++)
        {
            reachable.push_back(result[i]);
        }

        if (reachable.empty())
        {
            cout << "KHONG\n";
        }
        else
        {
            for (size_t i = 0; i < reachable.size(); i++)
            {
                if (i > 0)
                    cout << " ";
                cout << reachable[i];
            }
            cout << "\n";
        }
    }
};

int main()
{
    int v, e;
    cin >> v >> e;

    Graph G;
    G.inputGraph(v, e);
    G.findReachableVertices(v);

    return 0;
}
