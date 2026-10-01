#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* createTree(int n) {
    if (n == 0)
        return NULL;

    int value;
    cin >> value;

    Node* root = new Node(value);
    queue<Node*> q;
    q.push(root);

    int count = 1;

    while (count < n) {
        Node* current = q.front();
        q.pop();

        cin >> value;
        current->left = new Node(value);
        q.push(current->left);
        count++;

        if (count < n) {
            cin >> value;
            current->right = new Node(value);
            q.push(current->right);
            count++;
        }
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
}

int main() {
    int n;

    cout << "Enter number of nodes and their values: ";
    cin >> n;

    Node* root = createTree(n);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nLevel Order: ";
    levelOrder(root);

    return 0;
}