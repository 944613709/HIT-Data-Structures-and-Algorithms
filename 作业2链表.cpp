#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
	int Data;
	struct Node* Next;
	struct Node* Pre;
}Node;
Node* Creat(Node* Head)//头节点也有数据 双向不循环 
{
	Head = new Node;
	Node* Rear;
	Rear = Head;
	FILE *p;
	p=fopen("List.txt","r");
	int n;
	fscanf(p,"%d ",&n);
	Head->Data = n;
	Head->Next = NULL;
	Head->Pre = NULL;
	while(fscanf(p,"%d ",&n)!=EOF)
	{
		Node* t;
		t= new Node;
		t->Data = n;
		t->Next = NULL;
		t->Pre = Rear;
		Rear->Next = t;
		Rear=t;
	}
	fclose(p);
	return Head;
}
void Delete1(Node* &Head,int n)
{
	Node*t;
	Node *temp=Head;
	while(Head->Data==n)//头节点 
		{
			t=Head;
			Head=Head->Next;
			delete t;
		}
		temp=Head;
		//head->Data!=n
	while(Head->Next!=NULL)//非头结点 
	{
		if(Head->Next->Data==n)
		{
			t=Head->Next;
			Head->Next=t->Next;
			delete t;
			continue;
		}
		Head=Head->Next;
	}
	Head=temp;
}
Node* Delete2(Node* Head)
{
	Node* t1;
	Node* t2;
	Node* t;
	t1=Head;
	while(t1->Next!=NULL )//不用删掉头节点 
	{
		t2=t1;
		while(t2->Next!=NULL )
		{
			if(t1->Data==t2->Next->Data)
			{
				t=t2->Next;
				t2->Next=t->Next;
				delete t;
				continue;
			}
			t2=t2->Next;
		}
		t1=t1->Next;
	}
	return Head;
}
void Show(Node* Head)
{
	while(Head!=NULL)
		{
			cout<<Head->Data<<endl;
			Head=Head->Next;
		}
}
void Reverse(Node* Head)
{
	Node* Rear=Head;
	while(Rear->Next!=NULL)
		{
			Rear=Rear->Next;
		}
	int t;
	while((Head!=Rear)&&(Rear->Next!=Head))
	{
	t=Head->Data;
	Head->Data = Rear->Data;
	Rear->Data = t;
	Head=Head->Next;
	Rear=Rear->Pre;
	}
}
int main()
{
	Node* Head;
	Head = Creat(Head);
	//Delete1(Head,1);
	//Delete2(Head);
	Reverse(Head);
	Show(Head);
}
