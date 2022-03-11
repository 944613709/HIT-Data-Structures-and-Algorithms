#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<assert.h>
using namespace std;
#define INF -1
#define MaxVNode 100
int visited[MaxVNode];

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
void CreatMatGraph(MatGraph &G); //读入边和顶点建立邻接矩阵 
void Mat_DFS(MatGraph G,int start);//MatGraoh的DFS 
void Mat_BFS(MatGraph G,int start);//MatGraoh的BFS 
void ShowMatGraph(MatGraph G);//进行展示邻接矩阵 
void ShowALGraph(ALGraph* G);//进行展示邻接表 
void Mat_DFS_Tree(MatGraph G,int start);//MatGraoh的DFS 树展示 
void Mat_DFS_BianHao(MatGraph G,int start,int count,int arr[]);//MatGraoh的DFS 
void Mat_BFS_Tree(MatGraph G,int start);
void Mat_BFS_BianHao(MatGraph G,int start,int count,int arr[]);
void AL_DFS_Tree(ALGraph* G,int v);
void AL_DFS_BianHao(ALGraph* G,int v,int count,int arr[]);
void AL_BFS_Tree(ALGraph *G,int v);
void AL_BFS_BianHao(ALGraph *G,int v,int count,int arr[]);
void InitialTree();//初始化树 



