struct Node
{
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

struct HashTable
{
    int M; 
    int n;
    int loadFactor;
    Node** head;
}

int hashFucntion(int key, int M)
{
    return key % M;
}