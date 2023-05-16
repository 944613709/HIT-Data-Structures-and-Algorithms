#include<bits/stdc++.h>
void NLR_Creat(Node*&t)//������ǰ������,ABD##EG###C#FH##I##���������� 
{
	cin>>value;
	if(value!='#')
	{
		t = new Node;
		t->value=value;
		NLR_Creat(t->left);
		NLR_Creat(t->right);
	}
}
int BTDepth(BTNode* T)
{
	if(!T)
		return 0;
	else
	{
		return max(BTDepth(T->left),BTDepth(T->Right))+1;
	}
 } 
int leaf(BTNode *T)
{
	if(T==NULL)
		return 0;
	if(T!=NULL&&!T->left&&!T->Right)
		return 1;
	else
		return leaf(T->left)+leaf(T->Right);
}
int BT_JieDian_num(BTNode* T)
{
	if(T==NULL)
		return 0;
	else
		return 1+BT_JieDian_num(T->left)+BT_JieDian_num(T->Right);
}
int Degree1(BTNode* T)
{
	if(T==NULL)
		return 0;
	else if((!T->left&&T->Right)||(T->left&&!T->Right))
		return 1+Degree1(T->Left)+Degree1(T->Right);
	else
		return 0+Degree1(T->Left)+Degree1(T->Right);
}
int Degree2(BTNode* T)
{
	if(T==NULL)
		return 0;
	else if((!T->left&&T->Right)||(T->left&&!T->Right)||(!T->left&&!T->Right))
		return 0+Degree1(T->Left)+Degree1(T->Right);
	else
		return 1+Degree1(T->Left)+Degree1(T->Right);
}
void Change(BTNode* T)
{//��������Ϊһ���µ��������е����Ҷ��ӽ��� 
	BTNode* temp;
	if(T==NULL)
		return;
	if(T!=NULL)
	{
		change(T->Left);
		change(T->Right);
		temp = T->Left;
		T->Left = T->Right;
		T->Right = temp;
	 } 
}
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SeqList;
int Find(List L,ElemType x)
{
	for(int i=0;i<L.length;i++)
	{
		if(L.data[i] == x)
		{
			return i;
		}
	}
	return NULL;
}
int Bsearch(int R[],int low,int high,int key)
{
	int mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(R[mid] == key)
			return mid;
		else
		{
			if(R[mid]>key)
			{
				high = mid-1;
			}
			if(R[mid]<key)
				low = mid + 1;
		}
	}
	return NULL;
}

int Bsearch(int R[],int low,int high,int key)
{
	if(low>high)
		return NULL;
	mid = (low+high)/2;
	if(R[mid]>key)
	{
		Bsearch(R,low,mid-1,key);
	}
	if(R[mid]<key)
		Bsearch(R,mid+1,high,key);
}
BSTNode* SearchBST(BST* T,int key)
{
	BSTNode* temp =T;
	while(temp!=NULL)
	{
		if(key == temp->Data)
			return temp;
		if(key>temp->Data)
			temp=temp->Right;
		if(key<temp->Data)
			temp=temp->Left;
	}
}
BSTNode* SearchBST(BSTNode* T,int key)
{
	if(T==NULL)
		return NULL;
	if(key==T->Data)
		return NULL;
	else
		{
			if(key<T->Data)
				SearchBST(T->Left,key);
			else
				SearchBST(T->Right,key);
		}
}
//
typedef struct
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}SeQueue;//ѭ������ 
void SeQueueIn(SeQueue Q,ElemType x)
{
	if((Q.rear+1)%MAXSIZE == Q.front)
		{
			cout<<"FULL";
			exit(0);
		}
	Q.rear = (Q.rear+1)%MAXSIZE;
	Q.data[rear] = x;
}
void SeQueueOut(SeQueue Q,ElemType x)
{
	if(Q.front == Q.rear)
		cout<<"Empty";
	else
		{
			Q.front = (Q.front+1)%MAXSIZE;
			return Q.data[Q.front];
		}
}
//!!!!!!!!!!!
bool FindSum(int arr[],int target)
{
	int i = 0;
	int j = arr.length-1;
	while(i<j)
	{
		if(arr[i]+arr[j] == target)
		{
			cout<<i<<j;
			return	true;
		}
		if(arr[i]+arr[j]<target)
			i++;
		else
			j--;
	}
	return false;
}
typedef struct Node
{
	datatype data;
	struct node* firstchild;
	struct node* rightsib;
}Node;
int LeavesCounter(Node* F)
{
	if(F==NULL)
		return 0;
	if(F->firstchild==NULL)
		return 1+LeavesCounter(F->firstchild)+LeavesCounter(F->rightsib);
	else
		return 0+LeavesCounter(F->firstchild)+LeavesCounter(F->rightsib);
}


void InOder2(BTNode* root)
{
	if(root == null)
		return;
	BTNode* p = root;
	stack<BTNode*> s;
	while(!s.empty()||p)
	{
		if(p)
		{
			s.push(p);
			p = p->lchild;
		}
		else if(!p)
		{
			p = s.top();
			s.pop();
			cout<<p->Data;
			p = p ->rchild;
		}
	}
}

void PostOrder_2(BTreeNode* root)
{
	if(!root)
		return;
	BTreeNode* p  = root;
	BTreeNode* Cur = NULL;
	stack<BTreeNode*>s;
	while(!s.empty()||p)
	{
		if(p)
		{
			s.push(p);
			p=p->Left;
		}
		else if(!p)
		{
			p = s.top();
			if(p->Right&&Cur!=p->Right)
				p=p->Right;
			else
				{
					s.pop();
					cout<<p->Value;
					Cur = p;
					p=NULL;
				}
		}
	}
}
////////!!!!!!!!!!!!
void Floyd(Graph G,int D[][])
{//��ҽԺ 
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			D[i][j] = G.edge[i][j];
			Path[i][j] = -1;
		}
	for(int k=0;k<G.verNum;k++)
		for(int i=0;i<verNum;i++)
			for(int j=0;j<verNum;j++)
				if(D[i][j]>D[i][k]+D[k][j])
					{
						D[i][j] = D[i][k]+D[k][j];
						Path[i][j] = k;
					}
					
	int Pian[j];
	int min=MAXINT;
	int min_j;
	memset(Pian,MININT,sizeof(Pian));
	for(int j=0;j<verNum;j++)
	{
		for(int i=0;i<verNum;i++)
			if(D[i][j]>Pian[j])
			{
				Pian[j] = D[i][j];
				if(Pian[j]<min)
				{
					min = Pian[j];
					min_j = j;
				} 
			}
	}
	cout<<"���ĵ�"<<min_j;
}
 ///////////!!!!!!!!!!
