#include<iostream>
#include<queue>
using namespace std;
class tree {
public:
	char value;//结点值
	tree *liftchild;//左子树指针
	tree *rightChild;//右子树指针
};
void creat_tree(tree * &T)//创建二叉树
{
	char ch;
	ch = getchar();//从键盘输入一串字母,依次读取,直至换行键
	if (ch == '#')
		T = NULL;
	else {
		T = new tree;
		T->value = ch;
		creat_tree(T->liftchild);
		creat_tree(T->rightChild);
	}
}
void VLR(tree *T)//先序遍历二叉树
{
	if (T == NULL)
		return;
	else {
			cout << T->value;
			VLR(T->liftchild);
			VLR(T->rightChild);
	}
}
void LVR(tree *T)//中序遍历二叉树
{
	if (T == NULL)
		return;
	else {
		LVR(T->liftchild);
		cout << T->value;
		LVR(T->rightChild);
	}
}
void LRV(tree *T)
{
	if (T == NULL)
		return;
	else {
		LRV(T->liftchild);
		
		LRV(T->rightChild);
		cout << T->value;
	}

}
int caclnum(tree* T)//计算结点个数
{
	if (T == NULL)
		return 0;
	else
	{
		return 1 + caclnum(T->liftchild) + caclnum(T->rightChild);//计算二叉树结点个数
	}

}
void LevelOrder(tree * T)//层次遍历
{
	if (T == NULL)
		return;
	queue<tree *> deq;//建立一个队列容器
	
	deq.push(T);
	while (!deq.empty())
	{
		tree *tr = deq.front();
		cout << tr->value << endl;
		deq.pop();
		if (tr->liftchild != NULL)
			deq.push(tr->liftchild);

		if (tr->rightChild!= NULL)
			deq.push(tr->rightChild);
	}
}
int main() {

	tree * T ;
	creat_tree(T);
	VLR(T);//前序遍历
	cout << endl;
	LVR(T);//中序遍历
	cout << endl;
	LRV(T);//后序遍历
	cout << caclnum(T);//统计结点个数
	LevelOrder(T);//层次遍历
	system("pause");
	
	return 0;
}

