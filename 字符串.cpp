#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	char ch[9999];
	int length;
}String;
void StrInit(String* S)
{
	S->length=0;
}
void InStr(String* S,char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		S->ch[i]=str[i];
		S->length++;
	}
}
int main()
{
	String* S=(String*)malloc(sizeof(String));
	StrInit(S);
	char str[999];
	gets(str);
	InStr(S,str);
	int i=0;
	while(S->length!=0)
	{
		printf("%c",S->ch[i]);
		i++;
		S->length--;
	}
}
