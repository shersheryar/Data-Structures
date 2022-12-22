#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* previous;

        node(int val){
            data = val;
            next = NULL;
            previous = NULL;
        }
};
void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if(head != NULL){
        head->previous = n;
    }
    head = n;
}
void insertionAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        insertAtHead(head,val);
        return;
    }
    node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = n;
    n->previous = curr;
}
void deleteAtHead(node* &head){
    node* temp = head;
    head = head->next;
    head->previous = NULL;
    delete temp; temp = NULL;

}
void deletion(node* &head, int pos){
    if(head == NULL){
        cout << " list is empty";
        return;
    }
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(temp != NULL && count != pos){
        temp = temp->next;
        count++;
    }
    
    temp->previous->next = temp->next;
    if(temp->next != NULL){
            temp->next->previous = temp->previous;

    }

    delete temp; temp = NULL;

}
int length(node* head){
    node* curr = head;
    int l = 0;
    while(curr != NULL){
        l++;
        curr = curr->next;
    }
    return l; 
}
node* lastKNodes(node* &head, int k){
    node* curr = head;
    int count = 0;
    node* newTail = NULL;
    node* newHead = NULL;
    int l = length(head);
    k = k%l;
    while(curr->next != NULL ){
       
        if ( count == (l-k-1)){
            newTail = curr;
            newHead = curr->next;
        }
        curr = curr->next;
        count++;
    }
    newTail->next = NULL;
    curr->next = head;
    return newHead;
}
void print(node* head ){
    node* curr = head;

    while(curr != NULL){
        cout<< curr->data <<"-->";
        curr = curr->next;
    }
    cout <<"NULL" << endl;
}

int main(){
    node* head = NULL;
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 3);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    insertAtHead(head, 7);
    // print(head);
    insertionAtTail(head, 19);
    insertionAtTail(head, 1);
    insertionAtTail(head, 21);
    // deletion(head,1);
    // deleteAtHead(head);
    // print(head);
    // node* newHead = lastKNodes(head, 11);
    // print(newHead);  
    
}