#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define ElemType int
struct celltype
{
    ElemType data;
    celltype *next;
};
typedef celltype *LIST;
typedef celltype *position;
void Insert(ElemType x,int pos,LIST L)
{
    position q,p;
    q = (LIST)malloc(sizeof(celltype));
    p = L;
    int i = 0;
    while(p->next!=NULL)
    {
        if((i+1)==pos)
        {
            q->data = x;
            q->next = p->next;
            p->next = q;
            break;
        }
        p = p->next;
        i++;
    }
}
void Delete (int pos,LIST L)
{
    position q,p;
    q = L;
    int i = 0;
    while(q->next!=NULL)
    {
        if((i+1)==pos)
        {
            p = q->next;
            q->next = q->next->next;
            delete p;
            break;
        }
        q = q->next;
        i++;
    }
}
int Locate(ElemType x,LIST L)
{
    position p;
    p = L->next;
    int i=1;
    while(p!=NULL)
    {
        if(p->data == x)
            return i;
        else
        {
            p = p->next;
            i++;
        }
    }
    return 0;
}
int ListLength(LIST L)
{
    position p;
    p = L;
    int sum = 0;
    while (p->next!=NULL)
    {
        sum++;
        p = p->next;
    }
    return sum;
}
void Print(LIST L)
{
    position p;
    p = L->next;
    while(p->next!=NULL&&p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("%d\n",p->data);
}
LIST Reverse(LIST L)
{
    position p1 = L;
    position p2 = p1->next;
    position p3;
    while (p2!=NULL)
    {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    p2 = (LIST)malloc(sizeof(celltype));
    p2->next = p1;
    L->next->next = NULL;
    L = p2;
    return L;
}
LIST sor(LIST L)
{
    position p,q;
    int t;
    for(p = L->next; p!=NULL; p = p->next)
    {
        for(q = p->next; q!=NULL; q = q->next)
        {
            if(p->data>q->data)
            {
                t = q->data;
                q->data = p->data;
                p->data = t;
            }
        }
    }
    return L;
}
int main()
{

    int x;
    LIST L;
    position l,p;
    L = (LIST)malloc(sizeof(celltype));
    L->next = NULL;
    l = L;
    FILE* r = fopen("input.txt","r");
    while (fscanf(r,"%d",&x)!=EOF)
    {
        p = (LIST)malloc(sizeof(celltype));
        p->next = NULL;
        p->data = x;
        l->next = p;
        l = p;
    }
    sor(L);
    char s[10];
    scanf("%s",&s);
    while(strcmp(s,"OVER")!=0)
    {
        if(strcmp(s,"INSERT")==0)
        {
            int d;
            int q;
            scanf("%d %d",&d,&q);
            Insert(d,q,L);
        }
        else if(strcmp(s,"DELETE")==0)
        {
            int q;
            scanf("%d",&q);
            Delete(q,L);
        }
        else if(strcmp(s,"LOCATE")==0)
        {
            int d;
            int q;
            scanf("%d",&d);
            q = Locate(d,L);
            if(q!=0)printf("%d\n",q);
            else printf("NOT FOUND!\n");
        }
        else if(strcmp(s,"LISTLENGTH")==0)
        {
            int d;
            d = ListLength(L);
            printf("%d\n",d);
        }
        else if(strcmp(s,"REVERSE")==0)
        {
            L = Reverse(L);
        }
        else if(strcmp(s,"PRINT")==0)
        {
            Print(L);
        }
        scanf("%s",&s);
    }
    return 0;
}