void FindMin(int low,int high,int A[])
{
	int mid= (low+high)/2;
	if(A[mid]<A[mid+1]&&A[mid-1]<A[mid])
	{
		FindMin(low,mid-1,A);
	}
	if(A[mid]>A[mid+1]&&A[mid-1]>A[mid])
	{
		FindMin(mid+1,high,A);
	}
	else
	{
		cout<<A[mid];
		return;
	}
}
//!!!!!!!!!!!!!!!!!����
int TopSort(Graph* G)
{
	int i,j,cnt=0;
	int stack[MAXSIZE];
	int top=-1;
	ArcNode *p;
	for(i=0;i<G->verNum;i++)
		if(G->adjlist[i].indegree == 0)
			stack[++top] = i;
	while(top!=-1)
	{
		i = stack[top--];
		++n;
		//cout<<G.adjlist[i].Data;
		p = G.adjlist[i].Firstarc;
		while(p!=NULL)
		{
			j = p->adjvex;
			G->adjlist[j].Indegree--;
			if(G->adjlist[j].Indegree==0)
				{
					stack[++top] = j;
				}
			p = p->nextarc;
		}
	}	
	if(cnt == G->verNum)
		return 1;//��Ȧ
	else
		return 0 //ûȦ 
 } 
//1111111111�������� �ж���û�л� 
int indegree[MAXNUM];
bool visited[MAXNUM];
void InitIndegree(Graph G)
{
	memset(indegree,0,sizeof(indegree));
	for(int i=0;i<G.verNum;i++)
		for(int j=0;j<G.verNum;j++)
		{
			if(i!=j&&G.Edge[i][j]!=INF)
				indegeree[j]++;
		}
}
void Initvisited()
{
	memset(visited,false,sizeof(visited))
}
bool TuoPu(Graph G)
{
	InitIndegree(G);
	Initvisited();
	stack<int>s;
	int cnt = 0;//��¼�Ѿ�����ĸ���
	for(int i=0;i<G.verNum;i++)
		if(indegree[i]==0)
		{
			s.push(i);
			visited[i] = true;
		 } //����Ѿ���ջ 
	while(!s.empty())
	{
		int v = s.top();
		s.pop();
		cnt++;
		for(int i=0;i<G.verNum;i++)
		{
			if(i!=v&&G.Edge[v][i]!=INF&&visited[i] == false)
			{
				indegree[i]--;
				if(indegree[i] == 0)
				{
					s.push(i);
					visited[i] = true;
				}
			}
		}
	}
	if(cnt!=G.verNum)
		return false//��Ȧ 
	else
		return true //˳�����������û��Ȧ 
}
//
//!!!!!!!!!DFS�ж�����ͼ��·������� 
int color[9999];
stack<char> S;
bool dfs(int u,MatGraph G)
{
	color[u]=1;//���ڷ��� 
	for(int v=0;v<G.numVNode;v++)
	{
		if(G.ENode[u][v]!=INF)
		{
			if(color[v] == 1)//��Ȼ���������ڷ��ʵ� 
			{//�Ǿ�����Ȧ���߻ص�ĳ�����ΪȦ�� 
				S.push(G.VNode[v]); 
				return false;
			}
			else if(color[v] == 0)//��δ����
			{
				int re;
				re = dfs(v,G);
				if(re == false)
				{
					S.push(G.VNode[v]);
					return false;
				}	
			 } 
			color[u] = 2;
			return true;
		}		
	}
}
void Quan(MatGraph G)
{
	memset(color,0,sizeof(color));//��visited�����зֱ���0��1��2����ʾ����ô�����ڻ���������Զ���Ϊ���ڱ��������У�����ĳ�������һ����ָ��״̬1�Ķ��㣬��ʱ�ʹ��ڻ���״̬2�������Ϊ���������ϵ����е�����ڵ㶼�Ѿ������ꡣ
	if(!dfs(0,G))//0��δ���ʣ�1���ڷ��ʣ�2����������dfsȫ�����ʹ� 
		{cout<<"��Ȧ";
		while(!S.empty())
			{
				char a = S.top();
				S.pop();
				cout<<a<<"->";
			}		
		}	 
}
//!!!!!!!!!!

//������ż����Ԫ��
void NewSequ(int A[],int n)
{
	int i=0;
	int j=1;
	int temp;
	while(i<n&&j<n)
	{
		while(A[i]%2==0&&i<n)
		i+=2;
		while(A[j]%2!=0^&&j<n)
		j+= 2;
		if(i<n&&j<n)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] =temp;
		}
	}
 } 
 //!!!!!!!!!!!!!!!
 
 typedef struct Node
 {
 	datatype data;
 	struct node* lchild;
 	struct node* rchild;
 }*BTree;//*BTree��ĿҪ�󿴺ã���
 BTree FirstNode(BTree BT) //��ĿҪ��
 {
 	BTree p = BT;
 	while(1  )
 	{
 		while(p->lchild)
 			p=p->lchild;
 		if(p->rchild)
 			p=p->rchild;
 		if(!p->rchild&&!p->lchild)
 			break;
	 }
 	
  } 
   void FirstNode(BTreeNode* BT) //��ĿҪ��
 {
 	BTreeNode* p = BT;
 	while(1)
 	{
 		while((p->Left))
 		{
 			p=p->Left;
		 }
 			
 		if((p->Right))
 			p=p->Right;
 		if(!(p->Right)&&!(p->Left))
 			break;
	 }
 	cout<<p->Value;
  } 
//!!!!!!!!!! 


