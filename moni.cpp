#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Node
{
	int Data;
	struct Node* Next;
}Node;
typedef struct Queue
{
	Node* Front;
	Node* Rear;
	int size;
}Queue;
void Creat(Queue* Q)
{
	
	Q->Front=NULL;
	Q->Rear=NULL;
	Q->size=0;
}
void Push(Queue* Q,int Data)
{
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->Data=Data;
	temp->Next=NULL;
	Q->size=0;
	if(Q->size==0)
	{
		Q->Front=temp;
		Q->Rear=temp;
	}
	else
	{
		Q->Rear->Next=temp;
		Q->Rear=temp;
	}
	Q->size++;
}
void Show(Queue* Q)
{
	
	while(Q->Front!=NULL)
	{
		printf("%d ",Q->Front->Data);
		Q->Front=Q->Front->Next;
	}
}
int main()
{
	Queue* Q=new Queue;
	Creat(Q);
	Push(Q,1);
	Show(Q);
}
