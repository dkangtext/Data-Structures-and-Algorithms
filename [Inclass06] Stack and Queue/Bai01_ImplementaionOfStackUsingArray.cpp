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

    for (int i = 0; i < MAX; i++)
    {
        S.arr[i] = NULLDATA;
    }
}

int isFull(Stack S)
{
    if (S.n == MAX)
    {
        return true;
    }
    return false;
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

int isEmpty(Stack S)
{
    if (S.n == 0)
    {
        return true;
    }
    return false;
}

void Pop(Stack &S)
{
    if(isEmpty(S))
    {
        return;
    }
    
    if (S.n > 0)
    {
        S.n--;
    }
}

void printStack(Stack S)
{
    if (S.n == 0)
    {
        cout << "Stack is empty";
        return;
    }

    for (int i = 0; i < S.n; i++)
    {
        cout << S.arr[i] << " ";
    }
}

int Top(Stack S)
{
    if (S.n > 0)
    {
        return S.arr[S.n - 1];
    }
    return NULLDATA;
}

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    for (int i= 1; i<=n; i++)
    {
        cin>>x;
        Push(S,x);

    }
    cout<<"Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    Pop(S);
    cout<<"\nUpdated Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    return 0;
}