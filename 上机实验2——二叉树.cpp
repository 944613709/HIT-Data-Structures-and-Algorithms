#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define MAXSIZE 100
typedef struct BTreeNode
{
	char Value;
	struct	BTreeNode *Left;
	struct	BTreeNode *Right;
}BTreeNode;
typedef struct TreeList
{
	char Value;
}TreeList;
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
void Creat(BTreeNode* &Node);
void VLR(BTreeNode *T);
void LVR(BTreeNode *T);
void LBR(BTreeNode* T);
void LevelOrder(BTreeNode* T);
bool IsWanQuanErChaShu(BTreeNode* T);

void ShuZuHua(BTreeNode* NODE,TreeList TList[],int i)//将链式存储转为顺序存储 ，赋值TList[i].Value 
{//利用递归的不断进行 i从1开始，为后续 父*2=左子 
	if(NODE)
	{
		TList[i].Value=NODE->Value;
		ShuZuHua(NODE->Left,TList,2*i);
		ShuZuHua(NODE->Right,TList,2*i+1);
	}
	else//NODE==NULL，赋值#后当前这一层结束 
	{
		TList[i].Value='#';
	}
}
void GongGongZuXian(TreeList TList[],char A,char B)//寻找A与B公共祖先 
{
	int Father=-1;//公共祖先下标 
	int Anum=-1;//A下标 
	int Bnum=-1;//B下标 
	for(int i = 1;i<MAXSIZE;i++)
	{
		if(A==TList[i].Value)
			Anum=i;
		if(B==TList[i].Value)
			Bnum=i;	
	}//寻找A B下标 
	while(1)//寻找公共祖先,利用儿子/2=父亲的数字关系，类似解方程 
	{
		if(Anum==Bnum)
			{
				cout<<"祖先："<<TList[Anum].Value;
				return;
			}
		else if(Anum>Bnum)
		{
				Anum=Anum/2; 
		}
		else if(Bnum>Anum)
				Bnum=Bnum/2;
	} 
}
void Creat(BTreeNode* &Node)//层次建立 
{	
	FILE *p;
	FILE *pout;
	if((pout=fopen("TNodeOut.txt","a"))==NULL)
	{
		cout<<"文件打开失败";
		exit(0);
	}
	if((p=fopen("TNode.txt","r"))==NULL)
	{
		cout<<"文件打开失败";
		exit(0);
	}	
	queue<BTreeNode*> que;
	char Value;
	fscanf(p,"%c ",&Value);
	//先对第一个根结点进栈处理，原因1，&Node会一起把Node地址修改，原因2方便栈循环有第一个元素 
	if(Value=='#')//代表空 
		{
			Node=NULL;
			return;
		}
	else//!='#'
		{
			Node = new BTreeNode;
			Node->Value = Value;
			que.push(Node);
		}
	while(!que.empty())
	{//类似层次遍历，依次，某个节点，该节点左儿子，该节点右儿子， 
		BTreeNode *node = que.front();//读取队列里的待取元素，来依次赋值该元素的左右儿子
		que.pop();
		printf("%c ",node->Value);
		fprintf(pout,"%c ",node->Value);
		fscanf(p,"%c ",&Value);//读取 
		if(Value!='#')
		{
			node->Left = new BTreeNode;
			node->Left->Value =Value;
			printf("Left -> %c ",Value);
			fprintf(pout,"Left -> %c ",Value);
			que.push(node->Left);
		}
		else//=='#'，代表该元素没有左儿子 
		{
			node->Left=NULL;
			printf("Left -> %c ",Value);
			fprintf(pout,"Left -> %c ",Value);
		}
		fscanf(p,"%c ",&Value);
		if(Value!='#')
		{
			node->Right = new BTreeNode;
			node->Right->Value =Value;
			printf("Right -> %c \n",Value);
			fprintf(pout,"Right -> %c \n",Value);
			que.push(node->Right);
		}
		else//=='#'
		{
			node->Right=NULL;
			printf("Right -> %c \n",Value);
			fprintf(pout,"Right -> %c \n",Value);
		}
	}
	fclose(p);
	fclose(pout);
}
void VLR(BTreeNode *T)//前序遍历 
{
	if(T==NULL)
		return ;
	else
	{
		cout<<T->Value;
		VLR(T->Left);
		VLR(T->Right);
	}
 } 

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
void LBR(BTreeNode* T)
{
	if(T==NULL)
	{
		return;
	}
	else
	{
		LVR(T->Left);
		LVR(T->Right);
		cout<<T->Value;
	}
}
void LevelOrder(BTreeNode* T)
{
	FILE *pout;
	if((pout=fopen("TNodeOut.txt","a"))==NULL)
	{
		cout<<"文件打开失败";
		exit(0);
	}
	fprintf(pout,"层序遍历：");
	if(T ==NULL)
		return ;
	queue<BTreeNode*> que;
	que.push(T);//先处理根节点方便之后走循环while 
	while(!que.empty())
	{
		BTreeNode* t;
		t=que.front();
		que.pop();
		fprintf(pout,"%c",t->Value);
		cout<<t->Value;
		if(t->Left!=NULL)
			que.push(t->Left);
		if(t->Right!=NULL)
			que.push(t->Right);
	}
	fprintf(pout,"\n");
	fclose(pout);
}
void PreOrder_2(BTreeNode* T)
{
	FILE *pout;
	if((pout=fopen("TNodeOut.txt","a"))==NULL)
	{
		cout<<"文件打开失败";
		exit(0);
	}
	fprintf(pout,"前序遍历：");
	if(T==NULL)
		return;
	stack<BTreeNode*> s;
	while(T||!s.empty())//如果只有s.empty()一个判断条件，第一个就进入不了while循环 
	{//从自己这个结点和左子树先cout干净 
		while(T)
	{
		fprintf(pout,"%c",T->Value);
		cout<<T->Value;
		s.push(T);
		T=T->Left;
	}//最后一个进栈，然后T=null,
	if(!s.empty())
	{//这三句话是最终目的返回上一级的右子树，并对其前序遍历 
		T=s.top();//返回上一级已经cout，在下面马上进入未访问过右子树 
		s.pop();
		T=T->Right;//进入右子树,如果右儿子不为空√，如果右儿子为NULL，在下一次while进行没有push，只有T.top()，正好用光栈一个节点返回一次的机会 
	} 
	}
	fprintf(pout,"\n");
	fclose(pout);
 } 
