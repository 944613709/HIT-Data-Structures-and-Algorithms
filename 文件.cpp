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
		printf("�ļ���ʧ��");
		exit(0);
	}
	fprintf(p,"��ǰ���Ϊ:"); 
    int flag = 0;   // �������������ʽ��
    if (!P)
    {
        printf("0 ##END##\n");
        fprintf(p,"0 ##END##\n");
        return;
    }

    while (P)
    {
		if(P->coef>0&&flag==1)//flag==1 �ǿ�ͷ 
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
	P=(Polynomial)malloc(sizeof(PolyNode));//�̶���ʽ 
	P->link=NULL;
	Rear=P;//�����洢 
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
