#include <bits/stdc++.h>
using namespace std;
typedef struct List
{
	int Data[100];
	int length;
}List;
void Creat(List* L)
{
	L->length=0;
}
void Add(List* L)
{
	L->length++;
	int Data;
	cin>>Data;//´Ó1¿ªÊ¼ 
	L->Data[L->length]=Data;
}
void Show(List* L)
{
	for(int i = 1;i<=L->length;i++)
	{
		cout<<L->Data[i]<<" ";
	}
}
int main()
{
	List* L = new List;
	Creat(L);
	Add(L);
	Add(L)
	Show(L);
}
