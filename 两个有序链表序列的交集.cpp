#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int Data;
	struct Node* Next;
}Node;
typedef Node* LIST;
LIST Creat()//head空 
{
	LIST head=(LIST)malloc(sizeof(Node));
	head->Next=NULL;
	LIST tail=head;
	int Data=0;
	while(1)
	{
		scanf("%d",&Data);
		if(Data==-1)
			break;//不录入-1 
		else
			{
				LIST temp=(LIST)malloc(sizeof(Node));
				temp->Data=Data;
				temp->Next=NULL;
				tail->Next=temp;
				tail=temp;
			}
	}
	head=head->Next;
	return head;
}
void Show(LIST head)
{
	if(head==NULL)
		printf("NULL");
	else
	{
		while(head->Next!=NULL)
	{
		printf("%d ",head->Data);
		head=head->Next;
	}
	printf("%d",head->Data);
	}
	
}
void Attach(int Data,LIST head)
{
	LIST temp=(LIST)malloc(sizeof(Node));
	temp->Data=Data;
	temp->Next=NULL;
	while(head->Next!=NULL)
		head=head->Next;
	head->Next=temp;
}
int main()//head有数值 
{
	LIST head1=Creat();
	LIST head2=Creat();
	LIST head3=(LIST)malloc(sizeof(Node));
	head3->Next=NULL;
	while(head1!=NULL&&head2!=NULL)
	{
		if(head1->Data>head2->Data)
			head2=head2->Next;
		else if(head1->Data<head2->Data)
			head1=head1->Next;
		else if(head1->Data==head2->Data)
			{
				Attach(head1->Data,head3);
				head1=head1->Next;
				head2=head2->Next;
			}
	}
	head3=head3->Next;
	Show(head3);

}

