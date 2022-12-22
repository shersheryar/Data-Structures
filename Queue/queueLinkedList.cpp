#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node (int val){
        data = val;
        next = NULL;
    }
};
class queue{
     node* front;
  node* back;
  public:
  queue(){
    front = NULL;
    back = NULL;
  }
  void push(int x){
    node* n = new node(x);
    if(back == NULL){
        back = n;
        front = n;
        return;
    }
    back->next = n;
    back =n;
  }  
  void pop(){
    if(front == NULL){
        cout << "queue underflow" << endl;
    }
    node* todel = front; 
    if(front->next == NULL){
        back = front->next;
    }
    front = front->next;

    delete todel;
  }
  int peek(){
    if(front == NULL){
        cout << "no element in queue" << endl;
    }
    else{
        return front->data;
    }
  }
  bool empty(){
      if(front == NULL){
        return true;
        }
        else{
            return false;
        }
  }
};
int main(){
    queue q;
    q.push(1);
    q.push(12);
    q.push(13);
    q.push(14);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
}