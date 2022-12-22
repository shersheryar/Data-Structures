#include <iostream>
using namespace std;

class Stack{
    private:
        static const int  max = 100;
        int arr[max];
        int top;

    public:
        Stack(){
            top = -1;
        }
        bool isEmpty();
        int Top();
        bool isFull();
        void push(int x);
        int pop();
};
bool Stack :: isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}
bool Stack ::isFull(){
    if (top == max-1)
        return true;
    return false;

}
int Stack::Top(){
    return arr[top];
}
int Stack ::pop(){
    if(isEmpty()){

        cout << "Stack is underflow" << endl;
        abort();
    }
    int x = arr[top--];
    return x;
}

void Stack::push(int x)
{
    if (isFull()) {
        cout << "Stack Overflow";
        return;
    }
    top++;
    arr[top] = x;
}

class SpecialStack : public Stack{
    Stack min;
    public:
    int pop();
    void push(int x);
    int getMin();
};

void SpecialStack::push(int x){
    if(isEmpty() == true){
        Stack::push(x);
        min.push(x);
    }
    else{
        Stack::push(x);
        int y = min.pop();
        min.push(y);
        if(x < y){
            min.push(x);
        }
        else{
            min.push(y);
        }
    }
}
int SpecialStack::pop(){
    int x = min.pop();
    min.push(x);
    return x;
}

int SpecialStack::getMin(){
    int x = min.pop();
    min.push(x);
    return x;
}

int main()
{
    SpecialStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    // cout << s.getMin() << endl;
    s.push(5);
    cout << s.Top();
    return 0;
}