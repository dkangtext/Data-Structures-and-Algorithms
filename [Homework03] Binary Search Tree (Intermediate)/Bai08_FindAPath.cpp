#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
    Node *root;

    Node *insertRecursive(Node *current, int value)
    {
        if (current == nullptr)
        {
            return new Node(value);
        }

        if (value < current->value)
        {
            current->left = insertRecursive(current->left, value);
        }
        else
        {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    bool findWithPath(int x, int path[], int &pathLength)
    {
        Node *current = root;
        pathLength = 0;

        while (current != nullptr)
        {
            path[pathLength++] = current->value;

            if (current->value == x)
            {
                return true;
            }
            else if (x < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        return false;
    }
};

void solveTreeSearch()
{
    int n;
    cin >> n;

    BinarySearchTree tree;

    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        tree.insert(val);
    }

    int x;
    cin >> x;

    int path[100];
    int pathLength = 0;

    if (tree.findWithPath(x, path, pathLength))
    {
        cout << "Found. Path: ";
        for (int i = 0; i < pathLength; ++i)
        {
            cout << path[i];
            if (i < pathLength - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
}

int main()
{
    solveTreeSearch();
    return 0;
}
