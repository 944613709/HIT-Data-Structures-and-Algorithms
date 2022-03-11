#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

struct node
{
    node *lchild;
    int data;
    node *rchild;
};
typedef node *BTREE;
BTREE CreatBT()
{
    BTREE T;
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
        T = NULL;
    else
    {
        T = (BTREE)malloc(sizeof(node));
        if(!T)
            exit(0);
        T->data = ch;
        T->lchild = CreatBT();
        T->rchild = CreatBT();
    }
    return T;
}
void PreOrder(BTREE BT)
{
    if(BT!=NULL)
    {
        printf("%c ",BT->data);
        PreOrder(BT->lchild);
        PreOrder(BT->rchild);
    }
}
void InOrder(BTREE BT)
{
    if(BT!=NULL)
    {
        InOrder(BT->lchild);
        printf("%c ",BT->data);
        InOrder(BT->rchild);
    }
}
void PostOrder(BTREE BT)
{
    if(BT!=NULL)
    {
        PostOrder(BT->lchild);
        PostOrder(BT->rchild);
        printf("%c ",BT->data);
    }
}
void PreOrderfei(BTREE T)
{
    stack <BTREE> S;
    while(!S.empty())
    {
        S.pop();
    }
    BTREE p = T;
    while(p!=NULL||!S.empty())
    {
        while(p!=NULL)
        {
            printf("%c ",p->data);
            S.push(p);
            p = p->lchild;
        }

        if(!S.empty())
        {
            p = S.top();
            S.pop();
            p = p->rchild;
        }
    }

}
void InOrderfei(BTREE T)
{
    stack <BTREE> S;
    while(!S.empty())
    {
        S.pop();
    }
    BTREE root = T;
    while(root!=NULL||!S.empty())
    {
        while(root!=NULL)
        {
            S.push(root);
            root = root->lchild;
        }
        if(!S.empty())
        {
            root = S.top();
            S.pop();
            printf("%c ",root->data);
            root = root->rchild;
        }
    }
}
void PostOrderfei(BTREE T)
{
    BTREE p,pr;
    stack <BTREE> S;
    while(!S.empty())
    {
        S.pop();
    }
    p = T;
    while(p!=NULL||!S.empty())
    {
        while(p!=NULL)
        {
            S.push(p);
            pr = p->rchild;
            p = p->lchild;
            if(p==NULL)
                p = pr;
        }
        p = S.top();
        S.pop();
        printf("%c ",p->data);
        if(!S.empty()&&S.top()->lchild==p)
            p = S.top()->rchild;
        else
            p = NULL;
    }
}
void LevelOrder(BTREE root)
{
    queue <BTREE> Q;
    if(root==NULL)
        return;
    Q.push(root);
    while(!Q.empty())
    {
        BTREE q = Q.front();
        Q.pop();
        printf("%c ",q->data);
        if(q->lchild!=NULL)
            Q.push(q->lchild);
        if(q->rchild!=NULL)
            Q.push(q->rchild);
    }

}
bool IsComleteTree(BTREE root)
{
    if(root == NULL)
    {
        return false;
    }
    queue<BTREE>q;
    q.push(root);
    BTREE p = q.front();
    while(p != NULL)
    {
        q.pop();
        q.push(p->lchild);
        q.push(p->rchild);
        p = q.front();
    }
    q.pop();
    while(!q.empty())
    {
        if(q.front()!=NULL)
            return false;
        q.pop();
    }
    return true;
}
int main()
{
    BTREE T;
    T = CreatBT();
    printf("先序递归：");
    PreOrder(T);
    printf("\n");
    printf("中序递归：");
    InOrder(T);
    printf("\n");
    printf("后序递归：");
    PostOrder(T);
    printf("\n");
    printf("先序非递归：");
    PreOrderfei(T);
    printf("\n");
    printf("中序非递归：");
    InOrderfei(T);
    printf("\n");
    printf("后序非递归：");
    PostOrderfei(T);
    printf("\n");
    printf("层序遍历：");
    LevelOrder(T);
    printf("\n");
    printf("是否为完全二叉树：");
    if(IsComleteTree(T)==false)
        printf("FALSE\n");
    else
        printf("TRUE\n");
    return 0;
}
