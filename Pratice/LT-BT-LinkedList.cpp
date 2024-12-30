#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node *next;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

// Khởi tạo một Node mới
Node *getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

// Khởi tạo danh sách
void Init(List &L)
{
    L.pHead = L.pTail = NULL;
}

// Nhập danh sách
void inputList(List &L, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Node *p = getNode(x);
        if (L.pHead == NULL)
        {
            L.pHead = L.pTail = p;
        }
        else
        {
            L.pTail->next = p;
            L.pTail = p;
        }
    }
}

// Thêm một phần tử vào đầu danh sách
void addHead(List &L, int x)
{
    Node *p = getNode(x);
    if (L.pHead == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        p->next = L.pHead;
        L.pHead = p;
    }
}

// Thêm một phần tử vào cuối danh sách
void addTail(List &L, int x)
{
    Node *p = getNode(x);
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

// Thêm một phần tử vào sau phần tử có giá trị x
void addAfter(List &L, int x, int y)
{
    Node *p = L.pHead;
    while (p != NULL)
    {
        if (p->info == x)
        {
            Node *newNode = getNode(y);
            newNode->next = p->next;
            p->next = newNode;

            if (p == L.pTail)
            {
                L.pTail = newNode;
            }
            return;
        }
        p = p->next;
    }
    addHead(L, y);
}

// Xóa phần tử đầu danh sách
void deleteHead(List &L)
{
    if (L.pHead == NULL)
        return;

    Node *p = L.pHead;

    if (L.pHead == L.pTail)
    {
        L.pHead = L.pTail = NULL;
    }
    else
    {
        L.pHead = L.pHead->next;
    }

    delete p;
}

// Xóa phần tử cuối danh sách
void deleteNode(List &L, int x)
{
    if (L.pHead == NULL)
        return;

    if (L.pHead->info == x)
    {
        deleteHead(L);
        return;
    }

    Node *p = L.pHead;
    while (p->next != NULL && p->next->info != x)
    {
        p = p->next;
    }

    if (p->next != NULL)
    {
        Node *temp = p->next;
        p->next = p->next->next;

        if (temp == L.pTail)
        {
            L.pTail = p;
        }

        delete temp;
    }
}

// Xóa phần tử cuối danh sách
void deleteTail(List &L)
{
    if (L.pHead == NULL)
    {
        return;
    }
    if (L.pHead == L.pTail)
    {
        delete L.pHead;
        L.pHead = NULL;
        L.pTail = NULL;
        return;
    }
    Node *p = L.pHead;
    while (p->next != L.pTail)
    {
        p = p->next;
    }
    delete L.pTail;
    L.pTail = p;
    L.pTail->next = NULL;
}

// Xóa phần tử đầu tiên có giá trị n
void deleteFirst(List &L, int n)
{
    if (L.pHead == NULL)
    {
        return;
    }

    if (L.pHead->info == n)
    {
        deleteHead(L);
        return;
    }

    Node *p = L.pHead;
    while (p->next != NULL && p->next->info != n)
    {
        p = p->next;
    }

    if (p->next != NULL)
    {
        Node *temp = p->next;
        p->next = temp->next;
        if (temp == L.pTail)
        {
            L.pTail = p;
        }
        delete temp;
    }
}

// Xóa tất cả các phần tử có giá trị n
void DeleteAll(List &L, int n)
{
    while (L.pHead != NULL && L.pHead->info == n)
    {
        deleteHead(L);
    }

    Node *p = L.pHead;

    while (p != NULL && p->next != NULL)
    {
        if (p->next->info == n)
        {
            Node *temp = p->next;
            p->next = temp->next;
            if (temp == L.pTail)
            {
                L.pTail = p;
            }
            delete temp;
        }
        else
        {
            p = p->next;
        }
    }
}

// In danh sách
void printList(List L)
{
    Node *p = L.pHead;
    if (p != NULL)
    {
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
    }
    else
        cout << "List is empty";
}

// Sort và Search
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void MySort(List &L)
{
    for (Node *i = L.pHead; i != NULL; i = i->next)
    {
        Node *minNode = i;
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (j->info < minNode->info)
            {
                minNode = j;
            }
        }

        if (minNode != i)
        {
            swap(i->info, minNode->info);
        }
    }
}

