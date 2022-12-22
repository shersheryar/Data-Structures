// Queue using Stacks

#include <iostream>
#include <stack>
using namespace std;

class Queue{
    stack<int> s1, s2;

    public:
        void enQueue(int x){
            //move all elements from s1 to s2
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            //push item into s1
            s1.push(x);

            //Push everything back to s1
            while (!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
           
        }
        // dequeue an item fron the queue
        int  deQueue(){
            //if first stack is empty
            if(s1.empty()){
                cout << " Queue is Empty" << endl;
                return -1;
            }
        
            //return top of s1
            int x = s1.top();
            s1.pop();
            return x;
        
        }
};

int main(){
    Queue q;
    // cout << q.deQueue() << endl;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
}