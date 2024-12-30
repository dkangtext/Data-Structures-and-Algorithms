#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

class Graph
{
    vector<vector<int>> matrix;
    vector<string> vertices;
    map<string, int> toIndex;

public:
    void inputGraph(int e)
    {
        map<string, bool> vertexMap;
        vector<tuple<string, string, int>> edges;
        string u, v;
        int d;

        for (int i = 0; i < e; i++)
        {
            cin >> u >> v >> d;
            edges.push_back({u, v, d});
            vertexMap[u] = true;
            vertexMap[v] = true;
        }

        for (const auto &entry : vertexMap)
        {
            vertices.push_back(entry.first);
        }

        sort(vertices.begin(), vertices.end());
        int n = vertices.size();
        matrix.assign(n, vector<int>(n, numeric_limits<int>::max()));

        for (size_t i = 0; i < vertices.size(); i++)
        {
            toIndex[vertices[i]] = i;
            matrix[i][i] = 0;
        }

        for (const auto &edge : edges)
        {
            int from = toIndex[get<0>(edge)];
            int to = toIndex[get<1>(edge)];
            matrix[from][to] = get<2>(edge);
            matrix[to][from] = get<2>(edge);
        }
    }

    void heuristicPath(const string &start)
    {
        int n = vertices.size();
        int current = toIndex[start];
        vector<bool> visited(n, false);
        vector<string> path;
        int totalDistance = 0;

        path.push_back(start);
        visited[current] = true;

        while (path.size() < n)
        {
            int next = -1;
            int minDist = numeric_limits<int>::max();

            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && matrix[current][i] < minDist)
                {
                    minDist = matrix[current][i];
                    next = i;
                }
            }

            if (next == -1)
            {
                break; // Không tìm được đỉnh tiếp theo, thoát vòng lặp
            }

            visited[next] = true;
            path.push_back(vertices[next]);
            totalDistance += minDist;
            current = next;
        }

        if (path.size() == n)
        {
            path.push_back(start);
            totalDistance += matrix[current][toIndex[start]];

            for (size_t i = 0; i < path.size(); i++)
            {
                if (i > 0)
                    cout << " ";
                cout << path[i];
            }
            cout << "\n";
        }
    }
};

int main()
{
    int e;
    string start;
    cin >> e >> start;

    Graph G;
    G.inputGraph(e);
    G.heuristicPath(start);

    return 0;
}
