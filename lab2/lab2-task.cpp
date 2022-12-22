#include <iostream>
using namespace std;
#define SIZE 10

class ArrayList {
private:
	int count;
	int pos;
	char *Array;
	char *curr;
	
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
		Array = new char[SIZE];
		count = 0;
		pos = 0;
		curr = Array;
	}
	~ArrayList(){
		delete []Array;
		delete curr;
	}
	void printArray(){
		cout<<"am inside print";
		if (cout > 0){
			head();
			for (int x = 0; x < count; x++){
				cout << *curr++ << "\t";
			}
		}
		else {
			cout <<"Array is Empty";
		}
	}
	void InsertElement(char val){
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
	void CommonElement(ArrayList *first, ArrayList *second){
		char *secTemp = second->Array;
		while(*first->Array != NULL){
//			cout <<"welcome" <<endl;
			while(*second->Array != NULL){
//				cout << " welcome to second"<<endl;
				if(*second->Array == *first->Array){
//					cout <<"element: " << *first->Array;
					*this->Array = *first->Array;
					cout <<*this->Array << "\t";
					this->Array++;
				}
				second->Array++;
			}
			first->Array++;
			second->Array = secTemp;
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
	ArrayList* obj1 = new ArrayList();
	ArrayList* obj2 = new ArrayList();
	ArrayList* obj3 = new ArrayList();
	
	obj->emptylist();
	for(int i = 0;i < 4;i++){
		char x;
		cout <<"enter element for first array: ";
		cin>> x;
		obj1->InsertElement(x);	
	}
	for(int i = 0;i < 4;i++){
		char x;
		cout <<"enter element second array: ";
		cin>> x;
		obj2->InsertElement(x);	
	}

	obj3->CommonElement(obj1,obj2);
	obj3->printArray(); cout << endl;
//	obj->InsertAtPos(2,99);
//	obj->printArray(); cout <<endl;

};



