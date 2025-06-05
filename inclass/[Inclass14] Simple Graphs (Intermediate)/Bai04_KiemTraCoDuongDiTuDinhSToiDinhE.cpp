/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
// ###INSERT CODE HERE -

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Graph
{
    vector<vector<int>> danhSachKe;

public:
    void inputGraph(int m, int n)
    {
        danhSachKe.resize(m);

        int u, v;
        for (int i = 0; i < n; i++)
        {
            cin >> u >> v;
            danhSachKe[u].push_back(v);
            danhSachKe[v].push_back(u);
        }
    }

    void kiemTraDuongDi(int m)
    {
        vector<bool> daTham(m, false);
        queue<int> hangDoi;

        hangDoi.push(0);
        daTham[0] = true;

        while (!hangDoi.empty())
        {
            int dinh = hangDoi.front();
            hangDoi.pop();

            for (int ke : danhSachKe[dinh])
            {
                if (!daTham[ke])
                {
                    daTham[ke] = true;
                    hangDoi.push(ke);
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            if (daTham[i])
            {
                cout << "CO\n";
            }
            else
            {
                cout << "KHONG\n";
            }
        }
    }
};

int main()
{
    int m, n;
    cin >> m >> n;

    Graph G;
    G.inputGraph(m, n);

    G.kiemTraDuongDi(m);

    return 0;
}
