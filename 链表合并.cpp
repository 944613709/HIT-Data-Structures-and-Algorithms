#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	list<int> l1;
	list<int> l2;
	stack<int> s;
	do
	{
		cin>>a;
		if(a!=-1)
		l1.push_back(a);
		else
		{
			break;
		}
	}while(1);
	a=0;
	do
	{
		cin>>a;
		if(a!=-1)
		l2.push_back(a);
		else
		{
			break;
		}
	}while(1);
	list<int>::iterator it;
	list<int>::iterator it2;
	list<int>::iterator it3;
	it=l1.begin();
	while(l1.size()!=0)//l1Ã»ÓĞ-1  l1²å½øl2 
	{
		it2=++it;
		it3=--it;
		if(*it>=*(it2)&&*it<=*(it3))
		{
			l1.insert(++it);
		}
		else
			it++;
	} 
}
