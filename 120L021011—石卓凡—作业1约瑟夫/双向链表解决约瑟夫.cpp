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
Node* CreatNode(int data)//�½���㲢��ֵ 
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
Node* Delete(Node *head)//ɾ����ǰ�ģ����ҷ�����һ���ڵ㣬������һ�ֱ��� 
{
	Node *temp=head;
	delTime++;//�����ж��Ƿ�ɾ������ 
	printf("���ֱ������ó��У���%d��ִ��ɾ�����Ϊ%d\n",delTime,temp->data);
	if(temp->pre == NULL)//����ɾ��ͷ�ڵ� 
            {
            head=head->next;
            temp->next=NULL;
            head->pre=NULL;
            free(temp);
            return head;
            }

            /*�ж��Ƿ���β�ڵ�*/
            else if(temp->next == NULL)//����ɾ��β��� 
            {
            	while(head->pre!=NULL)
            		  head=head->pre;//ɾ����head������ǰ�����һ�� 
                temp->pre->next=NULL;
                temp->pre=NULL;
                free(temp);
                return head;
            }
            else//ɾ���м��� 
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
Node *Jump(Node *head, int m)//��headǰm-1������������Ȼ�󷵻ص�m�� 
{
	int count=0;
	while(count!=m-1)//ǰm-1���˶����������� 
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
	while(count!=n-1)//ִ��n-1�γ��У������ʣ�����һ���� 
	{
		count++;
		head=Jump(head,m);//��headǰm-1������������Ȼ�󷵻ص�m�� 
		head=Delete(head);//ɾ����ǰ�ģ����ҷ�����һ���ڵ㣬������һ�ֱ��� 
	}
	printf("���ʣ�µ��Ǳ��Ϊ%d\n",head->data);
}
