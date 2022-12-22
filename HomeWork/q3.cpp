#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int array[5][5]; // creating array
    int result[5];
    int number;
    ifstream myfile; 
    myfile.open("file.txt"); //opeing file

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int temp;
            myfile >> temp;
            array[i][j] = temp; //reading data from file and appending in new array
        }
    }

     for(int i = 0; i < 5; i++){
        int Sum = 0;
        for(int j = 0; j < 5; j++){
            Sum += array[i][j]; //calculating the sum of a row
        }
        result[i] = Sum; //appending sum in result
    }
    cout <<"[ ";
    for(int i = 0; i < 5; i++){
        cout << result[i]<< ", "; //printing the new array
    }
    cout<<"]";



}