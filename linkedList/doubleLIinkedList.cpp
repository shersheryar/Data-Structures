#include <iostream>
using namespace std;

class DoubleLinkedList
{
    class node
    {
    public:
        node *next;
        node *previous;
        int data;
        node(int val)
        {
            data = val;
            next = NULL;
            previous = NULL;
        }
    };

    private: 
        node *head;
        int length;

    public:
    DoubleLinkedList(){
        head = NULL;
        length = 0;
    }
    int size(){
        return length;
    }
    void setSize(int l){
        this->length = l;
    }
    node* getHead(){
        node* curr = head;
        return curr;
    }
    void insert(int val){
        node* t = new node(val);
        if(head = NULL) { //head is empty
            head = t;
            length++;
        }
        else {
            node* curr = head;
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = t;
            t->previous = curr;
            length++;
        }
    }
    void insetAt(int pos, int val){
        if(pos < 1 || pos > length + 1){
            cout <<" Invalid position. " <<endl;
            return;
        }
        node* t=  new node(val);
        if(pos == 1) { //when we want to inserting new node before head
            if(head == NULL){
                head = t;
                length++;
            }
            else{ //head is already exit, inserting new node
                t->next = head;
                head->previous = t;
                head = t;
                length++;
            }
        }
        else{
            //position can be in center or in last
            node* curr = head;
            for(int i = 1; i < pos-1; i++){
                curr = curr->next;
            }
            t->next = curr->next;
            t->previous = curr;
            if(curr->next != NULL){
                curr->next->previous = t;
            }
            curr->next = t;
            length++;
        }
    }
    void removeAt(int pos){
        node* curr = head;
        if(head = NULL){
            cout <<"List is empty" <<endl;
        }
        if(pos == 1) {
            //for deleting head
            head = curr->next;
            head->previous = NULL;
            delete curr; curr = NULL;
            length--;          
        }
        else{
            //for deleting any other node
            node* temp = NULL;
            for(int i= 0; i <pos -1; i++){
                temp = curr;
                curr = curr->next;
            }
            temp->next = curr->next;
            if(curr->next != NULL){
                curr->next->previous = temp;
            }
            delete curr; curr = NULL;
            length--;
        }
    }
    void printList(){
        // cout <<" hello";
        node* curr = head;
        while(curr->next){
            cout << curr->data <<"\t" <<endl;
            curr = curr->next;
        }
        cout<< curr->data <<"\t" <<endl;
    }
};

int main(){
    DoubleLinkedList list1;
    // cout <<"hellowrold";
    list1.insert(100);
    list1.insetAt(1,1);
    list1.insetAt(2,2);
    list1.insetAt(3,3);
    list1.insetAt(4,4);
    list1.removeAt(4);
    list1.printList();
}