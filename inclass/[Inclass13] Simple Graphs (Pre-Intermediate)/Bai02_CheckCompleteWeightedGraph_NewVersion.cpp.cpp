#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

class Graph
{
    // Vì không biết trước số đỉnh nên phải chọn danh sách kề
    map<string, set<string>> adj_list;

public:
    void inputGraph(int e)
    {
        for (int i = 0; i < e; i++)
        {
            string x, y;
            cin >> x >> y;
            adj_list[x].insert(y);
        }
    }

    bool isCompleteGraph( )
    {
        for (auto i = adj_list.begin(); i != adj_list.end(); i++)
        {
            if (i->second.size() != adj_list.size() - 1)
            {
                return false;
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
    G.inputGraph(e);

    if (G.isCompleteGraph())
    {
        cout << "TRUE";
    }
    else
    {
        cout << "FALSE";
    }

    return 0;
}