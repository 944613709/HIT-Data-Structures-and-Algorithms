#include<stdio.h>
#include<Stdlib.h>
#include<math.h>
typedef struct Node
{
	int data;
	struct Node*next;
	struct Node*ahead;
}Node;
Node* CreatNode(int data)
{
	Node *node=(Node*)malloc(sizeof(node));
	node->data=data;
	node->next=NULL;
	return node;
}
Node* CreatList(int len)
{
	Node *head=CreatNode(1);
	Node *tail=head;
	for(int i=2;i<=len;i++)
	{
		Node *node=CreatNode(i);
		tail->next=node;
		node->ahead=tail;
		tail=tail->next;
	}
	tail->next=head;
	head->ahead=tail;
	return head;
}
void Show(Node *head)
{	while(head->next!=NULL)
		{printf("%d\n",head->data);
		head=head->next;
		}
}
int main()
{
	Node*head=CreatList(10);

 } 
