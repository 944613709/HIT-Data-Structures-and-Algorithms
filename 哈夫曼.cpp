#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
	char Data;
	float Weight;
	int lchild;
	int rchild;
	int parent;
}Node;
void selectmin(Node HT[],int k,int &s1,int &s2)//从k之前找
{
	int min=99999;
	int temp;
	for(int i=0;i<k;i++)//从k之前找
	{
		if(-1==HT[i].parent&&HT[i].Weight<min)
		{
			min=HT[i].Weight;
			temp=i;
		}
	}
	s1=temp;
	
	min=99999;
	temp=0;
	for(int i=0;i<k;i++)//从k之前找
	{
		if(-1==HT[i].parent&&HT[i].Weight<min&&s1!=i)
		{
			min=HT[i].Weight;
			temp=i;
		}
	}
	s2=temp;
}
void Creat(Node HT[],int &n)
{
	int m;
	n=4;
	m=2*n-1;
	HT[0].Weight = 2;HT[0].lchild = -1;HT[0].rchild = -1;
	HT[1].Weight = 3;HT[1].lchild = -1;HT[1].rchild = -1;
	HT[2].Weight = 4;HT[2].lchild = -1;HT[2].rchild = -1;
	HT[3].Weight = 5;HT[3].lchild = -1;HT[3].rchild = -1;
	HT[0].Data = 'A';
	HT[1].Data = 'B';
	HT[2].Data = 'C';
	HT[3].Data = 'D';
	for(int i=0;i<m;i++)//有了权值后，初始化
	{
		HT[i].lchild=-1;
		HT[i].rchild=-1;
		HT[i].parent=-1;
	}
	for(int i=n;i<m;i++)
	{
		int s1=0;
		int s2=0;
		selectmin(HT,i,s1,s2);
		HT[i].Weight=HT[s1].Weight+HT[s2].Weight;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[s1].parent=i;
		HT[s2].parent=i;
	}
}
void BianMa(Node HT[],char* huffmancode[],int n)
{
	char temp[n];
	int start,pos,parent;
	temp[n-1] = '\0';
	for(int i=0;i<n;i++)//n个叶子
	{
		start = n-1;
		pos = i;
		parent = HT[i].parent;
		while(-1!=parent)//将所有线
		{
		if(i==HT[parent].lchild)
			temp[--start]='0';
		else
			temp[--start]='1';
		pos = parent;
		parent = HT[parent].parent;
		}
		huffmancode[i] = new char[n-start];
		strcpy(huffmancode[i],&temp[start]);
	}
}
void Show(Node HT[],int n,char* huffmancode[])
{
	int m = 2*n-1;
	for(int i=0;i<m;i++)
	{
		cout<<i<<" "<<HT[i].Data<<" "<<HT[i].Weight<<" "<<HT[i].lchild<<" "<<HT[i].rchild<<endl;
		if(-1==HT[i].lchild)
			cout<<"Code:"<<huffmancode[i]<<endl;
	}
}
int main()
{
    Node HT[100];
    char *huffmancode[100];
    int n;
    Creat(HT,n);
    BianMa(HT,huffmancode,n);
    Show(HT,n,huffmancode);
}
