#include<bits/stdc++.h>
using namespace std;
int main()
{
	int A[15];
	for(int k=0;k<15;k++)
	{
		cin>>A[k];
	}//输入15个
	cout<<"要交换多少次"<<endl;
	int n;
	cin>>n;
	int temp;
	int i;
	int j;
	for(int k=0;k<n;k++)
	{
		cin>>i>>j;
		temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	 } //交换
	 for(int k=0;k<15;k++)
	{
		cout<<A[k]<<" ";
	} 
}
