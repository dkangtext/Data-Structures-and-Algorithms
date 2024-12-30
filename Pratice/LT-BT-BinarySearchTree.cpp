#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int info;
    Node *left, *right;
};

typedef Node *Tree;

Node *getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertTree(Node *&T, int x)
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
        T = getNode(x);
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

// Duyệt cây theo thứ tự Node-Left-Right (NLR)
void NLR(Tree T)
{
    if (T)
    {
        cout << T->info << " ";
        NLR(T->left);
        NLR(T->right);
    }
}

// Duyệt cây theo thứ tự Left-Node-Right (LNR)
void LNR(Tree T)
{
    if (T)
    {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
    }
}

void LNR_2(Tree T)
{
    stack<Node *> s;
    Node *cur = T;
    while (cur != NULL || s.empty() == false)
    {
        while (cur != NULL)
        {
            s.push(cur);
            cur = cur->left;
        }

        cur = s.top();
        s.pop();
        
        cout << cur->info << " ";
        cur = cur->right;
    }
}

// Duyệt cây theo thứ tự Left-Right-Node (LRN)
void LRN(Tree T)
{
    if (T)
    {
        LRN(T->left);
        LRN(T->right);
        cout << T->info << " ";
    }
}

void LRN_2(Tree T)
{
    stack<Node *> s;
    stack<Node *> s2;
    Node *cur = T;

    while (cur != NULL || s.empty() == false)
    {
        while (cur != NULL)
        {
            s.push(cur);
            s2.push(cur);
            cur = cur->right;
        }
        cur = s.top();
        s.pop();
        cur = cur->left;
    }
    
    while (s2.empty() == false)
    {
        cout << s2.top()->info << " ";
        s2.pop();
    }
}

// Tìm giá trị x trên cây
Node *Search(Tree T, int x)
{
    if (!T)
        return NULL;

    if (T->info == x)
        return T;
    else if (x < T->info)
        return Search(T->left, x);
    else
        return Search(T->right, x);
}

// Tìm giá trị lớn nhất trên cây
int maxValue(Tree T)
{
    if (T->right == NULL)
        return T->info;
    return maxValue(T->right);
}

// Tìm giá trị nhỏ nhất trên cây
int minValue(Tree T)
{
    if (T->left == NULL)
        return T->info;
    return minValue(T->left);
}

// Liệt kê các nút lá trên cây
void listLeafs(Tree T)
{
    if (!T)
        return;

    if (T->left == NULL && T->right == NULL)
        cout << T->info << " ";
    listLeafs(T->left);
    listLeafs(T->right);
}

// Liệt kê các nút trong trên cây
void listInternalNodes(Tree T, int x)
{
    if (x == 0)
    {
        if (T)
        {
            listInternalNodes(T->left, 1);
            listInternalNodes(T->right, 1);
        }
    }
    else
    {
        if (T)
        {
            if ((T->left != NULL || T->right != NULL))
                cout << T->info << " ";
            listInternalNodes(T->left, 1);
            listInternalNodes(T->right, 1);
        }
    }
}

// Liệt kê các nút có một con trên cây
void listNodesWithOneChild(Tree T)
{
    if (!T)
        return;

    if ((T->left != NULL && T->right == NULL) ||
        (T->left == NULL && T->right != NULL))
        cout << T->info << " ";
    listNodesWithOneChild(T->left);
    listNodesWithOneChild(T->right);
}

