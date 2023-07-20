//dfs with adjacency matrix
#include<stdio.h>
void initialize(int v,int graph[][v]){
	int i,j;
	for(i=1;i<=v;++i){
		for(j=1;j<=v;++j){
			graph[i][j]=0;
		}
	}
}
void add(int v,int src,int dest,int graph[][v]){
		graph[src][dest]=1;
		graph[dest][src]=1;
}
void printMatrix(int v,int graph[][v]){
	int i,j;
	for(i=1;i<=v;i++){
		for(j=1;j<=v;j++){
			printf("%d	",graph[i][j]);
		}
		printf("\n");
	}
}
void dfs(int start,int v,int graph[][v],int visited[v]){
	printf("%d	",start);
	visited[start]=1;
	int j;
	for(j=1;j<=v;j++){
		if(graph[start][j]==1 && visited[j]==0){
			dfs(j,v,graph,visited);
		}
	}
	
}
int main(){
	int v,src=1,dest=1;
	printf("enter total number of vertices: ");
	scanf("%d",&v);
	int graph[v][v];
	int visited[v];
	initialize(v,graph);
	printf("\nenter edges (a b):enter (0 0) to step out.\n");
	while(src!=0||dest!=0){
		scanf("%d %d",&src,&dest);
		if(src>v||dest>v){
			printf("out of range error!!!\n");
			continue;
		}else if(src<0||dest<0){
			if(src<0){
				printf("Negative source is not allowed\n");
			}else printf("negative destination is not allowed");
			continue;
		}
		add(v,src,dest,graph);
	}
	printMatrix(v,graph);
	dfs(1,v,graph,visited);
	return 0;
}
