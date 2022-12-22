#include <iostream>
using namespace std;

class node{
    public:
    node* next;
    node* previous;
    int data;
    node(int val){
        data = val;
        next = NULL;
        previous = NULL;
    }
};
class DoubleLinkedList{
    private:
    node* head;
    int length;
    node* curr;
    node* value;

    public:
    DoubleLinkedList(){
        head = NULL;
        curr = NULL;
        value = NULL;
        length = 0;
    }
    void insert(int val){
        value = new node(val);
        if(head == NULL){
            head = value;
            length++;
        }
        else{
            curr = head;
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = value;
            value->previous = curr;
            length++;
        }
    }
    void insertAt(int pos, int val){
        if(pos < 1|| pos > length + 1){
            cout << "Invalid positions " <<endl;
        }
        value = new node(val);
        if (pos == 1)
        {
            if(head == NULL){
                head = value;
                length++;
            }
            else{
                value->next = head;
                head->previous = value;
                head = value;
                length++;
            }
        }
        else{
            curr = head;
            for(int i = 1; i < pos ;i++){
                curr = curr->next;
            }
            curr->previous->next = value;
            value->previous = curr->previous;
            curr->previous = value;
            value->next = curr;
            length++;
        }
    }
    void print(int order){
        curr = head;
        if(order == 1){
            while(curr != NULL){
            cout << curr->data <<"\t";
            curr = curr->next;
            }
        } 
        else if(order == 2){
            // cout <<length <<"      ";
            for(int i = 1; i < length; i++){
                curr= curr->next;
                // cout <<curr->data <<" ";
            }
            while (curr != NULL)
            {
                cout << curr->data << "\t";
                curr = curr->previous;
            }
        }
    }
    void removeAt(int pos){
        curr = head;
        if(pos < 1 || pos > length){
            cout << "invalid position" << endl;
            return;
        }   
        else if(pos == 1){
            if(head == NULL){
                cout << "list is empty" << endl;
                return;
            }
            else{
                // curr->next->previous = NULL
                head = curr->next;
                head->previous = NULL;
                delete curr; curr = NULL;
                length--;
            }
        }
        else{
            node* temp = NULL;
            for(int i = 1; i < pos; i++){
                temp = curr;
                curr = curr->next;
            }
            temp->next = curr->next;
            if(curr->next != NULL){
                curr->next->previous = temp;
            }
            delete curr; curr= NULL;
            length--;
        }
    }
};

int main(){
    DoubleLinkedList obj;
    obj.insert(1);
    obj.insert(2);
    obj.insert(4);
    obj.insert(5);
    obj.insertAt(2,0);
    // obj.print(2);
    obj.removeAt(4);
    obj.print(1);
}   