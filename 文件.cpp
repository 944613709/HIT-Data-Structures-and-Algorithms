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
Polynomial ReadPoly();
void Attach(float c, int e, Polynomial* pRear);
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Sub(Polynomial P1, Polynomial P2);
Polynomial Mult(Polynomial P1, Polynomial P2);
void PrintPoly(Polynomial P);
void Calulate(Polynomial P);
void Divide(Polynomial P1, Polynomial P2);
Polynomial Read(FILE *ff);
int main()
{
	Polynomial P;
	FILE *fp1=NULL;
	fp1= fopen("In1.txt","r");
	P=Read(fp1);
	fclose(fp1);

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
    int flag = 0;   // 辅助调整输出格式用
    if (!P)
    {
        printf("0 ##END##\n");
        fprintf(p,"0 ##END##\n");
        return;
    }

    while (P)
    {
		if(P->coef>0&&flag==1)//flag==1 非开头 
			{
			printf("+");
			fprintf(p,"+");	
			}
        printf("%.2fx^%d ", (P->coef), P->expon);
        fprintf(p,"%.2fx^%d ", (P->coef), P->expon);
        P = P->link;
        if(flag==0)
        	flag=1;
    }
    printf("\n");
    fprintf(p,"\n");
    fclose(p);
}
void Attach(float c, int e, Polynomial* pRear)
{
	Polynomial t;
	t=(Polynomial)malloc(sizeof(PolyNode));
	t->coef=c;
	t->expon=e;
	t->link=NULL;
	(*pRear)->link=t;
	*pRear=t;
}
Polynomial Read(FILE *ff)
{
	int exp;
	float coe;
	char ch;
	Polynomial P,Rear,t;
	P=(Polynomial)malloc(sizeof(PolyNode));//商多项式 
	P->link=NULL;
	Rear=P;//用来存储 
    ch = fgetc(ff);
    if(ch!='-')
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
	while(fscanf(ff,"%c%fx^%d",&ch,&coe,&exp)!=EOF)
	{
		if(ch=='+')
		{
			Attach(coe,exp,&Rear);
		}
		if(ch=='-')
		{
			Attach((-coe),exp,&Rear);
		}
	}
	t=P;
	P=P->link;
	free(t);
	PrintPoly(P);
	return P;
}
