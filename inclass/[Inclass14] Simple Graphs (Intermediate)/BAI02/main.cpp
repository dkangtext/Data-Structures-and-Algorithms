#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Graph
{
    vector<vector<int>> matrix;

public:
    void inputMatrix(int n)
    {
        matrix = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }

    void convertAdjacencyList()
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            vector<int> adjacencyList;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 1)
                {
                    adjacencyList.push_back(j + 1);
                }
            }

            if (!adjacencyList.empty())
            {
                cout << i + 1 << "->";
                for (int k = 0; k < adjacencyList.size(); k++)
                {
                    cout << adjacencyList[k];
                    if (k < adjacencyList.size() - 1)
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph G;

    int n;
    cin >> n;

    G.inputMatrix(n);
    G.convertAdjacencyList();

    return 0;
}