//!!!BST�Ĳ��ҺͲ���
Position BSTSearch2(int key,BST T)
{
	if(T->data == key)
		return T;
	if(T->data <key)
		return BSTSearch2(key,T->rchild);
	if(T->data > key)
		return BSTSearch2(key,T);
}
Position BSTSearch2(int target ,BinTree T)
{
	while(T&&T->data!=target)
	{
		if(T->data >target)
			T=T->lchild;
		if(T->data <target)
			T=T->rchild;
	}
	if(T == NULL)
		return NULL;
	if(T != NULL)
		return T;
}
Position BST_FindMin1(BST T)
{
	if(!T)
		return NULL;
	if(!T->lchild)
		return T;
	else
		return BST_FindMin(T->Lchild);
}
Position BST_FindMin2(BST T)
{
	while(T->lchild)
	{
		T=T->lchild;
	}
	return T;
}
////
bool BST_Insert(BST &T,int data)//����Ҫ& 
{
	if(T->data <data)
		return BST_Insert(T->rchild,data);
	if(T->data > data)
		return BST_Insert(T->lchild,data);
	if(T->data == data)
		{
			cout<<"ERROR";
			exit(0);
		}
	if(!T)
	{//����ֱ��&T �Ϳ��� 
		T = new BSTNode;
		T->data =data;
		T->lchid =NULL;
		T->rchild = NULL;
	}
}
int Find_k_min(int A[],int B[],int k)
{
	int i=0;
	int j=0;
	int flag=-1;//0����i 
	while((i+j)!=k)
	{
		if(A[i]<B[j])
		{
			i++;
			flag=0;
		}
			
		else
		{
			flag=1;
			j++;
		}
	}
	if(flag == 1)
		return B[j];
	else
		return A[i];
}
//
//!!!!!!!!!!!!!
void Dijkstra(Graph G,int v_start)
{
	for(int i=0;i<G.vexNum;i++)
	{
		S[i] = false;
		D[i] = G.Edge[v_start][i];//����Dist[i]Ҳ�����ж�INF��������INFҲҪ���� 
		if(D[i]<INF)
			Path[i] = v_start;
		else	
			Path[i]=-1;
	}
	S[v_start]=true;//����S����
	D[v_start]=0
	//��ʼ������
	//�ؼ�����
	for(int i=0;i<G.vexNUm-1;i++)//���ΰ�ʣ��n-1��������
	{
		int min =INF;
		for(int j=0;j<G.vexNum;j++)
			if(!S[j]&&D[j]<min)
				{
					u=j;
					min = D[j];
				}
		
		S[u]=true;//1.����;/1.Ѱ�ҵ�ǰͨ��·����С�Ķ���
		
		//2.����֮�󿴿���Ϊ�²���Ķ������D
		for(int j=0;j<G.vexNum;j++)
		{
			if(S[j]==false&&D[u]+G.Edge[u][j]<D[j])
				{
					D[j]=D[u]+G.Edge[u][j];
					Path[j] = u;
				}
		}
	}
}


void Dijkstra(Graph G,int v0)
{
	int n = G.vernum;
	bool S[n];
	memset(S,false,sizeof(S));
	int D[n];
	for(int i=0;i<n;i++)
	{
		D[i] = G.Edge[v0][i];
		if(D[i]!=INF)
			Path[i]=vo;
		else
			Path[i]=-1;
	}
	S[v0]=true;
	D[v0]=0;
	for(int i=0;i<n-1;i++)
	{
		int min = INF;
		for(int j = 0;j<n;j++)
		{
			if(!S[j]&&D[j]<min)
				{
					min_j=j;
					min = D[j];
				}
		}
		S[min_j] =true;
		for(int k = 0;k<n;k++)
		{
			if(!S[k]&&D[min_j]+G.Edge[min_j][k]<D[k])
			{
				D[k] =D[min_j]+G.Edge[min_j][k];
				Path[k] =min_j;
			}
		}
	}
}���� 
//
void Dijkstra(Graph C,int D,)
{
	for(int i=0;i<n;i++)
	{
		D[i] = C[0][i];
		if(C[0][i]!=INF)
			Path[i] = 0;
		else
			Path =-1;
	}
	for(int i=0;i<n-1;i++)
	{
		int min_j = MINCOST(D,S);
		S[min_j] =  true;
		for(int j=0;j<n;j++)
		{
			if(!S[j]&&D[min_j]+C[min_j][j]<D[min_j])
				D[min_j]=D[min_j]+C[min_j][j];
				Path[j] = min_j;
		}
	}
}
//!!!!!!!!
void Prim(Graph G,int v0)
{
	int lowcost[MAXSIZE];
	bool vset[MAXSIZE];//���Ǵ�S����
	int v=v0;
	for(int i=0;i<G.verNum;i++)
	{
		lowcost[i] = G.Edge[v0][i];//������Lowcost����G.Edge[vo][i]==INFҲҪ����INF�������������� 
		vset[i]= false;//��δ����S
	}
	vset[v0]=true;
	sum=0;//Ȩֵ��
	for(int i=0;i<G.verNum-1;i++)//��ʣ��n-1������prim����S
	{//ִ�� n-1��
		int min =INF;
		//1.ѡ��һ������
		for(j=0;j<G.verNum;j++)
			{
				if(vset[j]==false&&lowcost[j]<min)
				{
					min =lowcost[j];
					k=j;
				}
			}
		vset[k]=true;
		sum+=min;
		v= k;
		for(j=0;j<G.verNum;j++)//2.����lowcost
		{// ��ʱ����lowcost�͸���Dist��һ��������
			if(vset[j]==false&&G.Edge[v][j]<lowcost[j])
				lowcost[j] = G.Edge[v][j];
		}
	}
}


void Prim(Graph G,int v0)
{
	int lowcost[MAXSIZE];
	bool S[MAXSIZE];
	int n = G.vernum;
	for(int i=0;i<n;i++)
	{
		lowcost[i] = G.Edge[v0][i];
	}
	memset(S,false,sizeof(S));
	int sum=0;
	//
	S[v0]=true;
	for(itn i=0;i<n-1;i++)
	{
		int min =INF;
		int min_j;
		for(int j=0;j<n;j++)
		{
			if(S[j]==false&&lowcost[j]<min)
			{
				min = lowcost[j];
				min_j = j;
			}
		}
		//
		S[min_j]=true;
		sum += min;
		//
		for(int j=0;j<n;j++)
		{
			if(S[j]==false&&G.Edge[min_j][j]<lowcost[j])
				lowcost[j] = G.Edge[min_j][j]
		}
	}
}
//
typedef struct
{
	int begin;
	int end;
	int weight;
}Road;
Road road[MASSIZE];
void Union(int i,int j)
{
	parent[i] = [j];
}
int Find(int i)
{
	while(parent[i]!=-1)
		i = parent[i];
	return i;
}
void kruskal(Graph G,Road road)
{
	int bnf;
	int edf;
	int  parent[MASZIE];//�����������ݽṹ		
	Sort(road);//�Ա�Ȩֵ����;
	for(int i =1;i<n;i++)
		Initial(i,parent)//��ʼ������	parents����ÿһ������������ͨ����
	for(	int i=0;i<G.numEdge;i++)
	{
		bnf = Find(road[i].begin,parents);
		edf =Find(road[i],end,parents);
		if(bnf!=edf)//�����������ͨ����������ͬһ��ͨ����
		{//����Ժϲ�
			Union(bnf,edf,parents)
		}
	}
}
int getroot(int a)
{
	while(a!=-1)
		a = parent[a];
	int root =a;
	return root;
}
void kruskal(Graph G,Road road)
{
	int bnf;
	int edf;
	for(int i=0;i<G.numEdge;i++)
		parent[i]=-1;//��ʼ�����鼯
	Sort(road);
	for(int i=0;i<G.numEdge-1;i++)
	{//road����edge����ͷ��β��
		bnf = getroot(road[i].begin);
		edf = getroot(road[i].end);
		if(bnf!=edf)
			{
				parent[bnf] = edf//����;
			}
	}
}//////
//

