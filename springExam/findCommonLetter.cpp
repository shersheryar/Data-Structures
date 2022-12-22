#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main(){
    char *ar = new char[6];
    // ar[1] = 'c';
    cout << ar[1] << endl;
    char arr1[] = {'a', 'b', 'c', 'b', 'e', 'f','y','7','8'};
    char arr2[] = {'a', 'b','b','f','e','8','7'};
    char arr[8];
    int x = sizeof(arr1) / sizeof(*arr1); // size of arr1
    int y = sizeof(arr2) / sizeof(*arr2); // size of arr1
    int z = sizeof(arr) / sizeof(*arr); // size of arr1
    // cout <<y;

    char* arrPtr1 = arr1;
    char* arrPtrr = arr;
                // char* arrPtr = arr;
    //checking the common values in both of the arrays
    for(int i = 0; i < x; i++){
        //pointer to arr2  
       char* arrPtr2 = arr2;
        //inner loop for commong elements
        for(int j = 0; j < y; j++){
            //check elements are equal
            if(*arrPtr1 == *arrPtr2){
                //pointer to arr
                //check if the element is already in arr or not
                bool countt = std::count(begin(arr) , end(arr), *arrPtr1) >0;
                if(countt < 1){
                    *arrPtrr = *arrPtr1;
                    // cout << *arrPtrr <<" ";
                    arrPtrr++;    
                }

            }
            arrPtr2++;
        }
        arrPtr1++;
    }
    cout<<endl;

    //print the new array
   for(auto &ch: arr){
    cout << ch <<" ";
   }
}
