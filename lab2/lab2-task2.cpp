#include <iostream>
using namespace std;
#define SIZE 10

class ArrayList {
private:
	int count;
	int pos;
//	int pos;
	int *Array;
	int *curr;
	
	void head(){
	curr = Array;
	}
	void tail(){
		curr = Array + count - 1;
	}
	void back(){
		curr = curr - 1;	
	}
	void next (){
		curr = curr + 1;
	}
public:
	ArrayList(){
		Array = new int [SIZE];
		count = 0;
		pos = 0;
		curr = Array;
	}
	~ArrayList(){
		delete []Array;
		delete curr;
	}
	void printArray(){
		if (count > 0){
			head();
			for (int x = 0; x < count; x++){
				cout << *curr++ << "\t";
			}
		}
		else {
			cout <<"Array is Empty";
		}
	}
	void InsertElement(int val){
		if(!IsFull()){
			head();
			curr = curr + count;
			*curr = val;
			count ++; 
		}
		else{
			cout << "Array is Full " <<endl;
		}
	}
	void DeleteElement(int pos){

			if(pos <= count && pos > 0){
				head();
				for (int i = 1	; i <= count; i++ ){
					if(i == pos){
						*curr = *(curr+1);
						pos++;
					}
					next(); //curr = curr+1
				}
				back(); //curr = curr +1
				count--;
			}
			else{
				cout <<"Invalid Position" <<endl;
			}
}
	void InsertAtPos(int pos, int val){
		if(!IsFull()){
			if(pos <= count && pos > 0){
				tail();
				for (int i = count; i >= pos; i -- ){
					*(curr + 1) = *curr;
					back(); //curr = curr-1
				}
				next(); //curr = curr +1
				*(curr) = val;
				count++;
			}
			else if(pos > count && pos <= SIZE){
				head();
				curr = curr +  pos -1;
				*curr = val;
				count++;
			}
			else{
				cout <<"Invalid Position" <<endl;
			}
		
	}
	}
	bool IsFull(){
		if (count == SIZE){
			return true;
		}
		else{
			return false;
		}
	}
	bool IsEmpty(){
		if (count == 0){
			return true;
		}
		else{
			return false;
		}
	}
	int Count(){
		return count;
	}
	void emptylist(){
		head();
		for(int x = 0; x < SIZE; x++){
			*curr = 0;
		}
	}
};
int main(){
	ArrayList* obj = new ArrayList();
	
	obj->emptylist();
	obj->InsertElement(1);
	obj->InsertElement(2);
	obj->InsertElement(3);
	obj->InsertElement(4);
	
	obj->printArray(); cout << endl;
//	obj->InsertAtPos(2,99);
	obj->DeleteElement(4);
	obj->printArray(); cout <<endl;
	
}



