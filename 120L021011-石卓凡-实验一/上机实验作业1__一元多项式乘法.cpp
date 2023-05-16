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
    printf("                        |==================       һԪ����ʽ������       =================|\n");
    printf("                        -------------------------------------------------------------------\n\n");
    printf("                        |==================          1.��ӣ�+��         =================|\n");
    printf("                        |==================          2.�����-��         =================|\n");
    printf("                        |==================          3.��ˣ�*��         =================|\n");
    printf("                        |==================          4.�����/)         =================|\n");
    printf("                        |==================          5.����Xo��=��         =================|\n");
    int n;
    printf("������ѡ��");
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
			Divide(P1,P2);//���� 
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
			printf("������xo:");
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
		printf("�ļ���ʧ��");
		exit(0);
	}
	fprintf(p,"��ǰ���Ϊ:"); 
    int flag = 0;   // �ж��Ƿ��ǿ�ͷ ��ͷ����Ҫ+ 
    int Emptyflag = 1 ;//����Ƿ����ս���Ƿ�һ��û����������1->Empty�����0x^0 
    if (!P)
    {
        printf("NULL");//�������NULL��P����NULL,���Թ۲�ReadPoly��MUlt֮�ຯ������ֵ�Ƿ�����P==NULL 
        fprintf(p,"NULL");
        return;
    }
    while (P)
    {
    	if(P->coef==0) //��������ϵ��Ϊ0��ûɾ�ɾ�������0x^2��ֱ������,��ֹ�����������0��ǰ����Ų���Ӧ����ʱ����� 
    	{
    		P = P->link;
    		continue;
		}
		if(P->coef>0&&flag==1)//flag==1 ���ǿ�ͷ���Ҫ����+���� 
			{
			printf("+");
			fprintf(p,"+");	
			}
        printf("%.2fx^%d ", (P->coef), P->expon);
        fprintf(p,"%.2fx^%d ", (P->coef), P->expon);
        Emptyflag=0;//����з�0���� 
        P = P->link;
        if(flag==0)
        	flag=1;
    }
    if(Emptyflag==1)//���P���ȫ�� 0x^2+0x^1��ֻ���Ϊ0x^0 
    {
    	printf("0.00x^0");//���Ϊ0�ܵ����һ�� 
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
		return NULL;//��ֹP1��P2��һΪNULL��������ʾ ���Ա��ں����޸Ĵ������ 
	t1=P1;
	t2=P2;
	float c;
	int e;
	P=(Polynomial)malloc(sizeof(PolyNode));
	P->link=NULL;
	while(t1)//�̶�P1�е�ĳ�������α���P2ÿһ�� 
	{
		t2=P2;
		Rear=P;
		while(t2)//t2==NULL ͣ�� 
		{
			c=t1->coef * t2->coef;
			e=t1->expon + t2->expon;
			while(Rear->link!=NULL&&Rear->link->expon > e)//���ý���˳�� ��whileѭ���ҵ�����Ķ�Ӧλ�� 
				Rear=Rear->link;
			if(Rear->link==NULL||Rear->link->expon < e)//���1�ڽ�β���루Rear->link==NULL�� ���1��2�����Թ�Ϊ���� 
			{                                           //���2(Rear->link->expon)���м����
				t=(Polynomial)malloc(sizeof(PolyNode));
				t->coef=c;
				t->expon=e;
				t->link=Rear->link;
				Rear->link=t;
			}
			else if(Rear->link->expon == e)//���3���ֲ���Ŀ��Ժϲ�ͬ���� 
			{
				if(c + Rear->link->coef !=0)//�ϲ�֮����0 
				{
					Rear->link->coef += c;
				}
				else if (c + Rear->link->coef ==0)//�ϲ�֮��Ϊ0ֱ��ɾ����� 
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
	
	while(P1&&P2)//����������ʽ���ս���˳����ָ���ߵĿ�ʼ 
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
			}//һ��ϵ��Ϊ0���������� 
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
	}//�����Ϊ0ʱ���ֹP==NULL,�������½���㣬����Ϊ0x^0
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
		if((P1->expon) > (P2->expon) )//���ս�����ô����P 
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
	}//�����Ϊ0ʱ���ֹP==NULL,�������½���㣬����Ϊ0
	return P;
}

