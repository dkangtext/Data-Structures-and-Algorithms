/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

// ###INSERT CODE HERE -

typedef struct Product
{
    string ID;
    string Name;
    string Type;
    int Year;
    int Warranty;
} PRO;

struct Node
{
    PRO info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node *Tree;

Node *getNode(PRO x)
{
    Node *p = new Node;
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}


void insertTree(Node *&T, PRO x)
{
    if (T != NULL)
    {
        if (T->info.ID == x.ID)
            return;
        if (x.ID < T->info.ID)
        {
            insertTree(T->pLeft, x);
        }
        else
        {
            insertTree(T->pRight, x);
        }
    }
    else
    {
        T = getNode(x);
    }
}

void inputTree(Tree &T)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        PRO x;
        cin >> x.ID;
        cin.ignore();
        getline(cin, x.Name);
        getline(cin, x.Type);
        cin >> x.Year;
        cin >> x.Warranty;
        
        Node *p = getNode(x);
        
        if (T == NULL)
        {
            T = p;
        }  
        else
        {
            insertTree(T, x);
        }
    }
    return;
}

void listProduct(Tree T, string type)
{
    if (T != NULL)
    {
        if (T->info.Type == type)
        {
            cout << T->info.ID << "\t" << T->info.Name << "\t" << T->info.Type << "\t" << T->info.Year << "\t" << T->info.Warranty << endl;
        }
        listProduct(T->pLeft, type);
        listProduct(T->pRight, type);
    }
}

void countPRO(Tree T, int year, int &x)
{
    if (T != NULL)
    {
        if (T->info.Warranty > year)
        {
            x++;
        }
        countPRO(T->pLeft, year, x);
        countPRO(T->pRight, year, x);
    }
}

int countProduct(Tree T, int year)
{
    int count = 0;
    countPRO(T, year, count);
    return count;
}

// ###END CODE HERE###

int main()
{
    Tree T = NULL;
    inputTree(T);

    string type;
    cin.ignore();
    getline(cin, type);
    cout << "List of products whose type is  " << type << ": ";
    cout << "\nID\tName\tType\tYear\tWarranty\n";
    listProduct(T, type);

    int year;
    cin >> year;
    cout << "Number of products with more than " << year << " years of warranty: " << countProduct(T, year) << endl;

    return 0;
}
