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
Node* CreatNode(int data)
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
Node* Delete(Node *head)//删除当前的，并且跳下一个
{
	Node *temp=head;
	delTime++;
	printf("第%d次执行删除编号为%d\n",delTime,temp->data);
	if(temp->pre == NULL)
            {
            head=head->next;
            temp->next=NULL;
            head->pre=NULL;
            free(temp);
            return head;
            }

            /*判断是否是尾节点*/
            else if(temp->next == NULL)
            {
            	while(head->pre!=NULL)
            		  head=head->pre;
                temp->pre->next=NULL;
                temp->pre=NULL;
                free(temp);
                return head;
            }
            else
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
Node *Jump(Node *head, int m)
{
	int count=0;
	while(count!=m)
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
	while(count!=n-1)
	{
		count++;
		head=Jump(head,m);
		head=Delete(head);
	}
	printf("最后剩下的是编号为%d\n",head->data);
}