void InitMatGraph(MatGraph &G)//初始化Mat 
{
	memset(G.VNode,'#',sizeof(G.VNode));//全部初始化# 
	memset(G.ENode,INF,sizeof(G.ENode));
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
void Mat_DFS(MatGraph G,int start)//MatGraoh的DFS 
{
	cout<<G.VNode[start];
	visited[start]=1;//代表已经访问 
	for(int i=0;i<G.numVNode;i++)
	{ 
		if(G.ENode[start][i]!=INF&&visited[i]!=1)
		{
			Mat_DFS(G,i);//1深入 
		}
		//2可以自己转向所有可能的地方 
	}
	//3这一层Mat_DFS退出后返回上一层Mat_DFS，回退 
}	
void Mat_DFS_Tree(MatGraph G,int start)//MatGraoh的DFS 
{
	for(int i=0;i<G.numVNode;i++)
	{
		if(G.ENode[start][i]!=INF&&visited[i]!=1)
		{
			T.node[i].Data = G.VNode[i];
			T.node[i].Parent = start;
			T.numTNode++;
			visited[start]=1;//代表已经访问 
			Mat_DFS_Tree(G,i);
		}
	}
}	
void Mat_DFS_BianHao(MatGraph G,int start,int count,int arr[])//MatGraoh的DFS 
{
	arr[start]=count;//count最初从1开始 
	visited[start]=1;//代表已经访问 
	for(int i=0;i<G.numVNode;i++)
	{
		if(G.ENode[start][i]!=INF&&visited[i]!=1)
		{
			Mat_DFS_BianHao(G,i,++count,arr);
		}
	}
}	
void Mat_BFS(MatGraph G,int start)
{
	queue<int>Q;
	cout<<G.VNode[start];
	visited[start]=1;
	Q.push(start);//进队之前cout 
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
void Mat_BFS_Tree(MatGraph G,int start)
{
	queue<int>Q;
	visited[start]=1;
	Q.push(start);//进队之前cout 
	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		for(int i=0;i<G.numVNode;i++)
		{
			if(G.ENode[v][i]!=INF&&visited[i]!=1)
			{
				//cout<<G.VNode[v]<<"->"<<G.VNode[i]<<" ";
				T.node[i].Data = G.VNode[i];
				T.node[i].Parent = v;
				T.numTNode++;
				Q.push(i);
				visited[i]=1;
			}
		}
	}
}
void Mat_BFS_BianHao(MatGraph G,int start,int count,int arr[])
{
	queue<int>Q;
	visited[start]=1;
	arr[start]=count;//首个count=1 
	Q.push(start);//进队之前cout 
	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		for(int i=0;i<G.numVNode;i++)
		{
			if(G.ENode[v][i]!=INF&&visited[i]!=1)
			{
				arr[i]=++count;
				Q.push(i);
				visited[i]=1;
			}
		}
	}
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
	fscanf(p,"边个数=%d;",&m);
	for(int i=0;i<m;i++)
	{
		char V1,V2;
		int weight;
		fscanf(p,"%c,%c,%d;",&V1,&V2,&weight);
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
				if(G.ENode[i][j]!=INF)
				
					cout<<G.ENode[i][j]<<" ";
				else
					cout<<"oo ";
			 } 
		cout<<endl;
	}
}
void CreatALGraph(ALGraph* G)//有向图处理 
{
	FILE *p;
	assert((p=fopen("ALGraph.txt","r"))!=NULL);//txt文本必须要ANSI编码模式才可以中文 
	fscanf(p,"顶点个数=%d;",&(G->numVNode));//最初就给定numVNode 
	fscanf(p,"边个数=%d;",&(G->numENode));
	for(int i=0;i<G->numVNode;i++)
	{
		fscanf(p,"%c;",&(G->adjlist[i].Data));
		G->adjlist[i].FirstENode=NULL;
	}
	for(int i=0 ;i<G->numENode;i++)
	{
		char V1,V2;
		int V1_i,V2_i;//V1对应的下标是V1_i 
		int Weight;
		fscanf(p,"%c,%c,%d;",&V1,&V2,&Weight);
		ENode* e;
		e= new ENode;
		for(int i=0;i<G->numVNode;i++)
		{
			if(V1 == G->adjlist[i].Data)
				{
					V1_i=i;	
				}
			if(V2 == G->adjlist[i].Data )
				{
					V2_i=i;	
				}
		}//找到下标 
		//边 V1->V2
		e->AdjV=V2_i;//记录e边，由V1指向V2 
		e->Weight = Weight;
		e->Next=G->adjlist[V1_i].FirstENode;//e边的起点顶点在V1所以头插法进入V1 
		G->adjlist[V1_i].FirstENode=e;//头插法 
		/*//若是无向图
		//边V2->V1 
		e= new ENode;
		e->AdjV=V1_i;
		e->Weight = Weight;
		e->Next=G->adjlist[V2_i].FirstENode;
		G->adjlist[V2_i].FirstENode = e;
		*/
	}
	fclose(p);
	ShowALGraph(G);
}
void ShowALGraph(ALGraph* G)//进行展示邻接表 
{
	for(int i=0;i<G->numVNode;i++)
	{
		cout<<G->adjlist[i].Data;
		ENode* E;
		E = G->adjlist[i].FirstENode;
		while(E!=NULL)
			{
				cout<<"->";
				cout<<E->Weight<<"->"<<G->adjlist[E->AdjV].Data;
				E=E->Next;
			}
		cout<<"->NULL\n";
	}
}
void AL_DFS(ALGraph* G,int v)
{
	cout<<G->adjlist[v].Data;
	visited[v]=1;//cout后就记录进visited 
	ENode* p;
	p=G->adjlist[v].FirstENode;
	while(p!=NULL)
	{
		if(visited[p->AdjV]!=1)
			AL_DFS(G,p->AdjV);//从下一个点以DFS前进 
		p=p->Next;//当上一条路结束，开始这最开始同一个起点的下一条 
	}
}
void AL_DFS_BianHao(ALGraph* G,int v,int count,int arr[])
{
	arr[v]=count;//首次进入的count=1 
	visited[v]=1;//cout后就记录进visited 
	ENode* p;
	p=G->adjlist[v].FirstENode;
	while(p!=NULL)
	{
		if(visited[p->AdjV]!=1)
			AL_DFS_BianHao(G,p->AdjV,++count,arr);//从下一个点以DFS前进 
		p=p->Next;//当上一条路结束，开始这最开始同一个起点的下一条 
	}
}
void AL_DFS_Tree(ALGraph* G,int v)
{
		//cout<<G->adjlist[v].Data;
	visited[v]=1;//cout后就记录进visited 
	ENode* p;
	p=G->adjlist[v].FirstENode;
	while(p!=NULL)
	{
		if(visited[p->AdjV]!=1)
		{
			//cout<<G->adjlist[v].Data<<"->"<<G->adjlist[p->AdjV].Data<<" ";
				T.node[p->AdjV].Data =G->adjlist[p->AdjV].Data;
				T.node[p->AdjV].Parent = v;
				T.numTNode++;
			AL_DFS_Tree(G,p->AdjV);//从下一个点以DFS前进 
		}
			
		p=p->Next;//当上一条路结束，开始这最开始同一个起点的下一条 
	}
}
void AL_BFS(ALGraph *G,int v)
{
	cout<<G->adjlist[v].Data;
	queue<int> Q;
	Q.push(v);//设置为入队前cout 
	visited[v]=1;
	while(!Q.empty())// 
	{
		int temp;
		temp=Q.front();
		Q.pop();
		ENode* E = G->adjlist[temp].FirstENode;//E为当前顶点的某条边 
		while(E!=NULL)
		{
			if(visited[E->AdjV]!=1)//边E指向的终点顶点E->AdjV并没有访问过
			{
				cout<<G->adjlist[E->AdjV].Data;
				visited[E->AdjV]=1;//cout后visited记录 
			 } 
			if (E->Next!=NULL)//和E同一个起点终点的另一条边，所指向的顶点，没有访问过 ,并且这另一条边存在 
				if(visited[E->Next->AdjV]!=1)//连用两个if 是因为visited[E->Next->AdjV]，当 E->Next=NULL时候，判断语句visit[X]溢出 
				{
					Q.push(E->AdjV);
				}
			E = E->Next;//E更新为同一个出发顶点的下一条边 
		}
	}
}
void AL_BFS_BianHao(ALGraph *G,int v,int count,int arr[])
{
	arr[v]=count;
	queue<int> Q;
	Q.push(v);//设置为入队前cout 
	visited[v]=1;
	while(!Q.empty())// 
	{
		int temp;
		temp=Q.front();
		Q.pop();
		ENode* E = G->adjlist[temp].FirstENode;//E为当前顶点的某条边 
		while(E!=NULL)
		{
			if(visited[E->AdjV]!=1)//边E指向的终点顶点E->AdjV并没有访问过
			{
				arr[E->AdjV]=++count;
				visited[E->AdjV]=1;//cout后visited记录 
			 } 
			if (E->Next!=NULL)//和E同一个起点终点的另一条边，所指向的顶点，没有访问过 ,并且这另一条边存在 
				if(visited[E->Next->AdjV]!=1)//连用两个if 是因为visited[E->Next->AdjV]，当 E->Next=NULL时候，判断语句visit[X]溢出 
				{
					Q.push(E->AdjV);
				}
			E = E->Next;//E更新为同一个出发顶点的下一条边 
		}
	}
}
void AL_BFS_Tree(ALGraph *G,int v)
{
	queue<int> Q;
	Q.push(v);//设置为入队前cout 
	visited[v]=1;
	while(!Q.empty())// 
	{
		int temp;
		temp=Q.front();
		Q.pop();
		ENode* E = G->adjlist[temp].FirstENode;//E为当前顶点的某条边 
		while(E!=NULL)
		{
			if(visited[E->AdjV]!=1)//边E指向的终点顶点E->AdjV并没有访问过
			{
				//cout<<G->adjlist[temp].Data<<"->"<<G->adjlist[E->AdjV].Data<<" ";
					T.node[E->AdjV].Data =G->adjlist[E->AdjV].Data;
					T.node[E->AdjV].Parent = temp;
					T.numTNode++;
				visited[E->AdjV]=1;//cout后visited记录 
			 } 
			if (E->Next!=NULL)//和E同一个起点终点的另一条边，所指向的顶点，没有访问过 ,并且这另一条边存在 
				if(visited[E->Next->AdjV]!=1)//连用两个if 是因为visited[E->Next->AdjV]，当 E->Next=NULL时候，判断语句visit[X]溢出 
				{
					Q.push(E->AdjV);
				}
			E = E->Next;//E更新为同一个出发顶点的下一条边 
		}
	}
}
void MatToList(MatGraph MatG,ALGraph* &ALG)//同样是做有向图 
{//已知MatGraph邻接矩阵   有向图 转为 邻接表 
	ALG = new ALGraph;
	ALG->numVNode = MatG.numVNode;
	ALG->numENode = MatG.numENode;
	for(int i=0;i<MatG.numVNode;i++)	
		ALG->adjlist[i].FirstENode =NULL;//将初始化 
	for(int i=0;i<MatG.numVNode;i++)
	{
		int j =0;
		ALG->adjlist[i].Data = MatG.VNode[i];//顶点转换 
		for(;j<MatG.numVNode;j++)//将这个顶点所有相关的边转换 
		{
			if(INF!=MatG.ENode[i][j])//发现有对应的边从i到j 
			{
				ENode* E = new ENode;
				E->AdjV=j;
				E->Weight = MatG.ENode[i][j];
				E->Next = ALG->adjlist[i].FirstENode;
				ALG->adjlist[i].FirstENode=E;//头插法 
			}
		}
	}
	cout<<"已知的邻接矩阵\n";
	ShowMatGraph(MatG); 
	cout<<"转换后变成\n";
	ShowALGraph(ALG);
}
void ListToMat(MatGraph &MatG,ALGraph* &ALG)//这里是！做有向图的 ！ 
{//已知邻接表G ,转为邻接矩阵MatG 
	ENode* E;
	memset(MatG.VNode,'#',sizeof(MatG.VNode));
	memset(MatG.ENode,INF,sizeof(MatG.ENode));
	MatG.numENode=ALG->numENode;
	MatG.numVNode=ALG->numVNode;//初始化 邻接矩阵 
	for(int i=0;i<ALG->numVNode;i++)
	{
		//得到顶点 
		E = ALG->adjlist[i].FirstENode;//得到顶点的第一个条边 
		MatG.VNode[i] = ALG->adjlist[i].Data;//记录顶点 
		while(E!=NULL)
		{
			MatG.ENode[i][E->AdjV]=E->Weight;//记录边 
			E=E->Next;//准备记录下一条边 
		}
	}
	cout<<"已知的邻接表\n";
	ShowALGraph(ALG);
	cout<<"转换后变成\n";
	ShowMatGraph(MatG);
}
void AL_DFS_FeiDiGui(ALGraph* ALG,int start)
{
	stack<ENode*> S;
	memset(visited,0,sizeof(visited));
	cout<<ALG->adjlist[start].Data;
	visited[start]=1;//访问之后立刻visited等于1
	ENode* E = ALG->adjlist[start].FirstENode;
	while(E||!S.empty())
	{
		while(E)
		{
			//1.更深
			if(visited[E->AdjV]==0)//如果更深的终点顶点没有访问过
				{
					S.push(E);//visited之前入队,留下标记可以返回
					cout<<ALG->adjlist[E->AdjV].Data;
					visited[E->AdjV]=1;//cout之后立刻visited

					E = ALG->adjlist[E->AdjV].FirstENode;//进入更深的终点顶点
				}
			//2.转向再试试能不能深入 
			else//visited[E->Adjv]==1
				{
					E = E->Next;
				}//转为同一个起点的另一条边
		}
		if(!S.empty())//3.这条路全验证不通之后返回
		{
			E = S.top();
			S.pop();
		}
	}
}
void Mat_DFS_FeiDiGui(MatGraph MatG,int start)
{
	stack<int> S;
	cout<<MatG.VNode[start];
	visited[start]=1;
	S.push(start);//visited之后就立刻入栈
	//这里选择对首元素进行while之前就入栈
    int v1_i;
    int v2_i;
		while(!S.empty())
		{	
			v1_i = S.top();
			for(v2_i=0;v2_i<MatG.numVNode;v2_i++)
			{//1.深入
				if(visited[v2_i]!=1&&MatG.ENode[v1_i][v2_i]!=INF)//v1->v2有边且从来没有访问过 
					{
						cout<<MatG.VNode[v2_i];
						visited[v2_i]=1;//
						S.push(v2_i);//cout和visited后，入栈方便返回 
						//并且会由v2_i充当新的v1_i准备继续深入
						break;//准备继续深入
					}
				//2.自动转向，通过for循环已经做到，寻找能够深入的转向 
				
			}//3.返回上一级 
			if(v2_i==MatG.numVNode && !S.empty())
			{//证明由v1_i已经不可能再深入了且需要返回上一级 
				S.pop();
			}
		}
}
void InitialTree()//初始化树 
{
		for(int i=0;i<MaxVNode;i++) 
		{
			T.node[i].Data = '#';
			T.node[i].Parent  = -1; 
		}
		T.numTNode=0;
}
void ShowTree()
{
	for(int i=0;i<MaxVNode;i++)
	{
		if(T.node[i].Data!='#')
			cout<<"T.node["<<i<<"].Data ="<<T.node[i].Data<<" ,Parent="<<T.node[i].Parent<<endl;
	}
}
int main()
{
	cout<<"                        -------------------------------------------------------------------\n";
    cout<<"                        |==================       图的相关操作       =================|\n";
    cout<<"                        -------------------------------------------------------------------\n\n";
    cout<<"                        |==================          1.根据txt建立邻接矩阵         =================|\n";
    cout<<"                        |==================          2.邻接矩阵DFS         =================|\n";
    cout<<"                        |==================          3.邻接矩阵BFS         =================|\n";
    cout<<"                        |==================          4.根据txt建立邻接表        =================|\n";
    cout<<"                        |==================          5.邻接表DFS    =================|\n";
    cout<<"                        |==================          6.邻接表BFS  =================|\n";
    cout<<"                        |==================          7.邻接矩阵转邻接表 =================|\n";
	cout<<"                        |==================          8.邻接表转邻接矩阵 =================|\n";
    cout<<"                        |==================          9.邻接表非递归DFS         =================|\n";
    cout<<"                        |==================          10.邻接矩阵非递归DFS         =================|\n";
	while(1)
	{
	int n;
	cout<<"请输入";
	cin>>n; 
	int start;
	int arr[MaxVNode];

	switch(n)
	{
		case 1:
			MatGraph MatG;
			CreatMatGraph(MatG);
			cout<<endl;
			break;
		case 2:
			cout<<"请输入从哪个下标开始进行:";
			cin>>start;
			//
			memset(visited,0,sizeof(visited));//初始化visited 
			cout<<"序列展示\n" ;
			Mat_DFS(MatG,start);
			cout<<endl;
			//
			memset(visited,0,sizeof(visited));//初始化visited 
			InitialTree();
			cout<<"生成树展示\n";
			Mat_DFS_Tree(MatG,start);
			//补充特例头结点进入 
			T.node[start].Data= MatG.VNode[start];
			T.node[start].Parent = -1;
			T.numTNode++;
			ShowTree();
			cout<<endl;
			//
			memset(visited,0,sizeof(visited));//初始化visited 
			memset(arr,-1,sizeof(arr));//初始化arr
			cout<<"编号展示\n";
			Mat_DFS_BianHao(MatG,start,1,arr);//MatGraoh的DFS 
			for(int i=0;i<MatG.numVNode;i++)
				cout<<MatG.VNode[i]<<":"<<arr[i]<<" ";
			cout<<endl;
			break;
		case 3:
			cout<<"请输入从哪个下标开始进行:";
			cin>>start;
			
			cout<<"序号展示";
			memset(visited,0,sizeof(visited));//初始化visited 
			Mat_BFS(MatG,start);
			cout<<endl;
			
			memset(visited,0,sizeof(visited));//初始化visited 
			InitialTree();
			cout<<"生成树展示\n";
			Mat_BFS_Tree(MatG,start);
			//补充特例头结点进入 
			T.node[start].Data= MatG.VNode[start];
			T.node[start].Parent = -1;
			T.numTNode++;
			ShowTree();
			cout<<endl;
			
			memset(visited,0,sizeof(visited));//初始化visited 
			cout<<"编号展示\n";
			Mat_BFS_BianHao(MatG,start,1,arr);//MatGraoh的DFS 
			for(int i=0;i<MatG.numVNode;i++)
				cout<<MatG.VNode[i]<<":"<<arr[i]<<" ";
			cout<<endl;
			break;
		case 4:
			ALGraph* ALG;
			ALG = new ALGraph;
			CreatALGraph(ALG);
			cout<<endl;
			break;
		case 5:
			
			cout<<"请输入从哪个下标开始进行:";
			cin>>start;
			
			cout<<"序号展示\n";
			memset(visited,0,sizeof(visited));//初始化visited 
			AL_DFS(ALG,start);
			cout<<endl;
			
			memset(visited,0,sizeof(visited));//初始化visited 
			InitialTree();
			cout<<"生成树展示\n";
			AL_DFS_Tree(ALG,start);
			//补充特例头结点进入 
			T.node[start].Data= ALG->adjlist[start].Data;
			T.node[start].Parent = -1;
			T.numTNode++;
			ShowTree();
			cout<<endl;
			
			memset(visited,0,sizeof(visited));//初始化visited 
			memset(arr,-1,sizeof(arr));//初始化arr
			cout<<"编号展示\n";
			AL_DFS_BianHao(ALG,start,1,arr);//MatGraoh的DFS ,count=1所以直接传值1 
			for(int i=0;i<ALG->numVNode;i++)
				cout<<ALG->adjlist[i].Data<<":"<<arr[i]<<" ";
			cout<<endl;
			
		case 6:
			cout<<"请输入从哪个下标开始进行:";
			cin>>start;
			
			cout<<"序号展示\n";
			memset(visited,0,sizeof(visited));//初始化visited
			AL_BFS(ALG,start);
			cout<<endl;
			
			memset(visited,0,sizeof(visited));//初始化visited 
			InitialTree();
			cout<<"生成树展示\n";
			AL_BFS_Tree(ALG,start);
			//补充特例头结点进入 
			T.node[start].Data= ALG->adjlist[start].Data;
			T.node[start].Parent = -1;
			T.numTNode++;
			ShowTree();
			cout<<endl;
			
			memset(visited,0,sizeof(visited));//初始化visited 
			memset(arr,-1,sizeof(arr));//初始化arr
			cout<<"编号展示\n";
			AL_BFS_BianHao(ALG,start,1,arr);//MatGraoh的DFS ,count=1所以直接传值1 
			for(int i=0;i<ALG->numVNode;i++)
				cout<<ALG->adjlist[i].Data<<":"<<arr[i]<<" ";
			cout<<endl;
			break;
			
		case 7:
			memset(visited,0,sizeof(visited));//初始化visited 
			MatToList(MatG,ALG);
			cout<<endl;
			break;
		case 8:
			memset(visited,0,sizeof(visited));//初始化visited 
			ListToMat(MatG,ALG);
			cout<<endl;
			break;
		case 9:
			memset(visited,0,sizeof(visited));//初始化visited 
			cout<<"请输入从哪个下标开始进行:";
			cin>>start;
			AL_DFS_FeiDiGui(ALG,start);
			cout<<endl;
			break;
		case 10:
			memset(visited,0,sizeof(visited));//初始化visited 
			cout<<"请输入从哪个下标开始进行:";
			cin>>start;
			Mat_DFS_FeiDiGui(MatG,start);
			cout<<endl;
			break;
			
	}
	
	}
	
} 
