#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class VuongQuoc
{
private:
    int m, n;
    vector<vector<int>> banDo;
    const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

public:
    void inputGraph(int m, int n, const vector<vector<int>> &banDoInput)
    {
        this->m = m;
        this->n = n;
        banDo = banDoInput;
    }

    bool hopLe(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n && banDo[x][y] == 0;
    }

    int BFS(int startX, int startY, int endX, int endY)
    {
        // Chuyển đổi tọa độ theo hệ index ngược
        startX = m - 1 - startX;
        endX = m - 1 - endX;

        // Nếu điểm đầu hoặc điểm cuối không hợp lệ
        if (!hopLe(startX, startY) || !hopLe(endX, endY))
        {
            return -1;
        }

        // Trường hợp đặc biệt: điểm đầu trùng điểm cuối
        if (startX == endX && startY == endY)
        {
            return 0;
        }

        // Mảng đánh dấu các ô đã thăm và lưu khoảng cách
        vector<vector<int>> d(m, vector<int>(n, -1));
        queue<pair<int, int>> open;

        // Khởi tạo điểm xuất phát
        open.push({startX, startY});
        d[startX][startY] = 0;

        // BFS
        while (!open.empty())
        {
            int x = open.front().first;
            int y = open.front().second;
            open.pop();

            // Thử đi theo 8 hướng
            for (int i = 0; i < 8; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                // Kiểm tra ô mới có hợp lệ và chưa thăm
                if (hopLe(newX, newY) && d[newX][newY] == -1)
                {
                    d[newX][newY] = d[x][y] + 1;
                    open.push({newX, newY});

                    // Nếu đến đích, trả về khoảng cách
                    if (newX == endX && newY == endY)
                    {
                        return d[newX][newY];
                    }
                }
            }
        }

        return -1; // Không tìm thấy đường đi
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, startX, startY, endX, endY;
    cin >> m >> n >> startX >> startY >> endX >> endY;

    vector<vector<int>> banDo(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> banDo[i][j];
        }
    }

    VuongQuoc vuongQuoc;
    vuongQuoc.inputGraph(m, n, banDo);

    cout << vuongQuoc.BFS(startX, startY, endX, endY) << endl;

    return 0;
}