// Liệt kê các nút có hai con trên cây
void listNodesWithTwoChildren(Tree T)
{
    if (!T)
        return;

    if (T->left != NULL && T->right != NULL)
        cout << T->info << " ";
    listNodesWithTwoChildren(T->left);
    listNodesWithTwoChildren(T->right);
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

// Hàm xoay cây sang trái
void rotateLeft(Tree &T)
{
    if (T == NULL)
    {
        cout << "Khong the xoay vi cay rong" << endl;
        return;
    }

    if (T->right == NULL)
    {
        cout << "Khong the xoay trai vi khong co nut con ben phai" << endl;
        return;
    }

    Node *p = T->right;
    T->right = p->left;
    p->left = T;
    T = p;
}

// Hàm xoay cây sang phải
void rotateRight(Tree &T)
{
    if (T == NULL)
    {
        cout << "Khong the xoay vi cay rong" << endl;
        return;
    }

    if (T->left == NULL)
    {
        cout << "Khong the xoay phai vi khong co nut con ben trai" << endl;
        return;
    }

    Node *p = T->left;
    T->left = p->right;
    p->right = T;
    T = p;
}

// Hàm kiểm tra cây có phải là cây AVL không
int isAVL(Tree T)
{
    if (T == NULL)
        return 1;

    int leftDepth = depthOfTree(T->left);
    int rightDepth = depthOfTree(T->right);

    if (abs(leftDepth - rightDepth) > 1)
        return 0;
    return isAVL(T->left) && isAVL(T->right);
}

// Hàm tìm giá trị x trên cây (new)
Node *Search(Tree T, int x)
{
    if (T == NULL)
        return NULL;

    if (T->info == x)
        return T;

    Node *p = Search(T->left, x);

    if (p != NULL)
        return p;
    return Search(T->right, x);
}

// Hàm chèn số vào bên trái của node p
void SetLeft(Node *p, int x)
{
    if (p == NULL)
    {
        cout << "Node khong ton tai\n";
        return;
    }

    if (p->left != NULL)
    {
        cout << "Da co node con ben trai\n";
        return;
    }

    p->left = getNode(x);
}

// Hàm chèn số vào bên phải của node p
void SetRight(Node *p, int x)
{
    if (p == NULL)
    {
        cout << "Node khong ton tai\n";
        return;
    }

    if (p->right != NULL)
    {
        cout << "Da co node con ben phai\n";
        return;
    }

    p->right = getNode(x);
}

// Hàm xóa node gốc
void deleteRoot(Tree &T, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (!T)
            return;

        if (T->left == NULL)
            T = T->right;

        else if (T->right == NULL)
            T = T->left;

        else
        {
            Node *p = T->right;
            Node *parent = T;

            while (p->left)
            {
                parent = p;
                p = p->left;
            }
            T->info = p->info;

            if (parent->left == p)
                parent->left = p->right;
            else
                parent->right = p->right;
            delete p;
        }
    }
}

// Hàm xóa node có giá trị x
void deleteNode(Tree &T, int x)
{
    if (T)
    {
        if (T->info == x)
        {
            if (T->left == NULL)
            {
                Node *p = T;
                T = T->right;
                delete p;
            }
            else if (T->right == NULL)
            {
                Node *p = T;
                T = T->left;
                delete p;
            }
            else
            {
                Node *p = T->right;
                while (p->left)
                    p = p->left;
                T->info = p->info;
                deleteNode(T->right, p->info);
            }
        }
        else if (x < T->info)
            deleteNode(T->left, x);
        else
            deleteNode(T->right, x);
    }
}

// Hàm liệt kê các nút ở mức k (PHẢI QUA TRÁI)
void nodesWithLevel(Tree T, int k)
{
    if (T == NULL)
        return;
    if (k == 0)
    {
        cout << T->info << " ";
        return;
    }
    nodesWithLevel(T->right, k - 1);
    nodesWithLevel(T->left, k - 1);
}

// Hàm đếm số nút
int countNodes(Tree &T)
{
    if (T == NULL)
        return 0;
    return 1 + countNodes(T->left) + countNodes(T->right);
}

// Hàm đếm số nút lá
int countLeafs(Tree &T)
{
    if (T == NULL)
        return 0;
    if (T->left == NULL && T->right == NULL)
        return 1;
    return countLeafs(T->left) + countLeafs(T->right);
}

// Hàm đếm số nút trong (nút trong gian)
bool check = true;

int countInternalNodes(Tree &T)
{
    if (check)
    {
        check = false;
        return 0 + countInternalNodes(T->left) + countInternalNodes(T->right);
    }
    if (T == NULL || (T->left == NULL && T->right == NULL))
        return 0;
    return 1 + countInternalNodes(T->left) + countInternalNodes(T->right);
}

