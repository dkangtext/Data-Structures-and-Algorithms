#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

class compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
            // Nếu khoảng cách bằng nhau, ưu tiên đỉnh nhập sau
            return a.second < b.second;
        // Ưu tiên khoảng cách nhỏ hơn
        return a.first > b.first;
    }
};

class Graph
{
    vector<vector<int>> matrix; // Ma trận kề
    vector<string> names;       // Tên các đỉnh
    map<string, int> toIndex;   // Map tên đỉnh với chỉ số của nó

public:
    void inputGraph(int v)
    {
        matrix = vector<vector<int>>(v, vector<int>(v, 0));
        names = vector<string>(v);

        // Nhập danh sách các đỉnh
        for (int i = 0; i < v; i++)
        {
            cin >> names[i];
            toIndex[names[i]] = i;
        }

        // Nhập ma trận kề
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }

    void outputGraph(int v)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }

    void Dijsktra(string x, string y)
    {
        int s = toIndex[x];
        int g = toIndex[y];
        int v = matrix.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> open;
        // Ví dụ: open = {(20, 0), (35, 1)};

        vector<bool> close(v, false); // close[i] = true nếu i đã được xét
        vector<int> d(v, INT_MAX);    // Khởi tạo ban đầu của tất cả các đỉnh là cộng vô cùng
        vector<int> parent(v, -1);

        int count = 0; // Đếm số đỉnh
        d[s] = 0;
        open.push({0, s});

        while (!open.empty())
        {
            int p = open.top().second;
            open.pop();

            if (close[p])
                continue;

            close[p] = true;
            count++;

            if (p == g)
                break;

            for (int q = v - 1; q >= 0; q--)
            {
                if (matrix[p][q] > 0 && !close[q])
                {
                    int d_new = d[p] + matrix[p][q];
                    if (d_new < d[q])
                    {
                        d[q] = d_new;
                        parent[q] = p;
                        open.push({d_new, q});
                    }
                }
            }
        }


        // Xuất kết quả
        if (d[g] == INT_MAX)
        {
            cout << "-unreachable-" << endl;
            cout << count << " " << 0 << endl;
            return;
        }

        vector<int> duongDi;
        int viTriHienTai = g;

        while (viTriHienTai != -1)
        {
            duongDi.push_back(viTriHienTai);
            viTriHienTai = parent[viTriHienTai];
        }

        reverse(duongDi.begin(), duongDi.end());

        for (int diem : duongDi)
        {
            cout << names[diem] << " ";
        }
        cout << endl;

        cout << count << " " << d[g] << endl;
    }
};

int main()
{
    Graph G;
    int v, n;
    cin >> v >> n;

    G.inputGraph(v);

    string x, y;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        G.Dijsktra(x, y);
    }

    return 0;
}