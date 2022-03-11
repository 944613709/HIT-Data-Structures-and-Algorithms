#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

#define ElemType int
struct celltype
{
    ElemType data1;
    ElemType data2;
    celltype *next;
};
typedef celltype *LIST;
typedef celltype *position;


void Print(LIST L)
{
    position p;
    p = L;
    while(p->next!=NULL)
    {
        printf("[ %d %d ] ",p->data1,p->data2);
        p = p->next;
    }
    printf("[ %d %d ]\n",p->data1,p->data2);
}

LIST sor(LIST L)
{
    position p,q;
    int t;
    for(p = L->next; p!=NULL; p = p->next)
    {
        for(q = p->next; q!=NULL; q = q->next)
        {
            if(p->data2<q->data2)
            {
                t = q->data1;
                q->data1 = p->data1;
                p->data1 = t;
                t = q->data2;
                q->data2 = p->data2;
                p->data2 = t;
            }
        }
    }
    return L;
}

int main()
{

    int x,y;
    int T;
    scanf("%d",&T);
    while(T>0)
    {
        LIST LI0,LI2;
        LIST L0,L2;
        position l0,l2;
        LI0 = (LIST)malloc(sizeof(celltype));
        LI2 = (LIST)malloc(sizeof(celltype));
        L0 = (LIST)malloc(sizeof(celltype));
        L2 = (LIST)malloc(sizeof(celltype));
        LI0->next = NULL;
        LI2->next = NULL;
        l0 = LI0;
        l2 = LI2;
        scanf("%d%d",&x,&y);
        while(y>=0)
        {
            position p;
            p = (LIST)malloc(sizeof(celltype));
            p->next = NULL;
            p->data1 = x;
            p->data2 = y;
            l0->next = p;
            l0 = l0->next;
            scanf("%d%d",&x,&y);
        }
        scanf("%d%d",&x,&y);
        while(y>=0)
        {
            position q;
            q = (LIST)malloc(sizeof(celltype));
            q->next = NULL;
            q->data1 = x;
            q->data2 = y;
            l2->next = q;
            l2 = l2->next;
            scanf("%d%d",&x,&y);
        }

        L0=sor(LI0);
        L2=sor(LI2);
        LIST ANS;
        LIST m,n,v;
        position b;
        int j;
        m = L0->next;
        n = L2->next;
        ANS = (LIST)malloc(sizeof(celltype));
        b = ANS;
        while((m!=NULL)&&(n!=NULL))
        {
            if(m->data2==n->data2)
            {
                j = m->data1+n->data1;
                if(j!=0)
                {
                    v = (LIST)malloc(sizeof(celltype));
                    v->data2 = m->data2;
                    v->data1 = j;
                    b->next = v;
                    b = v;
                }
                m = m->next;
                n = n->next;
            }
            else if(m->data2>n->data2)
            {
                v = (LIST)malloc(sizeof(celltype));
                v->data1 = m->data1;
                v->data2 = m->data2;
                b->next = v;
                b = v;
                m=m->next;
            }
            else
            {
                v = (LIST)malloc(sizeof(celltype));
                v->data1 = n->data1;
                v->data2 = n->data2;
                b->next = v;
                b = v;
                n=n->next;
            }


        }
        while(m!=NULL)
        {
            v = (LIST)malloc(sizeof(celltype));
            v->data1 = m->data1;
            v->data2 = m->data2;
            b->next = v;
            b = v;
            m=m->next;
        }
        while(n!=NULL)
        {
            v = (LIST)malloc(sizeof(celltype));
            v->data1 = n->data1;
            v->data2 = n->data2;
            b->next = v;
            b = v;
            n=n->next;
        }
        b->next = NULL;
        v = ANS;
        ANS = ANS->next;
        delete v;
        Print(ANS);
        T-=1;
    }
    return 0;
}