// Hàm đếm số nút có một con
int countOneChild(Tree &T)
{
    if (T == NULL)
        return 0;
    if (T->left == NULL && T->right != NULL)
        return 1 + countOneChild(T->right);
    if (T->left != NULL && T->right == NULL)
        return 1 + countOneChild(T->left);
    return countOneChild(T->left) + countOneChild(T->right);
}

// Hàm đếm số nút có hai con
int countTwoChildren(Tree &T)
{
    if (T == NULL)
        return 0;
    if (T->left != NULL && T->right != NULL)
        return 1 + countTwoChildren(T->left) + countTwoChildren(T->right);
    return countTwoChildren(T->left) + countTwoChildren(T->right);
}

// Hàm đếm số nút có khóa nhỏ hơn x
int countLess(Tree &T, int x)
{
    if (T == NULL)
        return 0;
    if (T->info < x)
        return 1 + countLess(T->left, x) + countLess(T->right, x);
    return countLess(T->left, x) + countLess(T->right, x);
}

// Hàm đếm số nút có khóa lớn hơn x và nhỏ hơn y
int countBetweenValues(Tree &T, int x, int y)
{
    if (T == NULL)
        return 0;
    if (T->info > x && T->info < y)
        return 1 + countBetweenValues(T->left, x, y) + countBetweenValues(T->right, x, y);
    return countBetweenValues(T->left, x, y) + countBetweenValues(T->right, x, y);
}

// Hàm tính chiều cao của cây
int height(Tree T)
{
    if (T == NULL)
    {
        return 0;
    }
    return 1 + max(height(T->left), height(T->right));
}

// Hàm kiểm tra cây có phải là cây BST không
bool isCompleteBST(Tree T, int level, int height)
{
    if (T->left == NULL && T->right == NULL)
    {
        return level == height;
    }
    if (T->left == NULL || T->right == NULL)
    {
        return false;
    }
    return isCompleteBST(T->left, level + 1, height) && isCompleteBST(T->right, level + 1, height);
}

// Hàm kiểm tra cây có phải là cây nhị phân đầy không
int isCompleteBinaryTree(Tree T)
{
    int h = height(T);
    return isCompleteBST(T, 1, h) ? 1 : 0;
}

// Hàm kiểm tra cây nhị phân có cân bằng không
bool isBalance(Tree T)
{
    if (T == NULL)
        return true; 

    int leftHeight = height(T->left);
    int rightHeight = height(T->right);

    if (abs(leftHeight - rightHeight) <= 1 && isBalance(T->left) && isBalance(T->right))
        return true;

    return false;
}

// Hàm kiểm tra số bậc của cây
int nodesLevel(Tree T, int k, int c)
{
    if (T == NULL)
    {
        return 0;
    }

    if (c == k)
    {
        cout << T->info << " ";
        return 1;
    }
    return nodesLevel(T->right, k, c + 1) + nodesLevel(T->left, k, c + 1);
}

// Hàm liệt kê các nút ở mức k (2)
int nodesWithLevel(Tree T, int k, int c)
{
    int count = 0;
    cout << "\nList of nodes with level " << k << " (R->L): ";
    count = nodesLevel(T, k, c);

    cout << "\nNumber of nodes with level " << k << ": ";
    return count;
}

// Delete all leaf nodes
Node *removeLeafs(Tree T)
{
    if (!T)
        return NULL;

    if (!T->left && !T->right)
    {
        delete T;
        return NULL;
    }

    T->left = removeLeafs(T->left);
    T->right = removeLeafs(T->right);
    
    return T;
}

// Delete all square numbers
bool isSquare(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (i * i == n)
            return true;
    }

    return false;
}

void SearchStandFor(Node *&p, Node *&q)
{
    if (q->right != NULL)
    {
        SearchStandFor(p, q->right);
    }
    else
    {
        p->info = q->info;
        p = q;
        q = q->left;
    }
}

