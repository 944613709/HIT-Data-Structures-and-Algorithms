#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct PolyNode *Polynomial;
struct PolyNode
{
    float coef;
    int expon;
    Polynomial link;
}PolyNode;
Polynomial ReadPoly(FILE *ff);
void Attach(float c, int e, Polynomial* pRear);
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Sub(Polynomial P1, Polynomial P2);
Polynomial Mult(Polynomial P1, Polynomial P2);
void PrintPoly(Polynomial P);
void Calulate(Polynomial P,float x);
void Divide(Polynomial P1, Polynomial P2);
void Sort(Polynomial P);
int main()
{
	Polynomial P1,P2,P;
	FILE *fp1=NULL;
	FILE *fp2=NULL;
	fp1= fopen("In1.txt","r");
	fp2= fopen("In2.txt","r");
	printf("                        -------------------------------------------------------------------\n");
    printf("                        |==================       一元多项式的运算       =================|\n");
    printf("                        -------------------------------------------------------------------\n\n");
    printf("                        |==================          1.相加（+）         =================|\n");
    printf("                        |==================          2.相减（-）         =================|\n");
    printf("                        |==================          3.相乘（*）         =================|\n");
    printf("                        |==================          4.相除（/)         =================|\n");
    printf("                        |==================          5.计算Xo（=）         =================|\n");
    int n;
    printf("请输入选择：");
    scanf("%d",&n);
    switch (n)
    {
    case 3:
    		P1 = ReadPoly(fp1);
			P2 = ReadPoly(fp2);
			P=Mult(P1,P2);
    		printf("f1*f2="); 
			PrintPoly(P);
			break;
	case 1:
		    P1 = ReadPoly(fp1);
			P2 = ReadPoly(fp2);
			P=Add(P1,P2);
			printf("f1+f2="); 
			PrintPoly(P);
			break;
	case 4:
		    P1 = ReadPoly(fp1);
			P2 = ReadPoly(fp2);
			Divide(P1,P2);//除法 
			break;
	case 2:
		    P1 = ReadPoly(fp1);
			P2 = ReadPoly(fp2);
			P=Sub(P1,P2);
			printf("f1-f2="); 
			PrintPoly(P);
			break;
	case 5:
			float x;
			printf("请输入xo:");
			scanf("%f",&x);
			P1 = ReadPoly(fp1);
			P2 = ReadPoly(fp2);
			printf("f1(xo)=");
			Calulate(P1,x);
			printf("f2(xo)=");
			Calulate(P2,x);
	}
	fclose(fp1);
	fclose(fp2);
}
void PrintPoly(Polynomial P)
{
	FILE *p;
	if((p=fopen("Out.txt","a"))==NULL)
	{
		printf("文件打开失败");
		exit(0);
	}
	fprintf(p,"当前结果为:"); 
    int flag = 0;   // 判断是否是开头 开头不需要+ 
    int Emptyflag = 1 ;//标记是否最终结果是否一个没输出，如果是1->Empty则输出0x^0 
    if (!P)
    {
        printf("NULL");//当结果是NULL，P就是NULL,用以观测ReadPoly和MUlt之类函数返回值是否会出现P==NULL 
        fprintf(p,"NULL");
        return;
    }
    while (P)
    {
    	if(P->coef==0) //如果真的有系数为0的没删干净，对于0x^2先直接跳过,防止后续程序对于0的前面符号不适应，暂时不输出 
    	{
    		P = P->link;
    		continue;
		}
		if(P->coef>0&&flag==1)//flag==1 不是开头则就要考虑+符号 
			{
			printf("+");
			fprintf(p,"+");	
			}
        printf("%.2fx^%d ", (P->coef), P->expon);
        fprintf(p,"%.2fx^%d ", (P->coef), P->expon);
        Emptyflag=0;//输出有非0数据 
        P = P->link;
        if(flag==0)
        	flag=1;
    }
    if(Emptyflag==1)//如果P结果全是 0x^2+0x^1则只输出为0x^0 
    {
    	printf("0.00x^0");//结果为0总得输出一个 
        fprintf(p,"0.00x^0");
	}
    printf("\n");
    fprintf(p,"\n");
    fclose(p);
}
Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial P,t1,t2,t,Rear;
	if(!P1||!P2)
		return NULL;//防止P1或P2万一为NULL，报错提示 ，以便于后续修改错误代码 
	t1=P1;
	t2=P2;
	float c;
	int e;
	P=(Polynomial)malloc(sizeof(PolyNode));
	P->link=NULL;
	while(t1)//固定P1中的某个，依次遍历P2每一个 
	{
		t2=P2;
		Rear=P;
		while(t2)//t2==NULL 停下 
		{
			c=t1->coef * t2->coef;
			e=t1->expon + t2->expon;
			while(Rear->link!=NULL&&Rear->link->expon > e)//利用降幂顺序 来while循环找到插入的对应位置 
				Rear=Rear->link;
			if(Rear->link==NULL||Rear->link->expon < e)//情况1在结尾插入（Rear->link==NULL） 情况1与2都可以归为插入 
			{                                           //情况2(Rear->link->expon)在中间插入
				t=(Polynomial)malloc(sizeof(PolyNode));
				t->coef=c;
				t->expon=e;
				t->link=Rear->link;
				Rear->link=t;
			}
			else if(Rear->link->expon == e)//情况3发现插入的可以合并同类项 
			{
				if(c + Rear->link->coef !=0)//合并之后不是0 
				{
					Rear->link->coef += c;
				}
				else if (c + Rear->link->coef ==0)//合并之后为0直接删除结点 
				{
					Polynomial temp;
					temp=Rear->link;
					Rear->link=Rear->link->link;
					free(temp);
				}
			}
			t2=t2->link;
		}
		t1=t1->link;
	}
	t=P;
	P=P->link;
	free(t);
	return P;
}
Polynomial Add(Polynomial P1, Polynomial P2)
{
	Polynomial P,Rear,t;
	P=(Polynomial)malloc(sizeof(PolyNode));
	P->link=NULL;
	Rear=P;
	
	while(P1&&P2)//从两个多项式依照降幂顺序，找指数高的开始 
	{
		if((P1->expon) > (P2->expon) )
		{
			Attach(P1->coef,P1->expon,&Rear);
			P1=P1->link;
		}
		else if ((P1->expon) < (P2->expon))
		{
			Attach(P2->coef,P2->expon,&Rear);
			P2=P2->link;
		}
		else
		{	
			if(P1->coef + P2->coef!=0)
			{
			Attach(P1->coef + P2->coef,P2->expon,&Rear);
			P1=P1->link;
			P2=P2->link;
			}
			else//coef = = 0
			{
			P1=P1->link;
			P2=P2->link;
			}//一旦系数为0都不存入结点 
		}
	}
	while(P1)
		{Attach(P1->coef,P1->expon,&Rear);
			P1=P1->link;
		}
	while(P2)
		{Attach(P2->coef,P2->expon,&Rear);
			P2=P2->link;
		}
	t=P;
	P=P->link;
	free(t);
	if(!P)
	{
		P=(Polynomial)malloc(sizeof(PolyNode));
		P->link=NULL;
		P->coef =0;
		P->expon =0;
	}//当结果为0时候防止P==NULL,不妨将新建结点，数据为0x^0
	return P;
}
Polynomial Sub(Polynomial P1, Polynomial P2) //P1-P2    
{
	Polynomial P,Rear,t;
	P=(Polynomial)malloc(sizeof(PolyNode));
	P->link=NULL;
	Rear=P;
	while(P1&&P2)
	{
		if((P1->expon) > (P2->expon) )//按照降幂这么放入P 
		{
			Attach(P1->coef,P1->expon,&Rear);
			P1=P1->link;
		}
		else if ((P1->expon) < (P2->expon))
		{
			Attach(-(P2->coef),P2->expon,&Rear);
			P2=P2->link;
		}
		else if ((P1->expon) == (P2->expon))
		{	
			if((P1->coef) -(P2->coef) == 0)
			{
				P1=P1->link;
				P2=P2->link;
			}
			else
			{
				Attach((P1->coef)-(P2->coef),P1->expon,&Rear);
				P1=P1->link;
				P2=P2->link;
			}
		}
	}
	while(P1)
		{Attach(P1->coef,P1->expon,&Rear);
			P1=P1->link;
		}
	while(P2)
		{Attach(-(P2->coef),P2->expon,&Rear);
			P2=P2->link;
		}
	t=P;
	P=P->link;
	free(t);
	if(!P)
	{
		P=(Polynomial)malloc(sizeof(PolyNode));
		P->link=NULL;
		P->coef =0;
		P->expon =0;
	}//当结果为0时候防止P==NULL,不妨将新建结点，数据为0
	return P;
}

