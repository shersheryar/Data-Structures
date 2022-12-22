// Directed and Undirected graph Implementation
#include<iostream>
#include<list>
using namespace std;
class Graph{
	public:
	list<int> *adjList;
	int n;// no of nodes
	Graph(int v){
		adjList= new list<int>[v];
		n=v;
	}
	void addEdge(int startV, int endV, bool bi){
		adjList[startV].push_back(endV);
		if(bi)
			adjList[endV].push_back(startV);
	}
	void print(){
		for (int i=0; i<n;i++)
		{
	     	cout<<"-->";
			for(auto it:adjList[i])
				cout<<it<<" ";
		cout<<endl;
		}
	}
};

int main (){
  Graph g(7);
    g.addEdge(1, 2, true);
    g.addEdge(1, 5, true);
    g.addEdge(2, 3, true);
    g.addEdge(2, 4, true);
    g.addEdge(2, 5, true);
    g.addEdge(3, 4, true);
    g.addEdge(5, 4, true);
    g.print();

   
};
