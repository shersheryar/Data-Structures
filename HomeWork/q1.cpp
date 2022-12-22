#include <iostream>
using namespace std;

int main(){
    //creating two array of size 6x6
    int array[6][6];
    float result[6][6];

    //getting inputs from user
    for(int i = 0; i < 6 ; i++){
        for(int j = 0; j < 6; j++){
            cout << "enter the value for ["<<i<<"]"<<"["<<j<<"] "; cin>>array[i][j]; //appending the values in array  
        }
    }
    for(int i = 0; i < 6 ; i++){
        for(int j = 0; j < 6; j++){
            cout <<array[i][j] <<" \t"; // printing the values of array
        }
        cout <<endl;
    }
    //performing opperation on the array
    for(int i = 0; i < 6 ; i++){
        for(int j = 0; j < 6; j++){
            float Sum = 0.0;
            if(i == 0 && j == 0){
                Sum = array[i][j+1]+array[i+1][j+1]+array[i+1][j];
                Sum = Sum/array[i][j];
                result[i][j] = Sum; // appending the value in the new result array
            }
            else if(i == 0 && j == 5){
                Sum = array[i][j-1]+array[i+1][j-1]+array[i+1][j];
                Sum = Sum/array[i][j];
                result[i][j] = Sum;
            }
            else if(i == 0 && j < 5){
                Sum = array[i][j-1]+array[i+1][j-1]+array[i+1][j]+array[i+1][j+1]+array[i][j+1];
                Sum = Sum/array[i][j];
                result[i][j] = Sum;
            }
            else if(i < 5 && j == 0){
                Sum = array[i-1][j]+array[i-1][j+1]+array[i][j+1]+array[i+1][j+1]+array[i+1][j];
                Sum = Sum/array[i][j];
                result[i][j] = Sum;
            }
            else if(i == 5 && j == 0){
                Sum = array[i-1][j]+array[i-1][j+1]+array[i][j+1];
                Sum = Sum/array[i][j];
                result[i][j] = Sum;
            }
            else if(i == 5 && j == 5){
                Sum = array[i-1][j]+array[i-1][j-1]+array[i][j-1];
                Sum = Sum/array[i][j];
                result[i][j] = Sum;
            }
            else if (i == 5 && j < 5){
                Sum = array[i-1][j]+array[i-1][j+1]+array[i][j+1]+array[i-1][j-1]+array[i][j-1];
                Sum = Sum/array[i][j];
                result[i][j] = Sum;
            }
            else if(i < 5 && j == 5 ){
                Sum = array[i-1][j]+array[i-1][j-1]+array[i][j-1]+array[i+1][j-1]+array[i+1][j];
                Sum = Sum/array[i][j];
                result[i][j] = Sum;
            }
            else{
                Sum = array[i-1][j]+array[i-1][j-1]+array[i][j-1]+array[i+1][j-1]+array[i+1][j]+array[i+1][j+1]+array[i][j+1]+array[i-1][j+1];
                Sum = Sum/array[i][j];
                result[i][j] = Sum;
            }
        }
    cout <<endl;
    }

    cout <<"\nresult array: " <<endl;
    for(int i = 0; i < 6 ; i++){
        for(int j = 0; j < 6; j++){
            cout <<result[i][j] <<" \t"; // printing the values of the result array
        }
        cout <<endl;
    }
    // cout <<" the value of result is: " <<result[0][0];
    
}