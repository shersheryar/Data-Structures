#include<bits/stdc++.h>
using namespace std;
void Heapify(string msg[],int size,int i){
    int largest = i;
    int left_child = 2*i + 1;
    int right_child = 2*i + 2;

    if(left_child < size && msg[left_child] > msg[largest]){
        largest = left_child;
    }

    if(right_child < size && msg[right_child] > msg[largest]){
        largest = right_child;
    }

    if(largest != i){
        swap(msg[i],msg[largest]);

        Heapify(msg,size,largest);
    }
}

void bulid_Heap(string msg[],int size){
    int last_non_leaf_node = (size/2) - 1;

    for(int i = last_non_leaf_node;i >= 0 ; i--){
        Heapify(msg,size,i);
    }
}

void insertNode(string msg[], int& size, int Key){ 
    size = size + 1; 
  
    msg[size - 1] = Key; 
  
    Heapify(msg, size, size - 1); 
}

void print(string msg[],int size){
    for(int i = 0 ;i < size ; ++i){
        cout<<i<<") "<<msg[i]<<endl;
    }
    cout<<endl;
}

int main(){
  cout<<"******************* user is offline *******************"<<endl;
    string messages[] = {"call me later", "How are you", "what is going on bro!", "where are you?"};

    int size_of_arr = sizeof(messages) / sizeof(messages[0]);
    cout<<"******************* messages in buffer *******************"<<endl;
    print(messages,size_of_arr);
    char key_press;
    
    while(true){
      cout<<"******************* click enter to continue *******************"<<endl;
      key_press = getchar();3
      // cout<<"key_press"<<int(key_press)<<endl;
      if(int(key_press) == 10){
        cout<<"******************* user is online *******************"<<endl;
        bulid_Heap(messages,size_of_arr);
  
        cout<<"******************* messages in heap *******************"<<endl;
        print(messages,size_of_arr);
        break;
      }else{
        cout<<"Click enter to maintain messges in heap according to the priority"<<endl;
      }
    }
  
    return 0;
}