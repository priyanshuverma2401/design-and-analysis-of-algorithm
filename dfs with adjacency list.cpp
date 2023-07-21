//dfs using list
#include<iostream>
#include<vector>
using namespace std;
const int maxNode=100;

void printList(int v,vector<int>list[]){
	cout<<endl;
	vector<int>::iterator itr;
	for(int i=0;i<v;i++){
		cout<<"adjacent node of "<<i<<" is: ";
		for(itr=list[i].begin();itr != list[i].end();itr++){
			cout<<*itr<<"	";
		}
		cout<<endl;
	}
}
void dfs(int start,int v,vector<int>list[],int visited[]){
	cout<<start<<"	";
	visited[start]=1;
	vector<int>::iterator itr;
	for(itr=list[start].begin();itr != list[start].end();itr++){
		if(visited[*itr]);
		else{
			dfs(*itr,v,list,visited);
		}
	}
}
int main(){
	
	int v,src=1,dest=1;
	cout<<"enter total number of nodes: "<<endl;
	cin>>v;
	vector<int>list[maxNode];
	int visited[maxNode]={0};
	cout<<"insert edges: (a b) enter (0 0) to step out."<<endl;
	while(src!=0||dest!=0){
		cin>>src>>dest;
		if(src>v||dest>v){
			cout<<"out of range error!"<<endl;
			continue;
		}else if(src<0||dest<0){
			if(src<0){
			cout<<"negative source is not allowed!"<<endl;
			} 
			else cout<<"negative destination is not allowed!"<<endl;
		}
	list[src].push_back(dest);
	list[dest].push_back(src);
	}
	int root;
	cout<<"enter root value: ";
	cin>>root;
	dfs(root,v,list,visited);
	printList(v,list);
return 0;	
}
