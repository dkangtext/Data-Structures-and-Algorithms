#include <iostream>
using namespace std;

struct Node
{
    char key;     // Ký hiệu viên đá
    int weight;   // Trọng lượng viên đá
    int count;    // Số lần xuất hiện
    Node *left;   // Con trái
    Node *right;  // Con phải

    Node(char k, int w) : key(k), weight(w), count(1), left(nullptr), right(nullptr) {}
};

typedef Node *Tree;

// Hàm chèn nút vào cây
void insertNode(Tree &root, char key, int weight)
{
    if (root == nullptr)
    {
        root = new Node(key, weight);
    }
    else if (key < root->key)
    {
        insertNode(root->left, key, weight);
    }
    else if (key > root->key)
    {
        insertNode(root->right, key, weight);
    }
    else
    {
        if (root->weight == weight)
        {
            root->count++;
        }
    }
}

// Hàm tìm độ cao và thứ tự xuất hiện của viên đá
void findStone(Tree root, char key, int weight, int level, int &occurrence, int &foundLevel, int &currentOrder, int &targetOrder)
{
    if (root == nullptr)
        return;

    // Duyệt trái
    findStone(root->left, key, weight, level + 1, occurrence, foundLevel, currentOrder, targetOrder);

    // Cập nhật thứ tự duyệt
    currentOrder++;

    // Nếu tìm thấy viên đá
    if (root->key == key && root->weight == weight)
    {
        if (foundLevel == -1) // Lưu độ cao nếu là lần đầu tiên tìm thấy
        {
            foundLevel = level;
        }
        if (occurrence == 0) // Thứ tự đầu tiên
        {
            targetOrder = currentOrder - 1; // Bắt đầu từ 0
        }
        occurrence++;
    }

    // Duyệt phải
    findStone(root->right, key, weight, level + 1, occurrence, foundLevel, currentOrder, targetOrder);
}

int main()
{
    Tree T = nullptr;
    char key;
    int weight;

    // Nhập thông tin các viên đá và chèn vào cây
    while (cin >> key >> weight)
    {
        if (key == '-' && weight == 1) // Điều kiện dừng
            break;
        insertNode(T, key, weight);
    }

    // Nhập viên đá cần tìm
    char targetKey;
    int targetWeight;
    cin >> targetKey >> targetWeight;

    int occurrence = 0;   // Số lần xuất hiện
    int foundLevel = -1;  // Độ cao của lần xuất hiện đầu tiên
    int currentOrder = -1; // Thứ tự duyệt hiện tại
    int targetOrder = -1; // Thứ tự xuất hiện của viên đá

    // Tìm viên đá
    findStone(T, targetKey, targetWeight, 1, occurrence, foundLevel, currentOrder, targetOrder);

    // Xuất kết quả
    if (foundLevel != -1)
    {
        cout << foundLevel << " " << targetOrder << endl; // In độ cao và thứ tự
    }
    else
    {
        cout << "0 0" << endl; // Không tìm thấy viên đá
    }

    return 0;
}
