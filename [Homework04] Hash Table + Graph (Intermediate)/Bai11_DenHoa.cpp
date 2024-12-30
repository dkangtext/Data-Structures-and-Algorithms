/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multi_set
merge
###End banned keyword*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

vector<int> get_ans(const vector<int> &A, int K)
{
	map<int, int> Hash;
	vector<int> result;

	// Đếm tần suất từ cả hai đoạn code
	for (int color : A)
	{
		Hash[color]++;
	}

	// Tìm tần suất lớn nhất từ đoạn 1
	int maxFreq = 0;
	for (const auto &it : Hash)
	{
		maxFreq = max(maxFreq, it.second);
	}

	// Tạo mảng freqColors như đoạn 1
	vector<vector<int>> freqColors(maxFreq + 1);
	for (const auto &it : Hash)
	{
		freqColors[it.second].push_back(it.first);
	}

	// Thêm các phần tử theo thứ tự tăng dần từ đoạn 2
	for (auto &[color, count] : Hash)
	{
		if (result.size() < K)
		{
			result.push_back(color);
		}
		else
		{
			break;
		}
	}

	// Nếu chưa đủ K phần tử, thêm từ phần tử cuối như đoạn 2
	while (result.size() < K)
	{
		result.push_back(result.back());
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> ans = get_ans(a, k);

	for (const int &x : ans)
		cout << x << ' ';
	return 0;
}
