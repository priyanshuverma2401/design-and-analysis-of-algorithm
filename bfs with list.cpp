#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N =9999;
bool vis[N];
vector<int>list[N];

void bfs(int start){
	queue<int>que;
	que.push(start);
	vis[start]=1;
	while(!que.empty()){
		int node = que.front();
		que.pop();
		cout<<node<<"	";
		vector<int>:: iterator itr;
		for(itr=list[node].begin();itr!=list[node].end();itr++){
			if(!vis[*itr]){
				vis[*itr]=1;
				que.push(*itr);
			}
		}
	}
}

void printList(int v){
	cout<<endl;
	vector<int>:: iterator itr;
	for(int i=0;i<v;i++){

		cout<<"adjacent of "<<i <<" node is: ";
		for(itr=list[i].begin();itr!= list[i].end();itr++){
		
			cout<<*itr<<"	";
		}
		cout<<endl;
	}
}
int main(){
	int v,src=1,dest=1;
	for(int i=0;i<N;i++){
		vis[i]=0;
	}
	cout<<"enter total number of nodes: "<<endl;
	cin>>v;
	cout<<"insert edges: (a b) enter (0 0) to step out."<<endl;
	while(src!=0||dest!=0){
		cin>>src>>dest;
		if(src>v||dest>v){
			cout<<"out of range error!"<<endl;
			continue;
		}else if(src<0||dest<0){
			if(src<0) cout<<"negative source is not allowed!"<<endl;
			else cout<<"negative destination is not allowed!"<<endl;
		}
		list[src].push_back(dest);
		list[dest].push_back(src);
	}
	bfs(1);
	cout<<endl<<"printing list:"<<endl;
	printList(v);
	return 0;
}
