#include<bits/stdc++.h>
#define MaxVerNum 100 //���������Ŀֵ
#define INF 0x3f3f3f3f//��Ϊ���ֵ
using namespace std;
//ͼ�����ݽṹ
typedef struct Graph
{
	char VNode[MaxVerNum];//�����
	int ENode[MaxVerNum][MaxVerNum];//����
	int numVNode, numARC;//������������
}Graph;
int D[MaxVerNum];  //��������������·��
int Path[MaxVerNum]; //��¼ǰ��
void InitGraph(Graph &G)
{
	memset(G.VNode, '#', sizeof(G.VNode));//��ʼ�������
									  //��ʼ������
	for (int i = 0; i < MaxVerNum; i++)
		for (int j = 0; j < MaxVerNum; j++)
			G.ENode[i][j] = INF;
	G.numARC = G.numVNode = 0;          //��ʼ��������������
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
	int p1, p2;//v,w�����±�
	p1 = p2 = -1;//��ʼ��
	for (int i = 0; i<G.numVNode; i++)//Ѱ�Ҷ����±�
	{
		if (G.VNode[i] == v)p1 = i;
		if (G.VNode[i] == w)p2 = i;
	}
	if (-1 != p1&&-1 != p2)//���������ͼ���ҵ�
	{
		G.ENode[p1][p2] = weight;//����ͼ�ڽӾ��󲻶Գ�
		G.numARC++;
		return true;
	}
	return false;
}
void Bellman_Ford(Graph G, int v)
{
	//��ʼ��
	int n = G.numVNode;//nΪͼ�Ķ������
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
		cout << "�и�Ȧ����" << endl;
		exit(0);
	}
	for(int i=0;i<n;i++)
	{
		cout<<"����"<<G.VNode[i]<<" ";
		cout<<"D["<<i<<"]"<<"="<<D[i]<<" ";
		cout<<"Path["<<i<<"]="<<Path[i];
		cout<<endl;
	}

}
void CreateGraph(Graph &G) //����ߺͶ��㽨���ڽӾ��� 
{
	FILE *p;
	assert((p=fopen("MatGraph.txt","r"))!=NULL);
	int n;
	fscanf(p,"�������=%d;",&n);
	for(int i=0;i<n;i++)
	{
		char V;
		fscanf(p,"%c;",&V);
		if (InsertNode(G, V)) continue;//�����
		else {
			cout << "�������" << endl; break;
		}
	}
	int m;
	char flag;
	fscanf(p,"�߸���=%d;",&m);
	for(int i=0;i<m;i++)
	{
		char V1,V2;
		int weight;
		fscanf(p,"%c,%c,%d;",&V1,&V2,&weight);
			if(InsertENode(G,V1,V2,weight))
                continue;
	}
	fclose(p);
	cout << "ͼ�Ķ��㼰�ڽӾ���" << endl;
	for (int i = 0; i < G.numVNode; i++)
	{
		cout << G.VNode[i] << " ";
	}
	cout << endl;
		for (int i = 0; i < G.numVNode; i++)
	{
		for (int j = 0; j < G.numVNode; j++)
		{
			if (G.ENode[i][j] == INF)cout << "�� ";
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
