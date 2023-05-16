#include<iostream>
#include<queue>
using namespace std;
class BTreeNode
{
	public:
		char value;
		BTreeNode *Left;
		BTreeNode *Right;
};
void Creat_Tree(BTreeNode*& T)
{
	FILE* p;
	char ch;
	ch = getchar();
	fflush(stdin);
	if(ch =='#')
		{
			T = NULL;	
			return ;
		}
	else
	{
		T = new BTreeNode;
		T->value = ch;
		Creat_Tree(T->Left);
		Creat_Tree(T->Right);
	}
}
void VLR(BTreeNode *T)
{
	if(T==NULL)
		return ;
	else
	{
		cout<<T->value;
		VLR(T->Left);
		VLR(T->Right);
	}
 } 
void LVR(BTreeNode *T)
{
	if(T==NULL)
	{
		return;
	}
	else
	{
		LVR(T->Left);
		cout<<T->value;
		LVR(T->Right);
	}
}
void LBR(BTreeNode* T)
{
	if(T==NULL)
	{
		return;
	}
	else
	{
		LVR(T->Left);
		LVR(T->Right);
		cout<<T->value;
	}
}
void LevelOrder(BTreeNode* T)
{
	if(T ==NULL)
		return ;
	queue<BTreeNode*> que;
	que.push(T);
	while(!que.empty())
	{
		BTreeNode* t;
		t=que.front();
		que.pop();
		cout<<t->value;
		if(t->Left!=NULL)
			que.push(t->Left);
		if(t->Right!=NULL)
			que.push(t->Right);
	}
}
bool IsWanQuanErChaShu(BTreeNode* T)
{
	if(T==NULL)
		return false;//��Ϊ�շ��ش� 
	bool leaf =false;
	queue<BTreeNode*>q;
	q.push(T);
	while(!q.empty())
	{
		BTreeNode* Top = q.front();
		if(Top->Left&&Top->Right)
		{
			q.pop();
			q.push(Top->Left);
			q.push(Top->Right);
		}
		if(Top->Left==NULL&Top->Right!=NULL)
		{
			return false;
		}
		if((Top->Left&&Top->Right==NULL)||(Top->Left==NULL&&Top->Right==NULL))
		{
			q.pop();//��ýڵ�֮������н�㶼��Ҷ�ӽڵ�
			//����Ϊ�жϵ�ǰ���������ǲ��Ƕ���Ҷ�� 
			while(!q.empty())
			{
				Top=q.front();
				if(Top->Left==NULL&Top->Right==NULL)
				{
					q.pop();
				}
				else
				{
					return false;
				}
			}
			return true;
		}
	}
	return true;
}
/*
int WidthOfBitTree(Bitree root)
{
	if(root == NULL)
		return 0;
	int maxWidth=0;
	deque<BiTree> d;
	d.push_back(root);
	while(1)
	{
		int len = d.size();//��ǰ��һ��ջԪ�ظ��� 
		if(len==0)
			break;//�˳�ѭ��
		while(len!=0)//ֻ����һ�� 
		{
			Bitree temp = d.front();
			d.pop_front();
			len--;
			if(temp->Left)
				d.push_back(temp_Left);
			if(temp->Right)
				d.push_back(temp_Right);
		 } 
		 maxWidth=max(maxWidth,d.size());
	}
}*/
int main()
{
	BTreeNode* T;
	Creat_Tree(T);
	VLR(T);
}
