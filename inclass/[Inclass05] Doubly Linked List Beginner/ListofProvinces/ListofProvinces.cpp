/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -

typedef struct PROVINCE
{
    int id; // Mã tỉnh
    char name[31]; // Tên tỉnh
    int pop; // Dân số
    float area; // Diện tích
}pro;

struct node
{
    pro info;
    node* next;
};

struct List
{
    node *pHead, *pTail;
};

void Init (List &L)
{
    L.pHead = L.pTail = NULL;
}

node *getNode(pro x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

// Nhập thông tin của một tỉnh thành phố

void inputProvince(pro &x)
{
    cin >> x.id;
    cin.ignore();
    cin.getline(x.name, 31);
    cin >> x.pop;
    cin >> x.area;
}

// Xuất thông tin của một tỉnh thành phố

void outputProvince(pro x)
{
    cout << x.id << "\t" << x.name << "\t" << x.pop << "\t" << x.area << endl;
}

void addTail (List &L, pro x)
{
    node *p = getNode(x);
    if (L.pTail == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        L.pTail->next = p;
        L.pTail = p;
    }
}

void inputListProvinces (List &L)
{
    int n;
    cin >> n; // Nhập số lượng tỉnh thành
    pro x;
    for (int i = 0; i < n; i++)
    {
        inputProvince(x);
        addTail(L,x);
    }
}

void outputListProvinces (List L)
{
    node *p = L.pHead;
    while (p) // Mặc định p != NULL
    {
        outputProvince(p->info);
        p = p->next;
    }
}

void outputProvincesMore1MillionPop (List L)
{
    node *p = L.pHead;
    while (p)
    {
        if (p->info.pop > 1000)
        {
            outputProvince(p->info);
        }
        p = p->next;
    }
}

node *findProMaxArea (List L)
{
    if (L.pHead == NULL) return NULL;

    node* maxNode = L.pHead;
    node* p = L.pHead->next;

    while (p != NULL)
    {
        if (p->info.area > maxNode->info.area)
        {
            maxNode = p;
        }
        p = p->next;
    }

    return maxNode;
}

int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    cout<<"Provinces with a population of more than 1 million:"<<endl;
    outputProvincesMore1MillionPop(L);

    cout<<"The largest province:"<<endl;
    node *p = findProMaxArea(L);
    if(p) outputProvince(p->info);

    return 0;
}
