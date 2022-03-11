#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <time.h>

using namespace std;

struct records
{
    int key;
};
typedef struct celltype
{
    records data;
    struct celltype *lchild;
    struct celltype *rchild;
} BSTNode;
typedef BSTNode *BST;


struct LIST
{
    int  key;
};

void InsertList(LIST L[],records b[])
{
    int i = 0;
    while(b[i].key)
    {
        L[i+1].key = b[i].key;
        i++;
    }
}

void InsertBST(records R, BST &F)
{
    if(F == NULL)
    {
        F = new BSTNode;
        F->data.key = R.key;
        F->lchild = NULL;
        F->rchild = NULL;
    }
    else if(R.key < F->data.key)
        InsertBST(R,F->lchild);
    else if(R.key > F->data.key)
        InsertBST(R,F->rchild);

}

BST CreateBST(records b[])
{
    BST F = NULL;
    records k;
    k.key = b[0].key;
    int i = 1;
    while(k.key)
    {
        InsertBST(k,F);
        k.key = b[i].key;
        i++;
    }
    return F;
}

records deletemin(BST &F)
{
    records tmp;
    BST p;
    if(F->lchild == NULL)
    {
        p = F;
        tmp = F->data;
        F = F->rchild;
        delete p;
        return tmp;
    }
    else
        return(deletemin(F->lchild));
}

void DeleteB(int k,BST &F)
{
    if(F!=NULL)
    {
        if(k<F->data.key)
            DeleteB(k,F->lchild);
        else if(k>F->data.key)
            DeleteB(k,F->rchild);
        else
        {
            if(F->rchild == NULL)
                F = F->lchild;
            else if(F->lchild == NULL)
                F = F->rchild;
            else
                F->data = deletemin(F->rchild);
        }
    }
}

BST SearchBST(int k,BST F)
{
    BST p = F;
    if(p == NULL||k == p->data.key)
        return p;
    if(k < p->data.key)
        return (SearchBST(k,p->lchild));
    else
        return (SearchBST(k,p->rchild));
}

int sum = 1;
void BSTSUC(int k,BST F)
{
    BST p = F;
    if(p == NULL)
        sum = sum;
    else
    {
        if(k < p->data.key)
        {
            sum++;
            BSTSUC(k,p->lchild);
        }
        else if(k>p->data.key)
        {
            sum++;
            BSTSUC(k,p->rchild);
        }
        else if(p == NULL||k == p->data.key)
            sum = sum;
    }
}

void SortB(BST F)
{
    if(F!=NULL)
    {
        SortB(F->lchild);
        printf("%d ",F->data.key);
        SortB(F->rchild);
    }
}

