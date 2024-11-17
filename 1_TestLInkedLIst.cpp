// Make a linked list which inserts odd numbers at Head and Even Numbers at Tail
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
class node {
  public:
    int data;
    node *next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
void insertHead(node *&head, int d) {
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void insertTail(node *&tail, int d) {
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void insertPosition(node *&head, int p, int d) {
    node *mid = new node(d);
    node *temp = head;
    int cnt = 1;
    while (cnt < p - 1) {
        temp = temp->next;
        cnt++;
    }
    mid->next = temp->next;
    temp->next = mid;
}
void delnode(node *&head, int p) {
    node *temp = head;
    node *del;
    int cnt = 1;
    while (cnt < p - 1) {
        temp = temp->next;
        cnt++;
    }
    del = temp->next;
    temp->next = del->next;
    del->next = NULL;
}
void printList(node *&head) {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main() {
    node *node1 = new node(1);
    node *head = node1;
    node *tail = node1;
    insertHead(head, 3);
    insertTail(tail, 2);
    insertPosition(head, 2, 10);
    delnode(head, 3);
    printList(head);
    return 0;
}