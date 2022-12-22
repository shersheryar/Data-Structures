#include <iostream>
using namespace std;

class Queue {
    private:
        int *arr;
        int *tempArr;
        int size;
        int rear, front;
        int tempRear, tempFront;
        int noOfElements;
        public:
            Queue(int size){
                this->size = size;
                arr = new int[size];
                tempArr = new int[size];
                rear = -1, front = -1,tempRear = -1,tempFront = -1, noOfElements = 0;
            }
            ~Queue(){
                delete []arr;
            }
            void enqueue(int val){
                if(rear == size-1){
                    cout << " Stack overflow" << endl;
                    return;
                }
                if(front == -1){
                    front = 0;
                }
                // if(tempFront == -1){
                //     front = 0;
                // }
                if(rear == -1){
                    arr[++rear] = val;
                    noOfElements++;   
                }
                else if(rear != -1){
                    // cout << " arr " << endl;
                    while( front <= rear  ){
                        // cout << "hellow" << endl;
                        tempArr[++tempRear] = arr[front++];
                        cout <<  tempArr[tempRear]<< endl;
                    }
                    // rear = -1;
                    // front = 0;
                    // cout << "temp " << endl;
                    arr[++rear] = val;
                    while( tempRear > tempFront){
                        arr[++rear] = tempArr[++tempFront];
                        // cout << arr[rear] << endl;
                    }
                    
                    noOfElements++;  
                }


                
            }
            int dequeue(){
                if(front == -1){
                    cout <<"Queue Underflow";
                    return -1;
                }
                else{
                    cout << "Element deleted from queue is: " << arr[front] << endl;
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
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                }
                

            }
};
int main(){
    Queue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    // q1.display();
    q1.dequeue();
    q1.display();
    return 0;
}