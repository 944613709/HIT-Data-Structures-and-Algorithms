#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define  maxlen 100
using namespace std;
struct BTtree
{
    char data;
    BTtree  *lchild;
    BTtree  *rchild;
};
char genelist[100];//保存广义表
int i;
BTtree* pre_creat_bt()//先序建立二叉树
{
    char ch;
    BTtree  *T;
    cin >> ch;
    if(ch=='#')  T=NULL;
    else
    {
        T=(BTtree*)malloc(sizeof(BTtree));
        T->data=ch;
        T->lchild=pre_creat_bt();
        T->rchild=pre_creat_bt();
    }
    return T;
}
BTtree * level_create()//层次建立二叉链表
{
    BTtree* s[maxlen];
    int j;
    char ch;
    BTtree *T,*p;
    while(cin >> i >> ch&&(i!=0||ch!='#'))
    {
        p=(BTtree*)malloc(sizeof(BTtree));
        p->data=ch;
        p->lchild=NULL;
        p->rchild=NULL;
        s[i]=p;
        if(i==1)T=p;
        else
        {
            j=i/2;
            if(i%2==0)s[j]->lchild=p;//节点为偶数，i为j的左儿子
            else    s[j]->rchild=p;//节点为偶数，i为j的左儿子
        }
    }
    return T;
}
void pre_order(BTtree *T)//递归先根遍历二叉树
{
    if(T!=NULL)
    {
        cout << T->data;
        pre_order(T->lchild);
        pre_order(T->rchild);
    }
}
void in_order(BTtree *T)//递归中序遍历二叉树
{
    if(T!=NULL)
    {
        in_order(T->lchild);
        cout << T->data;
        in_order(T->rchild);
    }
}
void post_order(BTtree *T)//递归后根遍历二叉树
{
    if(T!=NULL)
    {
        post_order(T->lchild);
        post_order(T->rchild);
        cout << T->data;
    }
}
void npre_order(BTtree *T)//非递归先根遍历二叉树
{
    BTtree* STACK[maxlen];
    int top=maxlen;
    while(T!=NULL||top!=maxlen)
    {
        while(T!=NULL)
        {
            cout << T->data;
            STACK[--top]=T;
            T=T->lchild;
        }
        if(top!=maxlen)
        {
            T=STACK[top++];
            T=T->rchild;
        }
    }
}
/*
当树非空那么循环，访问，左走
若S不空，取栈顶右走
*/
void nin_order(BTtree *T)//非递归中序遍历二叉树
{
    BTtree* STACK[maxlen];
    int top=maxlen;
    while(T!=NULL||top!=maxlen)
    {
        if(T!=NULL)
        {
            STACK[--top]=T;
            T=T->lchild;
        }
        else
        {
            T=STACK[top++];
            cout << T->data ;
            T=T->rchild;
        }
    }
}
/*
  树不空，左走一步不访问
  若栈不空，取出栈顶访问 再访问父亲，再右走
*/
void npost_order(BTtree *T)//非递归后根遍历二叉树
{
    struct STACK
    {
        BTtree*  tree;
        int  flag;
    } S[maxlen];
    int top=maxlen;
    BTtree * temp;
    temp=T;
    while(temp!=NULL||top!=maxlen)
    {
        if(temp!=NULL)
        {
            S[--top].tree=temp;
            S[top].flag=1;
            temp=temp->lchild;
        }
        else
        {
            if(S[top].flag==2)
            {
                T=S[top++].tree;
                cout << T->data;
            }
            else
            {
                S[top].flag=2;
                temp=S[top].tree->rchild;
            }
        }
    }
}
void lev_order(BTtree* T)
{
    BTtree* Q[maxlen],*q=NULL;
    int front=0,rear=0;//建立一个空的队列
    if(T==NULL)return;
    Q[rear++]=T;//将根指针入队
    while(front!=rear)
    {
        q=Q[front];
        cout << q->data;
        if(q->lchild!=NULL)
        {
            Q[rear]=q->lchild;//左儿子不是空，将它入队列
            rear++;
        }
        if(q->rchild!=NULL)
        {
            Q[rear]=q->rchild;//右边儿子不是空，将它入队列
            rear++;
        }
        front++;//完成上面之后将队首元素就可以出队进行下一次循环操作
    }
}
void  order(BTtree * T)//遍历二叉链表
{
    printf("********递归遍历二叉链表***********\n");
    printf("\n先序递归遍历二叉链表:");
    pre_order(T);
    printf("\n中序递归遍历二叉链表:");
    in_order(T);
    printf("\n后序递归遍历二叉链表:");
    post_order(T);
    printf("\n********非递归遍历二叉链表***********\n");
    printf("\n先序非递归遍历二叉链表:");
    npre_order(T);
    printf("\n中序非递归遍历二叉链表:");
    nin_order(T);
    printf("\n后序非递归遍历二叉链表:");
    npost_order(T);
    printf("\n**********层次遍历二叉链表***********:\n");
    lev_order(T);
}
void print_tree(BTtree *T) /*按广义表方式打印*/
{
    if(T!=NULL)
    {
        if(T->lchild==NULL&&T->rchild==NULL)
        {
            genelist[i]=T->data;
            i++;
        }
        else
        {
            genelist[i]=T->data;
            i++;
            genelist[i]='(';
            i++;
            print_tree(T->lchild);
            genelist[i]=',';
            i++;
            print_tree(T->rchild);
            genelist[i]=')';
            i++;
        }
    }
}
void print(BTtree *T)
{
    BTtree *t=T;
    i=0;
    genelist[i]='(';
    i++;
    print_tree(t);
    genelist[i]=')';
    i++;
    genelist[i]='\0';
}
int main()
{
    BTtree *pre_t=NULL,*lev_t=NULL;
    int N;
    printf("********输入1先序建立二叉链表***********\n********输入2层次建立二叉链表***********\n********输入0退出***********\n");
    while(cin >> N)
    {
        switch(N)
        {
        case 1:
            pre_t=pre_creat_bt();
            order(pre_t);//遍历二叉链表
            printf("\n********二叉树用广义表表示为********:\n");
            print(pre_t);
            for(i=0; genelist[i]!='\0'; i++) cout << genelist[i];
            printf("\n");
            break;
        case 2:
            printf("********层次建立二叉链表***********\n输入节点次序和元素:");
            lev_t=level_create();
            order(lev_t);//遍历二叉链表*/
            printf("\n********二叉树用广义表表示为********:\n");
            print(lev_t);
            for(i=0; genelist[i]!='\0'; i++)cout << genelist[i];
            printf("\n");
            break;
        case 0:
            break ;
        default :
            break;
        }
        memset(genelist,' ',sizeof(genelist));
        printf("********输入1先序建立二叉链表***********\n********输入2层次建立二叉链表***********\n********输入0退出***********\n");
    }
    return 0;
}
/*1A 3C 4D 5E 6F 7G 8H 9I 10J 0#*/


