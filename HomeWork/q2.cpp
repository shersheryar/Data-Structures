#include <iostream>
#include <conio.h>
using namespace std;

void print(int*, int*);
int main(){
    int number, limit, key;
    int* ptrNum = NULL;
    int*  ptrLim = NULL;
    int* ptrKey = NULL;
    ptrKey = &key;
    ptrNum = &number;
    ptrLim = &limit;
    do{
        
    cout << "enter the table number: "; cin>> *ptrNum;
    cout <<"enter the  table limit: "; cin>> *ptrLim;
    print(ptrNum, ptrLim);
    getch();
    cout <<"press 1 for again and press 0 to quit: "; cin >> *ptrKey;
    }
    while( key != 0);
}
void print(int* num, int* lim){
    for(int i = 1; i <= *lim; i++){
        cout<<*num <<" * " << i << " = " << *num * i << endl;
    }
}
