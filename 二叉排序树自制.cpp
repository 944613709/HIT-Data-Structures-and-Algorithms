#include<bits/stdc++.h>
using namespace std;
typedef struct BSTNode
{
	int Data;
	struct BSTNode* lchild;
	struct BSTNode* rchild;
}BSTNode;
bool BST_insert(BSTNode* &T,int Data)
{
	if(NULL == T)
	{
		T= new BSTNode;
		T->Data = Data;
		T->lchild =NULL;
		T->rchild = NULL;
		return true;
	}
	else if(Data < T->Data)
		BST_insert(T->lchild,Data);
	else
		BST_insert(T->rchild,Data);
}
void CreatBST(BSTNode* &BST)
{
	FILE *p;
	if((p=fopen("BST_In.txt","r"))==NULL)
		{
			cout<<"文件打开失败";
			exit(0);
		}
	int n;
	fscanf(p,"n=%d;",&n);
	int temp;
	for(int i= 0;i<n;i++)
	{
		fscanf(p,"%d,",&temp);
		assert(true==BST_insert(BST,temp));
	}
}
bool Serch(BSTNode* BST,int target)
{
	if(NULL == BST)
		return false;
	if(target == BST->Data)
		{
			cout<<"FIND";
			return true;
		}
	else if(target < BST->Data)
	{
		Serch(BST->lchild,target);
	}
	else
		Serch(BST->rchild,target);
		
} 
void InOrder(BSTNode* BST)
{
	if(NULL==BST)
		return;
	InOrder(BST->lchild);
	cout<<BST->Data<<" ";
	InOrder(BST->rchild);
}
int main()
{
	BSTNode* BST=NULL;
	CreatBST(BST);
	InOrder(BST);
	Serch(BST,3);
}
