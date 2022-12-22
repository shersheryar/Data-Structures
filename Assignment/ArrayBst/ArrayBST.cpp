#include <iostream>
using namespace std;

class ArrBst{
    private:
        int *arr;
        int size;
        int left, right;
        int noOfElements;

    public:
        ArrBst(int size){
            this->size = size;
            arr = new int[size];
            left = 0; right = 0;
            noOfElements = 0;
            // setting the array to -1 
            for (int i = 0; i < size; i++)
            {
                arr[i] = -1;
            }
        }
        ~ArrBst(){
            delete []arr;
        }
    // =========================TO PRINT THE WHOLE ARRAY====================
        void print(){
            for(int i= 0; i < this->size; i++){
                cout << arr[i] << endl;
            }
        }
        // =========================INSERT FUNCTION================================
        void insert(int val, int index){
           if(index < size){
                if(arr[index] == -1){
                arr[index] = val;
                noOfElements++;
                return;
            }
            if(  val < arr[index] ){
                    insert(val, (index*2 +1));
            }
            if( val > arr[index]){
                insert(val, (index*2 +2));
            }
            if(arr[index] == val){
                cout << "Value is already exit.."<< endl;;
                return;
            }
            }else{
                cout << "out of range..." << endl;
                return;
            }
        }
        // ======================================SECCESSOR FUNCTION==================================
        //THIS FUNTION RETURN THE SECCORS 
        int seccessor(int index){
            index = index*2 + 2;
            while(arr[index*2 + 1] != -1){
                index = index*2 + 1;
            }
            return index;
        }
        // ============================================DELETE FUNCTION=============================
        void Delete(int val, int index){
            if(arr[0] == -1){
                cout << " no elements in bst .." << endl;
                return;
            }
            if(val < arr[index]){
                Delete(val, (index*2 + 1));
                return;
            }
            if(val > arr[index]){
                Delete(val, (index*2 + 2));
            }
            else{
                //if value if a leaf
                if(arr[index*2+1] == -1 && arr[index*2 + 2] == -1){
                    arr[index] =-1;
                    noOfElements--;
                    cout << " delete leaf \n";
                }
                //left child
                if(arr[index*2+1] != -1 && arr[index*2 + 2] == -1){
                   // deleting left child and calculing indexes after deleting
                    while(arr[index*2+1] != -1){
                        arr[index] = arr[index*2 + 1];
                        int tempIndex = index;
                        index = index*2+1;
                        int leftindex = index;
                        //if the upcomming node has any right childs
                        if(arr[index*2 + 2 != -1]){
                            while(arr[index*2 + 2]!=-1){
                                arr[tempIndex*2 + 2] = arr[index*2 + 2];
                                arr[index*2 +2] = -1;
                                index = index*2+2;
                                tempIndex = tempIndex*2 + 2;

                            }
                            index =  leftindex;
                        }
                    }
                    arr[index] = -1;  //deleting the given value from aarray
                    noOfElements--; // decrementing the total number of items from the bst
                }
                //right child
                if(arr[index*2+1] == -1 && arr[index*2 + 2] != -1){
                    // calculete index for every child after deleting
                    while(arr[index*2+2] != -1){
                        arr[index] = arr[index*2 + 2];
                        int tempIndex = index;
                        index = index*2+2;
                        int leftindex = index;

                        if(arr[index*2 + 1 != -1]){
                            while(arr[index*2 + 1]!=-1){
                                arr[tempIndex*2 + 1] = arr[index*2 + 1];
                                arr[index*2 +1] = -1;
                                index = index*2+1;
                                tempIndex = tempIndex*2 + 1;

                            }
                            index =  leftindex;
                        }
                    }
                    arr[index] = -1; //deleting the given value from aarray
                    noOfElements--; // decrementing the total number of items from the bst
                    cout << " delete right child \n";
                }

                //IF NODE HAS BOTH LEFT AND RIGHT CHILD
                if(arr[index*2+1] != -1 && arr[index*2 + 2] != -1){
                    int tempIndex;
                    tempIndex = this->seccessor(index);
                    arr[index] = arr[tempIndex];
                    Delete(arr[index], index*2+2);
                }

            }

        }
        // =================================SEARCH FUNCTION================================
        void search(int val, int index){
            if(arr[index]==-1){
                cout<<"value is not present...." << endl;
                return;
            }
            if(val < arr[index]){
                search(val,index*2 + 1);
                return;
            }
            if(val > arr[index]){
            search(val,index*2 +2);
            return;
            }
            cout<<"value is present...." << endl;
            return;
        }
        // =================================HEIGHT FUNCTION================================
        int Height(int index){
            static int height= 0;
            static int localHeight = 0;
            if(height < localHeight ){
                height = localHeight;
            }
            // cout << "index:" << index << endl;
            // cout <<"value: " << arr[index] << endl; 
            //     cout << "height: " << height << endl;
            if(arr[index]==-1){
                return height;
            }
            if(arr[index*2 +1] != -1){
                localHeight++;
                Height(index*2 +1);
                localHeight--;
            } 
            if(arr[index*2 + 2] != -1){
                localHeight++;
                Height(index*2 +2);
                localHeight--;
            }
            return height;

        }
        // =================================NODE OF SPECIFIC HEIGHT FUNCTION================================
        int SpecificHeight(int height,int index){
            static int nodes = 0;
            if(arr[index]==-1){
                return nodes;
            }
            int h = index*2 + 2;
            cout << "total : " <<this->Height(h) << endl;

            SpecificHeight(height,index);
            SpecificHeight(height,index);
            
           
            return nodes;


            // cout << h << endl;
            // if(height != this->Height(index)){
                // cout << "here" << endl;
                // SpecificHeight(height,index*2 + 1);
                // SpecificHeight (height,index*2 +2);
            // }else{
            // nodes++;

            // }
            // // cout << this->Height(index*2 + 1) << endl;
            // return nodes;
        }
         // =================================LEAF NODES FUNCTION================================
         int leafNode(int index){
            static int nodes = 0;
            if(arr[index]==-1){
            return nodes;
            }
            if(arr[index*2+1]==-1 && arr[index*2+2]==-1){
                nodes++;
                return nodes;
            }
            leafNode(index*2+1);
            leafNode(index*2 +2);
        
         }
        // =================================IN ORDER TRAVERSAL================================
        void InOrder(int index){

        if (index>=size)
        return;

        if(arr[index]==-1){
            return;
        }
        InOrder(index*2 + 1);
        cout<<this->arr[index]<<" < " ;
        InOrder(index*2 +2);
        }
// =================================PRE ORDER TRAVERSAL================================
        void PreOrder(int index){

            if (index>=size)
            return;
            if(arr[index]==-1){
            return;}
            cout<<this->arr[index]<<" < " ;
            PreOrder(index*2 +1);
            PreOrder(index*2 +2);

	    }
        // =================================POST ORDER TRAVERSAL================================
        void PostOrder(int index){
            if (index>=size)
                return;
            if(arr[index]==-1){
            return;}
            cout<<this->arr[index]<<" < " ;
            PostOrder(index*2 +1);
            PostOrder(index*2 +2);
        }
};

int main(){
    ArrBst a(100);
    a.insert(10,0);
    a.insert(5,0);
    a.insert(14,0);
    a.insert(16,0);
    a.insert(17,0);
    a.insert(15,0);
    a.insert(9,0);
    a.insert(8,0);
    // a.insert(10,0);
    a.insert(11,0);
    a.insert(6,0);
    a.insert(7,0);
    a.insert(12,0);
    cout <<" Searching: " << endl;
    a.search(13,0);

    cout << "\nheight: ";
    cout << a.Height(0) << endl;
    cout << "leafNodes: " << a.leafNode(0) << endl;
    cout << "inorder traver before delete: " << endl;
    a.InOrder(0);
    // cout << endl;
    a.Delete(8,0);
    cout << "'\ninorder traver after delete: " << endl;
    a.InOrder(0);
    cout << "\npreorder traver : " << endl;
    a.PreOrder(0);
    cout << endl;
    cout << "\npostorder traver : " << endl;
    a.PostOrder(0);
}