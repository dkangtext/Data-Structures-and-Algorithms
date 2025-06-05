#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class DirectedGraph
{
private:
    unordered_map<string, unordered_set<string>> adjacency_list;

public:
    void addVertex(const string &vertex)
    {
        if (adjacency_list.count(vertex))
        {
            cout << "DUP\n";
        }
        else
        {
            adjacency_list[vertex] = unordered_set<string>();
            cout << "ADD\n";
        }
    }

    void addEdge(const string &from, const string &to)
    {
        bool newFrom = false, newTo = false;

        if (!adjacency_list.count(from))
        {
            adjacency_list[from] = unordered_set<string>();
            newFrom = true;
        }
        if (!adjacency_list.count(to))
        {
            adjacency_list[to] = unordered_set<string>();
            newTo = true;
        }

        if (adjacency_list[from].count(to))
        {
            cout << "DUP2\n";
        }
        else
        {
            adjacency_list[from].insert(to);
            if (newFrom || newTo)
            {
                cout << "ADD2\n";
            }
            else
            {
                cout << "ADD3\n";
            }
        }
    }

    void checkAdjacent(const string &u, const string &v)
    {
        if (adjacency_list.count(u) && adjacency_list[u].count(v))
        {
            cout << "TRUE\n";
        }
        else
        {
            cout << "FALSE\n";
        }
    }

    void countNeighbors(const string &vertex)
    {
        if (adjacency_list.count(vertex))
        {
            cout << adjacency_list[vertex].size() << "\n";
        }
        else
        {
            cout << "0\n";
        }
    }
};

int main()
{
    DirectedGraph graph;
    string line;

    while (getline(cin, line))
    {
        if (line == "0")
        {
            break;
        }

        vector<string> tokens;
        size_t pos = 0;
        while ((pos = line.find(' ')) != string::npos)
        {
            tokens.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        tokens.push_back(line);

        int command = stoi(tokens[0]);
        if (command == 1)
        {
            graph.addVertex(tokens[1]);
        }
        else if (command == 2)
        {
            graph.addEdge(tokens[1], tokens[2]);
        }
        else if (command == 3)
        {
            graph.checkAdjacent(tokens[1], tokens[2]);
        }
        else if (command == 4)
        {
            graph.countNeighbors(tokens[1]);
        }
    }

    return 0;
}
