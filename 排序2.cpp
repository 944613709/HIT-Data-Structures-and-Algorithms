void InsertSort(int A[],int n)
{//��A[2]��ʼ��a[n]��ǰ���룬A[1]Ĭ���Ѿ����� 
	for(int i=2;i<=n;i++)
	{//�Ե�a[i]ȥ���� 
		if(A[i]<A[i-1])//a[i]��ǰһ��С����ֱ�Ӳ���β�� 
		{
			A[0] = A[i]; //�ڱ�ֱ�ӵ���Ҫ��������ֵ 
			for(int j=i-1;A[j]>A[0];j--)
			{
				A[j+1]	=	A[j];//���� 
			}
				A[j+1] = A[0];
			}
			//���ֱ��С��ǰ���Ͳ�Ҫ����for�� 
		//����պ��������ý���if��for 
	}
}
void InsertSort()
{
	for(int i =2;i<=n;i++)
	{
		if(A[i]<A[i-1])
		{
			A[0]=A[i];//�����ձ� 
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
