#include<iostream>
#include<malloc.h>
#define null -1
using namespace std;
struct TreeNode{
	char data;    // ��ֵ 
	int left;   // ���������±� 
	int right;  // ���������±� 
}T1[100];
// ���ظ���� 
int create(struct TreeNode T[]){
	int n;
	int root = 0;
	char left,right;
	cin>>n;
	if(!n)
		return null;
	for(int i=0;i<n;i++){
		cin>>T[i].data>>left>>right;
		if(left=='#')
			T[i].left = null;
		else{
			T[i].left = left-'0';
			root -= T[i].left;
		}
		if(right=='#')
			T[i].right = null;
		else{
			T[i].right = right-'0';
			root -= T[i].right;
		}
		// 0 �ۼӵ� n-1 
		root +=i;	
	}
	return root;
}

