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
ll a[MAXN];//ÿһ���ط��洢��ֵ 
struct tree
{
    int l,r;//����ڵ�ά�������䷶Χ;������a[l]->a[r] 
    ll data; //����ýڵ�ά����ֵ;//!!!!!!!!!sum�ܺ� 
    ll lazy; //�漰lazy��ǵĶ���;
    ll Max;//���ֵ 
}t[MAXN << 2];
inline int lson(int p){return p << 1;}//�����;
inline int rson(int p){return p << 1 | 1;}//�Ҷ���;
void push_up(int p)
{ //���ϸ��¸��ڵ�����ֵ;
    t[p].Max = max(t[lson(p)].Max,t[rson(p)].Max);
}
void build(int p,int l,int r)//���߶��� 
{
    t[p].l = l,t[p].r = r;//��pΪ��ŵĽڵ�ά��������Ϊ[l,r];
    if(l == r)//Ҷ�ӽڵ�����ʵ����ֵ;
    {
        t[p].data = a[l];
        
        t[p].Max = a[l];// 
        return;
    }
    int mid = t[p].l + t[p].r >> 1;
    build(lson(p),l,mid);
    build(rson(p),mid + 1,r);
    //����ʱ�����ӽڵ����Ϣ������;
    t[p].data = t[lson(p)].data + t[rson(p)].data;
    
    push_up(p);//�ݹ齨��ʱ,ά�����������Ŷ;
}

//���´���sum 
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
    if(l <= t[p].l && r >= t[p].r)
		return t[p].data;//�����˸������ֱ�ӷ�����������;

    push_down(p);//�˴���push_down��update������һ������;

    ll sum = 0;
    int mid = t[p].l + t[p].r >> 1;
    if(l <= mid)
		sum += querySum(lson(p),l,r);//��������ӵ�����;
    if(r > mid)
		sum += querySum(rson(p),l,r);//�����Ҷ��ӵ�����;

    return sum;//�ۼӴ𰸷������Ҷ��ӵĺ�;
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
//��һ�а����������� n, mn,m���ֱ��ʾ���������ֵĸ����Ͳ������ܸ�����

//�ڶ��а��� nn ���ÿո�ָ������������е� ii �����ֱ�ʾ���е� ii ��ĳ�ʼֵ��

//������ mm ��ÿ�а��� 33 �� 44 ����������ʾһ���������������£�

//1 x y k�������� [x, y][x,y] ��ÿ�������� kk��
//2 x y��������� [x, y][x,y] ��ÿ�����ĺ͡�
int main()
{
	printf("������һ���ж��ٸ���n,�Լ��ж��ٴβ���m\n");
    scanf("%d%d",&n,&m);
    printf("������������n������ֵ\n");
    for(int i = 1;i <= n;i ++)scanf("%lld",&a[i]);
    build(1,1,n);//�����߶��� 
	//ִ�в��� 
	printf("�����ʽΪ\n");
	printf("1 l r x ->����a[l]->a[r]ÿ��ֵ����x\n");
	printf("2 l r   ->�������a[l]->a[r]ÿ�����ĺ�\n");
	printf("3 l r   ->�������a[l]->a[r]ÿ���������ֵ\n");
    for(int i = 1;i <= m;i ++)
    {
        int oporate;scanf("%d",&oporate);
        if(oporate == 1)
        {
            int l,r;
			scanf("%d%d",&l,&r);
            ll value;
			scanf("%lld",&value);
            update(1,l,r,value);
            printf("�������\n");
        }
        else if(oporate ==2)
        {
            int l,r;scanf("%d%d",&l,&r);
            printf("sum = %lld\n",querySum(1,l,r));
        }
        else
        {
        	int l,r;scanf("%d%d",&l,&r);
        	mx = query_Max(1,l,r);//����l,r���ҳ�a[l]��a[r]�����ֵ 
       		printf("MAX = %lld\n",mx);//�����ֵ
		}
    }
}