//˳��������
void SeqInvert(SeqList a)
{
	int n=a.length;
	for(int i=0;i<=(n-1)/2;i++)
	{
		t = a.data[i];
		a.data[i] = a.data[n-1-i];
		a.data[n-1-i] = t;
	}
}
void SeQueueIn(SeQueue Q,Elemtype x)
{
	if((Q.rear+1)%MAXSIZE == front)
		exit(0);
	Q.rear = (Q.rear+1)%MAXSIZE;
	Q.data[rear] = x;
}
ElemType SeQueueOut(SeQueue Q)
{
	if(Q.front==Q.rear)
		exit(0);
	Q.front = (Q.front + 1)%MAXSIZE;//���ӣ���frontӦ��ָ�����Ԫ�ص�ǰһ����λ
	x=Q.data[Q.front];//�������������֮ǰ�Ķ���
	return x;
}
//
void LVR(BTreeNode *T)
{
	if(T==NULL)
	{
		return;
	}
	else
	{
		LVR(T->Left);
		cout<<T->Value;
		LVR(T->Right);
	}
}
//
void NLR(BT* T)
{
	if(!T)
		return
	else
	{
		visit(T);
		NLR(T->lchild);
		NLR(T->Rchild);
	}
}

//

void DFS1(ADjGraph* G,int i)
{
	EdgeNode * p;
	cout<<G.vexlist[i].vertex;
	visited[i]=True;
	dnf[i] = count++;
	p = G->vexlist[i].firstedge;
	while(p)
	{//1.���� 2.Ѱ�Һ�ʾ����
		if(visited[p->adjvex])
			p=p->next;
		if(!visited[p->adjvex])
			DFS1(G.p->adjvex);
	}
}
void DFS1p(Graph G,int i)
{
	ENode* P;
	p = G>adjlist[i].firstarc;
	cout<<G.adjlist[i].data;
	visited(i)=true;
	while(p)
	{
		int j  = p->adjvex;
		if(visited[j])
			p=p->nextarc;
		else
		{
			dfs(G,j);
		}
	}
}
void DFS(AdjGraph* G,int i)
{
	Stack S;
	InitStack(S);
	visited[i] = true;
	cout<<G->vexlist[i].data;
	EdgeNode* p=G��vexlist[i].firstedge;
	Push(S,p);
		//������Ԫ�أ���Ҫ��ջ
	//ͼ��DFS��Ԫ��Ҫ����ջ��ѭ��whlie
	while(!Isempty(S))
	{	//����ջ��Ķ��Ǳ� 
		p = Pop(S);
		while(p)
		{
			if(visited[p->adjvex])
				p=p->next;
			else if(!visited[p->adjvex])
			{
				cout<<G->vexlist[p->adjvex].vertex;
				visited[p->adjvex]=true;
				Push(S,p);
				p = G.adjlist[p->adjvex].firstarc;
			}
		}
	}
}
void dfs(Graph G,int i)
{
	visited[i]=true;
	stack<ENode*>s;
	s.push(p);
	cout<<G->vexlist[i].data;
	p = G.adjlist[i].firstarc;
	while(!s.empty())
	{
		p=s.top();
		s.pop();
		whlie(p)
		{
			if(visited[p->adjvex])
				p=p->next;
			if(!visited[p->adjvex])
			{
				cout<<G->ajlist[p->adjvex].data;
				visited[p->adjvex]=true;
				s.push(p);
				p = G.adjlist[p->adjvex].firstarc;
			}
		}
	}
}
void BFS1 (AdjGraph *G, int k)//��VkΪͷ���б�������ʵ����һ��ͼ�ð�ÿ�����㶼Ҫ��������ֹ�����ͨ����
{   int i; EdgeNode *p��visited[max]; 
    Queue Q; 
    MakeNull(Q);
   cout << G��vexlist[ k ] .vertex; 
   visited[ k ] = True;
   EnQueue (k, Q); //������
   while ( ! Empty (Q) ) {   //�ӿ���������
       i=DeQueue(Q); //vi����
       p =G��vexlist[ i ].firstedge; //ȡvi�ı߱�ͷָ��
        while ( p )//��vi���ڽӵ� vj
        { 
          int j= p��adjvex
         if ( !visited[j]) { //��vjδ���ʹ�
            cout << G��vexlist[j].vertex; //����vj
          visited[j]=True; //��vj�����ʹ����
          EnQueue ( j, Q ); //���ʹ���vj���
        }
       p = p��next; //��vi����һ���ڽӵ�
} / / �ظ���� vi�������ڽӶ���
} //���ѭ�����ж��пշ�
}//��vkΪ������ʱ�����ڽӱ��ʾ��ͼG�����ȹ�����


////


typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node,*Link;
Link getMiddleNode(Link head)
{
	if(head == NULL)
		return;
	Link p1 =head;//��ָ��
	Link p2 =head;//��ָ��
	while(p1&&p1->next)
	{
		p1 = p1->next->next;
		p2 = p2->next;
	}
	return p2;
}

//

typedef struct BiNode
{
	Elementtype data;
	struct BiNode *lchild,*rchild;
}BiNode,*Bintree;
int minDepth(TreeNode* root) {
	if (!root)
		return 0;
	int leftHeigh = minDepth(root->left);
	int rightHeigh = minDepth(root->right);
	if (leftHeigh == 0 || rightHeigh == 0) {
		//��ĳ���ڵ�����ӽڵ�Ϊ��ʱ������������С����У�ȡ�Һ��ӽڵ����ȣ���֮��Ȼ����Ϊ����ȡ0!!!!!!!!!!!!!!!!!!!!
		return max(leftHeigh, rightHeigh) + 1;
		}
	else {
		return min(leftHeigh, rightHeigh) + 1;	//�ⲽ����������һ����ֻ����max������min
	}
}

