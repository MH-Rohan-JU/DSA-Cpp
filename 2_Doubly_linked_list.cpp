#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};
int length(node *head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void printList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insertAtHead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(node *&tail, int data)
{
    node *temp = new node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(node *&head, node *&tail, int data, int position)
{
    int count = 1;
    node *temp = head;
    node *mid = new node(data);
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    mid->next = temp->next;
    temp->next->prev = mid;
    temp->next = mid;
    mid->prev = temp;
}
void del_element(node *&head, node *&tail, int position)
{
    node *temp = head;
    if (position == 1)
    {
        head = temp->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    int count = 1;
    while (count < position)
    {
        count++;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        tail = temp->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    temp->prev = NULL, temp->next = NULL;
    delete temp;
}
int main()
{
    node *n1 = new node(10);
    node *head = n1;
    node *tail = n1;
    insertAtHead(head, 7);
    insertAtHead(head, 3);
    insertAtTail(tail, 12);
    insertAtTail(tail, 18);
    insertAtPosition(head, tail, 15, 3);
    printList(head);
    cout << length(head) << endl;
    del_element(head, tail, 4);
    printList(head);
    cout << length(head) << endl;
    del_element(head, tail, 5);
    printList(head);
    cout << length(head) << endl;
    return 0;
}