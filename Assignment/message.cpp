#include <assert.h>
#include <iostream>
#include <string>

using namespace std;

class MinHeap {
    private:
        struct Node {
            //date of the msg
            int day;
            //msg of for the user
            string msg;
            //priority of the message
            int key;

        };

        Node* arr;
        int capacity;
        int totalItems;

        void doubleCapacity(){
            if(this->arr = NULL){
                this->arr = new Node[1];
                this->capacity = 1;
                return;
            }
            int newCapacity = capacity*2;
            Node *newArr = new Node[newCapacity];
            for(int i = 0; i < this->totalItems; i++){
                newArr[i] = this->arr[i];
            }
            //if (this->arr!=NULL)
            delete this->arr;
            this->capacity = newCapacity;
            this->arr = newArr;
        }
        void shiftUP(int index){
            if(index < 1){
                return;
            }
            int parent = (index-1) / 2;
            if(this->arr[index].key < this->arr[parent].key){
                swap(this->arr[index],this->arr[parent]);
                shiftUP(parent);
            }
            return;
        }
        void shiftDown(int index){
            int maxIndex = -1;
            int lChildIndex = index * 2+1;
            int rChildIndex = (index * 2) + 2;
            if(lChildIndex < totalItems){
                if(arr[index].key > arr[lChildIndex].key){
                    maxIndex = lChildIndex;
                }
            }
            if(rChildIndex < totalItems){
                int newindex = (maxIndex == -1 ? index : maxIndex);           
                if(arr[newindex].key > arr[rChildIndex].key){
                    maxIndex = rChildIndex;
                }
            }
            if(maxIndex == -1){
                return;
            }
            swap(arr[index], arr[maxIndex]);
            shiftDown(maxIndex);
        }

    public:
        MinHeap(){
            this->arr = NULL;
            this->capacity = 0;
            this->totalItems = 0;
        }
        MinHeap(int _capcity){
            assert(_capcity >= 1);
            this->arr = new Node[_capcity];
            this->capacity = _capcity;
            this->totalItems = 0;
        }
    void insert(int day, string mesg, int key){
        if(this->totalItems == this->capacity){
            doubleCapacity();

        }
        //  cout << mesg << endl;
        this->arr[totalItems].key = key;
        this->arr[totalItems].day = day;
        this->arr[totalItems].msg = mesg;
        // cout << arr[totalItems].key;
        shiftUP(totalItems);
        this->totalItems++;

    }
    void getMin(int &key, string &msg, int &Day){
        assert(totalItems != 0);
        key = this->arr[0].key;
        msg = this->arr[0].msg;
        Day = this->arr[0].day;

    }
    void deleteMin(){
        assert(totalItems != 0);
        swap(arr[0], arr[this->totalItems -1]);
        totalItems--;
        shiftDown(0);
    }
    bool isEmpty() const{
        return (totalItems == 0);
    }
    void deleteAll(){
        if(this->arr != NULL){
            delete []arr;
            arr = NULL;
            this->capacity = 0;
            this->totalItems = 0;
        }  
    }
    void InOrder(int index){
    
    if (index>=totalItems)
    return;
    InOrder(index*2 +1);
    cout << "message: \n" << this->arr[index].msg << endl;
    cout << "day: " << this->arr[index].day << endl;
    cout << "priority: "; 
    cout<<this->arr[index].key<<"\n " ;
    InOrder(index*2 +2);
	}


	void PreOrder(int index){
		
		if (index>totalItems)
		return;
		cout<<this->arr[index].key<<" < " ;
		InOrder(index*2 +1);
		InOrder(index*2 +2);

	}
	void PostOrder(int index){
		

		InOrder(index*2 +1);
		InOrder(index*2 +2);
		cout<<this->arr[index].key<<" < " ;
		if (index>totalItems)
		return;
	}
    ~MinHeap(){
        deleteAll();
    }
};
// funcion to take mesage from user
void sendMessage(MinHeap heap){
    string messg;
    int key, day;
    cout << "User is currently ofline....\n";
    cout << "please enter your message: ";
    getline(cin,messg);
    cout << "Enter day: "; cin >> day;
    cout <<"press 1 for (emergency) 2 for (important) 3 for (casual message): "; cin >> key;
    heap.insert(day, messg, key);
}
void logIn(MinHeap h){
    int check;
    cout << " Welcome back:  press 1 to check ur messages press 2 to return : ";  cin >> check;
    if (check == 1){
        int key, Day;
        string msg;
        h.getMin(key,msg, Day);
        cout << "message: \n" << msg << endl;
        cout << "day: " << Day << endl;
        cout << "priority: " << key; 
    } 
    else{
        return;
    }
}
int main(){
    MinHeap heap;
    int check=1;
    sendMessage(heap);
    // while(check ==1){
    //     cout << " press 1 to enter a msg: press 0 to quit: "; cin >> check;
    //     if(check == 1){
    //         sendMessage(heap);
    //     }else{
    //         break;
    //     }
    // }

    // while(1){
    //     cout << " press 1 to enter a msg: press 0 to quit: "; cin >> check;
    //     if(check == 1){
    //         sendMessage(heap);
    //     }else{
    //         break;
    //     }
    // }
    // logIn(heap);
    // for(int i = 0; i <7; i++){
    //     heap.insert(i);
    //     // cout<< sortArr[i] << endl;
    // }
    // heap.InOrder(0);
}