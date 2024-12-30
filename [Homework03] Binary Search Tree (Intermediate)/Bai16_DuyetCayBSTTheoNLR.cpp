/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
preOrder
###End banned keyword*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void preOrder(Node *root)
    {
        // ###INSERT CODE HERE -

        /* SV phai viet ca ham insert
        Node* insert(Node* root, int data);
         */
        if (root == NULL)
            return;

        stack<Node *> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty())
        {
            Node *node = nodeStack.top();
            cout << node->data << " ";
            nodeStack.pop();

            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
    }

    Node* insert(Node *root, int data)
    {
        Node *newNode = new Node(data);
        if (root == NULL)
        {
            return newNode;
        }

        Node *current = root;
        Node *parent = NULL;

        while (current != NULL)
        {
            parent = current;
            if (data <= current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        if (data <= parent->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }

        return root;
    }
}; // End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.preOrder(root);

    return 0;
}