int MaxDepth(Bintree)
{
	if(!T)
		return 0;
	else
	{	
	//	if(!T->lchild&&!T->rchild)
	//		return 1;
	//	else
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
}
void Max_Min(Bintree T)
{
	max =maxDepth(T);
	min =minDepth(T);
}
//

////////
typedef struct Stack
{
	int top;
	dataType data[MAXSIZE];//0->(MAXSIZE-1)
}Stack;
void MakeNULL(Stack &S)
{
	S.top = maxlength;
}
void push(elemtype x,Stack &S)
{
	if(S.top == 0)
		cout<<"FULL";
		exit(0);
	else	
		S.data[--top] = x;
}
void Pop(Stack & S)
{
	if(empty(S))
		cout<<"empty";
	else
		S.top++;
}
void Top(Stack&s)
	{
		return S.data[s.top];
	}
//////!!!!!!!!
struct Node
{
	int data;
	Node* next;
};
typedef Node* STACK;
STACK MakeNull()
{
	STACK S = new Node;
	S->next=NULL;	
	return S;
}
void Push(int data,STACK S)
{//    TOuChaFa
	STACK stk = new Node;
	stk->data=data;
	stk->next=S->next;
	S->next=stk;
}
void Pop(STACK S)
{
	STACK stk;
	if(S->next)
	{
		stk=S->next;
		S->next=stk->next;
		delete stk;
	}
}
/////!!!!!!
//////////!!!!!!!!!
typedef struct stack
{
	int top;
	ElemType data[MAXSIZE];
}stk;
typedef struct stack
{
	int top;
	ElemType data[MAXSIZE];
}max_stk;
void push(ElemType v)
{
	stk.data[++stk.top] =v;
	if(maxstk.top ==0??????)//���maxΪ�յĻ�,�Ȳ��˴�С������ֱ�Ӽ���
		max_stk.data[++max_stk.top] = v;
	else if(maxstk.top !=0)
	{//����ȵ�ǰջ��Ԫ��Сѹ�룬����ȵ�ǰջ��Ԫ�ش������ѹ��ջ��Ԫ��
		ElemType temp = max_stk.data[max_stk.top]
		if(v >= temp)
			max_stk.data[++max_stk.top] = v;//ÿһ��Ԫ�ض�Ҫѹ��ȥ������ÿ��״̬ʱ���ջӦ�õõ����ֵ�Ƕ��� 
		else
			max_stk.data[++max_stk.top] = temp;
	}
}
void pop(ElemType v)
{
	if(stk.top!=-1)
		return stk.data[stk.top--];
	if(max_stk.top!=-1)
		max_stk.top--;
}
ElemType getMax()
{
	return max_stk.data[max_stk.top];
}
///!!!!!!!!  
 void BubbleSort(int* arr)
{
	int len = sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<len-1;i++)//i<len-1!!!!
		for(int j=0;j<len-1-i;j++)
			{
				if(arr[j]>arr[j+1])
				{
					int temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
			}
}
void QSort(int* arr,int low,int high)
{
	if(low<high)
	{
		int pivotpos = Partition(arr,low,high);
		QSort(arr,low,pivotpos-1);
		QSort(arr,pivotpos+1,high);
	}
}
int Partition(int* A,int low,int high)
{
	int pivot = A[low];
	while(low<high)
	{
		while(low<high&&A[high]>=pivot)//���ƶ��Ҳ��j , ֻ�������С��
			high--;
		A[low] = A[high];
		while(low<high&&A[low]<=pivot)
			low--;
		A[high]=A[low];
	}
	A[low] = pivot;
	return low;
}
void swap(int*a,int*b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}
void heapSort(int R[],int n)
{
	int i;
	int temp;
	for(i=n/2;i>=1;i--)//���һ����֧��㿪ʼ�������β� 
	{
		Sift(R,i,n);//��鲢����(��������·�) ������д��Χ��i->n 
	 } 
	for(i=n;i>=2;i--)
	{
		temp = R[1];
		R[1]=i;
		R[i]=temp;
		Sift(R,1,i-1);//��鲢������1->i-1 
	}
}
void Sift(int R[],int low,int high)
{
	int i=low;
	int j=2*i;
	int temp = R[i];
	while(j<=high)
	{
		if(j<high&&R[j]<R[j+1])
			j++;//����� 
		if(temp<R[j])
		{
			R[i]=R[j];
			R[j]=temp;
			i=j;
			j=2*i;
			}
		else
			break;
	}
}
void InsertSort(int* A,int n)
{
	int temp;
	for(int i = 1;i<n;i++)
	{
		temp = A[i];
		int j = i-1;
		while(j>0&&temp<A[j])
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1] = temp;
	}
}
void MergeSort(int A[],int low.int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		MergeSort(A,low,mid);
		MergeSort(A,mid+1,high);
		Merge(A,low,mid,high);//�鲢 
	}
}
void Merge(int A[],int low,int mid,int high)
{
	int B[999];
	int p1=low;
	int p2=mid+1;
	int p=0;
	while(p1<=mid&&p2<=high)
	{
		if(A[p1]<=A[p2])
		{
			B[p++]=A[p1++];
		}
		else
		{
			B[p++]=A[p2++];
		}
	}
	while(p1<=mid)
		B[p++]=A[p1++];
	while(p2<=high)
		B[p++]=A[p2++];
	for(int i=0;i<n;i++)
		A[low+i]=B[i];
}
//

void LevelOrder(BTreeNode* T)
{
	queue<BTreeNode*>q;
	q.push(T);
	BTreeNode* temp;
	while(!q.empty())
	{
		temp =q.front();
		q.pop();
		cout<<T->data;
		if(temp->lchild)
			q.push(temp->lchild);
		if(temp->rhcild)
			q.push(temp->rchild);
	}
}
//6

void InsertSort(int A[],int n)
{//��A[2]��ʼ��ǰ���룬A[1]Ĭ���Ѿ����� 
	for(int i=2;i<=n;i++)
	{//�Ե�a[i]ȥ���� 
		if(A[i]<A[i-1])//a[i]��ǰһ��С����ֱ�Ӳ���β�� 
		{
			A[0] = A[i]; //�ڱ�ֱ�ӵ���Ҫ��������ֵ 
			for(int j=i-1;A[j]>A[0];j--)
			{
				A[j+1]	=	A[j];//���� 
			}
				A[j+1] = A[0];
			}
			//���ֱ��С��ǰ���Ͳ�Ҫ����for�� 
		//����պ��������ý���if��for 
	}
}
void InsertSort()
{
	for(int i =2;i<=n;i++)
	{
		if(A[i]<A[i-1])
		{
			A[0]=A[i];//�����ձ� 
			for(int j=i-1;A[j]>A[0];j--)
				A[j+1] = A[j];//���� 
			A[j+1] = A[0];
		}
	}
}
//

void selectSort()
{
	for(itn i=0;i<n-1;i++)//һ��ѡn-1�� 
	{
		min = i;
		for(int j=i+1;j<n;j++)//��i�Ѿ�ѡ��õ�ѡ���2����С
			if(A[j]<A[min])
				min=j;
		if(min!=i)
			swap(A[i],A[min]);
	}
}

