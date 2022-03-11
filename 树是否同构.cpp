#include<Stdio.h>
#include<stdlib.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree],T2[MaxTree];
Tree BuildTree(struct TreeNode T[])
{
	int N;
	int Root;
	int check[100];
	char cl,cr;
	scanf("%d\n",&N);
	if(N)
	{
		for(int i =0;i<N;i++)
			check[i]=0;
		for(int i =0;i<N;i++)
		{
			scanf("%c %c %c\n",&T[i].Element,&cl,&cr);
			if(cl!='-')
			{
				T[i].Left=cl-'0';
				check[T[i].Left]=1;
			}
			else
				T[i].Left=-1;
			if(cr!+'-')
			{
				T[i].Right=cr-'0';
				check[T[i].Right]=1;
			}
			else
				T[i].Right=-1;
		}
		for(int i=0;i<N;i++)
		{
			if(check[i]==0)
				{
					Root=i;
					break;
				}
		}
	}
	return Root;
}
int IsSame(Tree R1,Tree R2)//R1 R2往下走这一圈是不是同构
{
	if(R1==-1&&R2==-1)
		return 1;
	else if(R1==-1&&R2!=-1)
		return 0;
	else if(R1!=-1&&R2==-1)
		return 0;
	else if(R1!=-1&&R2!=-1)
	{
		if(T1[R1].Element!=T2[R2].Element)//树头根节点不同则一定不同
			return 0;
		if(T1[R1].Left==-1&&T2[R2].Left==-1)
		{
			return IsSame(T1[R1].Right,T2[R2].Right);
		}
		if((T1[R1].Left != Null && T2[R2].Left != Null) && (T1[R1].Element != T2[R2].Element))
			return (isSame(T1[R1].Left,T2[R2].Left) && isSame(T1[R1].Right,T2[R2].Right));
		else
			return (isSame(T1[R1].Left,T2[R2].Right) && isSame(T1[R1].Right,T2[R2].Left));
	}

}
int main
{
	Tree R1,R2;
	R1=BuildTree(T1);
	R2=BuildTree(T2);
	if(IsSame(R1,R2))
		printf("Yes\n");
	else
		printf("No\n");
}
