/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// ###INSERT CODE HERE -

class Graph
{
    int v, e;
    map<string, int> nameToIndex;
    vector<string> indexToName;
    vector<vector<int>> G;

public:
    
    void nhap(int v, int e)
    {
        this->v = v;
        this->e = e;
        G.resize(v);
        
        for (int i = 0; i < v; i++)
        {
            G[i].resize(v);
        }

        for (int i = 0; i < v; i++)
        {
            string name;
            cin >> name;
            nameToIndex[name] = i;
            indexToName.push_back(name);
        }

        for (int i = 0; i < e; i++)
        {
            string a, b;
            cin >> a >> b;
            G[nameToIndex[a]][nameToIndex[b]] = 1;
        }
    }

    void myProcess(int n)
    {
        for (int i = 0; i < n; i++)
        {
            int type;
            cin >> type;
            
            if (type == 1) 
            {
                string a, b;
                cin >> a >> b;
                
                if (G[nameToIndex[a]][nameToIndex[b]] == 1)
                {
                    cout << "TRUE" << endl;
                }
                else 
                {
                    cout << "FALSE" << endl;
                }
                cout << endl;
                continue;
            }
            else if (type == 2) 
            {
                string a;
                cin >> a;

                int count = 0;

                for (int i = 0; i < v; i++)
                {
                    if (G[nameToIndex[a]][i] == 1)
                    {
                        count++;
                        cout << indexToName[i] << " ";
                    }
                }

                if (count == 0)
                {
                    cout << "NONE";
                }
                cout << endl;
                continue;
            }
        }
    }
};

int main()
{
    Graph G;
    int v, e, n;
    cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}
