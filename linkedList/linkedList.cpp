#include <iostream>
// #pragma once
using namespace std;

class node{
    public:
    node* next;
    int data;
    node(int val){
        data = val;
        next = NULL;
    }
};

class SingleLinkedList{
    private:
    node* head;
    int length;

    public:
    SingleLinkedList(){
        head = NULL;
        length = 0;
    }
    //Insertion in single linked list
    void Insert(int val){
        node* t = new node(val);
        if(head == NULL) { //head is empty
            head = t;
            length++;
        }
        else{
            node* curr = head;
            while(curr->next !=NULL){
                curr = curr->next;
            }
            curr->next = t;
            length++;
        }
    }
    void insertAt(int pos, int val){
        if(pos<1 || pos > length +1){
            cout <<"Invalid positon" <<endl;
            return;
        }
        node* t = new node(val);
            if(pos ==1){ //when we wnat to inserting new node
                if(head == NULL){
                    head = t;
                }
                else{ //head is already exit inseting new 
                    t->next = head;
                    head = t;
                }
                length++;
            }
            else{
                //position can be in center or in last
                node* curr = head;
                node* pre = head;
                for(int i = 1;i<pos-1;i++){
                    pre = curr;
                    curr = curr->next;
                }
                pre->next = t;
                if(curr != NULL){ //if its not a last node
                    t->next = curr;
                }
                length++;
        }
    }
    void print(){
        cout <<"printing the single lingked list" << endl;
        cout <<"Head--->";
        node *curr = head;
        while(curr != NULL){
            cout <<curr->data <<"--->";
            curr = curr->next;
        }
        cout <<"NULL";
    }
    //removing node from list
    //what aobut removing nide through recursion.....?
    void removeAt(int pos){
        node* curr = head;
        if(head == NULL){
            cout <<"LIST is empty";
            return;
        }
        if (pos == 1){//for deleting head
            head = curr->next;
            delete curr;
            length--;
        }
        else{
            //deleting for other node
            node* temp= NULL;
            for(int i = 0; i < pos -1; i++ ){
                temp = curr;
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next= NULL;
            delete curr;
            length--;
        }
    }
};

int main(){
    SingleLinkedList obj;
    obj.Insert(11);
    obj.Insert(12);
    obj.Insert(13);
    obj.Insert(14);
    obj.Insert(15);
    obj.Insert(16);
    // obj.insertAt(1,300);
    // obj.removeAt(22);
    //   obj.insertAt(1,4);
    
    // obj.insertAt(1,3);
        
    // obj.insertAt(1,5);
    // obj.insertAt(2,8);
    // obj.insertAt(3,0);
    
    obj.print();

    return 0;
}