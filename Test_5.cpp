#include <stdio.h>
#include<stdlib.h>
#include <math.h>
void main()
{
    int t,q=1;
    double x,term,factorial=1.0,sum2=1,sxm,sum1=0;
    printf("请输入cos的值：");
    scanf("%lf",&x);
    for(t=2;;t++)
    {
        factorial=factorial*t;//控制阶乘
        if(t%2==0)
            //因为是每偶次方，所以这里进行判断，可以同时控制阶乘和q的值
        {
            sum1=sum2;
            q=q*(-1);
            sxm=fabs(pow(x,t));//取绝对值后的x次方
            term=sxm/factorial;
            sum2=q*term+sum2;
        }
        if(fabs(sum2-sum1)<=1e-5)//定义前后两个数，控制输出精度
            break;
    }
    printf("cosx=%lf",sum2);
}
