//topological sorting
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int count=0;
void tSort(int v,vector<int>list[],vector<int>indegree){
	queue<int>que;
	for(int i=0;i<v;i++){
		if(indegree[i]==0){
			que.push(i);
		}
	}
	while(!que.empty()){
		count++;
		vector<int>::iterator itr;
		int node=que.front();
		que.pop();
		cout<<node<<"	";
		for(itr=list[node].begin();itr!=list[node].end();itr++){
			indegree[*itr]--;
			if(indegree[*itr]==0){
				que.push(*itr);
			}
		}
	}
}
int main(){
	int v,src=1,dest=1;
	
	cout<<"enter the total number of nodes: ";
	cin>>v;
	vector<int>list[v];
	vector<int>indegree(v,0);
		while(1){
		cin>>src>>dest;
		if(src==0 && dest==0) break;
		if(src>v||dest>v){
			cout<<"out of range error!"<<endl;
			continue;
		}else if(src<0||dest<0){
			if(src<0) cout<<"negative source is not allowed!"<<endl;
			else cout<<"negative destination is not allowed!"<<endl;
			continue;
		}
		list[src].push_back(dest);
		indegree[dest]++;
	}
	tSort(v,list,indegree);
	return 0;
}
