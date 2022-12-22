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
    void removeAt(int pos){
        curr = head;
        if(head == NULL){
            cout <<" List is empty" << endl;
            return;
        }
        else if(pos == 1){
            head = curr->next;
            delete curr; curr= NULL;
            length--;
        }
        else if(pos < 1 || pos > length){
            cout << "Invalid postion" <<endl;
            return;
        }
        else{
            node* temp = NULL;
            for(int i = 1; i < pos; i++){
                temp = curr;
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = NULL;
            delete curr;
            length--;

        }
    }
    void removeAt(int pos){
        curr = head;
        if(head == NULL){
            cout << "List is empty"<< endl;
            return;
        }
        else if (pos < 0 || pos > length){
            cout << " Invalid position" <<endl;
            return;
        }
        else{
            if (pos == 1){
                head = curr->next;
                delete curr;
                curr = NULL;
                length--;
                return;
            }
            else{
                node* temp = NULL;
                for(int i = 1; i < pos;i++){
                    temp = curr;
                    curr = curr->next;
                }
                temp->next = curr->next;
                curr->next = NULL;
                delete curr;
                length--;
            }
        }
        
    }
    void print(){
        curr = head;
        while (curr != NULL)
        {   
            cout<<curr->data <<"---->";
            curr = curr->next;
        }
        cout<<"NULL";
        
    }
};


int main(){
    linkedList obj;
    // obj.insert(4);
    // obj.insert(5);
    // obj.insert(56);
    // obj.insert(43);

    obj.insertAt(1,4);
    
    // obj.insertAt(1,3);
        
    obj.insertAt(1,5);
    obj.insertAt(2,8);
    obj.insertAt(3,0);
    obj.insertAt(5,9);
    obj.insertAt(5,6);
    // obj.removeAt(1);
    obj.removeAt(6);
    // obj.insertAt(2,7);

    obj.print();

}