void deleteSquareNumbers(Tree &T)
{
    if (T == NULL)
        return;

    if (isSquare(T->info))
    {
        Node *p = T;
        if (T->left == NULL)
            T = T->right;
        else if (T->right == NULL)
            T = T->left;
        else
            SearchStandFor(p, T->left);
        delete p;
        deleteSquareNumbers(T);
    }
    else
    {
        deleteSquareNumbers(T->left);
        deleteSquareNumbers(T->right);
    }
}

// Delete Left Node
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

// Delete Right Node
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

// Is Full Binary Tree
int isFullBinaryTree(Tree T)
{
	if (T == NULL)
		return 1;

	if (T->left == NULL && T->right == NULL)
		return 1;
	
	if ((T->left) && (T->right))
		return (isFullBinaryTree(T->left) && isFullBinaryTree(T->right));
	
	return 0;
}

// Find Second Largest
void findSecondLargest(Tree T, Tree &parent, Tree &largest)
{
	if (T == NULL)
		return;

	if (T->right != NULL)
	{
		parent = T;
		findSecondLargest(T->right, parent, largest);
	}
	else
	{
		largest = T;
	}
}

void secondLargest(Tree T)
{
	if (T == NULL || (T->left == NULL && T->right == NULL))
		return;

	Tree parent = NULL, largest = NULL;
	findSecondLargest(T, parent, largest);

	if (largest->left != NULL)
	{
		Tree secondLargest = largest->left;
		while (secondLargest->right != NULL)
		{
			secondLargest = secondLargest->right;
		}
		cout << "2nd largest value is " << secondLargest->info << endl;
	}
	else if (parent != NULL)
	{
		cout << "2nd largest value is " << parent->info << endl;
	}
}

// Find Floor Of X
int findFloor(Tree T, int x)
{
    int floor = 201; 
    while (T != NULL)
    {
        if (T->info == x)
        {
            return T->info; 
        }
        else if (T->info < x)
        {
            floor = T->info; 
            T = T->right;  
        }
        else
        {
            T = T->left; 
        }
    }
    return floor;
}

// In ngược cây
int heightOfTree(Tree T)
{
    if (T == NULL)
    {
        return 0;
    }

    int leftHeight = heightOfTree(T->left);
    int rightHeight = heightOfTree(T->right);

    return max(leftHeight, rightHeight) + 1;
}

void printTreeWithHeight(Tree T, int height, int currentHeight)
{
    if (T == NULL)
    {
        return;
    }

    if (currentHeight == height)
    {
        cout << T->info << " ";
        return;
    }

    printTreeWithHeight(T->right, height, currentHeight + 1);
    printTreeWithHeight(T->left, height, currentHeight + 1);
}

void printTree(Tree T)
{
    int height = heightOfTree(T);

    for (int i = height; i >= 1; i--)
    {
        printTreeWithHeight(T, i, 1);
    }
}

