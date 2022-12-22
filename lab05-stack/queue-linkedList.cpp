#include <iostream>
using namespace std;

class node{
    public:
        node* next ;
        int data;
        node(int val){
            data  = val;
            next =  NULL;
        }
};

class Queue {
    private:
        node* rear;
        node* front;
        int length;
    public:
        Queue (){
            front = rear = NULL;
            length = 0;
        }
        void enqueue(int val);
        int dequeue();
        void display();
        bool isEmpty();
        int size();
};

int main(){
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);

    q1.display();
    cout << endl << "Queue size: " <<  q1.size() << endl;
    return 0;
}

int Queue::size(){
    return length;
}
bool Queue::isEmpty(){
    if(length == 0){
        return true;
    }
    else{
        return false;
    }
}
int Queue::dequeue(){
    node* curr = front;
    if(curr == NULL){
        cout << "List is Empty: Queue Under Flow, return -1" << endl;
        return -1;
    }
    else{
        int data = curr->data;
        front = curr->next;
        delete curr;
        length--;
        return data;
    }
}
void Queue::enqueue(int val){
    node* t = new node(val);
    if(rear == NULL){
        front = rear = t;
        length++;
    }
    else{
        rear->next = t;
        rear = t;
        length++;
    }
}
void Queue::display(){
    node* curr = front;
    while( curr != NULL){
        cout << "Node: " << curr->data << endl;
        curr = curr->next;
    }
}
