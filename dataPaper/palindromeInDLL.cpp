// Question 
//write a program in c++ that use recursion to check whether a doubly linked list, having single character
//  in every node as info, is palindrom or not
#include <iostream>
using namespace std;

struct Node {
  char data;
  Node* prev;
  Node* next;
};

// Function to check if the linked list is a palindrome
bool isPalindrome(Node* left, Node* right) {
  // If left and right pointers meet at the same node, the linked list is a palindrome
  if (left == right) return true;

  // If the data in the left and right nodes do not match, the linked list is not a palindrome
  if (left->data != right->data) return false;

  // Check the rest of the list recursively
  return isPalindrome(left->next, right->prev);
}

int main() {
  // Assume a doubly linked list with head node 'head' and tail node 'tail' is already created
    Node* head = NULL;
    Node* tail = NULL;
  // Check if the linked list is a palindrome
  if (isPalindrome(head, tail)) {
    cout << "The linked list is a palindrome." << endl;
  } else {
    cout << "The linked list is not a palindrome." << endl;
  }

  return 0;
}
