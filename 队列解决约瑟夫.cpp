#include <stdio.h>
#include <stdlib.h>
#include <assert.h>//n����Χ����һ��Բ����Χ���ӱ��Ϊk���˿�ʼ����������m���Ǹ��˳���
typedef struct Node
{
	int Data;
	struct Node* Next;
}Node;
typedef struct Queue
{
	Node* Front;
	Node* Rear;
	int Size;
}Queue;
typedef Quque* QUEUE;
QUEUE Creat()
{
	QUEUE Q=(QUEUE)malloc(Queue);
	Q->Front=NULL;
	Q->Rear=NULL;
	Q->Size=0;
	return Q;
}
void Push(QUEUE Q,int Data)
{
	QUEUE temp=(QUEUE)malloc(Queue);
	temp->Next=NULL;
	temp->Data=Data;
	if(Q->Size==0)
	{
		Q->Front=temp;
		Q->Rear=temp;
	}
	else
	{
		Q->Rear->Next=temp;
		Q->Rear=temp;
	}
	Q->Size++;
}
int Pop(QUEUE Q)
{
	int Data;
	QUEUE temp;
	if(Q->Size==0)
		return NULL;
	else
	{
		temp=Q->Front;
		Data=temp->Data;
		Q->Front=temp->Next;
		free(temp);
		return Data;
	}
}//n����Χ����һ��Բ����Χ���ӱ��Ϊk���˿�ʼ����������m���Ǹ��˳���
int main()
{
	int n,k,m;
	QUEUE Q;
	Q=Creat();
	for(int i=1;i<=n;i++)
		Push(Q,i);//�����ų�ʼ��
	 
	
}
