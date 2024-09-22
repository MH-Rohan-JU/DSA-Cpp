#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(Node *&head, Node *&tail, int val)
{
    if (head == NULL)
    {
        Node *temp = new Node(val);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
    }
}
void insertAtTail(Node *&tail, Node *&head, int val)
{
    if (tail == NULL)
    {
        Node *temp = new Node(val);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(val);
        tail->next = temp;
        tail = temp;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int position, int val)
{
    Node *middle = new Node(val);
    Node *temp = head;
    int cnt = 1;
    if (position == 1)
    {
        insertAtHead(head, tail, val);
        return;
    }
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, val);
        return;
    }
    middle->next = temp->next;
    temp->next = middle;
}
void del_Element(Node *&head, Node *&tail, int position)
{
    Node *temp = head;
    Node *del;
    if (position == 1)
    {
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int cnt = 1;
    while (cnt < position - 1)
    {
        cnt++;
        temp = temp->next;
    }
    del = temp->next;
    if (del->next == NULL)
    {
        tail = temp;
        temp->next = NULL;
        delete del;
        return;
    }
    temp->next = del->next;
    del->next = NULL;
    delete del;
}
void printLinkedList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    // Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    // Node *head = node1;
    // Node *tail = node1;
    Node *head = NULL, *tail = NULL;
    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 16);
    insertAtTail(tail, head, 8);
    insertAtTail(tail, head, 4);
    insertAtPosition(head, tail, 1, 5);
    insertAtPosition(head, tail, 5, 11);
    printLinkedList(head);
    del_Element(head, tail, 6);
    printLinkedList(head);
    del_Element(head, tail, 3);
    printLinkedList(head);
    return 0;
}