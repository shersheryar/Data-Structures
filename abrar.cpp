#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void uniqueWays(int steps,int n,int stepseq[])
{
	if(steps == 0) return; // if total steps are zero
	if(n > steps) return; // when taken steps exeed total steps
	if(n == steps){ // when taken steps reach total steps()
		for(int i = 0 ; i < steps; i++) // print sequence of possible steps
		{
			if(stepseq[i] != 0) // checking for valid step
				cout << stepseq[i] << " ";
		}
		cout << endl;
		return;
	}
	for(int i = 1; i <=steps; i++){
		stepseq[n] = i; // record step
		uniqueWays(steps,n+i,stepseq); // taken steps + 1 step and check
		stepseq[n] = 0; // remove step after check
	}
}
int main()
{

	int steps; // Total steps user input
	cout <<"Enter the number of steps you wanna know the combinations: "; cin>>steps;
	int  stepseq[steps]; // array to store sequence of steps

	// inserting the values to array initially
	for(int i = 0 ; i < steps ; i++)
	stepseq[i] = 0; // initially all invalid steps sequence
	uniqueWays(steps,0,stepseq); // find unique ways and print
	return 0;
}