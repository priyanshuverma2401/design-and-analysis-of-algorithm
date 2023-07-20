//adjacency list representation of graph
#include<stdio.h>
#include<stdlib.h>

struct node{	//node structure 
	int dest;
	struct node* next;
};

struct node* createNode(int dest){
	struct node * newnode= (struct node*)malloc(sizeof(struct node));
	newnode->dest = dest;
	newnode->next=NULL;
	return newnode;
}

struct Graph{
	int v;
	struct node**lists;
};
struct list{
	struct node * head;
};
struct Graph* createGraph(int v){
	struct Graph* graph= (struct Graph*)malloc(sizeof(struct Graph));
	graph->v=v;
	graph->lists=malloc(v*sizeof(struct list));
	int i;
	for(i=1;i<=v;i++){
		graph->lists[i] = NULL;
	}
	return graph;
}

//function to add edge in a graph
void add(struct Graph *graph,int src,int dest){
	struct node * temp=NULL;
	struct node* newnode = createNode(dest); //adding path from source to dest
	newnode->next=graph->lists[src];
	graph->lists[src]=newnode;
	//adding edge from destination t source
	newnode = createNode(src);
	newnode->next=graph->lists[dest];
	graph->lists[dest]=newnode;
	}
void printGraph(struct Graph*graph){
	int i;
	for(i=1;i<=graph->v;i++){
		struct node* temp =graph->lists[i];
		printf("for vertex %d : ",i);
		while(temp!=NULL){
			printf("%d-> ",temp->dest);
			temp=temp->next;
		}
		printf("NULL");
		printf("\n");
	}
}
int main(){
	int v,src=1,dest=1;
	printf("enter total number of vertices in the graph: ");
    scanf("%d",&v);
	struct Graph* graph=createGraph(v);
	printf("insert edges (a b): enter (0 0) to step out.\n");
	while(src!=0||dest!=0){
		scanf("%d %d",&src,&dest);
		if(src>v||dest>v){
			printf("\n out of range error\n");
			continue;
		}else if(src<0||dest<0){
			if(src<0){
				printf("\nnegative source is not allowed");
			}else{
				printf("Negative destination is not allowed.");
			}
		continue;	
		}
		add(graph,src,dest);
	}
	printGraph(graph);
	return 0;
}


