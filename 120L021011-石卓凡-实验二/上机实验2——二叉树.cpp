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
void Creat(BTreeNode* &Node);
void VLR(BTreeNode *T);
void LVR(BTreeNode *T);
void LBR(BTreeNode* T);
void LevelOrder(BTreeNode* T);
bool IsWanQuanErChaShu(BTreeNode* T);

void ShuZuHua(BTreeNode* NODE,TreeList TList[],int i)//����ʽ�洢תΪ˳��洢 ����ֵTList[i].Value 
{//���õݹ�Ĳ��Ͻ��� i��1��ʼ��Ϊ���� ��*2=���� 
	if(NODE)
	{
		TList[i].Value=NODE->Value;
		ShuZuHua(NODE->Left,TList,2*i);
		ShuZuHua(NODE->Right,TList,2*i+1);
	}
	else//NODE==NULL����ֵ#��ǰ��һ����� 
	{
		TList[i].Value='#';
	}
}
void GongGongZuXian(TreeList TList[],char A,char B)//Ѱ��A��B�������� 
{
	int Father=-1;//���������±� 
	int Anum=-1;//A�±� 
	int Bnum=-1;//B�±� 
	for(int i = 1;i<MAXSIZE;i++)
	{
		if(A==TList[i].Value)
			Anum=i;
		if(B==TList[i].Value)
			Bnum=i;	
	}//Ѱ��A B�±� 
	while(1)//Ѱ�ҹ�������,���ö���/2=���׵����ֹ�ϵ�����ƽⷽ�� 
	{
		if(Anum==Bnum)
			{
				cout<<"���ȣ�"<<TList[Anum].Value;
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
void Creat(BTreeNode* &Node)//��ν��� 
{	
	FILE *p;
	FILE *pout;
	if((pout=fopen("TNodeOut.txt","a"))==NULL)
	{
		cout<<"�ļ���ʧ��";
		exit(0);
	}
	if((p=fopen("TNode.txt","r"))==NULL)
	{
		cout<<"�ļ���ʧ��";
		exit(0);
	}	
	queue<BTreeNode*> que;
	char Value;
	fscanf(p,"%c ",&Value);
	//�ȶԵ�һ��������ջ����ԭ��1��&Node��һ���Node��ַ�޸ģ�ԭ��2����ջѭ���е�һ��Ԫ�� 
	if(Value=='#')//����� 
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
	{//���Ʋ�α��������Σ�ĳ���ڵ㣬�ýڵ�����ӣ��ýڵ��Ҷ��ӣ� 
		BTreeNode *node = que.front();//��ȡ������Ĵ�ȡԪ�أ������θ�ֵ��Ԫ�ص����Ҷ���
		que.pop();
		printf("%c ",node->Value);
		fprintf(pout,"%c ",node->Value);
		fscanf(p,"%c ",&Value);//��ȡ 
		if(Value!='#')
		{
			node->Left = new BTreeNode;
			node->Left->Value =Value;
			printf("Left -> %c ",Value);
			fprintf(pout,"Left -> %c ",Value);
			que.push(node->Left);
		}
		else//=='#'�������Ԫ��û������� 
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
void VLR(BTreeNode *T)//ǰ����� 
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
		cout<<"�ļ���ʧ��";
		exit(0);
	}
	fprintf(pout,"���������");
	if(T ==NULL)
		return ;
	queue<BTreeNode*> que;
	que.push(T);//�ȴ�����ڵ㷽��֮����ѭ��while 
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
		cout<<"�ļ���ʧ��";
		exit(0);
	}
	fprintf(pout,"ǰ�������");
	if(T==NULL)
		return;
	stack<BTreeNode*> s;
	while(T||!s.empty())//���ֻ��s.empty()һ���ж���������һ���ͽ��벻��whileѭ�� 
	{//���Լ����������������cout�ɾ� 
		while(T)
	{
		fprintf(pout,"%c",T->Value);
		cout<<T->Value;
		s.push(T);
		T=T->Left;
	}//���һ����ջ��Ȼ��T=null,
	if(!s.empty())
	{//�����仰������Ŀ�ķ�����һ������������������ǰ����� 
		T=s.top();//������һ���Ѿ�cout�����������Ͻ���δ���ʹ������� 
		s.pop();
		T=T->Right;//����������,����Ҷ��Ӳ�Ϊ�ա̣�����Ҷ���ΪNULL������һ��while����û��push��ֻ��T.top()�������ù�ջһ���ڵ㷵��һ�εĻ��� 
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
		cout<<"�ļ���ʧ��";
		exit(0);
	}
	fprintf(pout,"���������");
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
	BTreeNode* r=NULL; //rΪ������ʹ��Ľ�� 
	stack<BTreeNode*> s;
	//���ж�ÿ��������������� 
	while(T||!s.empty())
	{
		if(T)
		{
			s.push(T);
			T=T->Left;
		//һֱ��Ȼ��T=NULL	
		}
		else //T=NULL  ������֮���Ƿ�����ת 
		{
			T=s.top();//T=�����·��ķ�NULL���,Tû�������� 
			if(T->Right&&r!=T->Right)//1�������������Ҵ���û�з�������� 
			{
				T=T->Right;//Ȼ��������һ��ѭ����if(T),s.push(T),����������µ�T���к������� 
			}
			else//2��û�������� ,�����Ѿ���������� 
			{
				s.pop();//ֻ�е����Ҷ��ӻ���ʱ����û���Ҷ��ӣ�������򣬲ŵ�����ǰ���ڵ㣬�����ٻ��� 
				cout<<T->Value;//ֻ�е����Ҷ��ӻ���ʱ����û���Ҷ��ӣ�������򣬲ŵ�����ǰ���ڵ㣬�����ٻ��� 
				r=T;//��¼������ʵĽ�㣬�����ж� 
				T=NULL; //��һ��ѭ���н���T=s.top(); ,����ֱ�� T=s.top()�������if(T) 
			}
		}
	}
	
}
bool IsWanQuanErChaShu(BTreeNode* T)
{
	if(T==NULL)
		return false;//��Ϊ�շ��ش� ����������Ϊ������ȫ������ 
	queue<BTreeNode*>q;
	q.push(T);
	while(!q.empty())
	{
		BTreeNode* Top = q.front();
		if(Top->Left&&Top->Right)//1������Һ��Ӷ��У�ֱ�Ӽ�¼ 
		{
			q.pop();
			q.push(Top->Left);
			q.push(Top->Right);
		}
		if(Top->Left==NULL&Top->Right!=NULL)//2����ýڵ�����Ϊ�գ��Һ��Ӳ�Ϊ�գ���һ��������ȫ������
		{
			return false;
		}
		if((Top->Left&&Top->Right==NULL)||(Top->Left==NULL&&Top->Right==NULL))
		{//3����ýڵ����Ӳ�Ϊ�գ��Һ���Ϊ�ջ��߸ýڵ�ΪҶ�ӽڵ㣬��ýڵ�֮������н�㶼��Ҷ�ӽڵ�
			q.pop();//��ýڵ�֮������н�㶼��Ҷ�ӽڵ�
			if(Top->Left)
			q.push(Top->Left);
			//����Ϊ�жϵ�ǰ���������ǲ��Ƕ���Ҷ�� 
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

int Depth(BTreeNode* T)//������ 
{
	if(T)
		return max(Depth(T->Left),Depth(T->Right))+1;
	else
		return 0;
}
void Show(BTreeNode* T)//ͼ��չʾ 
{
	int TDepth = Depth(T);//�߶� 
	if(T==NULL)
		return;
	queue<BTreeNode*> q;//����queue���deque���е�����it 
	q.push(T);
	while(1)
	{ 
		int len=q.size();//��¼��ǰ��һ���ж��ٸ���� 
		if(TDepth==0)//������ȿ������ÿһ�����
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
				}//NULL���½���һ��'#'Ҳ��ջ 
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
				}//NULL���½���һ��'#'Ҳ��ջ 
			len--;
		}//����Ϊһ�� 
		cout<<endl;//��ǰ��һ����� 
		TDepth--;
	}
}
int main()
{
	BTreeNode* T;
	TreeList TList[MAXSIZE];
	int n;
	cout<<"                        -------------------------------------------------------------------\n";
    cout<<"                        |==================       ����������ز���       =================|\n";
    cout<<"                        -------------------------------------------------------------------\n\n";
    cout<<"                        |==================          1.ǰ��         =================|\n";
    cout<<"                        |==================          2.����         =================|\n";
    cout<<"                        |==================          3.����         =================|\n";
    cout<<"                        |==================          4.����        =================|\n";
    cout<<"                        |==================          5.ǰ��(�ǵݹ�)    =================|\n";
    cout<<"                        |==================          6.����(�ǵݹ�)  =================|\n";
    cout<<"                        |==================          7.����(�ǵݹ�) =================|\n";
	cout<<"                        |==================          8.ͼ����ʾ =================|\n";
    cout<<"                        |==================          9.�ж��Ƿ�Ϊ��ȫ������         =================|\n";
    cout<<"                        |==================          10.��������         =================|\n";
	Creat(T);
	while(1)
	{
	cout<<"������";
	cin>>n; 
	switch(n)
	{
		case 1:
			cout<<"ǰ��";
			VLR(T);
			cout<<endl;
			break;
		case 2:
			cout<<"����";
			LVR(T);
			cout<<endl;
			break;
		case 3:
			cout<<"����";
			LBR(T);
			cout<<endl;
			break;
		case 4:
			cout<<"����";
			LevelOrder(T);
			cout<<endl;
			break;
		case 5:
			cout<<"ǰ��(�ǵݹ�)";
			PreOrder_2(T); 
			cout<<endl;
			break;
		case 6:
			cout<<"����(�ǵݹ�)";
			InOrder_2(T); 
			cout<<endl;
			break;
			
		case 7:
			cout<<"����(�ǵݹ�)";
			PostOrder_2(T); 
			cout<<endl;
			break;
		case 8:
			cout<<"ͼ����ʾ\n"; 
			Show(T); 
			cout<<endl;
			break;	
		case 10:
			cout<<"��������"<<endl; 
			ShuZuHua(T,TList,1);//��ǰתΪ˳��洢�������±� 
			char C1,C2;
			cin>>C1>>C2;
			GongGongZuXian(TList,C1,C2);//�����±��� 
			cout<<"\n";
			break;
		case 9:
			if(IsWanQuanErChaShu(T)==true)
				cout<<"����ȫ������\n";
			else
				cout<<"������ȫ������\n";
			break; 
	}	
	
	}
}
