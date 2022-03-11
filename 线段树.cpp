#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<deque>
#include<stdlib.h>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
#define mem(a,x) memset(a,x,sizeof(a))
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
const ll MAXN = 1e5 + 10;
const ll inf = 1e18;
const ll mo = 998244353;

int n,m;
ll a[MAXN];//每一个地方存储的值 
struct tree
{
    int l,r;//代表节点维护的区间范围;
    ll data; //代表该节点维护的值;
    ll lazy; //涉及lazy标记的东西;
}t[MAXN << 2];
inline int lson(int p){return p << 1;}//左儿子;
inline int rson(int p){return p << 1 | 1;}//右儿子;
void build(int p,int l,int r)//建线段树 
{
    t[p].l = l,t[p].r = r;//以p为编号的节点维护的区间为[l,r];
    if(l == r)//叶子节点存放真实的数值;
    {
        t[p].data = a[l];
        return;
    }
    int mid = t[p].l + t[p].r >> 1;
    build(lson(p),l,mid);
    build(rson(p),mid + 1,r);
    //回溯时将其子节点的信息存下来;
    t[p].data = t[lson(p)].data + t[rson(p)].data;
}

void push_down(int p)//递归到达当前节点;
{
    if(t[p].lazy)
    {
        //如果lazy标记不为0,就将其下传,修改左右儿子维护的值;
        t[lson(p)].data += t[p].lazy * (t[lson(p)].r - t[lson(p)].l + 1);
        t[rson(p)].data += t[p].lazy * (t[rson(p)].r - t[rson(p)].l + 1);

        //接替父亲的任务,等待机会下传;
        t[lson(p)].lazy += t[p].lazy;
        t[rson(p)].lazy += t[p].lazy;

        t[p].lazy = 0;//下传完成,更新lazy为0;
    }
}
void update(int p,int l,int r,ll value)//将区间 [x, y][x,y] 内每个数加上 k
{
    if(l <= t[p].l && r >= t[p].r)//区间被覆盖,就修改;
    {
        t[p].data += value * (t[p].r - t[p].l + 1);
        t[p].lazy += value;
        return;
    }

    //如果没有被覆盖,那就需要继续向下找;
    push_down(p);//向下更新儿子节点的数据;
    //考虑儿子所维护的区间可能因为懒标记的存在而没有修改,因此将懒标记下放;

    int mid = t[p].l + t[p].r >> 1;
    if(l <= mid)update(lson(p),l,r,value);//覆盖了左儿子就修改左儿子;
    if(r > mid)update(rson(p),l,r,value);//覆盖了右儿子就修改右儿子;

    t[p].data = t[lson(p)].data + t[rson(p)].data;//向上更新父亲节点的数据;
}

ll querySum(int p,int l,int r)//输出区间 [x, y][x,y] 内每个数的和
{
    if(l <= t[p].l && r >= t[p].r)return t[p].data;//覆盖了该区间就直接返回整个数据;

    push_down(p);//此处的push_down和update函数是一个含义;

    ll sum = 0;
    int mid = t[p].l + t[p].r >> 1;
    if(l <= mid)sum += querySum(lson(p),l,r);//整合左儿子的数据;
    if(r > mid)sum += querySum(rson(p),l,r);//整合右儿子的数据;

    return sum;//累加答案返回左右儿子的和;
}
//第一行包含两个整数 n, mn,m，分别表示该数列数字的个数和操作的总个数。

//第二行包含 nn 个用空格分隔的整数，其中第 ii 个数字表示数列第 ii 项的初始值。

//接下来 mm 行每行包含 33 或 44 个整数，表示一个操作，具体如下：

//1 x y k：将区间 [x, y][x,y] 内每个数加上 kk。
//2 x y：输出区间 [x, y][x,y] 内每个数的和。
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i ++)scanf("%lld",&a[i]);
    build(1,1,n);

    for(int i = 1;i <= m;i ++)
    {
        int op;scanf("%d",&op);
        if(op == 1)
        {
            int l,r;scanf("%d%d",&l,&r);
            ll value;scanf("%lld",&value);
            update(1,l,r,value);
        }
        else
        {
            int l,r;scanf("%d%d",&l,&r);
            printf("%lld\n",querySum(1,l,r));
        }
    }
}