//void XunHuanZuoYi(int k)
{
	Node*  p = head;//��ͷ��� 
	for(int i=1;i<=k;i++)
	{
		p=p->next;
	}
	temp = p->next;
	p->next = NULL;
	while(temp->next)
		temp=temp->next;
	temp->next = head;
}
//
//����Ҷ���·�� 
int path[MAXSZIE]
int top=-1;
int longestpath[MAXSISE]
int deeptest =MININT;
void LongestrootToLeaf(BT* T)
{
	if(!T)
		return;
	if(T)
	{
		path[++top] = T->data;
	}
	if(!T->lchild&&!T->rchild)
	{
		if(top>deeptest)	
			deeptest = top+1;
		for(int i =0 ;i<=top;i++)
			longestpath[i]=path[i];
	}
	LongestrootToLeaf(T->lchild);
	LongestrootToLeaf(T->rchild);
	top--;//������һ��ջ��,
}

int path[MAXSZIE]
int top=-1;
//�Ӹ���Ҷ 
void rootToLeaf(BT* T)
{
	if(!T)
		return;
	if(T)
	{
		path[++top] = T->data;
	}
	if(!T->lchild&&!T->rchild)
	{
		for(int i =0 ;i<=top;i++)
			cout<<path[i];//����Ҷ��
		for(int i=top;i<=0;i++)
			cout<<path[i]//Ҷ�ӵ���
	}
	rootToLeaf(T->lchild);
	rootToLeaf(T->rchild);
	top--;//������һ��ջ��
}
void deleteKNumbers(string &str,int k)
{//һ��nλ������ȥ�����е�kλ��������ȥ��ʹ�����������Ǹ���n-k��λ������С��
	for(int i=0;i<k;i++)
	{//ɾ��K�� 
		for(int j=0;j<n;j++)
		{
			if(str[j]>str[j+1])
				{str_erase(j);//ɾ��A[j]
				break;
				}
		}
		//һֱû�ҵ�ɾ����
			str.erase(str.length);
			//ɾ������
	}
}

 //!!!!!
void dfs(Graph G,int i,int j)
{
	visited[i]=true;
	//cout<<G.adjlist[k].data;
	p = G.adjlist[i].firstarc;
		whlie(p)
		{
			if(visited[p->adjvex])
				p=p->next;
			if(!visited[p->adjvex])
			{
				dfs(G,i,j);
			}
		}
	}
}
bool If_itoj_lianTong(Graph G,int i,int j)
{
	memset(vitited,false,sizeof(visited));
	dfs(G,i);
	if(visited[j])
		return true;
	else
		return false;
}
///!!!!!!! 

void dfs(Graph *G,int i)
{
	Enode* p = G->ajlist[i].firstarc;
	visited[i]=true;
	//cout<<;
	stack<ENode*>s;
	s.push(p);
	while(!s.empty())
	{
		p =s.top();
		s.pop()
		while(p)
		{
			int j = p->adjvex;
			if(visited[j])
				p=p->next;
			else
			{
				//cout<<G->adjlist[j].data;
				visited[j]=true;
				s.push(p);
				p=G->adjlist[j].firstarc;
			}
		}
	}
}
bool LianTong()
{
	memset(visited,false,sizeof(visited));
	dfs(G,0);
	for(int i=0;i<n;i++)
		if(visited[i]==false)
			return false;
	return true;
}//�ж�����ͼ�Ƿ���ͨ 
//
///////
void Post(BT* root)
{
	BT* p = root;
	BT* Cur=NULL;
	if(!root)	
		return;
	stack<BT*>s;
	while(!s.empty()||p)
	{
		if(p)
		{
			s.push(p);
			p=p->lchild;
		}
		else if(!p)
		{ 
			p = s.top();
			if(p->rchild&&Cur!=p->rchild)
				p=p->rchild;
			else
			{
				cout<<p->data;
				s.pop();
				Cur = p;
				p=NULL;
			}
		}
	}
}/////

//��β��ͷ���������Lÿ���ڵ��ֵ
void R_print(LinkList L)
{
	if(L->next != NULL)
		R_print(L);
	if(L!=NULL)
		print(L->data);
}
void R_print(List L)
{
	stack<datatype>s;
	while(L->next)
	{
		s.push(L->data);
		L=L->next;
	}
}
///
void HeadSort(int n,LIST A)
{//��A[1]��A[n]
	for(int i=n/2;i>=1;i--)
		PushDown(A,i,n);
		//���i���յ�n
	for(i=n;i>=2;i--)//����n-1��
	{
		swap(A[1],a[i]);
		PushDown(A,1,i-1);
	}
}
void PushDown(LIST R,int first,int last)
{
	int i=low;
	int j =2*i;
	int temp=R[i];
	while(j<=high)
	{
		if(j<high&&R[j]<R[j+1])
			j=j+1;
		if(R[i]<R[j])
		{
			swap(R[i],R[j]);
			i=j;
			j=2*i;
		}
		else if(R[i]<=R[j])
			break;//!!!!!!!!!
	}
}
/////

void HeapSort(int n,LIST A)
{
	for(int i=n/2;i<=1;i--)
	{
		PushDown(R,i,n);
	}
	for(int i=1;i<=n-1;i--)
	{
		swap
		PushDown(R,1,n-i+1);
	}
}
void PushDown(int R[],int first,int last)
{
	int parent = first;
	int son = parent*2;
	while(parent<=n/2)
	{
		if(R[son]<R[son+1])
			son=son+1;
		if(R[parent]<R[son])
		{
			swap(R,parent,son);
			parent = son;
			son = parent*2;
		}
	}
}
///
///
void selectSort()
{
	for(int i=0;i<n-1;i++)
	{
		min = i;
		for(int j=i+1;j<n;j++)
		{
			if(A[j]<A[min])
				min  = j;
		}
		swap(A[min],A[i]);
	}
}
void InsertSort()
{
	for(int i=2;i<=n;i++)
	{
		A[0] = A[i];
		if(A[i]<A[i-1])
		{
			for(int j =i-1;;j--)
			{
				if(A[j]<=A[i])
					break;
				A[j+1]=A[j];
			}
			A[j+1] = A[i];
		}
		else
			continue;
	}
}
//////

