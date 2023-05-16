#include<stdio.h>
#include<stdlib.h>
// ����ʽ��� ���
// ���ݽṹ���
typedef struct PolyNode *Polynomial;
struct PolyNode
{
    int coef;
    int expon;
    Polynomial link;
};

Polynomial ReadPoly();
void Attach(int c, int e, Polynomial* pRear);
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Mult(Polynomial P1, Polynomial P2);
void PrintPoly(Polynomial P);
int Compare(int a, int b);

// �����ܴ
int main()
{
    Polynomial P1, P2, PP, PS;

    P1 = ReadPoly();
    P2 = ReadPoly();
    PP = Mult(P1, P2);
    PrintPoly(PP);
    PS = Add(P1, P2);
    PrintPoly(PS);

    return 0;
}

// ��ζ������ʽ

Polynomial ReadPoly()
{
    Polynomial p, rear, t;
    int c, e, n;

    scanf("%d", &n);
    p = (Polynomial)malloc(sizeof(Polynomial));
    p->link = NULL;
    rear = p;
    while (n--)
    {
        scanf("%d %d", &c, &e);
        Attach(c, e, &rear);//����ǰ������������ʽβ��
    }
    t = p;
    p = p->link;
    free(t);
    return p;
}

void Attach(int c, int e, Polynomial* pRear)
{
    Polynomial P;

    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c; // ���½�㸳ֵ
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P; // �޸�pRear��ֵ
}

int Compare(int a, int b)
{
    if (a > b)    return 1;
    else if (a < b)   return -1;
    else    return 0;
}

// ����ʽ���
Polynomial Add(Polynomial P1, Polynomial P2)
{
    Polynomial P, Rear, t, t1, t2;
    t1 = P1; t2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    while (t1 && t2)
    {
        switch (Compare(t1->expon, t2->expon))
        {
        case 1:
            Attach(t1->coef, t1->expon, &Rear);
            t1 = t1->link;
            break;
        case -1:
            Attach(t2->coef, t2->expon, &Rear);
            t2 = t2->link;
            break;
        case 0:
            if (t1->coef + t2->coef)   Attach(t1->coef + t2->coef, t1->expon, &Rear);
            t1 = t1->link;
            t2 = t2->link;
            break;
        }
    }
    //ע��ϸ�ģ���Ҫ�ѱ���д��ǰ���Ǹ�����ȥ��
    for (; t1; t1 = t1->link) Attach(t1->coef, t1->expon, &Rear);
    for (; t2; t2 = t2->link) Attach(t2->coef, t2->expon, &Rear);
    Rear->link = NULL;
    t = P;
    P = P->link;
    free(t);
    return P;
}

// ����ʽ���
Polynomial Mult(Polynomial P1,Polynomial P2)
{
	Polynomial t1,t2,P,Rear,t;
	int c,e;
	t1=P1;
	if(!P1||!P2)
		return NULL;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link=NULL;
	while(t1)
	{
		t2=P2;
		Rear=P;
		while(t2)
		{
			e=t1->expon+t2->expon;
			c=t1->coef*t2->coef;
			while(Rear->link&&Rear->link->expon>e)
				Rear=Rear->link;
			if(Rear->link&&Rear->link->expon==e)
			{
				if(c+Rear->link->coef!=0)
					Rear->link->coef += c;
				else
					{
						t=Rear->link;
						Rear->link=Rear->link->link;
						free(t);
					}
			}
			else
			{
				t=(Polynomial)malloc(sizeof(struct PolyNode));
				t->coef=c;
				t->expon=e;
				t->link=Rear->link;
				Rear->link=t;
				Rear=t;
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

// ��ν�����ʽ���
void PrintPoly(Polynomial P)
{
    int flag = 0;   // �������������ʽ��
    if (!P)
    {
        printf("0 0\n");
        return;
    }

    while (P)
    {
        if (flag==0)   flag = 1;
        else    printf(" ");
        printf("%d %d", P->coef, P->expon);
        P = P->link;
    }
    printf("\n");
}

