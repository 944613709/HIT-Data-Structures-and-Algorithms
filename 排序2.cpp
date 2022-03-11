void InsertSort(int A[],int n)
{//从A[2]开始到a[n]往前插入，A[1]默认已经有序 
	for(int i=2;i<=n;i++)
	{//对第a[i]去插入 
		if(A[i]<A[i-1])//a[i]比前一个小不能直接插在尾巴 
		{
			A[0] = A[i]; //哨兵直接等于要插入的这个值 
			for(int j=i-1;A[j]>A[0];j--)
			{
				A[j+1]	=	A[j];//后移 
			}
				A[j+1] = A[0];
			}
			//如果直接小于前驱就不要进入for了 
		//如果刚好有序则不用进入if的for 
	}
}
void InsertSort()
{
	for(int i =2;i<=n;i++)
	{
		if(A[i]<A[i-1])
		{
			A[0]=A[i];//设置烧饼 
			for(int j=i-1;A[j]>A[0];j--)
				A[j+1] = A[j];
			A[j+1] = A[0];
		}
	}
}

void InsertSort
{
	for(int i=2;i<=n;i++)
	{
		if(A[i]<A[i-1])
		{
			A[0] = A[i];
			for(int j=i-1;A[j]>A[0];j--)
				A[j+1] = A[j];//
			A[j+1] = a[0];
		}
	}
}

void selectSort()
	for(int i=0;i<n-1;i++)
	{
		int min = i;
		for(j=i+1;j<n;j++)
			if(A[min]>A[j])
				min  = j;
		if(min!=i)
			swap(A[i],A[min]); 
	}
