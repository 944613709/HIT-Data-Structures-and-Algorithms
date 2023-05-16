#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(a,x) memset(a,x,sizeof(a))
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
const ll MAXN = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 1e18;
const ll mo = 1e9+7;
int n,m,mx;
ll Data[MAXN];//代表这每一个区间的一块地点存储的值 
struct TREE
{
    int l,r;//代表节点维护的区间范围;代表了a[l]->a[r] 
    ll SUM; ////!!!!!!!!!sum总和 
    ll lazy; //涉及lazy标记的东西;
    ll Max;//最大值 
}t[MAXN << 2];
inline int lson(int p){return p << 1;}//左儿子;
inline int rson(int p){return p << 1 | 1;}//右儿子;
void build(int p,int l,int r)//建线段树 
{
    t[p].l = l,t[p].r = r;
    if(l == r)//叶子节点
    {
        t[p].SUM = Data[l];
        
        t[p].Max = Data[l];// 
        return;
    }
    int mid = t[p].l + t[p].r >> 1;
    build(lson(p),l,mid);
    build(rson(p),mid + 1,r);
    t[p].SUM = t[lson(p)].SUM + t[rson(p)].SUM;
    t[p].Max = max(t[lson(p)].Max,t[rson(p)].Max);//递归建树!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

void push_down(int p)
{
    if(t[p].lazy)
    {
        //如果lazy标记不为0
        t[lson(p)].SUM += t[p].lazy * (t[lson(p)].r - t[lson(p)].l + 1);
        t[rson(p)].SUM += t[p].lazy * (t[rson(p)].r - t[rson(p)].l + 1);
		t[lson(p)].Max += t[p].lazy;//!!!!
		t[rson(p)].Max += t[p].lazy;//!!!!
        //下传;
        t[lson(p)].lazy += t[p].lazy;
        t[rson(p)].lazy += t[p].lazy;

        t[p].lazy = 0;//下传完成,更新lazy为0;
    }
}
void update(int p,int l,int r,ll value)//将区间 [x, y][x,y] 内每个数加上 k
{
    if(l <= t[p].l && r >= t[p].r)//1.区间被覆盖,就修改;
    {
        t[p].SUM += value * (t[p].r - t[p].l + 1);
        t[p].Max += value;
        t[p].lazy += value;
        return;
    }
    push_down(p);	
    int mid = t[p].l + t[p].r >> 1;
    if(l <= mid)
		update(lson(p),l,r,value);//覆盖了左儿子就修改左儿子;
   	 if(r > mid)
		update(rson(p),l,r,value);

    t[p].SUM = t[lson(p)].SUM + t[rson(p)].SUM;
    t[p].Max = max(t[lson(p)].Max,t[rson(p)].Max);//!!!!!!!!!!!!!!
}

ll querySum(int p,int l,int r)//输出区间 [x, y][x,y] 内每个数的和
{
    if(l <= t[p].l && r >= t[p].r)
		return t[p].SUM;//覆盖了该区间就直接返回整个数据;

    push_down(p);

    ll sum = 0;
    int mid = t[p].l + t[p].r >> 1;
    if(l <= mid)
		sum += querySum(lson(p),l,r);
    if(r > mid)
		sum += querySum(rson(p),l,r);

    return sum;
}
ll query_Max(int p,int l,int r)
{
    if(l <= t[p].l && r >= t[p].r)
		return t[p].Max;

    int mid = t[p].l + t[p].r >> 1;
    ll maxL = -inf,maxR = -inf;
    if(l <= mid)maxL = max(maxL,query_Max(lson(p),l,r));
    if(r > mid)maxR = max(maxR,query_Max(rson(p),l,r));

    return max(maxL,maxR);

}

void update_point(int l,ll y)//l y ->代表a[l]的值变成y\n
{//等将于 将区间[l,l]内每个数加上 value = y-a[l] 
	ll value = y- Data[l];
	update(1,l,l,value); 
}
int main()
{
	printf("请输入一共有多少个数n,以及有多少次操作m\n");
    scanf("%d%d",&n,&m);
    printf("请依次输入这n个数的值,a[1]到a[n]\n");
    for(int i = 1;i <= n;i ++)
		scanf("%lld",&Data[i]);
    build(1,1,n);//建立线段树 a[1]->a[n]
	//执行操作 
	printf("输入格式为\n");
	printf("0 L y ->代表Data[L]的值变成y\n");
	printf("1 L r x ->代表Data[L]->Data[r]每个值都加x\n");
	printf("2 L r   ->代表输出DataL]->Data[r]每个数的和\n");
	printf("3 L r   ->代表输出Data[L]->Data[r]每个数的最大值\n");
	int l,r;
	ll y;
	ll value;
    for(int i = 1;i <= m;i ++)
    {
        int oporate;
			scanf("%d",&oporate);
        if(oporate == 0)
        {
			scanf("%d",&l);
			scanf("%lld",&y);
			value = y-Data[l];
            update(1,l,l,value);
            printf("Data[%d]的值变为%lld，更新完毕\n",l,y);
		}
        else if(oporate == 1)
        {
			scanf("%d%d",&l,&r);
			scanf("%lld",&value);
            update(1,l,r,value);
            printf("Data[%d]->Data[%d]的值都加上%lld 更新完毕\n",l,r,value);
        }
        else if(oporate ==2)
        {
            scanf("%d%d",&l,&r);
            printf("sum = %lld\n",querySum(1,l,r));
        }
        else
        {
        	scanf("%d%d",&l,&r);
        	mx = query_Max(1,l,r);//输入l,r，找出a[l]到a[r]的最大值 
       		printf("MAX = %lld\n",mx);//出最大值
		}
    }
}



