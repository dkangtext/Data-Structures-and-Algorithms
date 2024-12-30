#include <iostream>
using namespace std;

struct Node {
    char key;
    int weight;
    int count;
    Node* left;
    Node* right;
    Node(char k, int w) : key(k), weight(w), count(1), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;
    int total_occurrence;
    int found_height;
    char target_key;
    int target_weight;

    Node* insert(Node* node, char key, int weight, int depth) {
        if (!node) {
            Node* newNode = new Node(key, weight);
            if (tolower(key) == tolower(target_key) && weight == target_weight) {
                found_height = depth;
                total_occurrence++;
            }
            return newNode;
        }

        if (tolower(key) < tolower(node->key))
            node->left = insert(node->left, key, weight, depth + 1);
        else if (tolower(key) > tolower(node->key))
            node->right = insert(node->right, key, weight, depth + 1);
        else {
            // Handle duplicate keys
            if (tolower(key) == tolower(target_key) && weight == target_weight) {
                total_occurrence++;
            }
        }

        return node;
    }

public:
    BST() : root(nullptr), total_occurrence(0), found_height(-1), target_key('\0'), target_weight(0) {}

    void reset() {
        root = nullptr;
        total_occurrence = 0;
        found_height = -1;
        target_key = '\0';
        target_weight = 0;
    }

    void insert_stone(char key, int weight, char target, int target_w) {
        target_key = target;
        target_weight = target_w;
        root = insert(root, key, weight, 1);
    }

    pair<int, int> get_result() {
        return {found_height, total_occurrence > 0 ? total_occurrence - 1 : -1};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    BST bst;
    char key;
    int weight;

    // Input stones
    while (true) {
        cin >> key;
        if (key == '-' && cin.peek() == '1') {
            cin.ignore();
            break;
        }
        cin >> weight;
        bst.insert_stone(key, weight, key, weight);
    }

    // Input target stone
    char target_key;
    int target_weight;
    cin >> target_key >> target_weight;

    // Find and output result
    bst.insert_stone(target_key, target_weight, target_key, target_weight);
    pair<int, int> result = bst.get_result();

    cout << result.first << " " << result.second << endl;

    return 0;
}
