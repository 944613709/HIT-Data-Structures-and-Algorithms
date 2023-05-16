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
Node* Delete(Node *head)//ɾ����ǰ�ģ���������һ��
{
	Node *temp=head;
	delTime++;
	printf("��%d��ִ��ɾ�����Ϊ%d\n",delTime,temp->data);
	if(temp->pre == NULL)
            {
            head=head->next;
            temp->next=NULL;
            head->pre=NULL;
            free(temp);
            return head;
            }

            /*�ж��Ƿ���β�ڵ�*/
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
Node *Search(Node *head, int k) {   //��Head��ʼѰ�ҵ�P���ڵ�
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
		printf("����Ϊ->%d,���dataΪ->%d\n",count,head->data);//���� 
		if(head->next==NULL)
		{
			while(head->pre!=NULL)
				head=head->pre;
		}//���� 
		else 
			head=head->next;
	}
	return head;
}
int main()//��֪n����Χ����һ��Բ����Χ���ӱ��Ϊk���˿�ʼ����������m���Ǹ��˳��У�������һ�����ִ�1��ʼ����������m���Ǹ����ֳ��У����˹����ظ���ȥ��ֱ��Բ����Χ����ȫ�����С�(ժ�԰ٶȰٿ�)
{
	int n,k,m;
	int count=0;
	printf("����n,k,m\n");
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
	printf("���ʣ�µ��Ǳ��Ϊ%d\n",head->data);
}
