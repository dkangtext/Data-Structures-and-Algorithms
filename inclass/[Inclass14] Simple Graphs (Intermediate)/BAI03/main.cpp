#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Graph {
    vector<vector<int>> matrix;
    vector<string> names;

public:
    map<string, int> toIndex;

    void inputGraph(int v) {
        matrix = vector<vector<int>>(v, vector<int>(v, 0));
        names.resize(v);
        string x;

        for (int i = 0; i < v; i++) {
            cin >> x;
            names[i] = x;
            toIndex[x] = i;
        }

        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    void BFS(int v, int x, int y) {
        vector<int> close(v, 0);
        vector<int> visited(v, 0);
        queue<int> open;

        map<int, int> parent;
        parent[x] = -1; // Đánh dấu đỉnh nguồn không có cha

        bool found = false;
        int countClose = 0;
        int length = 0;

        open.push(x);

        while (!open.empty()) {
            int p = open.front();
            open.pop();

            if (close[p] == 1)
                continue;

            close[p] = 1;
            countClose++;

            if (p == y) {
                found = true;
                break;
            }

            for (int q = 0; q < v; q++) {
                if (matrix[p][q] > 0 && visited[q] == 0 && close[q] == 0) {
                    open.push(q);
                    visited[q] = 1;
                    parent[q] = p;
                }
            }
        }

        if (!found) {
            cout << "-unreachable-\n";
            cout << countClose << " " << 0 << "\n";
        } else {
            vector<string> path;
            int cur = y;

            while (cur != -1) {
                path.push_back(names[cur]);
                if (parent[cur] != -1) {
                    length += matrix[parent[cur]][cur];
                }
                cur = parent[cur];
            }

            reverse(path.begin(), path.end()); // Đảo ngược để in đường đi từ x -> y
            for (size_t i = 0; i < path.size(); i++) {
                if (i > 0) cout << " ";
                cout << path[i];
            }
            cout << "\n" << countClose << " " << length << "\n";
        }
    }
};

int main() {
    Graph G;
    int v, n;
    cin >> v >> n;

    string x, y;

    G.inputGraph(v);

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        G.BFS(v, G.toIndex[x], G.toIndex[y]);
    }

    return 0;
}