int MySearch(List &L, int x)
{
    Node *p = L.pHead;
    int pos = 0;
    while (p != NULL)
    {
        if (p->info == x)
        {
            return pos;
        }
        p = p->next;
        pos++;
    }
    return -1;
}

// Find MAX
Node *findMax(List L)
{
    if (L.pHead == NULL)
    {
        cout << "List is empty";
        return NULL;
    }
    Node *p = L.pHead;
    Node *max = p;
    while (p != NULL)
    {
        if (p->info > max->info)
            max = p;
        p = p->next;
    }
    return max;
}

// Find MIN
Node *findMin(List L)
{
    if (L.pHead == NULL)
    {
        cout << "List is empty";
        return NULL;
    }
    Node *p = L.pHead;
    Node *min = p;
    while (p != NULL)
    {
        if (p->info < min->info)
            min = p;
        p = p->next;
    }
    return min;
}

// The ith element from the end of L
Node *findElementFromEnd(List L, int i)
{
    if (L.pHead == NULL)
    {
        cout << "List is empty";
        return NULL;
    }

    Node *p = L.pHead;
    Node *q = L.pHead;

    for (int j = 0; j < i; j++)
    {
        if (q == NULL)
        {
            cout << "The index is invalid";
            return NULL;
        }
        q = q->next;
    }

    while (q)
    {
        p = p->next;
        q = q->next;
    }
    return p;
}

// Find Middle
Node *findMiddle(List L)
{
    Node *p = L.pHead;
    Node *q = L.pHead;
    if (p == NULL)
        return NULL;
    while (q && q->next)
    {
        p = p->next;
        q = q->next->next;
    }
    return p;
}

// Copy List
void copy(List l, List &l2)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        addTail(l2, p->info);
        p = p->next;
    }
}

// Concate
void concate(List &L1, List L2)
{
    if (L1.pHead == NULL)
    {
        L1 = L2;
        return;
    }
    L1.pTail->next = L2.pHead;
    L1.pTail = L2.pTail;
}

// Swap Data
Node *swapData(List &L, int x, int y)
{
    Node *p = L.pHead;

    Node *px = NULL;
    Node *py = NULL;

    while (p != NULL)
    {
        if (p->info == x && px == NULL)
        {
            px = p;
        }
        if (p->info == y && py == NULL)
        {
            py = p;
        }
        p = p->next;
    }

    if (px == NULL || py == NULL)
    {
        return NULL;
    }

    int temp = px->info;
    px->info = py->info;
    py->info = temp;

    return px;
}

// Move the last element to the front
void moveLastToFront(List &L)
{
    if (L.pHead == NULL || L.pHead == L.pTail)
    {
        return;
    }

    Node *p = L.pHead;
    while (p->next != L.pTail)
    {
        p = p->next;
    }

    p->next = NULL;
    L.pTail->next = L.pHead;
    L.pHead = L.pTail;
    L.pTail = p;
}

// Đảo ngược danh sách
void reverseList(List &l)
{
    Node *prev = NULL;
    Node *current = l.pHead;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    l.pHead = prev;
}

// Is Subsequence
int isSubsequence(List l1, List l2)
{
    Node *p1 = l1.pHead;
    Node *p2 = l2.pHead;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->info == p2->info)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        else
        {
            p2 = p2->next;
        }
    }
    if (p1 == NULL)
        return true;
    return false;
}

// Find Sub Array
void print_longest_increasing_sub_list(List l)
{
    int length = 0, tmp = 1;
    int a = l.pHead->info;
    for (Node *p = l.pHead; p != NULL; p = p->next)
    {
        if (p->info >= a)
        {
            tmp++;
        }
        else
        {
            if (tmp > length)
                length = tmp;
            tmp = 1;
        }
        a = p->info;
    }
    cout << length;
}

