AB#include<bits/stdc++.h>
#define MAX 99
using namespace std;
int main()
{
	char ch[MAX];
	cin>>ch;
	for(int i=0;ch[i]!='\0';i++)
	{
		cout<<ch[i]-'A'+1<<endl;
	}
}
