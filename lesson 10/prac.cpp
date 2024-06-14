#include<iostream>
#include<vector>
#include <queue>
using namespace std;


class graph{
	int totalNode;
		vector<vector <int> > adjList;
	public:
		graph(int node);
		void add(int src,int dest);
		void print();
};

 graph::graph(int node){
 	totalNode = node;
 	adjList.resize(node);
 }
 	
void graph::add(int src , int dest){
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}

	void graph::print(){
		for(int i = 0 ; i < totalNode ; i++){	
		cout<<"node "<<i<<" :";
			for(size_t j = 0 ; j < adjList[i].size();j++){
				cout<<" "<<adjList[i][j] << " ";
			}
			cout<<endl;
		}	
	}

int main(){
	graph g(5);
	queue<pair <int , int> > edges;
	g.add(0,1);
	g.add(0,4);
	g.add(1,2);
	g.add(1,3);
	g.add(1,4);
	g.add(2,3);
	g.add(2,4);
	
	while(!edges.empty()){
		pair <int,int> edge = edges.front();
		g.add(edge.first, edge.second);
		edges.pop();
	} 
	cout<<"Graph with adjecemet: \n";
	
	g.print();
	return 0 ; 
}


