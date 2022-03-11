#include<Stdio.h>
#include<math.h>
int main() 
{
	int count=0;
	int a[111];
	for(int n= 1; n<=100;n++) 
	{
		int b=n;
	while(b!=1)
	{
		if(b%2==0)
			{
				printf("%d/2=%d\n",b,b/2);
				b=b/2;
				count++;
			}
		else
			{
				printf("%d*3+1=%d\n",b,3*b+1);
			b=b*3+1;
				count++;
			}
	}
	a[n]=count;
	count=0;
	}
	int n =100;
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					int t;
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
	printf("\nmax=====%d",a[99]);
}
