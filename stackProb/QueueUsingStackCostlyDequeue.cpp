//cpp program to implement queue using
//two stacks with costly dequeue
#include <iostream>
#include <stack>
using namespace std;

struct Queue{
    stack<int> s1,s2;

    public:
    //enqueue an item to the queue
    void enQueue(int x){
        //push item into the first stack
        s1.push(x);
    }
    //dequeue item from queue
    int deQueue(){
        //if both stack are empty
        if(s1.empty() && s2.empty()){
            cout << "Queue to empty" << endl;
            return -1;
        }
        //if s2 is empty, move
        //elements from s1
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

        }
            int x = s2.top();
            s2.pop();
            return  x;

    }
};

int main(){
    Queue q1;
    cout << q1.deQueue() << endl;
    q1.enQueue(1);
    q1.enQueue(2);
    q1.enQueue(3);
    q1.enQueue(4);
    cout << q1.deQueue() << endl;
    cout << q1.deQueue() << endl;
    cout << q1.deQueue() << endl;
    cout << q1.deQueue() << endl;
}
