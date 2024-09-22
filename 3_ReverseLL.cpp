#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertHead(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
        return;
    }
}
void insertTail(node *&head, node *&tail, int data)
{
    if (tail == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
        return;
    }
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}
void printLL(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void reverseLL(node *&head)
{
    node *prev = NULL, *curr = head, *forward = curr;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}
int main()
{
    node *head = NULL, *tail = NULL;
    insertTail(head, tail, 1);
    insertTail(head, tail, 3);
    insertTail(head, tail, 5);
    insertTail(head, tail, 7);
    printLL(head);
    reverseLL(head);
    printLL(head);
    return 0;
}