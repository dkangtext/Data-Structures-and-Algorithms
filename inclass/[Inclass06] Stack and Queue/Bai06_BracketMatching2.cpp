#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    char arr[MAX];
    int n; 
};

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

void Pop(Stack &S)
{
    if (S.n > 0)
    {
        S.n--;
    }
}

int isValid(string s)
{
    Stack(S);
    Init(S);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            Push(S, s[i]);
        }
        else if (s[i] == ')'|| s[i] == ']' || s[i] == '}')
        {
            if (S.n == 0)
            {
                return 0;
            }
            Pop(S);
        }
    }

    if (S.n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}

// #include<string>
// #include<cstring>
// #include <iostream>

// #define MAX 2000
// #define NULLDATA -1

// using namespace std;

// struct Stack
// {
//     char arr[MAX];
//     int n; 
// };

// void Init(Stack &S)
// {
//     S.n = 0;

//     for (int i = 0; i < MAX; i++)
//     {
//         S.arr[i] = NULLDATA;
//     }
// }

// int isFull(Stack S)
// {
//     if (S.n == MAX)
//     {
//         return 1;
//     }
//     return 0;
// }

// void Push(Stack &S, int x)
// {
//     if(isFull(S))
//     {
//         return;
//     }

//     S.arr[S.n] = x;
//     S.n++;
// }

// int isEmpty(Stack S)
// {
//     if (S.n == 0)
//     {
//         return 1;
//     }
//     return 0;
// }

// void Pop(Stack &S)
// {
//     if (S.n > 0)
//     {
//         S.n--;
//     }
// }

// int Top(Stack S)
// {
//     if (S.n > 0)
//     {
//         return S.arr[S.n-1];
//     }
//     return NULLDATA;
// }

// int isValid(string s)
// {
//     Stack(S);
//     Init(S);

//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == '(' || s[i] == '[' || s[i] == '{')
//         {
//             Push(S, s[i]);
//         }
//         else if (s[i] == ')'|| s[i] == ']' || s[i] == '}')
//         {
//             if (isEmpty(S))
//             {
//                 return 0;
//             }

//             if (s[i]==')' and Top(S)=='(' || s[i]==']' and Top(S)=='[' || s[i]=='}' and Top(S)=='{')
//             Pop(S);
//         }
//     }

//     if (S.n == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int main()
// {
// 	string expr; cin>>expr;
// 	cout<< isValid(expr);

// 	return 0;
// }