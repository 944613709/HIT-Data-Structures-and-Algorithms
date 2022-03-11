#include<bits/stdc++.h>
using namespace std;
typedef struct {
	int x;
	int y;
} Coor;
void fun(int &a,int &b)
{
	int c=0;
	c=a;
	a=b;
	b=c;
}
int main()
{
	list<int> l;
	l.push_front(111);
	l.push_back(555);
	l.insert(l.begin(),2);
	
	cout<<l.front()<<endl;
	l.pop_front();
	cout<<l.front()<<endl;
	l.pop_front();
	cout<<l.front()<<endl;
	l.pop_front();
}
