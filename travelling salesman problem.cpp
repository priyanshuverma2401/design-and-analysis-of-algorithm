//travelling salesman problem
#include<iostream>

using namespace std;

int min(int node,int totalnodes,int graph[][100],int visited[]){
	int min= 999;
	int nextnode =-1;
	for(int i=1;i<=totalnodes;i++){
		if(!visited[i]){
			if(graph[node][i]<min){
				min = graph[node][i];
				nextnode =i;
			}
		}
	}
	return nextnode;
}

int tsp(int totalnodes,int startnode,int visited[100],int graph[][100],int direction[100]){
	int current = startnode;
	visited[startnode] = 1;
	direction[0] = startnode;
	int totaldistance = 0;
	for(int i=1;i<totalnodes;i++){
		int nextnode = min(current,totalnodes,graph,visited);
		visited[nextnode] = 1;
		direction[i] = nextnode;
		totaldistance += graph[current][nextnode];
		current = nextnode;
	}
	totaldistance += graph[current][startnode];
	
	cout<<endl<<"The best direction to travel all nodes is as: "<<endl;
	for(int i=0;i<totalnodes;i++){
		cout<<direction[i]<<" --> ";
	}
	    cout<<startnode;
	    
	return totaldistance;
}

int main(){
	int nodes,src,dest,wht,str;
	cout<<"Enter total number of nodes: ";
	cin>>nodes;
	int graph[100][100];
	int visited[100];
	int direction[100];
	for(int i=0;i<nodes;i++){
		visited[i]=0;
		direction[i]=0;
	}
	for(int i=0;i<nodes;i++){
		for(int j=0;j<nodes;j++){
			graph[i][j];
		}
	}
	
	while(1){
	cout<<endl<<"Enter (source destination weight): [press -ve to exit loop]"<<endl;
	cin>>src>>dest>>wht;
	if(src<0||dest<0||wht<0) break;
	graph[src][dest]=wht;
	graph[dest][src]=wht;
	}
	
	cout<<"enter starting node: ";
	cin>>str;
	
	int minDistance = tsp(nodes,str,visited,graph,direction);
	
	cout<<endl<<endl<<"The salesman have to travel at least "<<minDistance<<" unit distance to visit all"
		<<nodes<<" node."<<endl;
	
	
	return 0;
}
