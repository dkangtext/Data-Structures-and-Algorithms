#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int viTri;
    Node *next;

    Node(int x)
    {
        viTri = x;
        next = NULL;
    }
};

struct Stack
{
    Node *dinhStack;
    int soLuong;

    Stack()
    {
        dinhStack = NULL;
        soLuong = 0;
    }

    bool stackRong()
    {
        return dinhStack == NULL;
    }

    void themVaoStack(int x)
    {
        Node *nodeTemp = new Node(x);
        nodeTemp->next = dinhStack;
        dinhStack = nodeTemp;
        soLuong++;
    }

    int layDinhStack()
    {
        if (stackRong())
            return -1;
        return dinhStack->viTri;
    }

    void xoaDinhStack()
    {
        if (!stackRong())
        {
            Node *temp = dinhStack;
            dinhStack = dinhStack->next;
            delete temp;
            soLuong--;
        }
    }
};

bool coTheNhinThay(int viTri1, int viTri2, vector<int> &chieuCao)
{
    int chieuCaoMin = min(chieuCao[viTri1], chieuCao[viTri2]);

    for (int i = viTri1 + 1; i < viTri2; i++)
    {
        if (chieuCao[i] > chieuCaoMin)
        {
            return false;
        }
    }
    return true;
}

int demSoCapNhinThay(int soNguoi, vector<int> &chieuCao)
{
    int ketQua = 0;

    for (int i = 0; i < soNguoi; i++)
    {
        for (int j = i + 1; j < soNguoi; j++)
        {
            if (coTheNhinThay(i, j, chieuCao))
            {
                ketQua++;
            }
        }
    }

    return ketQua;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int soNguoi;
    cin >> soNguoi;

    vector<int> chieuCao(soNguoi);
    
    for (int i = 0; i < soNguoi; i++)
    {
        cin >> chieuCao[i];
    }

    cout << demSoCapNhinThay(soNguoi, chieuCao) << endl;

    return 0;
}