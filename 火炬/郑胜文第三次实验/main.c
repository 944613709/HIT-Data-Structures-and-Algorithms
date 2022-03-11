#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct wenjianshuru
{
    char s[1000];
} wj;
void Floyd1(int A[][5],int C[][5],int P[][5],int n)
{
    int i,j,k;
    for (i = 0; i < n; i++)

        for (j = 0; j < n; j++)
        {
            A[i][j] = C[i][j];
            P[i][j] = -1;
        }
    for(k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)

            for (j = 0; j < n; j++)
            {
                if(A[i][k]+A[k][j]<A[i][j])
                {
                    A[i][j] = A[i][k]+A[k][j];
                    P[i][j] = k;
                }
            }
    }

}
void printpath1(int P[][5],int a)
{
    int f = 0;
    int path[20];
    int m = 0;
    while(P[f][a]!=-1)
    {
        f = P[f][a];
        path[m] = f;
        m++;
    }
    int i;
    printf("path:s0,");
    for (i = 0; i < m; i++)
    {
        printf("s%d,",path[i]);
    }
    printf("s%d ",a);
}
void Floyd2(int A[][8],int C[][8],int P[][8],int n)
{
    int i,j,k;
    for (i = 0; i < n; i++)

        for (j = 0; j < n; j++)
        {
            A[i][j] = C[i][j];
            P[i][j] = -1;
        }
    for(k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)

            for (j = 0; j < n; j++)
            {
                if(A[i][k]+A[k][j]<A[i][j])
                {
                    A[i][j] = A[i][k]+A[k][j];
                    P[i][j] = k;
                }
            }
    }

}
void printpath2(int P[][8],int a)
{
    int f = a;
    int path[20];
    int m = 0;
    while(P[0][f]!=-1)
    {
        f = P[0][f];
        path[m] = f;
        m++;
    }
    int i;
    printf("path:a,");
    for (i = m-1; i >= 0; i--)
    {
        char v = (char)path[i]+'a';
        printf("%c,",v);
    }
    printf("h ");
}
void print1(int E[][5])
{
    printf("  s0 s1 s2 s3 s4\n");
    int i,j;
    for (i = 0; i < 5; i++)
    {
        printf("s%d ",i);
        for (j = 0; j < 5; j++)
        {
            printf("%d ",E[i][j]);
        }
        printf("\n");
    }
}
void print2(int E[][8])
{
    printf("  a  b  c  d  e  f  g  h\n");
    int i,j;
    for (i = 0; i < 8; i++)
    {
        printf("%c ",(char)i+'a');
        for (j = 0; j < 8; j++)
        {
            printf("%d ",E[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int z;
    printf("1.操作图1\n");
    printf("2.操作图2\n");
    printf("3.结束\n");
    printf("输入操作号码：");
    scanf("%d",&z);
    while(z!=3)
    {
        if(z==1)
        {
            FILE *fp;
            wj k[200];
            char h[80];
            int cnt = 0;
            fp = fopen("ex3_Graph1.txt","r");
            while(fscanf(fp,"%s",h)!=EOF)
            {
                strcpy(k[cnt].s,h);
                cnt++;
            }
            int len = strlen(k[0].s);
            char t = k[0].s[len-1];
            int N = (int)(t-'0');
            int E[N][N];
            int i;
            int j,g;
            j = 0;
            g = 0;
            for (i = 0; i < cnt; i++)
            {
                int a = (int)(k[i].s[0]-'0');
                if(k[i].s[0]=='-')
                {
                    E[j][g] = -1;
                    g++;
                    if(g == N)
                    {
                        j++;
                        g = 0;
                    }
                }
                else if(a>0&&a<10)
                {
                    E[j][g] = atoi(k[i].s);
                    g++;
                    if(g == N)
                    {
                        j++;
                        g = 0;
                    }
                }
            }
            int A[N][N];
            int P[N][N];


            print1(E);
            for (i=0; i<N; i++)
            {
                for (j = 0; j<N; j++)
                {
                    if(E[i][j]==-1)
                        E[i][j] = 1000000;
                }
            }
            Floyd1(A,E,P,N);
            printf("graph1:\n");
            for(i = 1; i < 5; i++)
            {
                printf("s0->s%d ",i);
                printpath1(P,i);
                printf("value=%d\n",A[0][i]);
            }


        }
        else if(z==2)
        {
            FILE *fp;
            wj k[200];
            char h[80];
            int cnt = 0;
            fp = fopen("ex3_Graph2.txt","r");
            while(fscanf(fp,"%s",h)!=EOF)
            {
                strcpy(k[cnt].s,h);
                cnt++;
            }
            int len = strlen(k[0].s);
            char t = k[0].s[len-1];
            int N = (int)(t-'0');
            int E[N][N];
            int i;
            int j,g;
            j = 0;
            g = 0;
            for (i = 0; i < cnt; i++)
            {
                int a = (int)(k[i].s[0]-'0');
                if(k[i].s[0]=='-')
                {
                    E[j][g] = -1;
                    g++;
                    if(g == N)
                    {
                        j++;
                        g = 0;
                    }
                }
                else if(a>0&&a<10)
                {
                    E[j][g] = atoi(k[i].s);
                    g++;
                    if(g == N)
                    {
                        j++;
                        g = 0;
                    }
                }
            }
            int A[N][N];
            int P[N][N];

            print2(E);
            for (i=0; i<N; i++)
            {
                for (j = 0; j<N; j++)
                {
                    if(E[i][j]==-1)
                        E[i][j] = 1000000;
                }
            }
            Floyd2(A,E,P,N);
            printf("graph2:\n");
            printf("a->h ");
            printpath2(P,7);
            printf("value = %d\n",A[0][7]);
            fclose(fp);
        }
        else
        {
            printf("不存在的指令！\n");
            printf("输入操作号码：");
            scanf("%d",&z);
            continue;
        }
        printf("输入操作号码：");
        scanf("%d",&z);
    }
    return 0;
}
