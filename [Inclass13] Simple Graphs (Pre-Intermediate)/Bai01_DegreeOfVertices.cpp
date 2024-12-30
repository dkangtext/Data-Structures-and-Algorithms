#include<iostream>
#include<map>
#include<vector> 

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

        // Bước 3:Nhập danh sách cạnh và lưu thông tin vào ma trận kề
        for (int i = 0; i < e; i++)
        {
            string x, y; 
            cin >> x >> y;  // Nhập cạnh
            int u = toIndex[x], v = toIndex[y];  // Lấy index của 2 đỉnh x, y
            matrix[u][v] = matrix[v][u] = 1; // Gán 1 cho 2 đỉnh x, y
        }
    }

    int degreeOfVertex(int index) //Đầu vào là index của đỉnh đang xét
    {
        int deg = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            deg += matrix[index][i]; // Đếm số cạnh nối đỉnh index với các đỉnh khác
        }
        return deg;
    }

    void degreeOfVertices( ) // Đếm bậc của tất cả các đỉnh
    {
        for (int i = 0; i < names.size(); i++)
        {
            // cout << names[i] << " " << degreeOfVertex(i) << endl;

            cout << degreeOfVertex(i) << " ";
        }
    }
};

int main()
{
    Graph G;
    
    int v, e;
    cin >> v >> e;
    
    G.inputGraph(v, e);
    G.degreeOfVertices();
    
    return 0;
}