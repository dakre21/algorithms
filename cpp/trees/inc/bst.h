#include <vector>

using namespace std;

struct Node
{
    Node(int data) : data(data) {
        // Do nothing
    }
    int data;
    struct Node* left, *right;
};

Node* root;

Node* createMinimalBST(const vector<int>& arr, int start, int end) {
    static int count = 0;

    if (end < start) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node* node = new Node(arr[mid]);
    if (0 == count) {
        count++;
        root = node;
    }

    node->left = createMinimalBST(arr, start, mid - 1);
    node->right = createMinimalBST(arr, mid + 1, end);

    return node;
}

bool findNode(int source) {
    Node* node = root;
    while (node != NULL) {
        if (node->data > source) {
            node = node->left;
        } else if (node->data < source) {
            node = node->right;
        } else {
            return true;
        }
    }
    return false;
}


