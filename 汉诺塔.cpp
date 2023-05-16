#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<io.h>
#include<windows.h>
void Move(char A,char C)
{
	printf("%c->%c\n",A,C);
}
void Hanoi(int n ,char A,char B,char C)//A->C 
{
	if(n==1)
		Move(A,C);
	else
	{
		Hanoi(n-1,A,C,B);
		Move(A,C);
		Hanoi(n-1,B,A,C);
	}
}
int main()
{
	Hanoi(8,'A','B','C');
}
