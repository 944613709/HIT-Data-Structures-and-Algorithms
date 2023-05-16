#include<bits/stdc++.h>
using namespace std;
typedef struct ENode
{
	int AdjV;
	int Weight;
	struct ENode *Next;
}ENode;
typedef struct VNode
{
	char Data;
	ENode* FirstENode;
}VNode,AdjList[1000];
typedef struct Graph
{
	AdjList adjlist;
	int numNode;
	int numEdge;
}Graph;
void Creat(Graph* G)
{
	cin>>G->numNode>>G->numEdge;
	for(int i=0;i<G->numNode;i++)
	{
		cin>>G->adjlist[i].Data;
		G->adjlist[i].FirstENode=NULL;
	}
	for(int i=0 ;i<G->numEdge;i++)
	{
		int V1,V2,Weight;
		cin>>V1>>V2>>Weight;
		ENode* e;
		e= new ENode;
		e->AdjV=V2;
		e->Next=G->adjlist[V1].FirstENode;
		G->adjlist[V1].FirstENode=e;
		//若是无向图
		e= new ENode;
		e->AdjV=V1;
		e->Next=G->adjlist[V2].FirstENode;
		G->adjlist[V2].FirstENode = e;
	}
}
void DFS(Graph G, int start)
{
	cout<< G.Vex[start];//访问
	visited[start] = true;
	for (int j = 0; j < G.vexnum; j++)
	{
		if (G.Edge[start][j] < INF && !visited[j])//是邻接点且未访问
		{
			cout << "->";
			DFS(G, j);//递归深度遍历
		}
	}
}

void DFS(Graph* G,int start)
{
	start = 0 //默认 
	cout<<G->adjlist[start].Data;
	for(int j=0;j<G->numNode;j++)
	{
		
	}
}
int main()
{
	Graph* G;
	G = new Graph;
	Creat(G);
}
