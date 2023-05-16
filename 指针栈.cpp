#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<io.h>
#include<windows.h>
int main()
{
	struct node
	{
		ElemType data;
		node *next; 
	}
	typedef node *STACK;
	STACK MakeNull()
	{
		STACK s;
		s= new node;
		s->next=NULL;
		return s;
	}
	Boolean Empty(STACK stk)
	{
		if(stk->next!=NULL)
			return FALSE;
		else
			return TRUE;
	}
	void Push(ElementType x , STACK stk)
	{
		STACK s;
		s= new node;
		s->next=stk->next;
		s->data=x;
		stk->next=s;
	}
	void Pop(STACK stk)
	{
		STACK s;
		if(stk->next!=NULL)
		{
			s=stk->next;
			stk->next=s->next;
			delete s;
		}
	}
	ElemType Top(STACK stk)
	{
		if(stk->next!=NULL)
			return stk->next->data;
		else
			return NULL;
	}
}
