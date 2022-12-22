#include <iostream>
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
class linkedList{
    private:
    node* head;
    int length;
    node* t;
    node* curr;
    
    public:
    linkedList(){
        head = NULL;
        length = 0;
    }
    // void insert(int val){
        
    //     node* t= new node(val);
    //     if(head == NULL){
    //         head = t;
    //         length++;  
    //     }
    //     else{
    //         node* curr = head;
    //         while(curr->next != NULL){
    //             curr = curr->next;
    //         }
    //         curr->next = t;
    //         length++;
    //     }
    // }

    void insert(int val){
        t = new node(val);
        
        if(head == NULL){
            head = t;
            length++;
        }
        else{
            node* curr = head;
            
            while(curr->next != NULL){
                // cout <<"curr: "<<curr->data;
                curr = curr->next;
            }
            curr->next = t;
            length++;
        }
    }
    void insertAt(int pos, int val){
        if(pos < 1 || pos > length + 1){
            cout <<" Invalid position" <<endl;
            return;
        }
        t = new node(val);
        if (pos == 1)
        {
            if (head == NULL)
            {
                head = t;
                length++;
            }
            else{
                t->next = head;
                head = t;
                length++;
            }
        }
        else{
            curr = head;
            
            for (int i = 1; i < pos-1; i++)
            {  
                curr = curr->next;
            }
            if(curr->next != NULL){
                t->next = curr->next;
            }
            curr->next = t;
            length++;
        }
        
        
    }
    void mode(){
        curr = head;
        if(curr == NULL){
            cout <<" linked list is empty";
        }
        if(curr->next == NULL){
            cout <<" mode is: " << curr->data;
        }
        int oldCount = 0;
        int mode = 0;
        while(curr!=NULL){
            int count = 0;
            node* temp1 = head;
            while (temp1 != NULL)
            {
                if(curr->data == temp1->data){       
                    count++;
                }
                cout<<curr->data <<"->" << count <<"    ";
                temp1 = temp1->next;   
            }
            if(count > oldCount){
                oldCount = count;
                mode = curr->data;
                // cout << "mode is: " << mode;
            }
            curr = curr->next;
            // cout <<"dfd"<< curr->data;
        }
        cout <<" mode is: " << mode <<endl;
    }
    void medium(){
        int newlen = length/2;
        curr = head;
        for(int i = 0;i < newlen;i++){
            curr = curr->next;
        }
        cout << " medium is: " << curr->data;
    }

    void reverse(linkedList ob){
        curr = head;
        if(curr == NULL){
            cout << " list is empty" << endl;
        }
        if(curr->next == NULL){
            ob.insert(curr->data);
        }
        node* previous = NULL;
        node* Next = NULL;
        while(curr != NULL)
        {   
            Next = curr->next;

            curr->next = previous;
            previous = curr;
            curr = Next;
            // ob.insert(previous->data);
                
        }
        curr = previous;
        while(curr != NULL){
            cout << curr->data <<"->";
            curr = curr->next;
        }
        // cout << "NULL";
    }
    void print(){
        curr = head;
        while (curr != NULL)
        {   
            cout<<curr->data <<"---->";
            curr = curr->next;
        }
        cout<<"NULL";
        cout<<endl;

    }
};
int main(){
    linkedList obj, ob;
    obj.insert(4);
    obj.insert(5);
    obj.insert(56);
    obj.insert(4);

    obj.insertAt(1,4);
    
    obj.insertAt(1,3);
        
    obj.insertAt(1,5);
    obj.insertAt(2,8);
    // obj.insertAt(3,0);
    obj.insertAt(5,9);
    obj.insertAt(5,6);
    // obj.removeAt(1);
    // obj.removeAt(6);
    obj.insertAt(2,7);

    obj.print();
    // obj.mode();
    // obj.medium();
    // obj.print();
    obj.reverse(ob);
    // ob.print();
}