int main()
{
    List L;
    Init(L);

    int x, y;

    // Thêm phần tử vào danh sách
    addHead(L, 1);

    // Thêm phần tử vào cuối danh sách
    addTail(L, 2);

    // Thêm phần tử vào sau phần tử có giá trị x
    addAfter(L, 1, 3);

    // Xóa phần tử đầu danh sách
    deleteHead(L);

    // Xóa phần tử có giá trị x
    deleteNode(L, 2);

    // Xóa phần tử đầu tiên có giá trị n
    deleteFirst(L, 3);

    // Xóa tất cả các phần tử có giá trị n
    DeleteAll(L, 3);

    // Sort và Search
    MySort(L);

    cout << "Sorted List: ";
    printList(L);

    cout << "\nFind an element: ";
    int x;
    cin >> x;
    cout << x << endl;

    int result = MySearch(L, x);

    if (result == -1)
        cout << x << " is not found";
    else
        cout << x << " is found at the position " << result;

    // Find MAX
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "\nEnter a sequence of " << n << " numbers: ";
    inputList(L, n);
    cout << "\nThe created Linked List: ";
    printList(L);

    cout << "\nThe maximum value: ";
    Node *p = findMax(L);
    if (p)
        cout << p->info;

    // Xóa phần tử cuối danh sách
    deleteTail(L);

    // The ith element from the end of L
    int i;
    cout << "\nEnter a number: ";
    cin >> i;
    cout << "\nThe element at index " << i << " (from the end of L): ";
    Node *p = findElementFromEnd(L, i);
    if (p)
        cout << p->info;

    // Find Middle
    Node *p = findMiddle(L); // Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if (p)
        cout << "The middle element is " << p->info;

    // Copy List
    List L2;
    Init(L2);
    copy(L, L2);

    Node *p = L.pHead, *q = L2.pHead;
    while (p != NULL)
    {
        if (p == q || p->info != q->info)
            cout << "WRONG";
        cout << p->info << endl;
        p = p->next;
        q = q->next;
    }

    // Concate
    List L1, L2;
    Init(L1);
    Init(L2);

    int n, m;
    cout << "Enter n: ";
    cin >> n;
    inputList(L1, n);
    printList(L1);

    cout << "Enter m: ";
    cin >> m;
    inputList(L2, m);
    printList(L2);

    concate(L1, L2);
    cout << "After concating: ";
    printList(L1);

    // Swap Data
    int x, y;
    cout << "Enter x and y: ";
    cin >> x >> y;
    Node *p = swapData(L, x, y);

    cout << "Updated List after swapping " << x << " and " << y << ": " << endl;
    printList(L);
    cout << endl;

    if (p)
    {
        cout << "At the address of " << x << ": ";
        cout << p->info;
    }
    else
        cout << "Can not swap";

    // Move the last element to the front
    moveLastToFront(L);
    cout << "Updated List after moving the last element to the front of L: " << endl;
    printList(L);

    // Đảo ngược danh sách
    reverseList(L);
    cout << "Reversed List: ";
    printList(L);

    // Is Subsequence
    List l1, l2;
    Init(l1);
    Init(l2);

    int n, m;
    cout << "Enter n: ";
    cin >> n;
    inputList(l1, n);
    printList(l1);

    cout << "Enter m: ";
    cin >> m;
    inputList(l2, m);
    printList(l2);

    if (isSubsequence(l1, l2))
        cout << "YES";
    else
        cout << "NO";

    // Find Sub Array
    List l;
    Init(l);

    int n;
    cout << "Enter n: ";
    cin >> n;
    inputList(l, n);
    printList(l);

    cout << "The length of the longest increasing sub list: ";
    print_longest_increasing_sub_list(l);

    return 0;
}