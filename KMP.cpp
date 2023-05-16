#include<stdio.h>
#include<stdlib.h>
#include<stringh.h> 
int KMP(char S[],char T[])
{
	int i=0;
	int j=0;
	int lenS=strlen(S);
	int lenT=strlen(T);
	while(i<lenS&&j<lenT)
	{
		if(j==-1||S[i]==T[j])
		{
			i++;
			j++;
		}
		else
			j=next[j];
	}
		if(j==lenT)
		{
			return (i-j);
		}
		else
			return -1;
}

void getNext(char *T,int *next)
{
	int j=-1;
	int i=0;
	next[0]=-1;
	while(i<T.len)
	{
		if(j==-1||T[i]==T[j])
		{
			i++;
			j++;
			next[i]=j;
		}
		else
			j=next[j];
	}
}
int main()
{
	char S[100];
	char T[100];
	gets(S);
	gets(T);
}
