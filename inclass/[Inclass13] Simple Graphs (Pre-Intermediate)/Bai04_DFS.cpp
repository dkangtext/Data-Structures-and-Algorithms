#include <iostream>
#include <map>
#include <vector> 
#include <stack>

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

    void inputGraph(int v, int e) // v: so dinh - e: so canh
    {
        // Bước 1: Cap phat vung nho cac mang
        matrix = vector<vector<int>>(v, vector<int>(v, 0));
        // Tạo 1 vector có v phần tử, trong đó mỗi phần tử là 1 vector<int>(v, 0)
                                    // Tức là 1 vector chứa v giá trị i, khởi tạo toàn 0

        names = vector<string>(v, ""); 
        // Cấp phát names là 1 vector có v phần tử, mỗi phần tử là 1 string rỗng

        // Bước 2: Nhập danh sách tên các đỉnh
        for (int i = 0; i < v; i++)
        {
            string x;
            cin >> x; // Nhập tên đỉnh
            names[i] = x; // Lưu tên đỉnh vào vector names
            toIndex[x] = i; // Lưu index của đỉnh vào map toIndex
        }

        // Bước 3:Nhập ma trận trong số
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }

    void DFS (int s, int g)
    {
        int v = names.size(); // Số đỉnh của đồ thị

        // Bước 1: Khởi tạo
        stack<string> Open; // Open := {s};
        Open.push(names[s]);

        vector<bool> Close(v, false); // Close := {};

        bool found = false; // Biến kiểm tra xem đã tìm thấy đỉnh g chưa

        map<string, string> parent; // Lưu đường đi

        // Bước 2: 
        while (!Open.empty())
        {
            // 2.1 Lấy p từ đầu Open (xóa p khỏi Open)

            string p = Open.top(); // Lấy phần tử đầu tiên của Open
            Open.pop(); // Xóa phần tử đầu tiên của Open

            // 2.2 Nếu p là trạng thái kết thúc thì thoát, thông báo kết quả. 

            if (p == names[g])
            {
                found = true;
                break;
            }

            // 2.3 Bỏ p vào Close

            Close[toIndex[p]] = 1;

            // 2.4 Với mỗi đỉnh q kề với p. Nếu q không thuộc Close thì bỏ q vào Open

            for (int i = names.size() - 1; i >= 0; i--)
            {
                if (matrix[toIndex[p]][i] > 0 && Close[i] == 0)
                {
                    Open.push(names[i]);
                    parent[names[i]] = p;
                }
            }
        }

        // Bước 3: Không tìm thấy kết quả hoặc xuất đường đi

        if (found == false)
        {
            cout << "-unreachable-" << endl;
        }
        else 
        {
            string current = names[g];

            while(current != names[s])
            {
                cout << current;
                current = parent[current];
            }
        }
    }

    void process (int n) // n là số đường đi cần tìm
    {
        for (int i = 0; i < n; i++)
        {
            string s, g;
            cin >> s >> g;
            DFS(toIndex[s], toIndex[g]);
            cout << endl;
        }
    }   
};

int main()
{
    Graph G;
    
    int v, e;
    cin >> v >> e;
    
    G.inputGraph(v, e);
    
    int n;
    cin >> n;

    G.process(n);
    
    
    return 0;
}