#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

bool IsAlphabet(char c)
{
    return isalpha(c);
}

int main()
{
    int n;
    cin >> n;

    vector<bool> Characters(26, false);

    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;

        if (IsAlphabet(c))
        {
            c = tolower(c);
            int index = c - 'a';
            Characters[index] = true;
        }
    }

    int CountCharacters = 0;
    
    for (bool present : Characters)
    {
        if (!present)
        {
            ++CountCharacters;
        }
    }

    cout << CountCharacters << endl;

    return 0;
}