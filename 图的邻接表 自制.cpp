#include<bits/stdc++.h>
#define INF 999999
#define MaxVNode 100
using namespace std;
typedef struct ENode
{
	int AdjV;//�ڽӵ��򣬴洢�ڽӶ����Ӧ���±�
	int Weight;
	struct ENode *Next;//����ָ��ͬһ��������һ���ڽӵ�

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
void CreatALGraph(ALGraph* G)//����ͼ���� 
{
	FILE *p;
	assert((p=fopen("ALGraph.txt","r"))!=NULL);
	fscanf(p,"�������=%d;",&G->numVNode);//����͸���numVNode 
	fscanf(p,"�߸���=%d;",&G->numENode);
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
		G->adjlist[V1].FirstENode=e;//ͷ�巨 
		//��������ͼ
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
{//��֪MatGraph�ڽӾ���   ����ͼ 
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
{//��֪�ڽӱ�G ,תΪ�ڽӾ���MatG 
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
{//����ͼ�Ķ� 
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
	cout<<A<<"��Ķ���"<<n; 
 } 
int main()
{
	memset(visited,0,sizeof(visited));
	ALGraph* G;
	G = new ALGraph;
	CreatALGraph(G);
}
