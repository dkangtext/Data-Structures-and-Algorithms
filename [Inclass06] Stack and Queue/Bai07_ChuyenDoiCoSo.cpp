#include <iostream>
#include <stack>

using namespace std;

void DecimaltoBinary(int n) 
{
    stack<int> Binary;  

    if (n == 0) 
    {
        cout << "0";
        return;
    }

    while (n > 0) 
    {
        Binary.push(n % 2);  
        n = n / 2;  
    }

    while (!Binary.empty()) 
    {
        cout << Binary.top();  
        Binary.pop();  
    }
}

int main() 
{
    int n;
    cin >> n;  

    DecimaltoBinary(n);  

    return 0;
}
