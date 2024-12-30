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

    void BFS(int v, int start, vector<int>& visited)
    {
        queue<int> open;
        open.push(start);
        visited[start] = 1;

        while (!open.empty())
        {
            int p = open.front();
            open.pop();

            for (int q = 0; q < v; q++)
            {
                if (matrix[p][q] == 1 && visited[q] == 0)
                {
                    visited[q] = 1;
                    open.push(q);
                }
            }
        }
    }

    int demThanhPhanLienThong(int v)
    {
        vector<int> visited(v, 0);
        int components = 0;

        for (int i = 0; i < v; i++)
        {
            if (visited[i] == 0)
            {
                BFS(v, i, visited);
                components++;
            }
        }

        return components;
    }
};

int main()
{
    int v, e;
    cin >> v >> e;

    Graph G;
    G.inputGraph(v, e);
    cout << G.demThanhPhanLienThong(v) << endl;

    return 0;
}
