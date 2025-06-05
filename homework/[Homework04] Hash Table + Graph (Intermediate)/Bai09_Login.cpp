#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    map<string, vector<string>> Database;

    for (int i = 0; i < N; i++)
    {
        string username, password;
        cin >> username >> password;
        Database[username].push_back(password); 
    }

    for (int i = 0; i < Q; i++)
    {
        string user;
        cin >> user;

        if (Database.find(user) != Database.end())
        {
            for (size_t j = 0; j < Database[user].size(); j++)
            {
                if (j > 0) cout << " ";
                cout << Database[user][j];
            }
            cout << endl;
        }
        else
        {
            cout << "Chua Dang Ky!" << endl;
        }
    }

    return 0;
}
