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
queue *q; //���б����ѳ�ջԪ��
int n;
int count=0;
STACK *s;

void OutPut_S(int k)
{
    int temp;
    if(k!=n+1)//��k��=n+1ʱ������ݹ� 
    {
        push(s,k);  
		//��ǰԪ��k��ջ
        OutPut_S(k+1);  
		//������һԪ��k+1
        pop(s);    //��������ǰԪ��״̬
        if(!Isempty(s))  //��ջ�ǿ�ʱ
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
    {//��k==n+1ʱ������ݹ� 
        Qnode* p=q->front;
        while(p->next!=NULL)
        {	//������Ԫ�ش�ӡ�����Ѿ���ջ��Ԫ�� 
            printf("%d ",p->next->data); 
            p=p->next;
        }
        int j;
        //Ȼ���ٴ�ӡջ��Ԫ�� ,Ȼ����� 
        for(j=s->top;j>=0;j--)
            printf("%d ",s->data[j]);  
        count++;  //�������м��ֿ���
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
    printf("���������������ж��ٸ�Ԫ��\n");
   	 scanf("%d",&n);
    OutPut_S(1);
    printf("����%d�ֿ���",count);
    return 0;
}

