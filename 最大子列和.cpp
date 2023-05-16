#include<stdio.h>
#include<stdlib.h>
int Max(int a[],int K)
{
	int sum=0;
	int max=0;
	for(int i=1;i<=K;i++)
	{
		sum=0;
		for(int j=i;j<=K;j++)
		{
            sum=sum+a[j];
			if(max<sum)
				max=sum;
		}
	}
	return max;
}
int main()
{
	int a[100001];
	int K;
	scanf("%d",&K);
	for(int i=1;i<=K;i++)
		scanf("%d",&a[i]);
	int sum;
	sum=Max(a,K);
	printf("%d",sum);
}
