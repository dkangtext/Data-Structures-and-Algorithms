#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

void check_horizontal(int n, int m, const vector<string> &grid, unordered_map<string, bool> &pattern_map, int max_pattern_length)
{
    for (const string &row : grid)
    {
        for (int start = 0; start < m; ++start)
        {
            string substring;
            for (int length = 0; length < max_pattern_length && start + length < m; ++length)
            {
                substring += row[start + length];
                if (substring.size() >= 2 && pattern_map.count(substring))
                {
                    pattern_map[substring] = true;
                }
            }
        }
    }
}

void check_vertical(int n, int m, const vector<string> &grid, unordered_map<string, bool> &pattern_map, int max_pattern_length)
{
    for (int col = 0; col < m; ++col)
    {
        for (int start = 0; start < n; ++start)
        {
            string substring;
            for (int length = 0; length < max_pattern_length && start + length < n; ++length)
            {
                substring += grid[start + length][col];
                if (substring.size() >= 2 && pattern_map.count(substring))
                {
                    pattern_map[substring] = true;
                }
            }
        }
    }
}

string check_patterns(const vector<string> &patterns, const unordered_map<string, bool> &pattern_map)
{
    string result;
    for (const string &pattern : patterns)
    {
        result += pattern_map.at(pattern) ? '1' : '0';
    }
    return result;
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
    }

    vector<string> patterns(q);
    unordered_map<string, bool> pattern_map;
    int max_pattern_length = 0;
    for (int i = 0; i < q; ++i)
    {
        cin >> patterns[i];
        pattern_map[patterns[i]] = false;
        max_pattern_length = max(max_pattern_length, (int)patterns[i].size());
    }

    check_horizontal(n, m, grid, pattern_map, max_pattern_length);
    check_vertical(n, m, grid, pattern_map, max_pattern_length);

    cout << check_patterns(patterns, pattern_map) << endl;

    return 0;
}
