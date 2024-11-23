#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class node {
  public:
    int data;
    node *left, *right;
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void insert(node *&root, int data) {

    if (root == NULL) {
        root = new node(data);
        return;
    }

    if (data <= root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

void inOrder(node *root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    return;
}

void preOrder(node *root) {

    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    return;
}

void postOrder(node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
    return;
}

int main() {
    node *root = NULL;
    int data;

    cout << "Enter datas to create a BST. Enter -1 to Terminate: ";
    cin >> data;
    while (data != -1) {
        insert(root, data);
        cin >> data;
    }

    cout << "\nIn Order Traversal: ";
    inOrder(root);

    cout << "\nPre Order Traversal: ";
    preOrder(root);

    cout << "\nPost Order Traversal: ";
    postOrder(root);

    return 0;
}