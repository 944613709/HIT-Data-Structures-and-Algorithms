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
const ll MAXN = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 1e18;
const ll mo = 1e9+7;

ll n,m,mx,mi;
ll a[MAXN];

inline int lson(int p){return p << 1;}
inline int rson(int p){return p << 1 | 1;}

struct tree
{
    int l,r;
    ll Max;//���߶���ά�����ֵ;
}t[MAXN << 2];

void push_up(int p)
{ //���ϸ��¸��ڵ�����;
    t[p].Max = max(t[lson(p)].Max,t[rson(p)].Max);
}

void build(int p,int l,int r)
{
    t[p].l = l,t[p].r = r;
    if(l == r)
    {
        t[p].Max = a[l];
        
        return;
    }

    int mid = l + r >> 1;
    build(lson(p),l,mid);
    build(rson(p),mid + 1,r);

    push_up(p);//�ݹ齨��ʱ,ά�����������Ŷ;
}

ll query_Max(int p,int l,int r)
{
    if(l <= t[p].l && r >= t[p].r)return t[p].Max;//��ѯ���串���˽ڵ�Ĺ�Ͻ����ֱ�ӷ��ظ���������ֵ;

    int mid = t[p].l + t[p].r >> 1;
    ll maxL = -inf,maxR = -inf;
    if(l <= mid)maxL = max(maxL,query_Max(lson(p),l,r));//��ѯ����ӵ����ֵ;
    if(r > mid)maxR = max(maxR,query_Max(rson(p),l,r));//��ѯ�Ҷ��ӵ����ֵ;

    return max(maxL,maxR);//��󷵻��Դ�Ϊ�����������������ֵ;

}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;i ++)scanf("%lld",&a[i]);//a[i]�����ֵ,a[0]->a[2]��������0��2���� ����0��2��ֵΪa[0]=4,a[1]=66,a[2]=1 
    build(1,1,n);

    for(int i = 1;i <= m;i ++)
    {
        int l,r;scanf("%d%d",&l,&r);
        mx = query_Max(1,l,r);//����l,r���ҳ�a[l]��a[r]�����ֵ 

        printf("%lld\n",mx);//�����ֵ 
    }
}

