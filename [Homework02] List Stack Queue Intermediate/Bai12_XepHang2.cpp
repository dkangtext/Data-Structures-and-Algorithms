#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    list<int> lst;
    for (int i = 1; i <= n; i++)
    {
        lst.push_back(i);
    }

    unordered_map<int, list<int>::iterator> idx;
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        idx[*it] = it;
    }

    for (int i = 0; i < m; i++)
    {
        int student;
        cin >> student;
        auto it = idx[student];
        if (it != lst.begin())
        {
            lst.splice(lst.begin(), lst, it);
            idx[student] = lst.begin();
        }
        cout << lst.back() << " ";
    }
    return 0;
}

// ANOTHER CODE - TIME LIMIT EXCEEDED

// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *next;
// };

// struct List
// {
//     Node *head;
//     Node *tail;
// };

// void InitList(List &L)
// {
//     L.head = NULL;
//     L.tail = NULL;
// }

// Node *GetNode(int x)
// {
//     Node *p = new Node;
//     p->data = x;
//     p->next = NULL;
//     return p;
// }

// void AddHead(List &L, int x)
// {
//     Node *p = GetNode(x);
//     if (L.head == NULL)
//     {
//         L.head = p;
//         L.tail = p;
//     }
//     else
//     {
//         p->next = L.head;
//         L.head = p;
//     }
// }

// void AddTail(List &L, int x)
// {
//     Node *p = GetNode(x);
//     if (L.head == NULL)
//     {
//         L.head = p;
//         L.tail = p;
//     }
//     else
//     {
//         L.tail->next = p;
//         L.tail = p;
//     }
// }

// void MoveToHead(List &L, int student)
// {
//     if (L.head == NULL || L.head->data == student)
//     {
//         return;
//     }

//     Node *prev = NULL;
//     Node *current = L.head;

//     while (current != NULL && current->data != student)
//     {
//         prev = current;
//         current = current->next;
//     }

//     if (current != NULL)
//     {
//         if (prev != NULL)
//         {
//             prev->next = current->next;
//             if (current == L.tail)
//             {
//                 L.tail = prev;
//             }
//         }
//         current->next = L.head;
//         L.head = current;
//     }
// }

// int GetTailValue(List &L)
// {
//     return L.tail ? L.tail->data : -1;
// }

// int main()
// {
//     cin.tie(NULL);
//     std::ios_base::sync_with_stdio(false);

//     int n, m;
//     cin >> n >> m;

//     List L;
//     InitList(L);

//     for (int i = 1; i <= n; i++)
//     {
//         AddTail(L, i);
//     }

//     for (int i = 0; i < m; i++)
//     {
//         int student;
//         cin >> student;
//         MoveToHead(L, student);
//         cout << GetTailValue(L) << " ";
//     }

//     return 0;
// }