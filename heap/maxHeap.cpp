#include <assert.h>
#include <iostream>

using namespace std;

class MaxHeap {
    private:
        struct Node {
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
            if(this->arr[index].key > this->arr[parent].key){
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
                if(arr[index].key < arr[lChildIndex].key){
                    maxIndex = lChildIndex;
                }
            }
            if(rChildIndex < totalItems){
                int newindex = (maxIndex == -1 ? index : maxIndex);           
                if(arr[newindex].key < arr[rChildIndex].key){
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
        MaxHeap(){
            this->arr = NULL;
            this->capacity = 0;
            this->totalItems = 0;
        }
        MaxHeap(int _capcity){
            assert(_capcity >= 1);
            this->arr = new Node[_capcity];
            this->capacity = _capcity;
            this->totalItems = 0;
        }
    void insert(int key){
        if(this->totalItems == this->capacity){
            doubleCapacity();

        }
        this->arr[totalItems].key = key;
        shiftUP(totalItems);
        this->totalItems++;

    }
    void getMax(int &key){
        assert(totalItems != 0);
        key = this->arr[0].key;
    }
    void deleteMax(){
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
    void largNum(int key){
        // MaxHeap heap;
        // for(int i = i; i <size; i++){
        //     this->insert(*arr);
        //     arr++;
        // }
        for(int i = 0; i <key; i++){
            int s;
            this->getMax(s);
            cout << s << endl;
            this->deleteMax();
        }
    }
    ~MaxHeap(){
        deleteAll();
    }
};
// void largNum(int arr[],int size,int key){
//     MaxHeap heap;
//     for(int i = i; i <size; i++){
//         heap.insert(*arr);
//         arr++;
//     }
//     for(int i = 0; i <key; i++){
//         int s;
//         heap.getMax(s);
//         cout << s << endl;
//         heap.deleteMax();
//     }
// }
int main(){
    int arr[7]= {4,8,3,88,34,100,99};
    // largNum(arr,7,4);
    MaxHeap heap;

    for(int i =0; i <7; i++){
        heap.insert(arr[i]);
    }
    heap.largNum(3);
    // heap.deleteAll();
    heap.deleteMax();
    while(!heap.isEmpty()){
        int s;
        heap.getMax(s);
        cout << s << endl;
        heap.deleteMax();
    }
}