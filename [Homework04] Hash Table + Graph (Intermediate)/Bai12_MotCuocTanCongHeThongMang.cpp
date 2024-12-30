#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(int start, const vector<vector<int>> &graph, vector<bool> &visited, vector<int> &infected)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        infected.push_back(current);

        for (int neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int s;
    cin >> s;

    vector<bool> visited(n + 1, false);
    vector<int> infected;

    bfs(s, graph, visited, infected);

    sort(infected.begin(), infected.end());

    cout << infected.size() << endl;
    for (int computer : infected)
    {
        cout << computer << " ";
    }

    return 0;
}
