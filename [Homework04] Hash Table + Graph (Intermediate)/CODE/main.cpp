#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

vector<int> get_ans(const vector<int>& A, int K) {
    map<int, int> Hash; // Lưu số lượng xuất hiện của từng màu
    vector<int> result;

    // Đếm số lần xuất hiện của mỗi màu
    for (int color : A) {
        Hash[color]++;
    }

    // Chọn ra k màu
    for (auto& [color, count] : Hash) {
        if (result.size() < K) {
            result.push_back(color);
        } else {
            break; // Dừng lại nếu đã chọn đủ k màu
        }
    }

    // Nếu số màu chưa đủ k, thêm các màu lặp lại
    while (result.size() < K) {
        result.push_back(result.back());
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans = get_ans(a, k);

    for (const int& x : ans) cout << x << ' ';
    return 0;
}
