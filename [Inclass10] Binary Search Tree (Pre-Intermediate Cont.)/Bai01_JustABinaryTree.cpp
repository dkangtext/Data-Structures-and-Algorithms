/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -

struct Node
{
    int Data;
    Node *Left;
    Node *Right;
};

typedef Node *Tree;

Node *getNode(int x)
{
    Node *p = new Node;
    p->Data = x;
    p->Left = p->Right = NULL;
    return p;
}

Node *Search(Tree T, int x)
{
    if (T == NULL)
        return NULL;

    if (T->Data == x)
        return T;
    
    Node *p = Search(T->Left, x);
    
    if (p != NULL)
        return p;
    return Search(T->Right, x);
}

void SetLeft(Node *p, int x)
{
    if (p == NULL)
    {
        cout << "Node khong ton tai\n";
        return;
    }

    if (p->Left != NULL)
    {
        cout << "Da co node con ben trai\n";
        return;
    }

    p->Left = getNode(x);
}

void SetRight(Node *p, int x)
{
    if (p == NULL)
    {
        cout << "Node khong ton tai\n";
        return;
    }

    if (p->Right != NULL)
    {
        cout << "Da co node con ben phai\n";
        return;
    }
    
    p->Right = getNode(x);
}

void LNR(Tree T)
{
    if (T)
    {
        LNR(T->Left);
        cout << T->Data << " ";
        LNR(T->Right);
    }
}

int main()
{
    Tree T = NULL;
    int x, b, c;
    char a;
    cin >> x;
    T = getNode(x); // tao nut goc
    while (true)
    {
        cin >> a; // Ky tu cho biet chen vao trai hay phai
        if (a != 'L' && a != 'R')
            break; // Neu khong phai L hoac R thi ket thuc viec tao cay
        cin >> b >> c;
        if (a == 'L')
            SetLeft(Search(T, b), c); // chen c vao ben trai b
        else if (a == 'R')
            SetRight(Search(T, b), c); // chen c vao ben phai b
    }
    cout << "\nLNR: ";
    LNR(T);
    cout << endl;

    return 0;
}
