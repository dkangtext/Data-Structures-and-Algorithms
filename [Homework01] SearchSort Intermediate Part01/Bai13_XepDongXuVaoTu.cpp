/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;

//###INSERT CODE HERE -

int countFullStacks(int n) 
{
    vector<int> stacks; 
    int k = 1; 
    
    while (n >= k) 
    {
        stacks.push_back(k);  
        n = n - k; 
        k++;  
    }

    return stacks.size();
}

int main() 
{
    int n;
    cin >> n;

    cout << countFullStacks(n) << endl;
    
    return 0;
}