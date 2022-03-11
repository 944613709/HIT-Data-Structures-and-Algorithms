#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int Data;
	struct Node* Next;
}Node;
typedef Node* LIST;
LIST CreatNode(int Data)
{
	LIST temp=(LIST)malloc(sizeof(Node));
	temp->Data=Data;
	temp->Next=NULL;
	return temp;
}
LIST AddList()
{
	LIST head=(LIST)malloc(sizeof(Node));
	head->Next=NULL;
	LIST tail=head;
	int Data=-1;
	do{
		scanf("%d",&Data);
		if(Data==-1)
			break;
		LIST temp=CreatNode(Data);
		tail->Next=temp;
		tail=tail->Next;
	}while(1);
	return head;
}
void Attach(int Data, LIST head)
{
	LIST temp=CreatNode(Data);
	while(head->Next!=NULL)
		head=head->Next;
	head->Next=temp;
}
void Show(LIST head)
{
	head=head->Next;
	while(head!=NULL)
	{
		printf("%d ",head->Data);
		head=head->Next;
	}
}
int Compare(int a, int b)
{
	if(a>b)
		return 1;
	if(a<b)
		return -1;
	if(a==b)
		return 0;
}
int main()
{
	LIST head1=AddList();
	LIST head2=AddList();
	LIST r1=head1,r2=head2;
	LIST head3=(LIST)malloc(sizeof(Node));
	head3->Next=NULL;		
	head1=head1->Next;
	head2=head2->Next;
	while(head1!=NULL&&head2!=NULL)
	{

		switch(Compare(head1->Data,head2->Data))
		{
				case 1:
				Attach(head2->Data,head3);
				head2=head2->Next;
				break;
			case -1:
				Attach(head1->Data,head3);
				head1=head1->Next;
				break;
			case 0:
				Attach(head1->Data,head3);
				Attach(head2->Data,head3);
				head1=head1->Next;
				head2=head2->Next;
				break;
		}		
	}
	for(;head1!=NULL;head1=head1->Next)
		Attach(head1->Data,head3);
	for(;head2!=NULL;head2=head2->Next)
		Attach(head2->Data,head3);
	Show(head3);
 } 
