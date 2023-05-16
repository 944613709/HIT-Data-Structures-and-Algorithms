#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<assert.h>
using namespace std;
#define INF 9999999
#define MaxVNode 100
int D[100];
int Pr[100];

typedef struct TNode {
	char Data;	//结点数据
	int Parent;		//该结点双亲再数组中的下标
}TNode;
 
typedef struct Tree{
	TNode node[MaxVNode];	//结点数组
	int numTNode;					//结点数量
}Tree;
Tree T;
typedef struct MatGraph//先按照有向图做 
{
	char VNode[MaxVNode];
	int ENode[MaxVNode][MaxVNode];
	int numENode;
	int numVNode;
}MatGraph;
typedef struct ENode
{
	int AdjV;//这条边的终点顶点对应的下标
	int Weight;
	struct ENode *Next;//链域，有着同一个起点的下一条边 

}ENode;
typedef struct VNode
{
	char Data;
	ENode* FirstENode;//由该顶点V出发的第一条边 
}VNode,AdjList[MaxVNode];
typedef struct ALGraph
{
	AdjList adjlist;
	int numVNode;
	int numENode;
}ALGraph;//ALGraph 
template<class T>class stack
{
private:
	struct Node
	{
		T data;
		Node *next;
	};
	Node *head;
	Node *p;
	int length;
 
public:
	stack()
	{
		head = NULL;
		length = 0;
	}
	void push(T n)//入栈
	{
		Node *q = new Node;
		q->data = n;
		if (head == NULL)
		{
			q->next = head;
			head = q;
			p = q;
		}
		else
		{
			q->next = p;
			p = q;
		}
		length++;
	}
 
	void pop()//出栈   不会！！并且不会！！！将出栈的元素返回
	{
		if (length <= 0)
		{
			abort();
		}
		Node *q;
		T data;
		q = p;
		data = p->data;
		p = p->next;
		delete(q);
		length--;
	}
	int size()//返回元素个数
	{
		return length;
	}
	T top()//返回栈顶元素
	{
		return p->data;
	}
	bool empty()//判断栈是不是空的
	{
		if (length == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
template<class T>class queue
{
private:
	struct Node
	{
		T data;
		Node *next;
	};
	Node *head;//!
	Node *rear;//！队尾 
	int length;
 
public:
	queue()
	{
		head = NULL;
		rear = NULL;//！初始化 
		length = 0;
	}
	void push(T n)//入队
	{
		Node *node = new Node;
		node->data = n;
		node->next = NULL;//!
		if (head == NULL)
		{
			head = node;
			rear = node;
		}
		else
		{
			rear->next = node;
			rear = node;
		}
		length++;
	}
	void pop()//出栈   不会！！并且不会！！！将出栈的元素返回
	{
		if (length <= 0)
		{
			abort();
		}
		Node *temp = head;
		head = head->next;
		delete (temp);
		length--;
	}
	int size()//返回元素个数
	{
		return length;
	}
	T front()//!返回队首元素
	{
		return head->data;
	}
	bool empty()//判断栈是不是空的
	{
		if (length == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
void InitMatGraph(MatGraph &G);//初始化Mat 
void InsertVNode(MatGraph &G,char V);//MatG插入V 
void InsertENode(MatGraph &G,char V,char W,int Weight);//向图MatG插入边 
void ShowMatGraph(MatGraph G);

void InitMatGraph(MatGraph &G)//初始化Mat 
{
	memset(G.VNode,'#',sizeof(G.VNode));//全部初始化# 
	memset(G.ENode,-1,sizeof(G.ENode));
	G.numENode=0;//当前有效的边 
	G.numVNode=0;
}
void InsertVNode(MatGraph &G,char V)//MatG插入V 
{
	G.VNode[G.numVNode++]=V;
}
void InsertENode(MatGraph &G,char V,char W,int Weight)//有向图MatG插入边 
{
	//有向图 
	int v1,v2;//边VW对应下标v1,v2 
	for(int i=0;i<G.numVNode;i++)
	{
		if(G.VNode[i]==V)
			v1=i;
		if(G.VNode[i]==W)
			v2=i;
	}
	G.ENode[v1][v2]=Weight;
	/*//若是无向图 
	G.ENode[v2][v1]=Weight;
	*/
	G.numENode++;
}
void CreatMatGraph(MatGraph &G) //读入边和顶点建立邻接矩阵 
{
	FILE *p;
	assert((p=fopen("MatGraph.txt","r"))!=NULL);
	InitMatGraph(G);
	int n;
	fscanf(p,"顶点个数=%d;",&n);
	for(int i=0;i<n;i++)
	{
		char V;
		fscanf(p,"%c;",&V);
		InsertVNode(G,V);
	}
	int m;
	char flag;
	fscanf(p,"边个数=%d;",&m);
	for(int i=0;i<m;i++)
	{
		char V1,V2;
		int weight;
		fscanf(p,"%c,%c,%d;",&V1,&V2,&flag,&weight);
		InsertENode(G,V1,V2,weight);
	}
	fclose(p);
	ShowMatGraph(G);//进行展示邻接矩阵 
}
void ShowMatGraph(MatGraph G)//进行展示邻接矩阵 
{
	int n=G.numVNode;
	int m=G.numENode;
		//进行展示邻接矩阵 
	cout<<"  ";//保证输入格式 
	for(int i=0;i<n;i++)
		cout<<G.VNode[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<G.VNode[i]<<" ";
		for(int j=0;j<n;j++)
			{
				if(G.ENode[i][j]!=-1)
					cout<<G.ENode[i][j]<<" ";
				else
					cout<<"oo ";
			 } 
		cout<<endl;
	}
}
//最短路径 - Bellman_Ford算法  参数：图G、源点v 作用：计算不含负圈图的最短路径 返回是否有圈
bool Bellman_Ford(MatGraph G, int v)
{
	//初始化
	int n = G.numVNode;//n为图的顶点个数
	for (int i = 0; i < n; i++)
	{
		D[i] = G.ENode[v][i];
		if (D[i] < INF)
			Pr[i] = v; //v与i连接，v为前驱
		else Pr[i] = -1;
	}
	D[v] = 0;
	//初始化结束，开始双重循环
		for(int j=0;j<G.numVNode-1;j++) //j为源点
			for(int k=0;k<G.numVNode-1;k++) //k为终点
				if (D[k] > D[j] + G.ENode[j][k])
				{
					D[k] = D[j] + G.ENode[j][k];
					Pr[k] = j;
				}
	//判断是否含有负圈
	bool flag = true;
	for (int j = 0; j<G.numVNode - 1; j++) //j为源点
		for (int k = 0; k<G.numVNode - 1; k++) //k为终点
			if (D[k] > D[j] + G.ENode[j][k])
			{
				flag = false;
				break;
			}
	for(int i=0;i<n;i++)
	{
		cout<<"D["<<i<<"]"<<"="<<D[i]<<" ";
		cout<<"Pr["<<i<<"]="<<Pr[i];
		cout<<endl;
	}
	return flag;
}
void Path(MatGraph G, int v)
{
	if (Pr[v] == -1)
		return;
	Path(G, Pr[v]);
	cout << G.VNode[Pr[v]] << "->";
}//递归去找前一个结点 
void Shortest_Bellman_Ford(MatGraph &G)
{
	
	int v = -1;
	cin>>v;
	int flag = Bellman_Ford(G,v);
		cout << "目标点" << "\t" << "最短路径值" << "\t" << "最短路径" << endl;
		for (int i = 0; i < G.numVNode; i++)
		{
			cout << "  " << G.VNode[i] << "\t" << "        " << D[i] << "\t";
			Path(G, i);
			cout << G.VNode[i] << endl;
	}
}

int main()
{
	memset(D,999999,sizeof(D));
	memset(Pr,-1,sizeof(Pr));
	MatGraph MatG;
	CreatMatGraph(MatG);
	Shortest_Bellman_Ford(MatG);
}
