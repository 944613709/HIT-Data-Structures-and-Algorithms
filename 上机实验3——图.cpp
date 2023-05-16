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
	char Data;	//�������
	int Parent;		//�ý��˫���������е��±�
}TNode;
 
typedef struct Tree{
	TNode node[MaxVNode];	//�������
	int numTNode;					//�������
}Tree;
Tree T;
typedef struct MatGraph//�Ȱ�������ͼ�� 
{
	char VNode[MaxVNode];
	int ENode[MaxVNode][MaxVNode];
	int numENode;
	int numVNode;
}MatGraph;
typedef struct ENode
{
	int AdjV;//�����ߵ��յ㶥���Ӧ���±�
	int Weight;
	struct ENode *Next;//��������ͬһ��������һ���� 

}ENode;
typedef struct VNode
{
	char Data;
	ENode* FirstENode;//�ɸö���V�����ĵ�һ���� 
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
	void push(T n)//��ջ
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
 
	void pop()//��ջ   ���ᣡ�����Ҳ��ᣡ��������ջ��Ԫ�ط���
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
	int size()//����Ԫ�ظ���
	{
		return length;
	}
	T top()//����ջ��Ԫ��
	{
		return p->data;
	}
	bool empty()//�ж�ջ�ǲ��ǿյ�
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
	Node *rear;//����β 
	int length;
 
public:
	queue()
	{
		head = NULL;
		rear = NULL;//����ʼ�� 
		length = 0;
	}
	void push(T n)//���
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
	void pop()//��ջ   ���ᣡ�����Ҳ��ᣡ��������ջ��Ԫ�ط���
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
	int size()//����Ԫ�ظ���
	{
		return length;
	}
	T front()//!���ض���Ԫ��
	{
		return head->data;
	}
	bool empty()//�ж�ջ�ǲ��ǿյ�
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
void InitMatGraph(MatGraph &G);//��ʼ��Mat 
void InsertVNode(MatGraph &G,char V);//MatG����V 
void InsertENode(MatGraph &G,char V,char W,int Weight);//��ͼMatG����� 
void CreatMatGraph(MatGraph &G); //����ߺͶ��㽨���ڽӾ��� 
void Mat_DFS(MatGraph G,int start);//MatGraoh��DFS 
void Mat_BFS(MatGraph G,int start);//MatGraoh��BFS 
void ShowMatGraph(MatGraph G);//����չʾ�ڽӾ��� 
void ShowALGraph(ALGraph* G);//����չʾ�ڽӱ� 
void Mat_DFS_Tree(MatGraph G,int start);//MatGraoh��DFS ��չʾ 
void Mat_DFS_BianHao(MatGraph G,int start,int count,int arr[]);//MatGraoh��DFS 
void Mat_BFS_Tree(MatGraph G,int start);
void Mat_BFS_BianHao(MatGraph G,int start,int count,int arr[]);
void AL_DFS_Tree(ALGraph* G,int v);
void AL_DFS_BianHao(ALGraph* G,int v,int count,int arr[]);
void AL_BFS_Tree(ALGraph *G,int v);
void AL_BFS_BianHao(ALGraph *G,int v,int count,int arr[]);
void InitialTree();//��ʼ���� 



void InitMatGraph(MatGraph &G)//��ʼ��Mat 
{
	memset(G.VNode,'#',sizeof(G.VNode));//ȫ����ʼ��# 
	memset(G.ENode,INF,sizeof(G.ENode));
	G.numENode=0;//��ǰ��Ч�ı� 
	G.numVNode=0;
}
void InsertVNode(MatGraph &G,char V)//MatG����V 
{
	G.VNode[G.numVNode++]=V;
}
void InsertENode(MatGraph &G,char V,char W,int Weight)//����ͼMatG����� 
{
	//����ͼ 
	int v1,v2;//��VW��Ӧ�±�v1,v2 
	for(int i=0;i<G.numVNode;i++)
	{
		if(G.VNode[i]==V)
			v1=i;
		if(G.VNode[i]==W)
			v2=i;
	}
	G.ENode[v1][v2]=Weight;
	/*//��������ͼ 
	G.ENode[v2][v1]=Weight;
	*/
	G.numENode++;
}
void Mat_DFS(MatGraph G,int start)//MatGraoh��DFS 
{
	cout<<G.VNode[start];
	visited[start]=1;//�����Ѿ����� 
	for(int i=0;i<G.numVNode;i++)
	{ 
		if(G.ENode[start][i]!=INF&&visited[i]!=1)
		{
			Mat_DFS(G,i);//1���� 
		}
		//2�����Լ�ת�����п��ܵĵط� 
	}
	//3��һ��Mat_DFS�˳��󷵻���һ��Mat_DFS������ 
}	
void Mat_DFS_Tree(MatGraph G,int start)//MatGraoh��DFS 
{
	for(int i=0;i<G.numVNode;i++)
	{
		if(G.ENode[start][i]!=INF&&visited[i]!=1)
		{
			T.node[i].Data = G.VNode[i];
			T.node[i].Parent = start;
			T.numTNode++;
			visited[start]=1;//�����Ѿ����� 
			Mat_DFS_Tree(G,i);
		}
	}
}	
void Mat_DFS_BianHao(MatGraph G,int start,int count,int arr[])//MatGraoh��DFS 
{
	arr[start]=count;//count�����1��ʼ 
	visited[start]=1;//�����Ѿ����� 
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
	Q.push(start);//����֮ǰcout 
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
	Q.push(start);//����֮ǰcout 
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
	arr[start]=count;//�׸�count=1 
	Q.push(start);//����֮ǰcout 
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
void CreatMatGraph(MatGraph &G) //����ߺͶ��㽨���ڽӾ��� 
{
	FILE *p;
	assert((p=fopen("MatGraph.txt","r"))!=NULL);
	InitMatGraph(G);
	int n;
	fscanf(p,"�������=%d;",&n);
	for(int i=0;i<n;i++)
	{
		char V;
		fscanf(p,"%c;",&V);
		InsertVNode(G,V);
	}
	int m;
	fscanf(p,"�߸���=%d;",&m);
	for(int i=0;i<m;i++)
	{
		char V1,V2;
		int weight;
		fscanf(p,"%c,%c,%d;",&V1,&V2,&weight);
		InsertENode(G,V1,V2,weight);
	}
	fclose(p);
	ShowMatGraph(G);//����չʾ�ڽӾ��� 
}
void ShowMatGraph(MatGraph G)//����չʾ�ڽӾ��� 
{
	int n=G.numVNode;
	int m=G.numENode;
		//����չʾ�ڽӾ��� 
	cout<<"  ";//��֤�����ʽ 
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
void CreatALGraph(ALGraph* G)//����ͼ���� 
{
	FILE *p;
	assert((p=fopen("ALGraph.txt","r"))!=NULL);//txt�ı�����ҪANSI����ģʽ�ſ������� 
	fscanf(p,"�������=%d;",&(G->numVNode));//����͸���numVNode 
	fscanf(p,"�߸���=%d;",&(G->numENode));
	for(int i=0;i<G->numVNode;i++)
	{
		fscanf(p,"%c;",&(G->adjlist[i].Data));
		G->adjlist[i].FirstENode=NULL;
	}
	for(int i=0 ;i<G->numENode;i++)
	{
		char V1,V2;
		int V1_i,V2_i;//V1��Ӧ���±���V1_i 
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
		}//�ҵ��±� 
		//�� V1->V2
		e->AdjV=V2_i;//��¼e�ߣ���V1ָ��V2 
		e->Weight = Weight;
		e->Next=G->adjlist[V1_i].FirstENode;//e�ߵ���㶥����V1����ͷ�巨����V1 
		G->adjlist[V1_i].FirstENode=e;//ͷ�巨 
		/*//��������ͼ
		//��V2->V1 
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
void ShowALGraph(ALGraph* G)//����չʾ�ڽӱ� 
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
	visited[v]=1;//cout��ͼ�¼��visited 
	ENode* p;
	p=G->adjlist[v].FirstENode;
	while(p!=NULL)
	{
		if(visited[p->AdjV]!=1)
			AL_DFS(G,p->AdjV);//����һ������DFSǰ�� 
		p=p->Next;//����һ��·��������ʼ���ʼͬһ��������һ�� 
	}
}
void AL_DFS_BianHao(ALGraph* G,int v,int count,int arr[])
{
	arr[v]=count;//�״ν����count=1 
	visited[v]=1;//cout��ͼ�¼��visited 
	ENode* p;
	p=G->adjlist[v].FirstENode;
	while(p!=NULL)
	{
		if(visited[p->AdjV]!=1)
			AL_DFS_BianHao(G,p->AdjV,++count,arr);//����һ������DFSǰ�� 
		p=p->Next;//����һ��·��������ʼ���ʼͬһ��������һ�� 
	}
}
void AL_DFS_Tree(ALGraph* G,int v)
{
		//cout<<G->adjlist[v].Data;
	visited[v]=1;//cout��ͼ�¼��visited 
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
			AL_DFS_Tree(G,p->AdjV);//����һ������DFSǰ�� 
		}
			
		p=p->Next;//����һ��·��������ʼ���ʼͬһ��������һ�� 
	}
}
void AL_BFS(ALGraph *G,int v)
{
	cout<<G->adjlist[v].Data;
	queue<int> Q;
	Q.push(v);//����Ϊ���ǰcout 
	visited[v]=1;
	while(!Q.empty())// 
	{
		int temp;
		temp=Q.front();
		Q.pop();
		ENode* E = G->adjlist[temp].FirstENode;//EΪ��ǰ�����ĳ���� 
		while(E!=NULL)
		{
			if(visited[E->AdjV]!=1)//��Eָ����յ㶥��E->AdjV��û�з��ʹ�
			{
				cout<<G->adjlist[E->AdjV].Data;
				visited[E->AdjV]=1;//cout��visited��¼ 
			 } 
			if (E->Next!=NULL)//��Eͬһ������յ����һ���ߣ���ָ��Ķ��㣬û�з��ʹ� ,��������һ���ߴ��� 
				if(visited[E->Next->AdjV]!=1)//��������if ����Ϊvisited[E->Next->AdjV]���� E->Next=NULLʱ���ж����visit[X]��� 
				{
					Q.push(E->AdjV);
				}
			E = E->Next;//E����Ϊͬһ�������������һ���� 
		}
	}
}
void AL_BFS_BianHao(ALGraph *G,int v,int count,int arr[])
{
	arr[v]=count;
	queue<int> Q;
	Q.push(v);//����Ϊ���ǰcout 
	visited[v]=1;
	while(!Q.empty())// 
	{
		int temp;
		temp=Q.front();
		Q.pop();
		ENode* E = G->adjlist[temp].FirstENode;//EΪ��ǰ�����ĳ���� 
		while(E!=NULL)
		{
			if(visited[E->AdjV]!=1)//��Eָ����յ㶥��E->AdjV��û�з��ʹ�
			{
				arr[E->AdjV]=++count;
				visited[E->AdjV]=1;//cout��visited��¼ 
			 } 
			if (E->Next!=NULL)//��Eͬһ������յ����һ���ߣ���ָ��Ķ��㣬û�з��ʹ� ,��������һ���ߴ��� 
				if(visited[E->Next->AdjV]!=1)//��������if ����Ϊvisited[E->Next->AdjV]���� E->Next=NULLʱ���ж����visit[X]��� 
				{
					Q.push(E->AdjV);
				}
			E = E->Next;//E����Ϊͬһ�������������һ���� 
		}
	}
}
void AL_BFS_Tree(ALGraph *G,int v)
{
	queue<int> Q;
	Q.push(v);//����Ϊ���ǰcout 
	visited[v]=1;
	while(!Q.empty())// 
	{
		int temp;
		temp=Q.front();
		Q.pop();
		ENode* E = G->adjlist[temp].FirstENode;//EΪ��ǰ�����ĳ���� 
		while(E!=NULL)
		{
			if(visited[E->AdjV]!=1)//��Eָ����յ㶥��E->AdjV��û�з��ʹ�
			{
				//cout<<G->adjlist[temp].Data<<"->"<<G->adjlist[E->AdjV].Data<<" ";
					T.node[E->AdjV].Data =G->adjlist[E->AdjV].Data;
					T.node[E->AdjV].Parent = temp;
					T.numTNode++;
				visited[E->AdjV]=1;//cout��visited��¼ 
			 } 
			if (E->Next!=NULL)//��Eͬһ������յ����һ���ߣ���ָ��Ķ��㣬û�з��ʹ� ,��������һ���ߴ��� 
				if(visited[E->Next->AdjV]!=1)//��������if ����Ϊvisited[E->Next->AdjV]���� E->Next=NULLʱ���ж����visit[X]��� 
				{
					Q.push(E->AdjV);
				}
			E = E->Next;//E����Ϊͬһ�������������һ���� 
		}
	}
}
void MatToList(MatGraph MatG,ALGraph* &ALG)//ͬ����������ͼ 
{//��֪MatGraph�ڽӾ���   ����ͼ תΪ �ڽӱ� 
	ALG = new ALGraph;
	ALG->numVNode = MatG.numVNode;
	ALG->numENode = MatG.numENode;
	for(int i=0;i<MatG.numVNode;i++)	
		ALG->adjlist[i].FirstENode =NULL;//����ʼ�� 
	for(int i=0;i<MatG.numVNode;i++)
	{
		int j =0;
		ALG->adjlist[i].Data = MatG.VNode[i];//����ת�� 
		for(;j<MatG.numVNode;j++)//���������������صı�ת�� 
		{
			if(INF!=MatG.ENode[i][j])//�����ж�Ӧ�ıߴ�i��j 
			{
				ENode* E = new ENode;
				E->AdjV=j;
				E->Weight = MatG.ENode[i][j];
				E->Next = ALG->adjlist[i].FirstENode;
				ALG->adjlist[i].FirstENode=E;//ͷ�巨 
			}
		}
	}
	cout<<"��֪���ڽӾ���\n";
	ShowMatGraph(MatG); 
	cout<<"ת������\n";
	ShowALGraph(ALG);
}
void ListToMat(MatGraph &MatG,ALGraph* &ALG)//�����ǣ�������ͼ�� �� 
{//��֪�ڽӱ�G ,תΪ�ڽӾ���MatG 
	ENode* E;
	memset(MatG.VNode,'#',sizeof(MatG.VNode));
	memset(MatG.ENode,INF,sizeof(MatG.ENode));
	MatG.numENode=ALG->numENode;
	MatG.numVNode=ALG->numVNode;//��ʼ�� �ڽӾ��� 
	for(int i=0;i<ALG->numVNode;i++)
	{
		//�õ����� 
		E = ALG->adjlist[i].FirstENode;//�õ�����ĵ�һ������ 
		MatG.VNode[i] = ALG->adjlist[i].Data;//��¼���� 
		while(E!=NULL)
		{
			MatG.ENode[i][E->AdjV]=E->Weight;//��¼�� 
			E=E->Next;//׼����¼��һ���� 
		}
	}
	cout<<"��֪���ڽӱ�\n";
	ShowALGraph(ALG);
	cout<<"ת������\n";
	ShowMatGraph(MatG);
}
void AL_DFS_FeiDiGui(ALGraph* ALG,int start)
{
	stack<ENode*> S;
	memset(visited,0,sizeof(visited));
	cout<<ALG->adjlist[start].Data;
	visited[start]=1;//����֮������visited����1
	ENode* E = ALG->adjlist[start].FirstENode;
	while(E||!S.empty())
	{
		while(E)
		{
			//1.����
			if(visited[E->AdjV]==0)//���������յ㶥��û�з��ʹ�
				{
					S.push(E);//visited֮ǰ���,���±�ǿ��Է���
					cout<<ALG->adjlist[E->AdjV].Data;
					visited[E->AdjV]=1;//cout֮������visited

					E = ALG->adjlist[E->AdjV].FirstENode;//���������յ㶥��
				}
			//2.ת���������ܲ������� 
			else//visited[E->Adjv]==1
				{
					E = E->Next;
				}//תΪͬһ��������һ����
		}
		if(!S.empty())//3.����·ȫ��֤��֮ͨ�󷵻�
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
	S.push(start);//visited֮���������ջ
	//����ѡ�����Ԫ�ؽ���while֮ǰ����ջ
    int v1_i;
    int v2_i;
		while(!S.empty())
		{	
			v1_i = S.top();
			for(v2_i=0;v2_i<MatG.numVNode;v2_i++)
			{//1.����
				if(visited[v2_i]!=1&&MatG.ENode[v1_i][v2_i]!=INF)//v1->v2�б��Ҵ���û�з��ʹ� 
					{
						cout<<MatG.VNode[v2_i];
						visited[v2_i]=1;//
						S.push(v2_i);//cout��visited����ջ���㷵�� 
						//���һ���v2_i�䵱�µ�v1_i׼����������
						break;//׼����������
					}
				//2.�Զ�ת��ͨ��forѭ���Ѿ�������Ѱ���ܹ������ת�� 
				
			}//3.������һ�� 
			if(v2_i==MatG.numVNode && !S.empty())
			{//֤����v1_i�Ѿ�������������������Ҫ������һ�� 
				S.pop();
			}
		}
}
void InitialTree()//��ʼ���� 
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
    cout<<"                        |==================       ͼ����ز���       =================|\n";
    cout<<"                        -------------------------------------------------------------------\n\n";
    cout<<"                        |==================          1.����txt�����ڽӾ���         =================|\n";
    cout<<"                        |==================          2.�ڽӾ���DFS         =================|\n";
    cout<<"                        |==================          3.�ڽӾ���BFS         =================|\n";
    cout<<"                        |==================          4.����txt�����ڽӱ�        =================|\n";
    cout<<"                        |==================          5.�ڽӱ�DFS    =================|\n";
    cout<<"                        |==================          6.�ڽӱ�BFS  =================|\n";
    cout<<"                        |==================          7.�ڽӾ���ת�ڽӱ� =================|\n";
	cout<<"                        |==================          8.�ڽӱ�ת�ڽӾ��� =================|\n";
    cout<<"                        |==================          9.�ڽӱ�ǵݹ�DFS         =================|\n";
    cout<<"                        |==================          10.�ڽӾ���ǵݹ�DFS         =================|\n";
	while(1)
	{
	int n;
	cout<<"������";
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
			cout<<"��������ĸ��±꿪ʼ����:";
			cin>>start;
			//
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			cout<<"����չʾ\n" ;
			Mat_DFS(MatG,start);
			cout<<endl;
			//
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			InitialTree();
			cout<<"������չʾ\n";
			Mat_DFS_Tree(MatG,start);
			//��������ͷ������ 
			T.node[start].Data= MatG.VNode[start];
			T.node[start].Parent = -1;
			T.numTNode++;
			ShowTree();
			cout<<endl;
			//
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			memset(arr,-1,sizeof(arr));//��ʼ��arr
			cout<<"���չʾ\n";
			Mat_DFS_BianHao(MatG,start,1,arr);//MatGraoh��DFS 
			for(int i=0;i<MatG.numVNode;i++)
				cout<<MatG.VNode[i]<<":"<<arr[i]<<" ";
			cout<<endl;
			break;
		case 3:
			cout<<"��������ĸ��±꿪ʼ����:";
			cin>>start;
			
			cout<<"���չʾ";
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			Mat_BFS(MatG,start);
			cout<<endl;
			
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			InitialTree();
			cout<<"������չʾ\n";
			Mat_BFS_Tree(MatG,start);
			//��������ͷ������ 
			T.node[start].Data= MatG.VNode[start];
			T.node[start].Parent = -1;
			T.numTNode++;
			ShowTree();
			cout<<endl;
			
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			cout<<"���չʾ\n";
			Mat_BFS_BianHao(MatG,start,1,arr);//MatGraoh��DFS 
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
			
			cout<<"��������ĸ��±꿪ʼ����:";
			cin>>start;
			
			cout<<"���չʾ\n";
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			AL_DFS(ALG,start);
			cout<<endl;
			
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			InitialTree();
			cout<<"������չʾ\n";
			AL_DFS_Tree(ALG,start);
			//��������ͷ������ 
			T.node[start].Data= ALG->adjlist[start].Data;
			T.node[start].Parent = -1;
			T.numTNode++;
			ShowTree();
			cout<<endl;
			
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			memset(arr,-1,sizeof(arr));//��ʼ��arr
			cout<<"���չʾ\n";
			AL_DFS_BianHao(ALG,start,1,arr);//MatGraoh��DFS ,count=1����ֱ�Ӵ�ֵ1 
			for(int i=0;i<ALG->numVNode;i++)
				cout<<ALG->adjlist[i].Data<<":"<<arr[i]<<" ";
			cout<<endl;
			
		case 6:
			cout<<"��������ĸ��±꿪ʼ����:";
			cin>>start;
			
			cout<<"���չʾ\n";
			memset(visited,0,sizeof(visited));//��ʼ��visited
			AL_BFS(ALG,start);
			cout<<endl;
			
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			InitialTree();
			cout<<"������չʾ\n";
			AL_BFS_Tree(ALG,start);
			//��������ͷ������ 
			T.node[start].Data= ALG->adjlist[start].Data;
			T.node[start].Parent = -1;
			T.numTNode++;
			ShowTree();
			cout<<endl;
			
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			memset(arr,-1,sizeof(arr));//��ʼ��arr
			cout<<"���չʾ\n";
			AL_BFS_BianHao(ALG,start,1,arr);//MatGraoh��DFS ,count=1����ֱ�Ӵ�ֵ1 
			for(int i=0;i<ALG->numVNode;i++)
				cout<<ALG->adjlist[i].Data<<":"<<arr[i]<<" ";
			cout<<endl;
			break;
			
		case 7:
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			MatToList(MatG,ALG);
			cout<<endl;
			break;
		case 8:
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			ListToMat(MatG,ALG);
			cout<<endl;
			break;
		case 9:
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			cout<<"��������ĸ��±꿪ʼ����:";
			cin>>start;
			AL_DFS_FeiDiGui(ALG,start);
			cout<<endl;
			break;
		case 10:
			memset(visited,0,sizeof(visited));//��ʼ��visited 
			cout<<"��������ĸ��±꿪ʼ����:";
			cin>>start;
			Mat_DFS_FeiDiGui(MatG,start);
			cout<<endl;
			break;
			
	}
	
	}
	
} 
