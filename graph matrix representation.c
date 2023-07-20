//implementation of graph(undirected) as a adjacency matrix
#include<stdio.h>

void initialize(int v,int graph[][v]){
	int i,j;
	for(i=1;i<=v;i++)
		for(j=1;j<=v;j++)
			graph[i][j]=0;
}

void add(int src,int dest,int v,int graph[][v]){
	graph[src][dest]=1;
	graph[dest][src]=1;
	return;
}
void printMatrix(int v,int graph[][v]){
	printf("displaying matrix:\n");
	int i,j;
	for(i=1;i<=v;i++){
		for(j=1;j<=v;j++){
			printf("%d	",graph[i][j]);
		}
	printf("\n");
	}
			
}

int main(){
	printf("enter the total number of nodes in the graph: ");
	int v,src=1,dest=1;
	scanf("%d",&v);
	int graph[v][v];
	initialize(v,graph);
	
	printf("enter the path (a b): enter (0 0) number to step out\n");
	
	while(src!=0||dest!=0){
	scanf("%d %d",&src,&dest);

	if(src>v||dest>v){
		printf("\nout of range error.\n");
		continue;
	}
	if(src<0||dest<0){
		if(src<0){
			printf("\nNegative src is not allowed.");
		}
		else{
			printf("\nNegative destination is not allowed.\n");
		}
		continue;
	}	
		add(src,dest,v,graph);
	}
	printMatrix(v,graph)	;
	return 0;
}
