#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
    // Ma trận kề
    vector<vector<int>> matrix;
    // Danh sách tên các đỉnh
    vector<string> names;
    // Ánh xạ từ tên đỉnh sang chỉ số trong ma trận
    map<string, int> toIndex;

public:
    void inputGraph(int v, int e)
    { // v: số đỉnh, e: số cạnh
        // Bước 1: Cấp phát vùng nhớ cho ma trận và danh sách tên đỉnh
        matrix = vector<vector<int>>(v, vector<int>(v, 0));
        names = vector<string>(v, "");

        // Bước 2: Nhập danh sách tên các đỉnh
        for (int i = 0; i < v; i++)
        {
            string x;
            cin >> x;
            names[i] = x;
            toIndex[x] = i;
        }

        // Bước 3: Nhập ma trận kề
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }

    void DFS(int startIdx, int goalIdx)
    {
        stack<string> Open;
        Open.push(names[startIdx]);

        vector<bool> Close(names.size(), false);
        bool found = false;
        map<string, string> parent;
        int developedNodes = 0;
        int pathLength = 0;

        while (!Open.empty())
        {
            // Lấy đỉnh đầu tiên từ stack Open
            string p = Open.top();
            Open.pop();

            if (Close[toIndex[p]])
                continue;
            Close[toIndex[p]] = true;
            developedNodes++;

            // Kiểm tra xem đỉnh hiện tại có phải đỉnh cần tìm không
            if (p == names[goalIdx])
            {
                found = true;
                break;
            }

            // Thêm các đỉnh kề vào Open theo thứ tự danh sách names
            for (int i = names.size() - 1; i >= 0; i--)
            {
                if (matrix[toIndex[p]][i] > 0 && !Close[i])
                {
                    Open.push(names[i]);
                    parent[names[i]] = p;
                }
            }
        }

        if (!found)
        {
            cout << "-unreachable-" << endl;
            cout << developedNodes << " 0" << endl;
        }
        else
        {
            // Tạo và in đường đi từ đỉnh bắt đầu đến đỉnh đích
            vector<string> path;
            string current = names[goalIdx];
            while (current != names[startIdx])
            {
                path.push_back(current);
                pathLength += matrix[toIndex[parent[current]]][toIndex[current]];
                current = parent[current];
            }
            path.push_back(names[startIdx]);

            for (int i = path.size() - 1; i >= 0; i--)
            {
                cout << path[i];
                if (i > 0)
                    cout << " ";
            }
            cout << endl;

            cout << developedNodes << " " << pathLength << endl;
        }
    }

    void process(int n)
    {
        for (int i = 0; i < n; i++)
        {
            string start, goal;
            cin >> start >> goal;
            DFS(toIndex[start], toIndex[goal]);
        }
    }
};

int main()
{
    Graph G;

    int v, n;
    cin >> v >> n;

    G.inputGraph(v, n);
    G.process(n);

    return 0;
}