int main()
{
    Tree T = NULL;
    inputTree(T);

    // Duyệt cây theo 3 thứ tự
    cout << "\nNLR: ";
    NLR(T);
    cout << "\nLRN: ";
    LRN(T);
    cout << "\nLNR: ";
    LNR(T);

    // Tìm kiếm giá trị x trên cây
    int x;
    cout << "\nEnter the element you want to find: ";
    cin >> x;
    Node *p = Search(T, x);
    if (p)
        cout << "Found";
    else
        cout << "Not found";

    // Tìm giá trị lớn nhất và nhỏ nhất trên cây
    cout << "\nMinimum value in BTS is " << minValue(T);
    cout << "\nMinimax value in BTS is " << maxValue(T);

    // Liệt kê các nút lá, nút trong, nút có một con, nút có hai con
    cout << "\nLeaf nodes: ";
    listLeafs(T);
    cout << "\nInternal nodes: ";
    listInternalNodes(T, 0);
    cout << "\nNodes with one child: ";
    listNodesWithOneChild(T);
    cout << "\nNodes with two children: ";
    listNodesWithTwoChildren(T);

    // Đếm số nút của cây, chiều cao của cây
    cout << "Number of nodes: " << countNodes(T) << endl;
    cout << "Depth of Tree: " << depthOfTree(T) << endl;

    // Đếm số nút có giá trị chẵn, lẻ, dương, âm, nguyên tố
    int count_even = 0, count_odd = 0;
    countEven(T, count_even);
    countOdd(T, count_odd);
    cout << "Number of even nodes: " << count_even << endl;
    cout << "Number of odd nodes: " << count_odd << endl;

    cout << "Number of positive nodes: " << countPositive(T) << endl;
    cout << "Number of negative nodes: " << countNegative(T) << endl;

    // Liệt kê các số nguyên tố trong cây theo thứ tự NLR
    cout << "Number of prime nodes: " << countPrime(T) << endl;
    cout << "Prime numbers: ";
    listPrime(T);

    // Xoay cây sang trái
    rotateLeft(T);
    cout << "\nAfter rotating left: ";
    NLR(T);

    // Xoay cây sang phải
    rotateRight(T);
    cout << "\nAfter rotating right: ";
    NLR(T);

    // Kiểm tra cây có phải là cây AVL không
    cout << "\nIs AVL: " << isAVL(T);

    // Hàm chèn số vào bên trái của node p
    SetLeft(Search(T, 5), 10);

    // Hàm chèn số vào bên phải của node p
    SetRight(Search(T, 5), 15);

    // Hàm xóa node gốc
    int m;
    cout << "\nEnter m: ";
    cin >> m;
    deleteRoot(T, m);

    // Hàm xóa node có giá trị x
    int x;
    cout << "\nEnter x: ";
    cin >> x;
    deleteNode(T, x);

    // Hàm liệt kê các nút ở mức k (PHẢI QUA TRÁI)
    int k;
    cout << "\nEnter k: ";
    cin >> k;
    cout << "List of nodes with level " << k << " (R->L) : ";
    nodesWithLevel(T, k);

    // Hàm đếm số nút, nút lá, nút trong, nút có một con, nút có hai con
    cout << "Number of nodes: " << countNodes(T) << endl;
    cout << "Number of leaf nodes: " << countLeafs(T) << endl;
    cout << "Number of internal nodes: " << countInternalNodes(T) << endl;
    cout << "Number of nodes with one child: " << countOneChild(T) << endl;
    cout << "Number of nodes with two children: " << countTwoChildren(T) << endl;

    // Hàm đếm số nút có khóa nhỏ hơn x
    int x;
    cout << "Enter x: ";
    cin >> x;
    cout << "\nNumber of nodes less than " << x << ": " << countLess(T, x) << endl;

    // Hàm đếm số nút có khóa lớn hơn x và nhỏ hơn y
    int y;
    cout << "Enter x,y: ";
    cin >> x >> y;
    cout << "\nNumber of nodes greater than " << x << " and less than " << y << ": " << countBetweenValues(T, x, y) << endl;

    // Hàm kiểm tra cây có phải là cây BST không
    int i = isCompleteBinaryTree(T);
    if (i == 0)
        cout << "\nThe tree is not a Complete Binary Tree";
    else
        cout << "\nThe tree is a Complete Binary Tree";
        
    // Hàm kiểm tra số bậc của cây
    int k;
    cout << "\nEnter k: ";
    cin >> k;
    cout << nodesWithLevel(T, k, 0) << endl;

    // Delete all leaf nodes
    removeLeafs(T);

    // Delete all square numbers
    deleteSquareNumbers(T);

    // Delete Left Node
    DeleteLeft(Search(T, 5));

    // Delete Right Node
    DeleteRight(Search(T, 5));

    // Is Full Binary Tree
    cout << isFullBinaryTree(T);

    // Find Second Largest
    secondLargest(T);

    // Find Floor Of X
    int x;
    cout << "Enter x: ";
    cin >> x;
    cout << findFloor(T, x);

    // In ngược cây
    int x;
    cout << "Enter x: ";
    cin >> x;
    int height = heightOfTree(T);
    printTreeWithHeight(T, height, 1);


    return 0;
}
