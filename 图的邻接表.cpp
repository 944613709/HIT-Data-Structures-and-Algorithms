#include<bits/stdc++.h>
using namespace std;
#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;
typedef struct EdgeNode
{
	int adjvex;
	EdgeType weight;//权重 
	struct EdgeNode* next;
 } EdgeNode;
typedef struct	VextexNode
{
 	VertexType data;
 	EdgeNode *firstedge;
}VextexNode,AdjList[MAXVEX];
typedef struct 
{
	AdjList adjList;
	int numNodes,numEdges;
}GraphAdjList;

void CreatALGraph(GraphAdjList *Gp)
{
	int i,j,k;
	EdgeNode *pe;
	cout<<"顶点数和边数"<<endl;
	cin>>Gp->numNodes>>Gp->numEdges;
	for(i=0;i<Gp->numNodes;i++)
	{
		cin>>Gp->adjList[i].data;
		Gp->adjList[i].firstedge=NULL;
	}
	for(k=0;k<Gp->numEdges;k++)
	{
		cout<<"边ij"<<endl;
		cin>>i>>j;
		EdgeNode* pe;
		pe = new  EdgeNode;
		pe->adjvex = j;//i->j
		pe->next = Gp->adjList[i].firstedge;
		Gp->adjList[i].firstedge = pe;
		
		pe = new  EdgeNode;
		pe->adjvex =i;
		pe->next = Gp->adjList[j].firstedge;
		Gp->adjList[j].firstedge= pe;
	}
}
int main()
{
	GraphAdjList *G;
	G = new GraphAdjList;
	CreatALGraph(G);
}
