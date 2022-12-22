#include <assert.h>
#include <iostream>

using namespace std;

class MinHeap {
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
    void insert(int key){
        if(this->totalItems == this->capacity){
            doubleCapacity();

        }
        this->arr[totalItems].key = key;
        shiftUP(totalItems);
        this->totalItems++;

    }
    void getMin(int &key){
        assert(totalItems != 0);
        key = this->arr[0].key;
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
    cout<<this->arr[index].key<<" < " ;
    InOrder(index*2 +2);
	}
    void evenNodes(int index){
    static int count = 0;
    if (index>=totalItems)
    return;
    evenNodes(index*2 +1);
    if(arr[index].key % 2 == 0){
        count++;
        cout  <<this->arr[index].key<<" < " ;
    }
    evenNodes(index*2 +2);
	}
    // void parents(int index, int key){
    //     static int count = 0;
    // if (index>=totalItems)
    //     count--;
    // return;
    // count++;
    // InOrder(index*2 +1);
    //     if(count == key){
    //         cout<<this->arr[index].key<<" < " ;
    //     }
    // InOrder(index*2 +2);
	// }
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
void inOrderCbt(int ind,int arr[],int size,int sortArr[]){
    static int count=0;
    // for(int i = 0; i < size/2; i++){
    //     sortArr[i] = arr[   ]
    // }
    if (ind>=size)
    return;
    inOrderCbt(ind*2 +1,arr,size,sortArr);
    cout<<arr[ind]<<" < " ;
    sortArr[count] = arr[ind];
    count++; 
    inOrderCbt(ind*2 +2,arr,size,sortArr);
}
void PreOrderCbt(int ind,int size,int sortArr[]){
    MinHeap heap;

    if (ind>=size)
    return;
    // cout<< "ind: " <<ind <<"value: " <<sortArr[ind] << endl
    // for(int ind = 0;ind<7;ind++){
    //     cout<<sortArr[ind]<<endl;
        
    // }
    // cout<<sortArr[ind]<<" < " ;
    heap.insert(sortArr[ind]);
    // cout << "1";
    PreOrderCbt(ind*2 +1,size,sortArr);
    // cout << endl << "2" << endl;
    PreOrderCbt(ind*2 +2,size,sortArr);
    // heap.PreOrder(0);

}
int main(){
    MinHeap heap;

    // int sortArr[7];
    // int arr[7] = {4,2,6,1,3,5,7};
    // inOrderCbt(0,arr,7,sortArr);
    // cout << endl;
    // PreOrderCbt(0,7,sortArr);
    for(int i = 0; i <7; i++){
        heap.insert(i);
        // cout<< sortArr[i] << endl;
    }
    // heap.PreOrder(0);
    // for(int i = 0;i<7;i++){
    //     cout<<sortArr[i]<<endl;
        
    // }
    // heap.InOrder(0);
    // while(!heap.isEmpty()){
    //     int s;
    //     heap.getMin(s);
    //     cout << s << endl;
    //     heap.deleteMin();
    // }
    // heap.parents(0, 2);
    heap.evenNodes(0);
}