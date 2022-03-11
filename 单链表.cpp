#include<Stdio.h>
#include<math.h>
#include <stdlib.h>
//结点结构体
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node *create_node(int data)
{
	Node *node=(Node*)malloc(sizeof(Node));//node名只在这里使用，当时申请的空间会一直存在 
	node->data=data;
	node->next=NULL;
	return node;
}
Node *creat_list(int num)
{
	Node *head= create_node(1);
	Node *tail = head;
	for(int i =2;i<=num;++i)
	{
		Node *node=create_node(i);
		tail->next=node;
		tail=node;
	}
	return head;
}

int list_len(Node*head)//head箭头每次都会重叠 
{
	int len=0;
	while(head!=NULL)
	{
		head=head->next;//headmeici 
		len++;
	}
	return len;
}
Node *list_insert(Node *head,int index,int data)
{
	if(index>list_len(head)||index<0)
	{
		return NULL;
	}
	else if(index == 0){
		Node *node = create_node(data);
		node->next=head;
		head = node;
	}
	else
	{
		Node *temp = head;
		for(int i=0;i<index-1;i++){
			temp=temp->next;
		}
		Node *node = create_node(data);
		node->next=temp->next;
		temp->next=node;
	}
	return head;
}
Node* list_delete(Node *head,int index)
{
	if(head==NULL||index>=list_len(head)||index<0)
		return NULL;
	else if(index == 0)
	{
		Node *temp =head;
		head = temp->next;
		free(temp);
		temp= NULL;
	}
	else
	{
		Node *node=head;
		for(int i =0;i<index-1;i++)
		{
			node=node->next; 
		}
		Node *temp = node->next;
		node->next=temp->next;
		free(temp);
		temp=NULL;
	}
	return head;
}
bool modifu_index(Node *head,int index,int data)
{
	if(head==NULL||index<0||index>=list_len(head))
		return false;
	Node *node=head;
	for(int i=0;i<index-1;i++)
	{
		node=node->next;
	}
	node->data=data;
	return true;
}
int main()
{
	Node *head=creat_list(5);
	printf("%d\n",list_len(head));
	for(int i=1;i<=5;i++)
		printf("%d\n",head)
}

