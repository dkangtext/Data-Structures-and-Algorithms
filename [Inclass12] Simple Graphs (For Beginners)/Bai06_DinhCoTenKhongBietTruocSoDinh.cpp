#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>

using namespace std;

class Graph
{
    int v, e;
    map<string, set<string>> G;

public:
    
    // Hàm nhập vào đồ thị
    void nhap(int e)
    {
          this->e = e;

        for (int i = 0; i < e; i++)
        {
            string a, b;
            cin >> a >> b;
            G[a].insert(b);
            G[b].insert(a);
        }

        v = G.size();
    }

    // Hàm xử lý các thao tác
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
                G[a].insert(b);
                G[b].insert(a);
            }
            else if (type == 2)
            {
                string a, b;
                cin >> a >> b;
                G[a].erase(b);
                G[b].erase(a);
            }
            else if (type == 3)
            {
                string a;
                cin >> a;
                cout << G[a].size() << endl;
            }
            else if (type == 4)
            {
                string a;
                cin >> a;
                for (auto x : G[a])
                {
                    cout << x << " ";
                }
                cout << endl;
            }
            else if (type == 5)
            {
                string a, b;
                cin >> a >> b;
                if (G[a].find(b) != G[a].end())
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    }
};