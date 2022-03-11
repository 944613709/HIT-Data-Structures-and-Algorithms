#include<bits/stdc++.h>
#define MaxVerNum 100 //顶点最大数目值
#define INF 0x3f3f3f3f//作为最大值
using namespace std;
//图的数据结构
typedef struct Graph
{
	char VNode[MaxVerNum];//顶点表
	int ENode[MaxVerNum][MaxVerNum];//弧表
	int numVNode, numARC;//顶点数、弧数
}Graph;
int D[MaxVerNum];  //到各个顶点的最短路径
int Path[MaxVerNum]; //记录前驱
void InitGraph(Graph &G)
{
	memset(G.VNode, '#', sizeof(G.VNode));//初始化顶点表
									  //初始化弧表
	for (int i = 0; i < MaxVerNum; i++)
		for (int j = 0; j < MaxVerNum; j++)
			G.ENode[i][j] = INF;
	G.numARC = G.numVNode = 0;          //初始化顶点数、弧数
}
bool InsertNode(Graph &G, char v)
{
	if (G.numVNode < MaxVerNum)
	{
		G.VNode[G.numVNode++] = v;
		return true;
	}
	return false;
}
bool InsertENode(Graph &G, char v, char w, int weight)
{
	int p1, p2;//v,w两点下标
	p1 = p2 = -1;//初始化
	for (int i = 0; i<G.numVNode; i++)//寻找顶点下标
	{
		if (G.VNode[i] == v)p1 = i;
		if (G.VNode[i] == w)p2 = i;
	}
	if (-1 != p1&&-1 != p2)//两点均可在图中找到
	{
		G.ENode[p1][p2] = weight;//有向图邻接矩阵不对称
		G.numARC++;
		return true;
	}
	return false;
}
void Bellman_Ford(Graph G, int v)
{
	//初始化
	int n = G.numVNode;//n为图的顶点个数
	for (int i = 0; i < n; i++)
	{
		D[i] = G.ENode[v][i];
		if (D[i] < INF)Path[i] = v;
		else Path[i] = -1;
	}
	D[v] = 0;
	for(int i=0;i<G.numVNode-1;i++)
		for(int j=0;j<G.numVNode;j++)
			for(int k=0;k<G.numVNode;k++) 
				if (D[k] > D[j] + G.ENode[j][k])
				{
					D[k] = D[j] + G.ENode[j][k];
					Path[k] = j;
				}
	bool flag = true;
	for (int j = 0; j<G.numVNode - 1; j++) 
		for (int k = 0; k<G.numVNode - 1; k++) 
			if (D[k] > D[j] + G.ENode[j][k])
			{
				flag = false;
				break; 
			}
		if(flag == false)
	{
		cout << "有负圈错误" << endl;
		exit(0);
	}
	for(int i=0;i<n;i++)
	{
		cout<<"顶点"<<G.VNode[i]<<" ";
		cout<<"D["<<i<<"]"<<"="<<D[i]<<" ";
		cout<<"Path["<<i<<"]="<<Path[i];
		cout<<endl;
	}

}
void CreateGraph(Graph &G) //读入边和顶点建立邻接矩阵 
{
	FILE *p;
	assert((p=fopen("MatGraph.txt","r"))!=NULL);
	int n;
	fscanf(p,"顶点个数=%d;",&n);
	for(int i=0;i<n;i++)
	{
		char V;
		fscanf(p,"%c;",&V);
		if (InsertNode(G, V)) continue;//插入点
		else {
			cout << "输入错误！" << endl; break;
		}
	}
	int m;
	char flag;
	fscanf(p,"边个数=%d;",&m);
	for(int i=0;i<m;i++)
	{
		char V1,V2;
		int weight;
		fscanf(p,"%c,%c,%d;",&V1,&V2,&weight);
			if(InsertENode(G,V1,V2,weight))
                continue;
	}
	fclose(p);
	cout << "图的顶点及邻接矩阵：" << endl;
	for (int i = 0; i < G.numVNode; i++)
	{
		cout << G.VNode[i] << " ";
	}
	cout << endl;
		for (int i = 0; i < G.numVNode; i++)
	{
		for (int j = 0; j < G.numVNode; j++)
		{
			if (G.ENode[i][j] == INF)cout << "∞ ";
			else cout << G.ENode[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	Graph G;
	InitGraph(G);
	CreateGraph(G);
	char V;
	int v = -1;
	cin >> V;
	for (int i = 0; i < G.numVNode; i++)
		if (G.VNode[i] == V)
			v = i;
	if (v == -1)
	{
		cout << "ERROR" << endl;
		return 0;
	}
	Bellman_Ford(G,v);
}
