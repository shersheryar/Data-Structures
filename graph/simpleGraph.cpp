#include <iostream>
#include<list>
using namespace std;

class Graph{
    public:
        list<int> *adjlist;
        int n;
    Graph(int v){
        adjlist = new list<int>[v];
        n = v;
    }
    void addEdge(int startEdge, int endEdge, bool bi){
        adjlist[startEdge].push_back(endEdge);
        if(bi){
            adjlist[endEdge].push_back(startEdge);   
        }
    }
    void print(){
        for(int i = 1; i < n; i++){
            cout <<i<<"-->";
            for(auto it:adjlist[i]){
                cout << it <<" ";
            }
        cout << endl;
        }
    }
};
int main (){
	Graph g(6);
	g.addEdge(1,2, true);
	g.addEdge(1,5, true);
	g.addEdge(2,3, true);
	g.addEdge(2,4, true);
	g.addEdge(2,5, true);
	g.addEdge(3,4, true);
	g.addEdge(5,4, true);
	// g.addEdge(6,4, true);
	g.print();
	
}