void InOrder_2(BTreeNode* T)
{
	FILE *pout;
	if((pout=fopen("TNodeOut.txt","a"))==NULL)
	{
		cout<<"文件打开失败";
		exit(0);
	}
	fprintf(pout,"中序遍历：");
	if(T==NULL)
		return;
	stack<BTreeNode*> s;
	while(T||!s.empty())
	{
		while(T)
	{
		s.push(T);
		T=T->Left;
	} 
	if(!s.empty())
	{
		T=s.top();
		s.pop();
		fprintf(pout,"%c",T->Value);
		cout<<T->Value;
		T=T->Right;
	}
	
	}
	fprintf(pout,"\n");
	fclose(pout);	
 } 
void PostOrder_2(BTreeNode* T)
{
	if(T==NULL)
		return;
	BTreeNode* r=NULL; //r为最近访问过的结点 
	stack<BTreeNode*> s;
	//进行对每个子树来后序遍历 
	while(T||!s.empty())
	{
		if(T)
		{
			s.push(T);
			T=T->Left;
		//一直左，然后到T=NULL	
		}
		else //T=NULL  看返回之后是否能右转 
		{
			T=s.top();//T=最左下方的非NULL结点,T没有左子树 
			if(T->Right&&r!=T->Right)//1，右子树存在且从来没有访问输出过 
			{
				T=T->Right;//然后会进入下一次循环的if(T),s.push(T),对其这个以新的T进行后续遍历 
			}
			else//2，没有右子树 ,或者已经访问输出过 
			{
				s.pop();//只有当从右儿子回来时或者没有右儿子，满足后序，才弹出当前根节点，不会再回来 
				cout<<T->Value;//只有当从右儿子回来时或者没有右儿子，满足后序，才弹出当前根节点，不会再回来 
				r=T;//记录最近访问的结点，用来判断 
				T=NULL; //下一次循环中进入T=s.top(); ,不能直接 T=s.top()否则进入if(T) 
			}
		}
	}
	
}
bool IsWanQuanErChaShu(BTreeNode* T)
{
	if(T==NULL)
		return false;//树为空返回错 空树这里认为不是完全二叉树 
	queue<BTreeNode*>q;
	q.push(T);
	while(!q.empty())
	{
		BTreeNode* Top = q.front();
		if(Top->Left&&Top->Right)//1如果左右孩子都有，直接记录 
		{
			q.pop();
			q.push(Top->Left);
			q.push(Top->Right);
		}
		if(Top->Left==NULL&Top->Right!=NULL)//2如果该节点左孩子为空，右孩子不为空，则一定不是完全二叉树
		{
			return false;
		}
		if((Top->Left&&Top->Right==NULL)||(Top->Left==NULL&&Top->Right==NULL))
		{//3如果该节点左孩子不为空，右孩子为空或者该节点为叶子节点，则该节点之后的所有结点都是叶子节点
			q.pop();//则该节点之后的所有结点都是叶子节点
			if(Top->Left)
			q.push(Top->Left);
			//缩减为判断当前队列里面是不是都是叶子 
			while(!q.empty())
			{
				Top=q.front();
				if(Top->Left==NULL&Top->Right==NULL)
				{
					q.pop();
				}
				else
				{
					return false;
				}
			}
			return true;
		}
	}
	return true;
}

