#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
// ===========Insert at head==========================
void insertAtHead(node* &head,int val){
    node* n= new node(val);
    if(head == NULL){
        n->next = n;
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
// ================insert at tail=====================
void insertAtTail(node* &head,int val){
    node* value = new node(val);
    node* temp = head;
    if(head == NULL){
        insertAtHead(head,val);
        return;
    }

    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = value;
    value->next=head;
}
// ================Tail======================================
void print(node* head ){
    node* curr = head;
    do
    {
        cout<<curr->data<< "->";
        curr = curr->next;
    } while (curr!=head);
    
    cout <<"NULL" << endl;
}
// ====================Delete at last==========================
void deleteAtLast(node* &head){
    node* curr = head;
    while(curr->next->next != head){
        curr = curr->next;
    }
    node* temp = curr->next;
    curr->next = head;
    delete temp;
}
//=====================delete at head===========================
void deleteAtHead(node* &head){
    node* curr = head;
        while(curr->next != head){
            curr = curr->next;
        }
        node* temp = head;
        curr->next = head->next;
        head = head->next;
        delete temp;
        temp=NULL;
}
// ==============delete at any position========================
void deletion(node* &head, int pos){
    node* curr = head;
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    int count = 1;
    while(count != pos-1){
        curr = curr->next;
        count++;
    }
    node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}
int main(){
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtHead(head,0);
    print(head);
    deletion(head,1 );
    // deleteAtHead(head);
    print(head);

}