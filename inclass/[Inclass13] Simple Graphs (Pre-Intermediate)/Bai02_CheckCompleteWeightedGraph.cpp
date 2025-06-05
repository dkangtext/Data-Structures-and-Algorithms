#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Graph
{
    // Ma tran ke
    vector<vector<int>> matrix;

    // Danh sach ten cac dinh
    vector<string> names;

    // Anh xa tu ten dinh den index trong ma tran
    map<string, int> toIndex;

public:
    //

    void addEdge(const string &u, const string &v)
    {
        if (toIndex.find(u) == toIndex.end())
        {
            toIndex[u] = names.size();
            names.push_back(u);
            matrix.push_back(vector<int>(names.size(), 0));
            for (auto &row : matrix)
            {
                row.resize(names.size(), 0);
            }
        }
        if (toIndex.find(v) == toIndex.end())
        {
            toIndex[v] = names.size();
            names.push_back(v);
            matrix.push_back(vector<int>(names.size(), 0));
            for (auto &row : matrix)
            {
                row.resize(names.size(), 0);
            }
        }
        matrix[toIndex[u]][toIndex[v]] = 1;
    }

    bool isComplete()
    {
        int n = names.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i != j && (matrix[i][j] == 0 || matrix[j][i] == 0))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    int e;
    cin >> e;

    Graph G;
    for (int i = 0; i < e; ++i)
    {
        string u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }

    if (G.isComplete())
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
    
    return 0;
}