int Depth(BTreeNode* T)//求树高 
{
	if(T)
		return max(Depth(T->Left),Depth(T->Right))+1;
	else
		return 0;
}
void Show(BTreeNode* T)//图形展示 
{
	int TDepth = Depth(T);//高度 
	if(T==NULL)
		return;
	queue<BTreeNode*> q;//不设queue设成deque才有迭代器it 
	q.push(T);
	while(1)
	{ 
		int len=q.size();//记录当前这一层有多少个结点 
		if(TDepth==0)//利用深度控制输出每一层次数
			break; 
		while(len>0)
		{
			T =q.front();
			q.pop();
			cout<<T->Value;
			if(T->Left)
				q.push(T->Left);
			else
				{
					BTreeNode* temp;
					temp=new BTreeNode;
					temp->Value='#';
					temp->Left=NULL;
					temp->Right=NULL;
					q.push(temp);
				}//NULL就新建立一个'#'也入栈 
			if(T->Right)
				q.push(T->Right);
			else
				{
					BTreeNode* temp;
					temp=new BTreeNode;
					temp->Value='#';
					temp->Left=NULL;
					temp->Right=NULL;
					q.push(temp);
				}//NULL就新建立一个'#'也入栈 
			len--;
		}//这里为一层 
		cout<<endl;//当前这一层结束 
		TDepth--;
	}
}
int main()
{
	BTreeNode* T;
	TreeList TList[MAXSIZE];
	int n;
	cout<<"                        -------------------------------------------------------------------\n";
    cout<<"                        |==================       二叉树的相关操作       =================|\n";
    cout<<"                        -------------------------------------------------------------------\n\n";
    cout<<"                        |==================          1.前序         =================|\n";
    cout<<"                        |==================          2.中序         =================|\n";
    cout<<"                        |==================          3.后序         =================|\n";
    cout<<"                        |==================          4.层序        =================|\n";
    cout<<"                        |==================          5.前序(非递归)    =================|\n";
    cout<<"                        |==================          6.中序(非递归)  =================|\n";
    cout<<"                        |==================          7.后序(非递归) =================|\n";
	cout<<"                        |==================          8.图形显示 =================|\n";
    cout<<"                        |==================          9.判断是否为完全二叉树         =================|\n";
    cout<<"                        |==================          10.公共祖先         =================|\n";
	Creat(T);
	while(1)
	{
	cout<<"请输入";
	cin>>n; 
	switch(n)
	{
		case 1:
			cout<<"前序";
			VLR(T);
			cout<<endl;
			break;
		case 2:
			cout<<"中序";
			LVR(T);
			cout<<endl;
			break;
		case 3:
			cout<<"后序";
			LBR(T);
			cout<<endl;
			break;
		case 4:
			cout<<"层序";
			LevelOrder(T);
			cout<<endl;
			break;
		case 5:
			cout<<"前序(非递归)";
			PreOrder_2(T); 
			cout<<endl;
			break;
		case 6:
			cout<<"中序(非递归)";
			InOrder_2(T); 
			cout<<endl;
			break;
			
		case 7:
			cout<<"后序(非递归)";
			PostOrder_2(T); 
			cout<<endl;
			break;
		case 8:
			cout<<"图形显示\n"; 
			Show(T); 
			cout<<endl;
			break;	
		case 10:
			cout<<"公共祖先"<<endl; 
			ShuZuHua(T,TList,1);//提前转为顺序存储方便用下标 
			char C1,C2;
			cin>>C1>>C2;
			GongGongZuXian(TList,C1,C2);//利用下标找 
			cout<<"\n";
			break;
		case 9:
			if(IsWanQuanErChaShu(T)==true)
				cout<<"是完全二叉树\n";
			else
				cout<<"不是完全二叉树\n";
			break; 
	}	
	
	}
}
