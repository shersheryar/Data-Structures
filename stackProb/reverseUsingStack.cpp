#include <iostream>
#include <stack>
using namespace std;

///reverse a  sentence
void reverseSentence(string s){
    stack<char> st;
    for(int i = 0; i<s.length();i++){
        st.push(s[i]);
    } 
    while(!st.empty()){
        cout << st.top() << "";
        st.pop();
    }
    cout << endl;
}

//insert at bottom through recursion
void insertAtBottom(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(topele);
}
//reverse a stack using recursion
void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, ele);
}
int main(){
    string s= "hey, how are you doing";
    reverseSentence(s);
    stack<int> st; 
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}