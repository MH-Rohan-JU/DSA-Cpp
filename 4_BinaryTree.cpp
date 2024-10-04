#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
class node
{
public:
    int data;
    node *left, *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *binaryTree(node *root)
{
    int data;
    cout << "Enter Data: " << endl;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Left Node of parent " << data << " ";
    root->left = binaryTree(root->left);
    cout << "Right Node of parent " << data << " ";
    root->right = binaryTree(root->right);
    return root;
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    node *root = NULL;
    root = binaryTree(root);
    levelOrderTraversal(root);
    return 0;
}