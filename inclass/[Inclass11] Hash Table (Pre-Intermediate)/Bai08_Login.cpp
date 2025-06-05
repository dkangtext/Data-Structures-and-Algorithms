#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    map<string, string> Database;

    for (int i = 0; i < N; i++)
    {
        string username, password;
        cin >> username >> password;
        Database[username] = password;
    }

    for (int i = 0; i < Q; i++)
    {
        string user;
        cin >> user;

        if (Database.find(user) != Database.end())
        {
            cout << Database[user] << endl;
        }
        else
        {
            cout << "Chua Dang Ky!" << endl;
        }
    }

    return 0;
}