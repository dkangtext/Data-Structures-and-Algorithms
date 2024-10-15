#include <iostream>
#include <stack>
#include <vector>

using namespace std;

long long demCapCoTheNhinThay(const vector<int> &chieuCao)
{
    stack<pair<int, int>> s;
    long long ketQua = 0;

    for (int i = 0; i < chieuCao.size(); i++)
    {
        int Dem = 1;

        while (!s.empty() && s.top().first <= chieuCao[i])
        {
            ketQua += s.top().second;
            if (s.top().first == chieuCao[i])
            {
                Dem += s.top().second;
            }
            s.pop();
        }

        if (!s.empty())
        {
            ketQua++;
        }

        s.push({chieuCao[i], Dem});
    }

    return ketQua;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    vector<int> chieuCao(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> chieuCao[i];
    }

    cout << demCapCoTheNhinThay(chieuCao) << endl;
    return 0;
}