int BinSearch(LIST F[],int low,int up,int k)
{
    if(low>up)
        return 0;
    else
    {
        int mid = (low+up)/2;
        if(k<F[mid].key)
        {
            return BinSearch(F,low,mid-1,k);
        }
        else if(k>F[mid].key)
        {
            return BinSearch(F,mid+1,up,k);
        }
        else
            return mid;

    }
}
void BINSUC(LIST F[],int low,int up,int k)
{
    if(low<=up)
    {
        int mid = (low+up)/2;
        if(k<F[mid].key)
        {
            sum++;
            BINSUC(F,low,mid-1,k);
        }
        else if(k>F[mid].key)
        {
            sum++;
            BINSUC(F,mid+1,up,k);
        }
        else
            sum = sum;

    }
    else
        sum = sum;
}
void random(records b[],int n)
{
    int index;
    int i;
    int tmp1,tmp2;
    srand(time(NULL));
    for(i = 0; i < n; i++)
    {
        index = rand()%(n-i)+i;
        if(index!=i)
        {
            tmp1 = b[i].key;
            b[i].key = b[index].key;
            b[index].key = tmp1;
        }
    }
}
int main()
{
    int a[2000];
    records A[2000];
    records C[2000];
    LIST L[2000];
    memset(a,0,sizeof(a));
    int i = 0;
    int j = 0;
    while(i<=2048)
    {
        if( i % 2 == 1)
        {
            a[j] = i;
            j++;
        }
        i++;
    }
    for (i = 0; i <1024; i++)
    {
        A[i].key = a[i];
    }
    for (i = 1024; i<2000; i++)
    {
        A[i].key = 0;
    }
    for (i = 0; i < 2000; i++)
    {
        C[i].key = A[i].key;
    }
    random(C,1024);
    BST F1,F2;
    F1 = CreateBST(A);
    F2 = CreateBST(C);
    InsertList(L,A);
    printf("1.打印原始数组\n");
    printf("2.打印打乱后的数组\n");
    printf("3.BST搜索功能\n");
    printf("4.BST插入功能\n");
    printf("5.BST删除功能\n");
    printf("6.BST排序功能\n");
    printf("7.折半查找功能\n");
    printf("8.打印BST1,BST2,折半查找的成功查找与失败查找的平均查找长度\n");
    printf("9.结束\n");
    int z;
    printf("输入执行号码：");
    scanf("%d",&z);
    while(z!=9)
    {
        if(z==1)
        {
            for (i = 0; i <1024; i++)
            {
                printf("%d ",A[i].key);
            }
            printf("\n");
        }
        else if(z==2)
        {
            for (i = 0; i <1024; i++)
            {
                printf("%d ",C[i].key);
            }
            printf("\n");
        }
        else if(z==3)
        {
            int k;
            printf("输入查找的数值（小于0时结束）：");
            scanf("%d",&k);
            while (k>=0)
            {
                BST p = SearchBST(k,F2);
                if(p!=NULL)
                {
                    printf("EXISTED!\n");
                }
                else
                {
                    printf("NOT FOUND!\n");
                }
                printf("输入查找的数值（小于0时结束）：");
                scanf("%d",&k);
            }
        }
        else if(z==4)
        {
            int k;
            printf("输入要插入的数值（小于0时结束）：");
            scanf("%d",&k);
            while (k>=0)
            {
                records R;
                R.key = k;
                InsertBST(R,F1);
                SortB(F1);
                printf("\n");
                printf("输入要插入的数值（小于0时结束）：");
                scanf("%d",&k);
            }
        }
        else if(z==5)
        {
            int k;
            printf("输入要删除的数值（小于0时结束）：");
            scanf("%d",&k);
            while (k>=0)
            {
                DeleteB(k,F2);
                SortB(F2);
                printf("\n");
                printf("输入要删除的数值（小于0时结束）：");
                scanf("%d",&k);
            }
        }
        else if(z==6)
        {
            SortB(F2);
        }

        else if(z==8)
        {
//BST查找成功的平均查找长度
            int ans1 = 0;
            int ans2 = 0;
            for (i = 1; i <= 2047; i+=2)
            {
                sum = 1;
                BSTSUC(i,F1);
                ans1+=sum;
            }
            ans1 = ans1/1024;
            for (i = 1; i <= 2047; i+=2)
            {
                sum = 1;
                BSTSUC(i,F2);
                ans2+=sum;
            }
            ans2 = ans2/1024;
            printf("BST1成功：%d BST2成功：%d\n",ans1,ans2);
//BST查找失败的平均查找长度
            ans1 = 0;
            ans2 = 0;
            for (i = 0; i <= 2048; i+=2)
            {
                sum = 1;
                BSTSUC(i,F1);
                ans1+=sum;
            }
            ans1 = ans1/1024;
            for (i = 0; i <= 2048; i+=2)
            {
                sum = 1;
                BSTSUC(i,F2);
                ans2+=sum;
            }
            ans2 = ans2/1024;
            printf("BST1失败：%d BST2失败：%d\n",ans1,ans2);
            int ans3 = 0;
//折半查找成功的平均查找长度
            for (i = 1; i <= 2047; i+=2)
            {
                sum = 1;
                BINSUC(L,1,1024,i);
                ans3+=sum;
            }
            ans3 = ans3/1024;
            printf("折半查找：成功：%d ",ans3);
//折半查找失败的平均查找长度
            ans3 = 0;
            for (i = 0; i <= 2048; i+=2)
            {
                sum = 1;
                BINSUC(L,1,1024,i);
                ans3+=sum;
            }
            ans3 = ans3/1024;
            printf("失败：%d\n",ans3);
        }
        else if(z==7)
        {


            int k;
            printf("输入查找的数值（小于0时结束）：");
            scanf("%d",&k);
            while (k>=0)
            {
                int t = BinSearch(L,1,1024,k);
                if(t==0)
                {
                    printf("NOT FOUND!\n");
                }
                else
                {
                    printf("EXISTED\n");
                    printf("位置：%d 查找值：%d\n",t,L[t].key);
                }
                printf("输入查找的数值（小于0时结束）：");
                scanf("%d",&k);
            }
        }
        else
        {
            printf("不存在的指令！\n");
            printf("输入执行号码：");
            scanf("%d",&z);
            continue;
        }
        printf("输入执行号码：");
        scanf("%d",&z);
    }
    return 0;
}
