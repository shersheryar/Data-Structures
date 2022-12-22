#include <iostream>
using namespace std;
class Node{
    public:
        int processId;
        string state;
        int time; 
};
class Queue :public Node{
    private:
        Node *arr;
        int size;
        int rear, front;
        int noOfElements;
        public:
            Queue(int size){
                this->size = size;
                arr = new Node[size];
                rear = -1, front = -1, noOfElements = 0;
            }
            ~Queue(){
                delete []arr;
            }
            void enqueue(){
                cout << " enter the required entries" << endl;
                int Exit = 0;
                int pI = 0;
                string pS = " ";
                int t = 0;
                while(Exit != -1 && (noOfElements != size)){
                    cout << " Enter the process id: "; cin>> pI;
                    cout << " Enter the State : "; cin>> pS;
                    cout << " Enter the time: "; cin>> t;
                    if(rear == size-1){
                    cout << " Stack overflow" << endl;
                    return;
                    }
                    if(front == -1){
                        front = 0;
                    }
                    rear++;
                    arr[rear].processId = pI;
                    arr[rear].state = pS;
                    arr[rear].time = t;
                    noOfElements++;

                    cout << "press -1 to quit: "; cin >> Exit;
                }
             
            }
            Node dequeue(){
                if(front == -1){
                    cout <<"Queue Underflow";
                }
                else{
                    // cout << "Element deleted from queue is: " << arr[front] << endl;
                    return arr[front++];
                }
            }
            void display(){
                if(front == -1){
                    cout << " Queue is empty" << endl;
                }
                else{
                    cout << "Queue elements are: ";
                    for(int i = front; i<=rear; i++ ){
                        cout << "The process ID: " <<arr[i].processId <<"'s completed in : " << arr[i].time << " and State is: " << arr[i].state << endl;
                    }
                    cout << endl;
                }
                

            }
};
int main(){
    Queue q1(2);
    q1.enqueue();
    q1.dequeue();
    q1.display();
    return 0;
}