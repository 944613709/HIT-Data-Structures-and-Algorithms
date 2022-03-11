#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<assert.h>
using namespace std;
#define INF -1
#define MaxVNode 100
#define MAXSIZE 4
typedef struct queue
{
	int front;
	int rear;
	int data[MAXSIZE];
}queue;
void Initial(queue q,queue maxq)
{
	q.front = 0;
	q.rear = 0;
	maxq.front = 0 ;
	maxq.rear = 0;
}
bool empty(queue q)
{
	if(q.front == q.rear)
		return true;
	else
	return false;
}
bool full(queue q)
{
	if((q.rear+1)%MAXSIZE == q.front)
		return true;
	else
		return false;
}
void push(queue q,queue maxq,int x)
{
	if(full(q))
		return;
	q.rear = (q.rear+1)%MAXSIZE;
	q.data[q.rear] = x;
	
	if(empty(maxq))
	{
		maxq.rear = (maxq.rear+1)%MAXSIZE;
		maxq.data[maxq.rear] = x;
	}
	else
	{
		int temp = maxq.data[maxq.rear];
		maxq.rear = (maxq.rear+1)%MAXSIZE;
		maxq.data[maxq.rear] = max(temp,x);
	}
}
void pop(queue q,queue maxq,int& q1,int &maxq1)
{
	if(empty(q))
		return ;
	q.front = (q.front+1)%MAXSIZE;
	q1 =  q.data[q.front];
	maxq.front = (maxq.front+1)%MAXSIZE;
	q1 =  maxq.data[maxq.front];
}
int main()
{
	queue q;
	queue maxq;
	int q1,maxq1;
	Initial(q,maxq);
	push(q,maxq,3);
	push(q,maxq,2);
	push(q,maxq,1);
	for(int i=0;i<4;i++)
		cout<<q.data[i]<<endl;
	pop(q,maxq,q1,maxq1);
	cout<<"q1"<<q1<<"  maxq1"<<maxq1<<endl;
	pop(q,maxq,q1,maxq1);
	cout<<"q1"<<q1<<"  maxq1"<<maxq1<<endl;
}