typedef struct Road
{
	int begin;
	int end;
	int weight;
}Road;
Road road[MAXSIZE];
void Krusal()
{
	int b;
	int e;
	Sort(road);
	int parent[MAXSIZE];
		memset(parent,-1,sizeof(parent));
	for(int i=0;i<n-1;i++)
	{
		b=Find(road[i].begin);
		e=Find(roar[i].end);
		if(b!=e)
			Union(b,e);
	}
}
int Find(int i)
{
	while(parent[i]!=-1)
		i=parent[i];
	return i;
}
void Union()
{
	parent[b] = e;
//}
//


//���������������� 
typedef struct HTNODE
{
	double weight;
	int lchild;
	int rchild;
	int parent;
}HTNode;
typedef HTNODE HuffmanT[2n-1];
HuffmanT T;
typedef struct COdeNode
{
	char ch;
	char bits[n+1];
}CodeNode;
typedef HuffmanCode[n];
HuffmanCode H;
void CreatHT(HuffmanT T)
{
	int i,p1,p2;
	initHT(T);
	inputW(T);
	for(int i=n;i<2n-1;i++)
	{//һ��2n-1 - n��
	//��Ҷ�ӽ�����ϲ�����
		SelectMin(T,i-1;&p1,&p2)//��k֮ǰ��
		T[p1].parent=T[p2].parent = i;
		T[i].lchild = p1;
		T[i].rchild = p2;
		T[i].weight = T[p1].weight=T[p2].weight;
	}
}
vodi HuffmanEnCoding(HuffmanT T,HuffmanCode H)
{
	int cp,i;
	char cd[n+1];
	int start;
	cd[n] ='\0';
	for(int i=0;i<n;i++)
	{
		H[i].ch =getchar();
		start = n;
		c = i;
		while((p=T[c].parent)>=1)
		{
			if(c == T[p].lchild)
				cd[--start] = '0';
			else
				cd[--start] = '1';
			c = p;
		}
		strcpy(H[i].bits,&cd[start]);
	}
}
void selectmin(HuffmanT T,int k,int &p1,int &p2)
{
	int min=INF;
	int min_i;
	for(int i=0;i<k;i++)
	{
		if(-1==T[i].parent&&T[i].weight<min)
			{
				min = T[i].weight;
				min_i = i;
			}
	}
	s1=min_i;
	min = INF;
	int min_j;
	for(int i=0;i<k;i++)
	{
		if(-1==T[i].parent&&T[i].weight<min&&i!=s1)
		{
			min = T[i].weight;
			min_j = j;
		}
	}
	s2 = min_j;
}

//void HeBingShunXuBiao()
{//A��������B���򣬰�B�ϲ�����A����
	int m,n,i,j;
	m  = A.length;
	n = A.length;
	k = m+n-1;
	i=m-1;
	j=n-1;
	resize(A,m+n)//��A��չ�����СΪm+n
	while(i>=0&&j>=0)
	{
		if(A.data[i]>B.data[j])
			{
				A.data[k--] = A.data[i--];
			}
		else
			A.data[k--]=B.data[j--];
	}
	while(i>=0)
		A.data[k--] = A.data[i--];
	while(j>=0)
		A.data[k--]=B.data[j--];
}
///ɾ��˳���ָ��ֵ��ʱ�临�Ӷ�Ҫ����O(n) 
void delShunXuBiao(SeqList &L,int x)
{
	int k =0;
	for(int i=0;i<L.length;i++)
	{
		if(L.data[i]!=x)
			{
				L.data[k] = L.data[i];
				k++;
			}
	}
	L.length = k;
}
void delShunXuBiao(int A[],int x)
{
	int k =0;
	for(int i=0;i<n;i++)
	{
		if(A[i]!=x)
		{
			A[k]=A[i];
			k++;
		}
	}
}//
void XunHuanZuoYi_P(int R[],int p)
{
	int temp;
	for(int i=0;i<=(p-1)/2;i++)
	{
		t=R[i];
		R[i] = R[p-1-i];
		R[p-1-i]=t;
	}
	//Inverse(A,0,p-1);
	for(int i=p;i<=(n+p)/2;i++)
	{

	}
	//Inverse(A,p,n-1);
	for(int i=0;i<n/2;i++)
	{

	}
	//INverse(A,0,n-1)
}
//
int SearchInvk(int k,List head)
{//Ѱ����������k��Ԫ��
//����˫ָ��˼�룬
	p = head->next;
	q = p;
	for(int i=0;i<k;i++)
		p=p->next;
	while(p->next)
	{
		q=q->next;
		p=p->next;
	}
	return q;
}
//
//�ж����Ŷ������Ƿ����
def isEqual(root1,root2):
    if root1 ==None and root2 == None:
        return True
    elif root1 == None and root2 != None:
        return False
    elif root1 != None and root2 == None:
        return False
    if root1.data == root2.data:
        return isEqual(root1.left,root2.left) and isEqual(root1.right,root2.right)
    else:
        return False

//�������������н������
void Exchange(BTreeNode* root)
{
	Node* temp;
	if(root)
	{
		temp = root->lchild;
		root->lchild = root->rhclid;
		root->rchild = temp;
		Exchange(root->lchild);
		Exchange(root->rchild);
	}
}
///
//����ջ�ĺ������ 
typedef struct treenode{
        treenode* parent;
        treenode* lnode;
        treenode* rnode;
        int flag;
        int value;
} tree;
flag =0;
void    Posttravel(tree st)
{        
	int flag = 0 ;
	while(1)
	{
		while(p!=NULL)
		{
			if(st->flag==0) 
			{
				flag = 1 ;
				pr =st;
				st=st->lnode;
			}
			else if(st->flag==1) 
			{
				flag =2;
				pr =st;
				st=st->rnode;
			}
			else if(st->flag==2) 
			{
				printf("%d",st->value);
				if(st->parent==null) //����˸��ڵ� 
						return ;
				pr =st;
				st=st->parent;
			}
		}
		if(p==NULL)
			p = pr;
	}
		
}

//
void Post(BTreeNode* root)
{
	BTreeNode* N;
	{
		if(root->flag == 0 )
		{
			flag = 1;
			if(root->lchild)
				Post(root->lchild);
		}
		else if(root->flag == 1)
		{
			flag=2;
			if(root->rchild)
				Post(root->rchild);
		}
		else if(root->flag ==2)
		{
			cout<<root->data;
			if(root==N)
				return;
			Post(root->parent);
		}
	}
}
	//
//// 
typedef struct Node
{
	datatype data;
	struct Node* lchild;
	struct Node *rchild;
	bool ltag;
	bool rtag;
}Node;
typedef struct Node* THTREE;
THTREE InNext(THTREE p)
{//�������������������
	if(!p->rtag)
		return p->rchild;
	else
	{
		p = p->rchild;
		while(p->lchild)
		{
			p=p->lchild;
		}
		return p;
	}
}
//���half�󣬵��������С�Ľ�� 
typedef struct Node
{
	int data;
	Node* lchild;
	Node* rchild;
}Node,*BinTree;
int FindNode(BinTree root)
{
	BinTree	pr;
	BinTree p;
	p=root;
	while(p->lchild)
		p=p->lchild;
	int min = p->data;
	p=root;
	whlie(p->rchlid)
		p=p->rchild;
	int max = p->data;
	int half = (min+max)/2;
	while(1)
	{
		if(p->data > half)
			pr = p;
		while(p->rchild&&p->data<=half)
			p=p->rchlid;
		assert(p->data>half);
		if(p->data > half)
			pr = p;
		if(p->lchild)
			p=->lchild;
		else if(!p->lchild)
			break;
	}
	return pr;
}
//ѭ������ 
typedef struct queue
{
	int front;
	int rear;
	int data[MAXSIZE];
}queue;
void Initial(queue &q,queue &maxq)
{
	q.front = 0;
	q.rear = 0;
	q.data[0]=-9999;
}
bool empty(queue &q)
{
	if(q.front == q.rear)
		return true;
	else
	return false;
}
bool full(queue &q)
{
	if((q.rear+1)%MAXSIZE == q.front)
		return true;
	else
		return false;
}
void push(queue &q,queue &maxq,int x)
{
	if(full(q))
		return;
	q.rear = (q.rear+1)%MAXSIZE;
	q.data[q.rear] = x;

}
void pop(queue &q,queue &maxq,int& q1,int &maxq1)
{
	if(empty(q))
		return ;
	q.front = (q.front+1)%MAXSIZE;
	q1 =  q.data[q.front];

}
//
// ����е����ֵ 
//deque������¼���ֵ,queue��¼ 
void push_back(int x)
{
	queue1.push(x);
	count=1;
	while(!deque1.empty()&&deque1.back()<x)
	{
		deque1.pop_back();
		count ++;
	}
	while(count!=0)
	{
		deque1.push_back(x);
		count--;
	}	
}
void pop_front()
{
	if(queue1.empty())
		return;
	deque1.pop_front();
	queue1.pop();
}
int max_value
{
	return deque.front();
} 
///
//�ж��Ƿ�ΪBST 
bool IsBST(Node* node,int min,int max)
{
	//Ӧ��min<x<max
	if(node == NULL)
		return true;
	if(node->data<=min||node->data>=max)	
		return false;
	return (IsBST(node->left,min,node->data))&&(IsBST(node->right,node->data,max))
} 


int pr = INT_MIN;
int flag =0;
void IsBST(Node* root)
{
	if(!root)
		return;
	else if(root)
	{
		IsBST(root->lchild);
		{
			cout<<root->data;
			if(root->data >pr)
				pr = root->data;
			if(root->data <= pr)
			{
					flag = 1;
					return;
			}
		}
		IsBST(root->rchild);
	}
}
/// 
void R_Rotate(BST &*A)
{
	B = A->lchild;
	A->lchild = B->rchild;
	B->rchild = A;
	A = B;
}
//
void Prim( C[n+1][n+1])
{
	int Lowcost[n+1];
	int CLOSEST[n+1];
	int min;
	for(int i=2;i<=n;i++)
		{
			LOWCOST[i] = C[1][i];
			CLOSEST[i] = 1;//Ŀǰѡ������Ȩֵ 1,i
		}
	LOWCOST[1] =INF;
	for(int j=2;j<=n;j++)
	{
		if(LOWCOST[j]<min)
			{
				k=j;
				min = LOWCOST[j];
			}
	}
	cout<<CLOSEST[k]<<k;
	LOWCOST[k] =INF;
	for(j=2;j<=n;j++)
	{
		if(C[k][j]<LOWCOST[j]&&LOWCOST[j]<INF)
		{
			LOWCOST[j] = C[k][j];
			CLOSEST[j] = k;//k->j
		}
	}
}
void Prim( Graph G)
{
	int lowcost[MAXSIZEF];
	int closest[MAXSIZE];
	int min;
	int sum=0;
	n  = G.vernum;
	for(int i=2;i<=n;i++)
	{
		lowcost[i]=G.edge[1][i];
		closest[i] =1;
	}
	lowcost[1] = INF;
	for(int i=2;i<=n;i++)
	{//ѭ��n-1��
		min = INF;
		for(int j=2;j<=n;j++)
		{
			
			if(lowcost[j]<min)
			{
				k=j;
				min = lowcost[j]
			}
		}//�ҵ���Сlowcost
		cout<<closet[k]<<k;
		sum+=min;
		LOWCOST[k] =INF;
		for(int j =2;j<=n;j++)
		{
			if(G.[k][j]<lowcost[j]&&lowcost[j]<INF)
			{
				lowcost[j] = G.edge[k][j];
				closest[j] = k;
			}
		}
	}
	
}

int minDepth(BTNode* root)
{
	if(!root)
		return 0;
	else
	{
		if(root->lchild&&!root->rchild)
			return max(minDepth(root->lchild),minDepth(root->lchild))+1;
		else if(!root->lchild&&root->rchild)
			return max(minDepth(root->lchild),minDepth(root->lchild))+1;
		else
			return min(minDepth(root->lchild),minDepth(root->lchild))+1
	}
}

//
typedef struct HTNOde
{
	double weight;
	int lchild;
	int rchild;
	int parent;
}HTNODE;
typedef HTNODE huffmanT[2n-1];

void CreatHT(huffmanT T)
{
	int i,p1,p2;
	Initial(T);
	Input(T);
	for(int i=n;i<2n-1;i++)
	{
		selectmin(T,i-1,&p1,&p2);
		T[i].lchild =p1;
		T[i].rchild = p2;
		T[p1].parent=T[p2].parent = i;
		T[i].weight = T[p1].weight+T[p2].weight
	}

}
void selectMin(HuffmanT T,int k,int&p1,int &p2)
{
	int min=INF;
	for(int i=0;i<k;i++)
	{
		if(T[i]<min&&T[i].parent ==-1)
		{
			min1 = T[i];
			min_i = i;
		}
		
	}
	p1 =min_i;
	int min2=INF;
	for(int i=0;i<k;i++)
	{
		if(T[i]<min&&T[i].parent ==-1&&T[i]!=min1)
		{
			min = T[i];
			min_i = i;
		}
		
	}
	p2 =min_k;
}
typedef struct{
	char cg;
	char bits[n+1];
}CodeNode;
typedef CodeNode HuffmanCode[n];
HuffmanCode H;
void EnCoding(HuffmanCode H,HuffmanT T)
{
	int c,p,i;
	char cd[n+1];
	int start;
	cd[n] = '\0';
	for(int i=0;i<n;i++)
	{
		H[i].ch =T[i].ch;
		start = n;
		c = i;
		while((p=T[c].parent)>=0)
		{
			if(T[p].lchild == c)
				cd[--start] = '0';
			else
				cd[--start]  ='1';
			c =p;
		}
		strcpy(H[i].bits,&cd[start]);
	}
}
