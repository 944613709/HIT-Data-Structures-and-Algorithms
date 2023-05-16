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
ll a[MAXN];//ÿһ���ط��洢��ֵ 
struct tree
{
    int l,r;//����ڵ�ά�������䷶Χ;
    ll data; //����ýڵ�ά����ֵ;
    ll lazy; //�漰lazy��ǵĶ���;
}t[MAXN << 2];
inline int lson(int p){return p << 1;}//�����;
inline int rson(int p){return p << 1 | 1;}//�Ҷ���;
void build(int p,int l,int r)//���߶��� 
{
    t[p].l = l,t[p].r = r;//��pΪ��ŵĽڵ�ά��������Ϊ[l,r];
    if(l == r)//Ҷ�ӽڵ�����ʵ����ֵ;
    {
        t[p].data = a[l];
        return;
    }
    int mid = t[p].l + t[p].r >> 1;
    build(lson(p),l,mid);
    build(rson(p),mid + 1,r);
    //����ʱ�����ӽڵ����Ϣ������;
    t[p].data = t[lson(p)].data + t[rson(p)].data;
}

void push_down(int p)//�ݹ鵽�ﵱǰ�ڵ�;
{
    if(t[p].lazy)
    {
        //���lazy��ǲ�Ϊ0,�ͽ����´�,�޸����Ҷ���ά����ֵ;
        t[lson(p)].data += t[p].lazy * (t[lson(p)].r - t[lson(p)].l + 1);
        t[rson(p)].data += t[p].lazy * (t[rson(p)].r - t[rson(p)].l + 1);

        //���游�׵�����,�ȴ������´�;
        t[lson(p)].lazy += t[p].lazy;
        t[rson(p)].lazy += t[p].lazy;

        t[p].lazy = 0;//�´����,����lazyΪ0;
    }
}
void update(int p,int l,int r,ll value)//������ [x, y][x,y] ��ÿ�������� k
{
    if(l <= t[p].l && r >= t[p].r)//���䱻����,���޸�;
    {
        t[p].data += value * (t[p].r - t[p].l + 1);
        t[p].lazy += value;
        return;
    }

    //���û�б�����,�Ǿ���Ҫ����������;
    push_down(p);//���¸��¶��ӽڵ������;
    //���Ƕ�����ά�������������Ϊ����ǵĴ��ڶ�û���޸�,��˽�������·�;

    int mid = t[p].l + t[p].r >> 1;
    if(l <= mid)update(lson(p),l,r,value);//����������Ӿ��޸������;
    if(r > mid)update(rson(p),l,r,value);//�������Ҷ��Ӿ��޸��Ҷ���;

    t[p].data = t[lson(p)].data + t[rson(p)].data;//���ϸ��¸��׽ڵ������;
}

ll querySum(int p,int l,int r)//������� [x, y][x,y] ��ÿ�����ĺ�
{
    if(l <= t[p].l && r >= t[p].r)return t[p].data;//�����˸������ֱ�ӷ�����������;

    push_down(p);//�˴���push_down��update������һ������;

    ll sum = 0;
    int mid = t[p].l + t[p].r >> 1;
    if(l <= mid)sum += querySum(lson(p),l,r);//��������ӵ�����;
    if(r > mid)sum += querySum(rson(p),l,r);//�����Ҷ��ӵ�����;

    return sum;//�ۼӴ𰸷������Ҷ��ӵĺ�;
}
//��һ�а����������� n, mn,m���ֱ��ʾ���������ֵĸ����Ͳ������ܸ�����

//�ڶ��а��� nn ���ÿո�ָ������������е� ii �����ֱ�ʾ���е� ii ��ĳ�ʼֵ��

//������ mm ��ÿ�а��� 33 �� 44 ����������ʾһ���������������£�

//1 x y k�������� [x, y][x,y] ��ÿ�������� kk��
//2 x y��������� [x, y][x,y] ��ÿ�����ĺ͡�
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



