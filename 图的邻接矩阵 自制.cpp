#include<bits/stdc++.h>
using namespace std;
#define INF 999999
#define MaxVNode 100
typedef struct Graph//先按照无向图做 
{
	char VNode[MaxVNode];
	int ENode[MaxVNode][MaxVNode];
	int numENode;
	int numVNode;
}Graph;

void InitGraph(Graph &G)
{
	memset(G.VNode,'#',sizeof(G.VNode));//全部初始化# 
	memset(G.ENode,INF,sizeof(G.ENode));
	G.numENode=0;//当前有效的边 
	G.numVNode=0;
}
void InsertVNode(Graph &G,char V)
{
	G.VNode[G.numVNode++]=V;//一边记录V，一边增加numVNode 
}
void InsertENode(Graph &G,char V,char W,int Weight)
{
	//无向图 
	int v1,v2;
	for(int i=0;i<G.numVNode;i++)
	{
		if(G.VNode[i]==V)
			v1=i;
		if(G.VNode[i]==W)
			v2=i;
	}
	G.ENode[v1][v2]=Weight;
	G.ENode[v2][v1]=Weight;
	G.numENode++;
}	
int visited[MaxVNode];
void DFS(Graph G,int start)
{
	cout<<G.VNode[start];
	visited[start]=1;
	for(int i=0;i<G.numVNode;i++)
	{
		if(G.ENode[start][i]!=INF&&visited[i]!=1)
		{
			DFS(G,i);
		}
	}
}
void BFS(Graph G,int start)
{
	queue<int>Q;
	cout<<G.VNode[start];
	visited[start]=1;
	Q.push(start);
	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		for(int i=0;i<G.numVNode;i++)
		{
			if(G.ENode[v][i]!=INF&&visited[i]!=1)
			{
				cout<<G.VNode[i];
				Q.push(i);
				visited[i]=1;
			}
		}
	}
}
void Dijkstra(Graph G, int v)
{
	bool S[G.numVNode];
	bool U[G.numVNode];
	int D[G.numVNode];
	int n = G.numVNode;
	int Pr[G.numVNode];
	for(int i = 0;i<n;i++)
	{
		S[i]=false;//未进入S[i]
		D[i]= G.ENode[v][i];
		if(D[i]<INF)
			Pr[i]=v;
		else
			Pr[i]=-1;
		
	}//初始化
	
	
	for(int i=1;i<n;i++)
	{	
		int min=INF;
		int temp;
		for(int w=0;w<n;w++)//找到一个当前最短的然后加入S 
			if(!S[w]&&D[w]<min)
			{
				temp = w;
				min = D[w];
			}
		S[temp] = true;
		for(int w = 0;w<n;w++)//更新一次D最短路径 
		{
			if(!S[w]&&D[temp]+G.ENode[temp][w]<D[w])
			{
				D[w]=D[temp]+G.ENode[temp][w];
				Pr[w] = temp;
			}
		}
	}
}
void CreatMatGraph(Graph &G) //读入边和顶点建立邻接矩阵 
{
	FILE *p;
	assert((p=fopen("MatGraph.txt","r"))!=NULL);
	InitGraph(G);
	int n;
	fscanf(p,"顶点个数=%d;",&n);
	for(int i=0;i<n;i++)
	{
		char V;
		fscanf(p,"%c;",&V);
		InsertVNode(G,V);
	}
	int m;
	fscanf(p,"边个数=%d;",&m);
	for(int i=0;i<m;i++)
	{
		char V1,V2;
		int weight;
		fscanf(p,"%c,%c,%d;",&V1,&V2,&weight);
		InsertENode(G,V1,V2,weight);
	}
	fclose(p);
}

int main()
{
	memset(visited,0,sizeof(visited));//初始化visited 
	Graph G;
	CreatMatGraph(G);
	DFS(G,0);
	BFS(G,0); 
} 
