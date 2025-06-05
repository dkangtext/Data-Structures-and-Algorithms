/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -

struct node
{
    int info;
    node *left, *right;
};

typedef node *Tree;

node *getnode(int x)
{
    node *p = new node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertTree(node *&T, int x)
{
    if (T)
    {
        if (T->info == x)
            return;
        if (x < T->info)
            insertTree(T->left, x);
        else
            insertTree(T->right, x);
    }
    else
        T = getnode(x);
}

void inputTree(Tree &T)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertTree(T, x);
    }
}

void LNR(Tree T)
{
    if (T)
    {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
    }
}

// Hàm đếm số nút của cây
int countNodes(Tree &T)
{
    if (T == NULL)
        return 0;
    return 1 + countNodes(T->left) + countNodes(T->right);
}

// Hàm tính chiều cao của cây
int depthOfTree(Tree T)
{
    if (T == NULL)
        return -1;
    int leftDepth = depthOfTree(T->left);
    int rightDepth = depthOfTree(T->right);
    return max(leftDepth, rightDepth) + 1;
}

// Hàm đếm số nút có giá trị chẵn
int countEven(Tree T, int &count)
{
    if (T)
    {
        if (T->info % 2 == 0)
            count++;
        countEven(T->left, count);
        countEven(T->right, count);
    }
    return count;
}

// Hàm đếm số nút có giá trị lẻ
int countOdd(Tree T, int &count)
{
    if (T)
    {
        if (T->info % 2 != 0)
            count++;
        countOdd(T->left, count);
        countOdd(T->right, count);
    }
    return count;
}

// Hàm đếm số nút có giá trị dương
int countPositive(Tree T)
{
    if (T == NULL)
        return 0;
    return (T->info > 0 ? 1 : 0) + countPositive(T->left) + countPositive(T->right);
}

// Hàm đếm số nút có giá trị âm
int countNegative(Tree T)
{
    if (T == NULL)
        return 0;
    return (T->info < 0 ? 1 : 0) + countNegative(T->left) + countNegative(T->right);
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

// Hàm đếm số nút có giá trị nguyên tố
int countPrime(Tree T)
{
    if (T == NULL)
        return 0;
    return (isPrime(T->info) ? 1 : 0) + countPrime(T->left) + countPrime(T->right);
}

// Hàm liệt kê các số nguyên tố trong cây theo thứ tự NLR
void listPrime(Tree T)
{
    if (T)
    {
        if (isPrime(T->info))
            cout << T->info << " ";
        listPrime(T->left);
        listPrime(T->right);
    }
}

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "LNR: ";
    LNR(T);
    cout << endl;

    cout << "Number of nodes: " << countNodes(T) << endl;
    cout << "Depth of Tree: " << depthOfTree(T) << endl;

    int count_even = 0, count_odd = 0;
    countEven(T, count_even);
    countOdd(T, count_odd);
    cout << "Number of even nodes: " << count_even << endl;
    cout << "Number of odd nodes: " << count_odd << endl;

    cout << "Number of positive nodes: " << countPositive(T) << endl;
    cout << "Number of negative nodes: " << countNegative(T) << endl;

    cout << "Number of prime nodes: " << countPrime(T) << endl;
    cout << "Prime numbers: ";
    listPrime(T);

    return 0;
}
