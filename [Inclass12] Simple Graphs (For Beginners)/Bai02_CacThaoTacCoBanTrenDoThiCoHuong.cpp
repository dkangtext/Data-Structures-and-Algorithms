/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;

// ###INSERT CODE HERE -

void inputGraph(vector<vector<int>> &G, int v, int e)
{
	G.resize(v);
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a - 1].push_back(b);
	}
}

void simpleSort(vector<int> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i + 1; j < a.size(); j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

void process(const vector<vector<int>> &G, int v, int n)
{
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;

		if (type == 1)
		{ // Kiểm tra tính kề của hai đỉnh
			int u, w;
			cin >> u >> w;
			bool check = false;
			for (int j = 0; j < G[u - 1].size(); j++)
			{
				if (G[u - 1][j] == w)
				{
					check = true;
					break;
				}
			}
			if (check)
				cout << "TRUE" << endl;
			else
				cout << "FALSE" << endl;
		}
		else if (type == 2)
		{ 
			int u;
			cin >> u;
			if (G[u - 1].empty())
			{
				cout << "NONE" << endl;
			}
			else
			{
				vector<int> neighbors = G[u - 1];
				simpleSort(neighbors);
				for (int j = 0; j < neighbors.size(); j++)
				{
					if (j > 0)
					{ // In ra khoảng trắng trước mỗi phần tử
						cout << " ";
					}
					cout << neighbors[j];
				}
				cout << endl;
			}
		}
	}
}

int main()
{

	int v, e, n;
	cin >> v >> e >> n; // v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int>> G;

	inputGraph(G, v, e);
	process(G, v, n);

	return 0;
}
