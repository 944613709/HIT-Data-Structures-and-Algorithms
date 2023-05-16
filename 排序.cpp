#include<bits/stdc++.h>
using namespace std;
void QSort(int* arr,int left,int right);
void swap(int*a,int*b);
void heapSort(int R[],int n);
int Partition(int* A,int low,int high);
void InsertSort(int* A,int n);
void Sift(int R[],int low,int high);
int main()
{
	int arr[5];
	arr[0]=1;
	arr[1]=3;
	arr[2]=2;
	arr[3]=6;
	arr[4]=2;
	//int length = sizeof(arr)/sizeof(arr[0]);
	heapSort(arr,5);
	//InsertSort(arr,5);
	//QSort(arr,0,4);
	for(int i=0;i<5;i++)
	{
		cout<<"i="<<i<<",arr[i]=" <<arr[i]<<endl;
	}
 } 
 void BubbleSort(int* arr)
{
	int len = sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<len-1;i++)//i<len-1!!!!
		for(int j=0;j<len-1-i;j++)
			{
				if(arr[j]>arr[j+1])
				{
					int temp = arr[j];
					arr[j] = arr[J+1];
					arr[j+1] = temp;
				}
			}
}
void QSort(int* arr,int low,int high)
{
	if(low<high)
	{
		int pivotpos = Partition(arr,low,high);
		QSort(arr,low,pivotpos-1);
		QSort(arr,pivotpos+1,high);
	}
}
int Partition(int* A,int low,int high)
{
	int pivot = A[low];
	while(low<high)
	{
		while(low<high&&A[high]>=pivot)//先移动右侧的j , 只处理比它小的
			high--;
		A[low] = A[high];
		while(low<high&&A[low]<=pivot)
			low--;
		A[high]=A[low];
	}
	A[low] = pivot;
	return low;
}
void swap(int*a,int*b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}
void HeadSort(int n,LIST A)
{//从A[1]到A[n]
	int i;
	for(int i=n/2;i>=1;i--)
		PushDown(A,i,n);
		//起点i，终点n
	for(i=n;i>=2;i--)//进行n-1趟
	{
		swap(A[1],a[i]);
		PushDown(A,1,i-1);
	}
}
void PushDown(LIST R,int first,int last)
{
	int i=low;
	int j =2*i;
	int temp=R[i];
	while(j<=high)
	{
		if(j<high&&R[j]<R[j+1])
			j=j+1;
		if(R[i]<R[j])
		{
			swap(R[i],R[j]);
			i=j;
			j=2*i;
		}
		else if(R[i]<=R[j])
			break;
	}
}
void InsertSort(int* A,int n)
{
	int temp;
	for(int i = 1;i<n;i++)
	{
		temp = A[i];
		int j = i-1;
		while(j>0&&temp<A[j])
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1] = temp;
	}
}
void MergeSort(int A[],int low.int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		MergeSort(A,low,mid);
		MergeSort(A,mid+1,high);
		Merge(A,low,mid,high);//归并 
	}
}
void Merge(int A[],int low,int mid,int high)
{
	int B[999];
	int p1=low;
	int p2=mid+1;
	int p=0;
	while(p1<=mid&&p2<=high)
	{
		if(A[p1]<=A[p2])
		{
			B[p++]=A[p1++];
		}
		else
		{
			B[p++]=A[p2++];
		}
	}
	while(p1<=mid)
		B[p++]=A[p1++];
	while(p2<=high)
		B[p++]=A[p2++];
	for(int i=0;i<n;i++)
		A[low+i]=B[i];
}
