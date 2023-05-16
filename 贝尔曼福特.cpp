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
void ShowMatGraph(MatGraph G);

void InitMatGraph(MatGraph &G)//��ʼ��Mat 
{
	memset(G.VNode,'#',sizeof(G.VNode));//ȫ����ʼ��# 
	memset(G.ENode,-1,sizeof(G.ENode));
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
	char flag;
	fscanf(p,"�߸���=%d;",&m);
	for(int i=0;i<m;i++)
	{
		char V1,V2;
		int weight;
		fscanf(p,"%c,%c,%d;",&V1,&V2,&flag,&weight);
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
				if(G.ENode[i][j]!=-1)
					cout<<G.ENode[i][j]<<" ";
				else
					cout<<"oo ";
			 } 
		cout<<endl;
	}
}
//���·�� - Bellman_Ford�㷨  ������ͼG��Դ��v ���ã����㲻����Ȧͼ�����·�� �����Ƿ���Ȧ
bool Bellman_Ford(MatGraph G, int v)
{
	//��ʼ��
	int n = G.numVNode;//nΪͼ�Ķ������
	for (int i = 0; i < n; i++)
	{
		D[i] = G.ENode[v][i];
		if (D[i] < INF)
			Pr[i] = v; //v��i���ӣ�vΪǰ��
		else Pr[i] = -1;
	}
	D[v] = 0;
	//��ʼ����������ʼ˫��ѭ��
		for(int j=0;j<G.numVNode-1;j++) //jΪԴ��
			for(int k=0;k<G.numVNode-1;k++) //kΪ�յ�
				if (D[k] > D[j] + G.ENode[j][k])
				{
					D[k] = D[j] + G.ENode[j][k];
					Pr[k] = j;
				}
	//�ж��Ƿ��и�Ȧ
	bool flag = true;
	for (int j = 0; j<G.numVNode - 1; j++) //jΪԴ��
		for (int k = 0; k<G.numVNode - 1; k++) //kΪ�յ�
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
}//�ݹ�ȥ��ǰһ����� 
void Shortest_Bellman_Ford(MatGraph &G)
{
	
	int v = -1;
	cin>>v;
	int flag = Bellman_Ford(G,v);
		cout << "Ŀ���" << "\t" << "���·��ֵ" << "\t" << "���·��" << endl;
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