void Attach(float c, int e, Polynomial* pRear)
{
	Polynomial t;
	t=(Polynomial)malloc(sizeof(PolyNode));
	t->coef=c;
	t->expon=e;
	t->link=NULL;
	(*pRear)->link=t;//利用尾插法，当然要将尾结点指向更新，*pRear才能修改尾结点自己地址 
	*pRear=t;
}
Polynomial ReadPoly(FILE *ff)
{
	int exp;
	float coe;
	char ch;
	Polynomial P,Rear,t,Head;
	P=(Polynomial)malloc(sizeof(PolyNode));
	P->link=NULL;
	Rear=P;
    ch = fgetc(ff);
    if(ch==EOF)//看txt文本是否为空 
    {
     	printf("ERROR:  In.txt输入为空");
		exit(0); 
	}
    if(ch!='-')//3x^2+3x^1这种首项第一个不会带有+，特殊情况 
    {
    	rewind(ff);
    	fscanf(ff,"%fx^%d",&coe,&exp);
    	Attach(coe,exp,&Rear);
	}
	else//ch='-'
	{
		fscanf(ff,"%fx^%d",&coe,&exp);
		Attach((-coe),exp,&Rear);
	}
	while(fscanf(ff,"%c%fx^%d",&ch,&coe,&exp)!=EOF)//开始按照降幂插入 
	{
		if(ch=='-')//如果是符号要调整coe 
			coe=-coe;
			
		Head=P;
		while(Head->link!=NULL&&Head->link->expon > exp ) //
			Head=Head->link;
		if(Head->link==NULL||Head->link->expon < exp)
			{
				t=(Polynomial)malloc(sizeof(PolyNode));
				t->coef=coe;
				t->expon=exp;
				t->link=Head->link;
				Head->link=t;
			}
		else if(Head->link->expon == exp)
			{
				if(coe + Head->link->coef !=0)
				{
					Head->link->coef += coe;
				}
				else if (coe + Head->link->coef ==0)
				{
					t=Head->link;
					Head->link=Head->link->link;
					free(t);
				}//对于0x^2这种数据直接删掉结点  
			}
	}
	t=P;
	P=P->link;
	free(t);
	printf("f(x)=");
	PrintPoly(P);
	return P;//若In.txt为空则输出0x^0 
}
void Calulate(Polynomial P,float x)
{
	FILE *p;
	if((p=fopen("Out.txt","a"))==NULL)
	{
		printf("文件打开失败");
		exit(0);
	}
	float sum;
	sum=0;
	while(P)
	{
		sum+=(P->coef)*pow(x,P->expon);
		P=P->link;
	}
	printf("%f",sum);
	fprintf(p,"代入Xo之后等于：%f",sum);
	fclose(p);
	printf("\n");
}
void Divide(Polynomial P1, Polynomial P2)//p1 / p2 
{
	Polynomial PS,t1,t2,RearS,Ptemp1,t;
	PS=(Polynomial)malloc(sizeof(PolyNode));//商多项式 
	PS->link=NULL;
	RearS=PS;//用来存储 
	t1=P1;
	t2=P2;
	if(P2->coef==0&&P2->expon==0)//当除数时0，数学公式不成立
		{
			printf("ERROR：P2不能为0");
			exit(0);
		}
	float newc; 
	int newe;
	while(1)//进入循环 
	{
		if(P2->expon==0)//特殊情况，当除数是常数（x是0次方）只需要出一次就能够得到，且余数多项式一定为0 
			{
			newe=t1->expon - P2->expon;//本次依次得到的商的一个项的指数 
			newc=t1->coef / P2->coef;//本次依次得到的商的一个项的系数
			Attach(newc,	newe, &RearS);//将当前项，加入到商多项式
			Ptemp1 = Mult(RearS,P2);//PP1*P2 = Ptemp，除法公式用到的 
	        Ptemp1 = Sub(t1,Ptemp1);//除法公式用到的 
	        t1=Ptemp1;//再次进行，当前短除法之后得到的余数多项式（不一定是最终的余数），成为新的t1，继续试探 
	        break;
			}
	    if(t1->expon < P2->expon)
		{
			//已经完成商多项式 余数多项式
			//t1就是最终余数多项式 
			break;//终止循环唯一条件 
		}
		else//需要继续除 
		{
			newe=t1->expon - P2->expon;//本次依次得到的商的一个项的指数 
			newc=t1->coef / P2->coef;//本次依次得到的商的一个项的系数
			Attach(newc,	newe, &RearS);//将当前项，加入到商多项式
			Ptemp1 = Mult(RearS,P2);//PP1*P2 = Ptemp
	        Ptemp1 = Sub(t1,Ptemp1);
	        t1=Ptemp1;//再次进行，当前短除法之后得到的余数多项式（不一定是最终的余数），成为新的t1，继续试探 
		}
	}
	t=PS;
	PS=PS->link;
	free(t);//删掉PS空白头结点 
	if(!PS)//对于0/9x = 0 ..9x   此时防止商为空 
	{
	PS=(Polynomial)malloc(sizeof(PolyNode));//商多项式 
	PS->link=NULL;
	PS->coef = 0;
	PS->expon = 0;
	}
	printf("余数多项式:");
	PrintPoly(t1);//开始输出余数多项式 
	printf("商多项式:");
	PrintPoly(PS);//已经完成输出商多项式 
}

