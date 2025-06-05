#include <iostream>
#include <string>
using namespace std;

struct WeightNode
{
    int weight;          
    WeightNode *next;    
};

struct StoneNode
{
    char symbol;         
    WeightNode *weights; 
    StoneNode *left;     
    StoneNode *right;    
};
typedef StoneNode *BinaryTree;

WeightNode *createWeightNode(int weight)
{
    WeightNode *node = new WeightNode;

    if (!node)
    {
        exit(1); 
    }

    node->weight = weight;
    node->next = nullptr;

    return node;
}

StoneNode *createStoneNode(int weight, char symbol)
{
    StoneNode *node = new StoneNode;

    if (!node)
    {
        exit(1); 
    }

    node->symbol = symbol;
    node->weights = createWeightNode(weight);
    node->left = node->right = nullptr;

    return node;
}

void addStone(BinaryTree &tree, int weight, char symbol)
{
    if (!tree)
    {
        tree = createStoneNode(weight, symbol);
    }
    else
    {
        if (tree->symbol == symbol)
        {
            WeightNode *current = tree->weights;
            WeightNode *prev = nullptr;

            while (current)
            {
                prev = current;
                if (current->weight == weight)
                {
                    return; 
                }
                current = current->next;
            }

            prev->next = createWeightNode(weight);
        }
        else if (tree->symbol < symbol)
        {
            addStone(tree->right, weight, symbol);
        }
        else
        {
            addStone(tree->left, weight, symbol);
        }
    }
}

void buildTree(BinaryTree &tree)
{
    while (true)
    {
        int weight;
        string input;
        cin >> input;

        if (input == "-1") 
        {
            break;
        }

        cin >> weight;
        char symbol = *input.begin();

        addStone(tree, weight, symbol);
    }
}

bool searchStone(BinaryTree tree, char symbol, int weight, int &level, int &position)
{
    if (!tree)
    {
        return false;
    }

    if (tree->symbol == symbol)
    {
        WeightNode *current = tree->weights;

        while (current)
        {
            if (current->weight == weight)
            {
                return true; 
            }
            position++;
            current = current->next;
        }

        if (!current)
            return false;
    }
    else if (tree->symbol < symbol)
    {
        return searchStone(tree->right, symbol, weight, ++level, position);
    }
    else
    {
        return searchStone(tree->left, symbol, weight, ++level, position);
    }
}

int main()
{
    BinaryTree tree = nullptr;

    buildTree(tree);

    int level = 1, position = 0;

    int weight;
    char symbol;
    cin >> symbol >> weight;

    bool found = searchStone(tree, symbol, weight, level, position);

    if (found)
    {
        cout << level << ' ' << position;
    }

    return 0;
}
