#include <iostream>
#include <cstdio>
#define maxlen 100
using namespace std;
bool visited[maxlen];
struct Link
{
    int v;//v为节点编号

    Link * next;
};
struct node
{
    char element;
    struct Link* firstedge;
};//头结点
struct Adgraph
{
    int n,e;
    node Ad[maxlen];
};//邻接表
struct matrix_graph
{
    int n,e;
    int mat[maxlen][maxlen];
    char element[maxlen];
};
void cre1(matrix_graph  &G)//无向图邻接矩阵
{
    int i,j,x,y;
    cin >> G.n >> G.e;
    for(i=0; i<G.n; i++)  cin >> G.element[i];
    for(i=0; i<G.n; i++)
        for(j=0; j<G.n; j++)
            G.mat[i][j]=0;
    for(i=0; i<G.e; i++)
    {
        cin >> x >> y;
        G.mat[x][y]=1;
        G.mat[y][x]=1;
    }
    for(i=0; i<G.n; i++)
    {
        for(j=0; j<G.n; j++)
            cout << G.mat[i][j] << " ";
        cout << endl;
    }
}
void DFS1(matrix_graph *G,int i)//邻接矩阵深度优先（递归）
{
    int j;
    cout << G->element[i] << " ";
    visited[i]=true;
    for(j=0; j<G->n; j++)if(G->mat[i][j]==1&&!visited[j])  DFS1(G,j);
}
void DFS1_nonrec(matrix_graph *G,int v)//邻接矩阵深度优先（非递归）
{
    int STACK[maxlen];
    int top=maxlen;
    STACK[--top]=v;//第一个压栈
    while(top!=maxlen)
    {
        int w=STACK[top++];
        if(!visited[w])
        {
            cout <<  G->element[w] <<  " ";
            visited[w]=true;
        }//取栈顶判断
        for(int i=0; i<G->n; i++)if(!visited[i]&&G->mat[w][i])
                STACK[--top]=i;//遇到一个没有访问的，压栈,向下搜索
    }
}
void BFS1(matrix_graph *G,int v)//邻接矩阵的广度优先
{
    int Queue[maxlen],front=0,rear=0,w;
    visited[v]=true;
    Queue[rear++]=v;
    cout << G->element[v] << " ";
    while(front!=rear)
    {
        v=Queue[front++];
        for(w=0; w<G->n; w++)
        {
            if(!visited[w]&&G->mat[v][w])
            {
                cout <<G->element[w] << " ";
                visited[w]=true;
                Queue[rear++]=w;
            }
        }
    }
}
void cre2(Adgraph* G)
{
    int k,i,j;
    cin >> G->n >> G->e;
    for (k=0; k<G->n; k++)
    {
        cin >> G->Ad[k].element;
        G->Ad[k].firstedge=NULL;
    }//头结点的初始化
    for(k=0; k<G->e; k++)
    {
        cin >> j >> i;
        Link* p=new Link;
        p->v=i;
        p->next=G->Ad[j].firstedge;
        G->Ad[j].firstedge=p;//在表头插入
        p=new Link;//建立无向图，所以还要反过来链接
        p->v=j;
        p->next=G->Ad[i].firstedge;
        G->Ad[i].firstedge=p;
    }
    for(i=0; i<G->n; i++)
    {
        cout << G->Ad[i].element;
        Link *m=G->Ad[i].firstedge;
        while(m!=NULL)
        {
            printf("->%c",G->Ad[m->v].element);
            m=m->next;
        }
        printf("->NULL\n");
    }
}
void DFS2(Adgraph* G,int v)
{
    Link *p;
    cout << G->Ad[v].element << " ";
    visited[v]=true;
    p=G->Ad[v].firstedge;
    while(p!=NULL)
    {
        if(!visited[p->v]) DFS2(G,p->v);
        p=p->next;
    }
}
void DFS2_nonrec(Adgraph* G,int v)
{
    int STACK[maxlen],top=maxlen;
    Link *p=NULL;
    STACK[--top]=v;//第一个压栈
    while(top!=maxlen)
    {
        int w=STACK[top++];
        if(!visited[w])
        {
            cout <<  G->Ad[w].element << " ";
            visited[w]=true;
        }
        for(p=G->Ad[w].firstedge; p!=NULL; p=p->next)
            if(!visited[p->v])
                STACK[--top]=p->v;//遇到一个没有访问的，压栈,向下搜索
    }
}
void BFS2(Adgraph* G,int v)
{
    int Queue[maxlen],front=0,rear=0;
    struct Link *p=NULL;
    visited[v]=true;
    Queue[rear++]=v;
    cout << G->Ad[v].element << " ";
    while(front!=rear)
    {
        v=Queue[front++];
        p=G->Ad[v].firstedge;
        while(p!=NULL&&!visited[p->v])
        {
            cout <<G->Ad[p->v].element << " ";
            visited[p->v]=true;
            Queue[rear++]=p->v;
            p=p->next;
        }
    }
}
int main()
{
    struct Adgraph G2;
    int i,N;
    struct matrix_graph G1;
    printf("1----邻接矩阵(无向图)\n2----邻接表（无向图）\n");
    cin >> N;
    switch(N)
    {
    case 0:
        return 0;
    case 1:
        freopen("lab3.txt", "r", stdin);
        cre1(G1);//建立邻接矩阵
        printf("DFS:");
        for(i=0; i<G1.n; i++) visited[i]=false;
        for(i=0; i<G1.n; i++)if(!visited[i]) DFS1(&G1,i);//递归深先
        printf("\nDFS_NONREC:");
        for(i=0; i<G1.n; i++) visited[i]=false;
        for(i=0; i<G1.n; i++)if(!visited[i])DFS1_nonrec(&G1,i);//非递归深先
        printf("\nBFS:");
        for(i=0; i<G1.n; i++) visited[i]=false;
        for(i=0; i<G1.n; i++)if(!visited[i])BFS1(&G1,i);
        fclose(stdin);
        break;
    case 2:
        freopen("lab3.txt", "r", stdin);
        cre2(&G2);
        printf("DFS:");
        for(i=0; i<G2.n; i++) visited[i]=false;
        for(i=0; i<G2.n; i++)if(!visited[i]) DFS2(&G2,i);//递归深先
        printf("\nDFS_NONREC:");
        for(i=0; i<G2.n; i++) visited[i]=false;
        for(i=0; i<G2.n; i++)if(!visited[i]) DFS2_nonrec(&G2,i);
        printf("\nBFS:");
        for(i=0; i<G2.n; i++) visited[i]=false;
        for(i=0; i<G2.n; i++)if(!visited[i]) BFS2(&G2,i);
        fclose(stdin);
        break;
    default: break;
    }
    return 0;
}


