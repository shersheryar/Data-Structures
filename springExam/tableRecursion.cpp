#include <iostream>
using namespace std;

//first solutin
void tableRecursion(int *num, int *limit){
    static int iterator = 1; //iterator to increment the number
    if(*limit == 0){
        return; //if limit reaches to 0 the fucntion should return
    }
    cout << *num <<" * " << iterator << " = " << *num * iterator << endl; //printing table
    *limit = *limit -1; //decrementing limit
    iterator++; //incrementing iterator
    tableRecursion(num, limit);   //recursive call to calculate table
};
void tableRecursion(int *num, int *limit){
    static int iterator = 1;
    if(iterator > *limit){ //while limit is greater then iterator
        return;
    }
    cout << *num <<" * " << iterator << " = " << *num * iterator << endl;
    // *limit = *limit -1;
    iterator++;
    tableRecursion(num, limit);  
};





int main(){
    int num, limit; //defining varibles
    int *numptr; int *limitptr; //defing pointeres
    numptr = &num;  //assigning values to pointers
    limitptr= &limit;
    cout << "enter the number: "; cin >> *numptr; //geting input from user
    cout << "enter limit: "; cin >> *limitptr;
    tableRecursion(numptr, limitptr); //call table function

}