void Attach(float c, int e, Polynomial* pRear)
{
	Polynomial t;
	t=(Polynomial)malloc(sizeof(PolyNode));
	t->coef=c;
	t->expon=e;
	t->link=NULL;
	(*pRear)->link=t;//����β�巨����ȻҪ��β���ָ����£�*pRear�����޸�β����Լ���ַ 
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
    if(ch==EOF)//��txt�ı��Ƿ�Ϊ�� 
    {
     	printf("ERROR:  In.txt����Ϊ��");
		exit(0); 
	}
    if(ch!='-')//3x^2+3x^1���������һ���������+��������� 
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
	while(fscanf(ff,"%c%fx^%d",&ch,&coe,&exp)!=EOF)//��ʼ���ս��ݲ��� 
	{
		if(ch=='-')//����Ƿ���Ҫ����coe 
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
				}//����0x^2��������ֱ��ɾ�����  
			}
	}
	t=P;
	P=P->link;
	free(t);
	printf("f(x)=");
	PrintPoly(P);
	return P;//��In.txtΪ�������0x^0 
}
void Calulate(Polynomial P,float x)
{
	FILE *p;
	if((p=fopen("Out.txt","a"))==NULL)
	{
		printf("�ļ���ʧ��");
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
	fprintf(p,"����Xo֮����ڣ�%f",sum);
	fclose(p);
	printf("\n");
}
void Divide(Polynomial P1, Polynomial P2)//p1 / p2 
{
	Polynomial PS,t1,t2,RearS,Ptemp1,t;
	PS=(Polynomial)malloc(sizeof(PolyNode));//�̶���ʽ 
	PS->link=NULL;
	RearS=PS;//�����洢 
	t1=P1;
	t2=P2;
	if(P2->coef==0&&P2->expon==0)//������ʱ0����ѧ��ʽ������
		{
			printf("ERROR��P2����Ϊ0");
			exit(0);
		}
	float newc; 
	int newe;
	while(1)//����ѭ�� 
	{
		if(P2->expon==0)//����������������ǳ�����x��0�η���ֻ��Ҫ��һ�ξ��ܹ��õ�������������ʽһ��Ϊ0 
			{
			newe=t1->expon - P2->expon;//�������εõ����̵�һ�����ָ�� 
			newc=t1->coef / P2->coef;//�������εõ����̵�һ�����ϵ��
			Attach(newc,	newe, &RearS);//����ǰ����뵽�̶���ʽ
			Ptemp1 = Mult(RearS,P2);//PP1*P2 = Ptemp��������ʽ�õ��� 
	        Ptemp1 = Sub(t1,Ptemp1);//������ʽ�õ��� 
	        t1=Ptemp1;//�ٴν��У���ǰ�̳���֮��õ�����������ʽ����һ�������յ�����������Ϊ�µ�t1��������̽ 
	        break;
			}
	    if(t1->expon < P2->expon)
		{
			//�Ѿ�����̶���ʽ ��������ʽ
			//t1����������������ʽ 
			break;//��ֹѭ��Ψһ���� 
		}
		else//��Ҫ������ 
		{
			newe=t1->expon - P2->expon;//�������εõ����̵�һ�����ָ�� 
			newc=t1->coef / P2->coef;//�������εõ����̵�һ�����ϵ��
			Attach(newc,	newe, &RearS);//����ǰ����뵽�̶���ʽ
			Ptemp1 = Mult(RearS,P2);//PP1*P2 = Ptemp
	        Ptemp1 = Sub(t1,Ptemp1);
	        t1=Ptemp1;//�ٴν��У���ǰ�̳���֮��õ�����������ʽ����һ�������յ�����������Ϊ�µ�t1��������̽ 
		}
	}
	t=PS;
	PS=PS->link;
	free(t);//ɾ��PS�հ�ͷ��� 
	if(!PS)//����0/9x = 0 ..9x   ��ʱ��ֹ��Ϊ�� 
	{
	PS=(Polynomial)malloc(sizeof(PolyNode));//�̶���ʽ 
	PS->link=NULL;
	PS->coef = 0;
	PS->expon = 0;
	}
	printf("��������ʽ:");
	PrintPoly(t1);//��ʼ�����������ʽ 
	printf("�̶���ʽ:");
	PrintPoly(PS);//�Ѿ��������̶���ʽ 
}

