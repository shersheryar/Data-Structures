// Question
// Assume singly link list exists in a memory. 
// find the middle node of singly linked list recursively in cpp
#include <iostream>
using namespace std;
struct Node {
  int data;
  Node* next;
};

Node* findMiddle(Node* head, int length) {
  if (length == 0) return head;
  if (length == 1) return head->next;
  return findMiddle(head->next, length - 2);
}

int main() {
  // Assume a singly linked list with head node 'head' is already created
Node* head = NULL;
  int length = 0;
  Node* temp = head;
  while (temp != NULL) {
    length++;
    temp = temp->next;
  }

  Node* middle = findMiddle(head, length);
  cout << "Middle node: " << middle->data << endl;

  return 0;
}
