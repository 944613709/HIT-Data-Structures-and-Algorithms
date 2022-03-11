#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<io.h>
#include<windows.h>
int main()
{
	void Pop(STACK S)
	{
		if(Empty(S)==true)
			cout<<"empty";
		else 
			S.top=S.top-1;
	} 
	void Push(STACK &S,ElemType x)
	{
		if(S.top==max-1)
			cout<<"wrong";
		else
		{
			S.top=S.top+1;
			S.elements[S.top]=x;
		}
	}
}
