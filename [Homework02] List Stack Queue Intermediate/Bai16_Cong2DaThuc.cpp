/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
new
delete
using
###End banned keyword*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    int val;
    Node *next;
};

struct List
{
    Node *head, *tail;
    int x;
};

void list_initializing(List &l)
{
    l.head = l.tail = NULL;
}
void add_tail(List &l, int x)
{
    Node *p = new Node;
    p->val = x;
    p->next = NULL;
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void xuat(List &l)
{
    for (Node *p = l.head; p != NULL; p = p->next)
    {
        cout << p->val << " ";
    }
    cout << endl;
}

// ###INSERT CODE HERE -
void NhapNode(DATHUC &b, double hs, int x)
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
            if (b.head->data->heso != -1)
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
            if (b.head->data->heso != 1)
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
                if (p->data->heso != -1)
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
                if (p->data->heso != 1)
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

void Nhap(DATHUC &a)
{
    a.head = a.tail = NULL;
    int n;
    cin >> n;
    int check, tmp;
    if (n == 0)
        NhapNode(a, 0, 0);
    else
    {
        double heso;
        int somu;
        cin >> heso >> somu;
        NhapNode(a, heso, somu);
        tmp = somu - 1;
        for (int i = 1; i < n; i++)
        {
            cin >> heso >> somu;
            if (tmp == somu)
            {
                NhapNode(a, heso, somu);
                tmp--;
            }
            else
            {
                while (tmp > somu)
                {
                    NhapNode(a, 0, tmp);
                    tmp--;
                }
                NhapNode(a, heso, somu);
                tmp--;
            }
        }
        while (tmp > -1)
        {
            NhapNode(a, 0, tmp);
            tmp--;
        }
    }
}

int Tong2DaThuc(DATHUC &a, DATHUC &b)
{
    DATHUC c;
    Node *p = new Node;
    Node *a1 = new Node;
    Node *b1 = new Node;
    DONTHUC *d = new DONTHUC;
    int tmp;
    c.head = c.tail = NULL;
    if (a.head->data->somu > b.head->data->somu)
    {
        tmp = a.head->data->somu;
        p = a.head;
        while (tmp > b.head->data->somu)
        {
            NhapNode(c, p->data->heso, p->data->somu);
            p = p->next;
            tmp--;
        }
        a1 = p;
        b1 = b.head;
    }
    else if (a.head->data->somu < b.head->data->somu)
    {
        tmp = b.head->data->somu;
        p = b.head;
        while (tmp > a.head->data->somu)
        {
            NhapNode(c, p->data->heso, p->data->somu);
            p = p->next;
            tmp--;
        }
        a1 = a.head;
        b1 = p;
    }
    else
    {
        a1 = a.head;
        b1 = b.head;
    }

    double newHeso;
    for (Node *z = a1; z != NULL; z = z->next)
    {
        // cout<<a1->data->somu << " "<< b1->data->somu<<endl;
        newHeso = a1->data->heso + b1->data->heso;
        NhapNode(c, newHeso, a1->data->somu);
        if (a1->next != NULL && b1->next != NULL)
        {
            a1 = a1->next;
            b1 = b1->next;
        }
        else if (a1->next != NULL)
            cout << a1->next->data->somu;
        else if (b1->next != NULL)
            cout << b1->next->data->somu;
    }
    Xuat(c);
    return 0;
}
void Xuat(int t)
{
    int a = t;
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List l;

    list_initializing(l);
    int x;
    do
    {
        cin >> x;
        if (x != -1)
            add_tail(l, x);
        else
            break;
    } while (true);

    print_longest_increasing_sub_list(l);

    return 0;
}
