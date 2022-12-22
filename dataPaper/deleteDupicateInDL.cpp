#include <iostream>
#include <unordered_set>

struct Node {
  int data;
  Node* prev;
  Node* next;
};

void deleteDuplicates(Node* head) {
  // Use an unordered set to store the values of the nodes we have seen
  std::unordered_set<int> seen;

  // Keep track of the current node
  Node* curr = head;

  // While we are not at the end of the list
  while (curr != nullptr) {
    // If we have seen the value of the current node before
    if (seen.count(curr->data) > 0) {
      // Remove the current node from the list by updating the next and prev pointers
      curr->prev->next = curr->next;
      if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
      }

      // Free the memory for the current node
      delete curr;
    } else {
      // Otherwise, add the value of the current node to the set
      seen.insert(curr->data);
    }

    // Move to the next node
    curr = curr->next;
  }
}


int main() {
  // Initialize the doubly linked list
  Node* head = new Node{1, nullptr, nullptr};
  head->next = new Node{2, head, nullptr};
  head->next->next = new Node{2, head->next, nullptr};
  head->next->next->next = new Node{3, head->next->next, nullptr};
  head->next->next->next->next = new Node{3, head->next->next->next, nullptr};

  // Print the list before deleting duplicates
  std::cout << "Before deleting duplicates:" << std::endl;
  Node* current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;

  // Delete duplicates
  deleteDuplicates(head);

  // Print the list after deleting duplicates
  std::cout << "After deleting duplicates:" << std::endl;
  current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;

  return 0;
}
