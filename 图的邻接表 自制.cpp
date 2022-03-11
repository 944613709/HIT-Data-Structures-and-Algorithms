#include<bits/stdc++.h>
#define INF 999999
#define MaxVNode 100
using namespace std;
typedef struct ENode
{
	int AdjV;//邻接点域，存储邻接顶点对应的下标
	int Weight;
	struct ENode *Next;//链域，指向同一个起点的下一个邻接点

}ENode;
typedef struct VNode
{
	char Data;
	ENode* FirstENode;
}VNode,AdjList[1000];
typedef struct ALGraph
{
	AdjList adjlist;
	int numVNode;
	int numENode;
}ALGraph;//ALGraph 
typedef struct MatGraph
{
	char VNode[100];
	int ENode[100][100];
	int numENode;
	int numVNode;
}MatGraph;
void CreatALGraph(ALGraph* G)//无向图处理 
{
	FILE *p;
	assert((p=fopen("ALGraph.txt","r"))!=NULL);
	fscanf(p,"顶点个数=%d;",&G->numVNode);//最初就给定numVNode 
	fscanf(p,"边个数=%d;",&G->numENode);
	for(int i=0;i<G->numVNode;i++)
	{
		fscanf(p,"%c;",&G->adjlist[i].Data);
		G->adjlist[i].FirstENode=NULL;
	}
	for(int i=0 ;i<G->numENode;i++)
	{
		int V1,V2,Weight;
		fscanf(p,"%c,%c,%d;",&V1,&V2,&Weight);
		ENode* e;
		e= new ENode;
		e->AdjV=V2;
		e->Next=G->adjlist[V1].FirstENode;
		G->adjlist[V1].FirstENode=e;//头插法 
		//若是无向图
		e= new ENode;
		e->AdjV=V1;
		e->Next=G->adjlist[V2].FirstENode;
		G->adjlist[V2].FirstENode = e;
	}
}
int visited[MaxVNode];
void AL_DFS(ALGraph* G,int v)
{
	cout<<G->adjlist[v].Data;
	visited[v]=1;
	ENode* p;
	p=G->adjlist[v].FirstENode;
	while(p!=NULL)
	{
		if(visited[p->AdjV]!=1)
			AL_DFS(G,p->AdjV);
		p=p->Next;
	}
}
void AL_BFS(ALGraph *G,int v)
{
	cout<<G->adjlist[v].Data;
	queue<int> Q;
	Q.push(v);
	visited[v]=1;
	while(!Q.empty())
	{
		int temp;
		temp=Q.front();
		Q.pop();
		ENode* E = G->adjlist[temp].FirstENode;
		while(E!=NULL)
		{
			cout<<G->adjlist[E->AdjV].Data;
			if(visited[E->Next->AdjV]!=1)
				{
					visited[E->Next->AdjV]=1;
					Q.push(E->AdjV);
				}
			E = E->Next;
		}
	}
}
/*
void MatToList(MatGraph MatG,Graph* &G)
{//已知MatGraph邻接矩阵   有向图 
	G = new Graph;
	G->numVNode = MatG.numVNode;
	G->numENode = MatG.ENode;
	for(int i=0;i<MatG.numVNode)	
		G->adjlist[i].FirstENode =NULL;
	for(int i=0;i<MatG.numVNode;i++)
	{
		int j =0;
		ENode* E = new ENode;
		G->adjlist[i].Data = MatG.VNode[i];
		for(;j<MatG.numVNode;j++)
			if(0==MatG.ENode[i][j])
			{
				G->adjlist[i].FirstENode = E;
				E->AdjV=j;
				E->Next=NULL;
			}
		for(;j<MatG.numVNode;j++)
		{
			if(0==MatG.ENode[i][j])
			{
				ENode* temp = new ENode;
				temp->AdjV=j;
				temp->Next=NULL;
				E->Next = temp;
				E = temp;	
			}
		}
			
	}
}
void ListToMat(MatGraph MatG,Graph* &G)
{//已知邻接表G ,转为邻接矩阵MatG 
	ENode* E;
	memset(MatG.VNode,'#',sizeof(MatG.VNode));
	memset(MatG.ENode,INF,sizeof(MatG.ENode));
	for(int i=0;i<G->numVNode;i++)
	{
		E = G->adjlist[i].FirstENode;
		MatG.VNode[i] = G->adjlist[i].Data;
		while(E!=NULL)
		{
			MatG.ENode[i][E->AdjV]=E->Weight;
			E=E->Next;
		}
	}
}*/
void deq(ALGraph* G,char A)
{//无向图的度 
	ENode* E;
	int n,v;
	for(v=0;G->adjlist[v].Data==A;v++)
	{
		
	}
	while(E!=NULL)
	{
		n++;
		E=E->Next;
	}
	cout<<A<<"点的度数"<<n; 
 } 
int main()
{
	memset(visited,0,sizeof(visited));
	ALGraph* G;
	G = new ALGraph;
	CreatALGraph(G);
}
