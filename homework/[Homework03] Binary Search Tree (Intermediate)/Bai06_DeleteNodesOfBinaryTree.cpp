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
    int info;
    Node *left;
    Node *right;
};
typedef Node *Tree;

Node *getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void SetLeft(Node *p, int x)
{
    if (p == NULL || p->left != NULL)
        return;
    p->left = getNode(x);
}

void SetRight(Node *p, int x)
{
    if (p == NULL || p->right != NULL)
        return;
    p->right = getNode(x);
}

Node *Search(Node *T, int x)
{
    if (T == NULL)
        return NULL;
    if (T->info == x)
        return T;
    Node *p = Search(T->left, x);
    if (p == NULL)
        p = Search(T->right, x);
    return p;
}

void DeleteLeft(Node *p)
{
    if (p == NULL)
    {
        cout << "Node khong ton tai\n";
        return;
    }
    if (p->left == NULL)
    {
        cout << "Khong co node ben trai\n";
        return;
    }
    if (p->left->left != NULL || p->left->right != NULL)
    {
        cout << "Khong la node la nen khong xoa duoc\n";
        return;
    }
    Node *q = p->left;
    p->left = NULL;
    delete q;
}

void DeleteRight(Node *p)
{
    if (p == NULL)
    {
        cout << "Node khong ton tai\n";
        return;
    }
    if (p->right == NULL)
    {
        cout << "Khong co node ben phai\n";
        return;
    }
    if (p->right->left != NULL || p->right->right != NULL)
    {
        cout << "Khong la node la nen khong xoa duoc\n";
        return;
    }
    Node *q = p->right;
    p->right = NULL;
    delete q;
}

void LNR(Node *T)
{
    if (T != NULL)
    {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
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
            break;
        cin >> b >> c;
        if (a == 'L')
            SetLeft(Search(T, b), c);
        else if (a == 'R')
            SetRight(Search(T, b), c);
    }
    cout << "LNR: ";
    LNR(T);
    cout << "\nDelete some nodes:\n";
    string s;
    while (true)
    {
        cin >> s; // Chuoi cho biet xoa ben trai hay ben phai
        if (s != "DL" && s != "DR")
            break;
        cin >> b;
        if (s == "DL")
            DeleteLeft(Search(T, b));
        else if (s == "DR")
            DeleteRight(Search(T, b));
    }
    cout << "\nLNR: ";
    LNR(T);

    return 0;
}
