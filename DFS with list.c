//dfs implementation of list representation
#include<stdio.h>
#include<stdlib.h>

struct node{
	int dest;
	struct node* next;
};
struct node*createNode(int dest){
	struct node*newnode =(struct node*)malloc(sizeof(struct node));
	newnode->dest=dest;
	newnode->next=NULL;
	return newnode;
	}
struct Graph{
	int v;
	int *visited;
	struct node**lists;
};
struct Graph* createGraph(int v){
	struct Graph*graph=malloc(sizeof(struct node));
	graph->v=v;
	graph->lists=malloc(v*sizeof(struct node));
	graph->visited=malloc(v*sizeof(int));
	int i;
	for(i=1;i<=v;i++){
		graph->lists[i]=NULL;
		graph->visited[i]=0;
	}
	return graph;
}
//dfs algorithm
void dfs(struct Graph*graph,int v){
	struct node* list= graph->lists[v];
	struct node*temp = list;
	graph->visited[v]=1;
	printf(" %d		",v);
	while(temp){
		int connectedVertex = temp->dest;
		if(graph->visited[connectedVertex]==0){
			dfs(graph,connectedVertex);
		}
		temp=temp->next;
	}
}
//adding edge
void add(struct Graph* graph,int src,int dest){
	//adding edge frm source to destination
	struct node*newnode= createNode(dest);
	newnode->next=graph->lists[src];
	graph->lists[src]=newnode;
	//adding edge from destination to source
	newnode = createNode(src);
	newnode->next=graph->lists[dest];
	graph->lists[dest]=newnode;
}
void printGraph(struct Graph* graph){
	int i;
	for(i=1;i<=graph->v;++i){
		struct node*temp= graph->lists[i];
		printf("adjacency list of %d: ",i);
		while(temp!=NULL){
			printf("%d->",temp->dest);
			temp=temp->next;
		}
		printf("NULL");
		printf("\n");
	}
}
int main(){
	int v,src=1,dest=1;
	printf("\nEnter the total number node in the graph: ");
	scanf("%d",&v);
	struct Graph*graph = createGraph(v);
	printf("enter the path(a b):enter (0 0) to step out\n");
	while(src!=0||dest!=0){
		scanf("%d %d",&src,&dest);
		if(src>v||dest>v){
			printf("out of range error");
		}
		if(src<0||dest<0){
			if(src<0){
				printf("negative source are not allowed\n");
			}else printf("negative destination is not allowed\n");
		}
		add(graph,src,dest);
	}
	printGraph(graph);
	dfs(graph,v);
	return 0;
}
