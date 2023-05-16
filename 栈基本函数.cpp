#include<Stdio.h>
#include<Stdlib.h>
#include<math.h>
struct Node
{
	int data;
	Node* next;
};
typedef Node* STACK;
STACK MakeNull()
{
	STACK S = new Node;
	S->next=NULL;	
	return S;
}
void Push(int data,STACK S)
{
	STACK stk = new Node;
	stk->data=data;
	stk->next=S->next;
	S->next=stk;
}
void Pop(STACK S)
{
	STACK stk;
	if(S->next)
	{
		stk=S->next;
		S->next=stk->next;
		delete stk;
	}
}
int Top(STACK S)
{
	if(S->next)
	{
		return S->next->data;
	}
	else
		return NULL;
}
bool IsEmpty(STACK S)
{
	if(S->next)
		return false;
	else
		return true;
}
void Show(STACK S)
{
	STACK stk=S->next;
	while(stk->next!=NULL)
		{printf("data %d\n",stk->data);
		 stk=stk->next;
		}
	printf("data %d\n",stk->data);
}
int main()
{
	STACK S;
	S=MakeNull();
	Push(1,S);
	Push(2,S);
	Show(S);
}
