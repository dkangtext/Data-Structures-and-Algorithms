/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};

//###INSERT CODE HERE -

void Init(Stack &S)
{
    S.n = 0;
}

int isFull(Stack S)
{
    if (S.n == MAX)
    {
        return 1;
    }
    return 0;
}

void Push(Stack &S, int x)
{
    if(isFull(S))
    {
        return;
    }

    S.arr[S.n] = x;
    S.n++;
}

void printStack(Stack S)
{
    for (int i = S.n - 1; i >= 0; i--)
    {
        cout << S.arr[i];
    }
}

void DecimaltoBinary2(int n, Stack &S)
{
    if (n == 0)
    {
        Push(S, 0);  
        return;
    }

    while (n > 0)
    {
        Push(S, n % 2);  
        n = n / 2;      
    }
}

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary2(n,S);
    printStack(S);
    return 0;
}




