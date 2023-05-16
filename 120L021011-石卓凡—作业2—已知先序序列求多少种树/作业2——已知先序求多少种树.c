#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 99

typedef struct STACK
{
    int top;
    int data[MAX];
}STACK;
void push(STACK *s,int data)
{
    s->data[++s->top]=data;
}
void pop(STACK *s)
{
    s->top--;
}
void STACK_Initial(STACK *s)
{	
    s->top=-1;
}

int top(STACK *s)
{
    return s->data[s->top];
}
bool Isempty(STACK *s)
{
    if(s->top==-1)
        return true;
    else
        return false;
}
typedef struct Qnode
{
    int data;
    struct Qnode* next;
}Qnode;

typedef struct Queue
{
    Qnode* front;
    Qnode* rear;
}queue;
void Q_Initial(queue *q)
{
    Qnode *p=malloc(sizeof(Qnode));
    p->next=NULL;
    q->front=p;
    q->rear=p;
}
void enqueue(queue *q,int k)
{
    Qnode *p=malloc(sizeof(Qnode));
    p->data=k;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
}
void dequeue(queue *q)
{
    Qnode *p=q->front->next;
    q->front->next=p->next;
    free(p);
    if(q->front->next==NULL)
        q->rear=q->front;
}
queue *q; //队列保存已出栈元素
int n;
int count=0;
STACK *s;

void OutPut_S(int k)
{
    int temp;
    if(k!=n+1)//当k！=n+1时候继续递归 
    {
        push(s,k);  
		//当前元素k入栈
        OutPut_S(k+1);  
		//处理下一元素k+1
        pop(s);    //回溯至当前元素状态
        if(!Isempty(s))  //当栈非空时
        {
            temp=top(s);
            pop(s);
            enqueue(q,temp); 
            OutPut_S(k);
            dequeue(q);
            push(s,temp);
        }
    }
    else if(k==n+1) 
    {//当k==n+1时候结束递归 
        Qnode* p=q->front;
        while(p->next!=NULL)
        {	//将队列元素打印——已经出栈的元素 
            printf("%d ",p->next->data); 
            p=p->next;
        }
        int j;
        //然后再打印栈的元素 ,然后回溯 
        for(j=s->top;j>=0;j--)
            printf("%d ",s->data[j]);  
        count++;  //计数共有几种可能
        printf("\n");
        return ;
    }
   
}

int main()
{
    s = malloc(sizeof(STACK));
    STACK_Initial(s);
    q = malloc(sizeof(queue));
    Q_Initial(q);
    printf("请输入先序序列有多少个元素\n");
   	 scanf("%d",&n);
    OutPut_S(1);
    printf("共有%d种可能",count);
    return 0;
}

