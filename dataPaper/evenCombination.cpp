// Question
// Assume Singly Link List with integer info exists in memory.
//  Write code that counts how many combinations of 
// adding two numbers of two nodes generate even numbers in cpp

#include <iostream>
using namespace std;


// define a Node class to represent each node in the linked list
class Node {
public:
    int info;
    Node* next;
    Node(int info) : info(info), next(nullptr) {}
};

// define a LinkedList class to represent the linked list
class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void add_node(int info) {
        Node* new_node = new Node(info);
        new_node->next = head;
        head = new_node;
    }

    int count_even_combinations() {
        // initialize a counter for the number of even combinations
        int even_combinations = 0;

        // iterate through the linked list and check each combination of two nodes
        Node* current_node = head;
        while (current_node != nullptr) {
            // set the second node to the next node in the linked list
            Node* second_node = current_node->next;
            while (second_node != nullptr) {
                // check if the sum of the two node values is even
                if ((current_node->info + second_node->info) % 2 == 0) {
                    // if the sum is even, increment the counter
                    even_combinations++;
                }
                // set the second node to the next node in the linked list
                second_node = second_node->next;
            }
            // set the current node to the next node in the linked list
            current_node = current_node->next;
        }

        // return the final count of even combinations
        return even_combinations;
    }
};

int main() {
    // create a new linked list
    LinkedList linked_list;

    // add some nodes to the linked list
    linked_list.add_node(1);
    linked_list.add_node(2);
    linked_list.add_node(3);
    linked_list.add_node(4);

    // count the number of even combinations
    int even_combinations = linked_list.count_even_combinations();

    // print the result
    std::cout << even_combinations << std::endl;

    return 0;
}
