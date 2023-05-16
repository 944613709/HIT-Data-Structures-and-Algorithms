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
ll Data[MAXN];//������ÿһ�������һ��ص�洢��ֵ 
struct TREE
{
    int l,r;//����ڵ�ά�������䷶Χ;������a[l]->a[r] 
    ll SUM; ////!!!!!!!!!sum�ܺ� 
    ll lazy; //�漰lazy��ǵĶ���;
    ll Max;//���ֵ 
}t[MAXN << 2];
inline int lson(int p){return p << 1;}//�����;
inline int rson(int p){return p << 1 | 1;}//�Ҷ���;
void build(int p,int l,int r)//���߶��� 
{
    t[p].l = l,t[p].r = r;
    if(l == r)//Ҷ�ӽڵ�
    {
        t[p].SUM = Data[l];
        
        t[p].Max = Data[l];// 
        return;
    }
    int mid = t[p].l + t[p].r >> 1;
    build(lson(p),l,mid);
    build(rson(p),mid + 1,r);
    t[p].SUM = t[lson(p)].SUM + t[rson(p)].SUM;
    t[p].Max = max(t[lson(p)].Max,t[rson(p)].Max);//�ݹ齨��!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

void push_down(int p)
{
    if(t[p].lazy)
    {
        //���lazy��ǲ�Ϊ0
        t[lson(p)].SUM += t[p].lazy * (t[lson(p)].r - t[lson(p)].l + 1);
        t[rson(p)].SUM += t[p].lazy * (t[rson(p)].r - t[rson(p)].l + 1);
		t[lson(p)].Max += t[p].lazy;//!!!!
		t[rson(p)].Max += t[p].lazy;//!!!!
        //�´�;
        t[lson(p)].lazy += t[p].lazy;
        t[rson(p)].lazy += t[p].lazy;

        t[p].lazy = 0;//�´����,����lazyΪ0;
    }
}
void update(int p,int l,int r,ll value)//������ [x, y][x,y] ��ÿ�������� k
{
    if(l <= t[p].l && r >= t[p].r)//1.���䱻����,���޸�;
    {
        t[p].SUM += value * (t[p].r - t[p].l + 1);
        t[p].Max += value;
        t[p].lazy += value;
        return;
    }
    push_down(p);	
    int mid = t[p].l + t[p].r >> 1;
    if(l <= mid)
		update(lson(p),l,r,value);//����������Ӿ��޸������;
   	 if(r > mid)
		update(rson(p),l,r,value);

    t[p].SUM = t[lson(p)].SUM + t[rson(p)].SUM;
    t[p].Max = max(t[lson(p)].Max,t[rson(p)].Max);//!!!!!!!!!!!!!!
}

ll querySum(int p,int l,int r)//������� [x, y][x,y] ��ÿ�����ĺ�
{
    if(l <= t[p].l && r >= t[p].r)
		return t[p].SUM;//�����˸������ֱ�ӷ�����������;

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

void update_point(int l,ll y)//l y ->����a[l]��ֵ���y\n
{//�Ƚ��� ������[l,l]��ÿ�������� value = y-a[l] 
	ll value = y- Data[l];
	update(1,l,l,value); 
}
int main()
{
	printf("������һ���ж��ٸ���n,�Լ��ж��ٴβ���m\n");
    scanf("%d%d",&n,&m);
    printf("������������n������ֵ,a[1]��a[n]\n");
    for(int i = 1;i <= n;i ++)
		scanf("%lld",&Data[i]);
    build(1,1,n);//�����߶��� a[1]->a[n]
	//ִ�в��� 
	printf("�����ʽΪ\n");
	printf("0 L y ->����Data[L]��ֵ���y\n");
	printf("1 L r x ->����Data[L]->Data[r]ÿ��ֵ����x\n");
	printf("2 L r   ->�������DataL]->Data[r]ÿ�����ĺ�\n");
	printf("3 L r   ->�������Data[L]->Data[r]ÿ���������ֵ\n");
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
            printf("Data[%d]��ֵ��Ϊ%lld���������\n",l,y);
		}
        else if(oporate == 1)
        {
			scanf("%d%d",&l,&r);
			scanf("%lld",&value);
            update(1,l,r,value);
            printf("Data[%d]->Data[%d]��ֵ������%lld �������\n",l,r,value);
        }
        else if(oporate ==2)
        {
            scanf("%d%d",&l,&r);
            printf("sum = %lld\n",querySum(1,l,r));
        }
        else
        {
        	scanf("%d%d",&l,&r);
        	mx = query_Max(1,l,r);//����l,r���ҳ�a[l]��a[r]�����ֵ 
       		printf("MAX = %lld\n",mx);//�����ֵ
		}
    }
}



