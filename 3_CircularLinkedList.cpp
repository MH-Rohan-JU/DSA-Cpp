#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
class node {
  public:
    int data;
    node *next = NULL;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
void insertNode(node *&head, int data, int value) {
    if (head == NULL) {
        node *temp = new node(data);
        head = temp;
        head->next = temp;
        return;
    }
    node *temp = head;
    node *add = new node(data);
    while (temp->data != value) {
        temp = temp->next;
    }
    add->next = temp->next;
    temp->next = add;
}
void deleteValue(node *&head, int value) {
    node *temp = head, *dlt;
    while (temp->next->data != value) {
        temp = temp->next;
    }
    dlt = temp->next;
    if (dlt == head) {
        head = dlt->next;
    }
    temp->next = dlt->next;
    dlt->next = NULL;
    delete dlt;
}
void printcircular(node *&head) {
    node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    node *head = NULL;
    insertNode(head, 1, 1);
    insertNode(head, 3, 1);
    insertNode(head, 7, 3);
    insertNode(head, 5, 3);
    printcircular(head);
    cout << head->data << endl;
    deleteValue(head, 1);
    printcircular(head);
    cout << head->data << endl;
    return 0;
}