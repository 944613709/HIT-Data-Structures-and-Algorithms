#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
typedef struct Node{
    int Data;
    struct Node* Next;
} Node;
typedef Node MinStack;
typedef MinStack* STACK;
MinStack* minStackCreate() {
	STACK S;
	S=(STACK)malloc(sizeof(Node));
	S->Next=NULL;
	return S;
}

void minStackPush(MinStack* obj, int val) {
	STACK temp=(STACK)malloc(sizeof(Node));
	temp->Data=val;
	temp->Next=obj->Next;
	obj->Next=temp;
}

void minStackPop(MinStack* obj) {
	if(obj->Next!=NULL)
	{
		STACK temp;
		temp=obj->Next;
		obj->Next=obj->Next->Next;
		free(temp);
	}
}

int minStackTop(MinStack* obj) {
	if(obj->Next!=NULL)
	{
		return obj->Next->Data;
	}
	else
		return NULL;
}

int minStackGetMin(MinStack* obj) {
	int Min=99999;
	while(obj->Next!=NULL)
	{
		if(minStackTop(obj)<Min)
		{
			Min=minStackTop(obj);
		}
		minStackPop(obj);
	}
	return Min;
}

void minStackFree(MinStack* obj) {
	obj->Next=NULL;
}
int main()
{
	STACK S=minStackCreate();
	minStackPush(S,-1);
	minStackPush(S,-6);
	minStackPop(S);
	minStackPop(S);
	minStackPush(S,3);
	printf("%d",minStackGetMin(S));
}
