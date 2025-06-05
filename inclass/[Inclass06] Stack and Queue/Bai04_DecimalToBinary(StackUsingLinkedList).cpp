/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

/*Cach 1: Khi da cai dat List roi, dinh nghia Stack dua tren List
struct Stack
{
	List L;
};

Cach 2: Cai dat lai Stack tu dau, giong nhu List
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead; // pTail khong co cung duoc

};*/

//###INSERT CODE HERE -

struct Node
{
    int info;
    Node *next;
};

struct Stack
{
    Node *pHead;
};

void Init(Stack &S)
{
    S.pHead = NULL;
}

Node *getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void Push(Stack &S, int x)
{
    Node *p = getNode(x);
    if (S.pHead == NULL)
    {
        S.pHead = p;
    }
    else
    {
        p->next = S.pHead;
        S.pHead = p;
    }
}

void DecimaltoBinary1(int n, Stack &S)
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

void printStack(Stack S)
{
    Node *p = S.pHead;
    while (p != NULL)
    {
        cout << p->info;
        p = p->next;
    }
}

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary1(n,S);
    printStack(S);
    return 0;
}

