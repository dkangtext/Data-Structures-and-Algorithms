/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
[
]
define
include
###End banned keyword*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct DONTHUC
{
    int somu;
    double heso;
};

struct Node
{
    DONTHUC *data;
    Node *next;
};

typedef struct DATHUC
{
    Node *head;
    Node *tail;
} List;

// ###INSERT CODE HERE -

void Nhap(DATHUC &b, double hs, int x)
{
    Node *p = new Node;
    DONTHUC *d = new DONTHUC;
    d->heso = hs;
    d->somu = x;
    p->data = d;
    p->next = NULL;
    if (b.head == NULL)
        b.head = b.tail = p;
    else
    {
        b.tail->next = p;
        b.tail = p;
    }
}

void Xuat(DATHUC &b)
{
    int size = 0, tmp = 0;
    int check = 1;
    for (Node *p = b.head; p != NULL; p = p->next)
    {
        size++;
        if (p->data->heso == 0)
            tmp++;
    }
    if (size == tmp)
        cout << 0;
    else
    {
        if (b.head->data->heso < 0)
        {
            if (b.head->data->heso == -1)
            {
                if (b.head->data->somu == 0)
                    cout << "-1";
                else
                    cout << "-";
            }
            if (b.head->data->heso < -1)
                cout << b.head->data->heso;
            if (b.head->data->somu > 0)
                cout << "x";
            if (b.head->data->somu > 1)
                cout << "^" << b.head->data->somu;
            check++;
        }
        else if (b.head->data->heso > 0)
        {
            if (b.head->data->heso == 1 && b.head->data->somu == 0)
                cout << 1;
            if (b.head->data->heso > 1)
                cout << b.head->data->heso;
            if (b.head->data->somu > 0)
                cout << "x";
            if (b.head->data->somu > 1)
                cout << "^" << b.head->data->somu;
            check++;
        }

        for (Node *p = b.head->next; p != NULL; p = p->next)
        {
            if (p->data->heso < 0)
            {
                if (p->data->heso == -1)
                {
                    if (p->data->somu == 0)
                        cout << "-1";
                    else
                        cout << "-";
                }
                if (p->data->heso < -1)
                    cout << p->data->heso;
                if (p->data->somu > 0)
                    cout << "x";
                if (p->data->somu > 1)
                    cout << "^" << p->data->somu;
                check++;
            }
            else if (p->data->heso > 0)
            {
                if (check > 1)
                    cout << "+";
                if (p->data->heso == 1 && p->data->somu == 0)
                    cout << 1;
                if (p->data->heso > 1)
                    cout << p->data->heso;
                if (p->data->somu > 0)
                    cout << "x";
                if (p->data->somu > 1)
                    cout << "^" << p->data->somu;
                check++;
            }
        }
    }
}
double TinhDaThuc(DATHUC &b, double x)
{
    double result = 0;
    for (Node *p = b.head; p != NULL; p = p->next)
    {
        result += p->data->heso * pow(x, p->data->somu);
    }
    return result;
}

int main()
{
    DATHUC B;
    B.head = B.tail = NULL;
    int n;
    cin >> n;
    double heso;
    int somu;
    for (int i = 0; i < n; i++)
    {
        cin >> heso >> somu;
        Nhap(B, heso, somu);
    }
    cout << "Da thuc vua nhap la: ";
    Xuat(B);
    double x;
    cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
