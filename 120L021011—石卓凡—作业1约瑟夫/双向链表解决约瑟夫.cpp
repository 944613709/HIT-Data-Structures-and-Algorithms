#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int delTime=0;
typedef struct Node
{
	int data;
	struct Node *pre;
	struct Node *next;
}Node;
Node* CreatNode(int data)//新建结点并赋值 
{
	Node *node=(Node*)malloc(sizeof(Node));
	node->data=data;
	node->pre=NULL;
	node->next=NULL;
	return node;
}
Node* CreatList(int len)
{
	int num=1;
	Node *head= CreatNode(1);
	Node *tail=head;
	for(int i=2;i<=len;i++)
	{
		Node *node=CreatNode(i);
		tail->next=node;
		node->pre=tail;
		tail=tail->next;
	}
	tail->next=NULL;
	return head;
}
Node* Delete(Node *head)//删除当前的，并且返回下一个节点，进行下一轮报数 
{
	Node *temp=head;
	delTime++;//用以判断是否到删除的数 
	printf("本轮报数正好出列，第%d次执行删除编号为%d\n",delTime,temp->data);
	if(temp->pre == NULL)//对于删除头节点 
            {
            head=head->next;
            temp->next=NULL;
            head->pre=NULL;
            free(temp);
            return head;
            }

            /*判断是否是尾节点*/
            else if(temp->next == NULL)//对于删除尾结点 
            {
            	while(head->pre!=NULL)
            		  head=head->pre;//删除后head跳到当前链表第一个 
                temp->pre->next=NULL;
                temp->pre=NULL;
                free(temp);
                return head;
            }
            else//删除中间结点 
            {
            	head=head->next;
                temp->pre->next=temp->next;
                temp->next->pre=temp->pre;
                free(temp);    
                return head;   
            }
              
} 
Node *Search(Node *head, int k) {   //从Head开始寻找第P个节点
	while (head->data != k) {
		head = head->next;
	}
	return head;
}
Node *Jump(Node *head, int m)//将head前m-1次正常报数，然后返回第m次 
{
	int count=0;
	while(count!=m-1)//前m-1个人都能正常报数 
	{
		count++;
		printf("报数为->%d,编号data为->%d\n",count,head->data);//报数 
		if(head->next==NULL)
		{
			while(head->pre!=NULL)
				head=head->pre;
		}//换行 
		else 
			head=head->next;
	}
	return head; 
}
int main()//已知n个人围坐在一张圆桌周围。从编号为k的人开始报数，数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；依此规律重复下去，直到圆桌周围的人全部出列。(摘自百度百科)
{
	int n,k,m;
	int count=0;
	printf("按照n,k,m\n");
	while(scanf("%d,%d,%d",&n,&k,&m)!=3)
	{
	} 
	Node *head=CreatList(n);
	head=Search(head,k);
	while(count!=n-1)//执行n-1次出列，来完成剩下最后一个人 
	{
		count++;
		head=Jump(head,m);//将head前m-1次正常报数，然后返回第m次 
		head=Delete(head);//删除当前的，并且返回下一个节点，进行下一轮报数 
	}
	printf("最后剩下的是编号为%d\n",head->data);
}
