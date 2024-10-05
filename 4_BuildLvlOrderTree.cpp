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
void buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    int data;
    cout << "Enter Data: ";
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        int leftData, rightData;
        cout << "Enter Left data for " << temp->data << " : ";
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter Right data for " << temp->data << " : ";
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root), q.push(NULL);
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
    buildFromLevelOrder(root);
    cout << "Level Order Traversal:\n";
    levelOrderTraversal(root);
    return 0;
}