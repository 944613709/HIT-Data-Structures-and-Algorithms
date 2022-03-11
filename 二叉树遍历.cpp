#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
	int Data;
	struct Node* Left;
	struct Node* Right;
}Node;
typedef struct Node* BinTree BT
void PreOrderTraversal(BinTree BT)
{
	if(BT)
	{
		cout<<BT->Data<<endl;
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}
void InOrderTraversal(BinTree BT)
{
	if(BT)
	{
		InOrderTraversal(BT->Left);
		cout<<BT->Data;
		InOrderTraversal(BT->Right);
	}
}
void PostOrderTraversal(BinTree BT)
{
	if(BT)
	{
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		cout<<BT->Data;
	}
}
void InOrderTraversal_Stack(BinTree BT)
{
	BinTree T;
	STACK S = CreatStack(Maxsize);
	while(T||!IsEmpty(S))
	{
		while(T)
		{
			Push(S,T);
			T = T->Left;
		}
		if(!IsEmpty(S))
		{
			T=Pop(S);
			cout<<T->Data<<endl;
			T=T->Right;
		}
	}
}
void PreOrderTraversal_Stack(BinTree BT)
{
	BinTree T;
	STACK S = CreatStack(Maxsize);
	while(T||!IsEmpty(S))
	{
		while(T)
		{
			Push(S,T);
			cout<<T->Data<<endl;
			T=T->Left;
		}
		if(!IsEmpty(S))
		{
			T = Pop(S);
			T = T->Right;
		}
	}
}
void LevelOrderTraversal(BinTree BT)
{
	QUEUE Q;
	BinTree T;
	if(!BT)
		return NULL;
	Q = CreatQueue(MaxSize);
	AddQ(Q,Bt);
	while(!IsEmptyQ(Q))
	{
		T = DeleteQ(Q);
		cout<<T->Data;
		if(T->Left)
			AddQ(Q,T->Left);
		if(T->Right)
			AddQ(Q,T->Right);
	}
}
