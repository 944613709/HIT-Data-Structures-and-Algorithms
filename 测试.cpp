#include<iostream>
#include<queue>
using namespace std;
class tree {
public:
	char value;//���ֵ
	tree *liftchild;//������ָ��
	tree *rightChild;//������ָ��
};
void creat_tree(tree * &T)//����������
{
	char ch;
	ch = getchar();//�Ӽ�������һ����ĸ,���ζ�ȡ,ֱ�����м�
	if (ch == '#')
		T = NULL;
	else {
		T = new tree;
		T->value = ch;
		creat_tree(T->liftchild);
		creat_tree(T->rightChild);
	}
}
void VLR(tree *T)//�������������
{
	if (T == NULL)
		return;
	else {
			cout << T->value;
			VLR(T->liftchild);
			VLR(T->rightChild);
	}
}
void LVR(tree *T)//�������������
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
int caclnum(tree* T)//���������
{
	if (T == NULL)
		return 0;
	else
	{
		return 1 + caclnum(T->liftchild) + caclnum(T->rightChild);//���������������
	}

}
void LevelOrder(tree * T)//��α���
{
	if (T == NULL)
		return;
	queue<tree *> deq;//����һ����������
	
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
	VLR(T);//ǰ�����
	cout << endl;
	LVR(T);//�������
	cout << endl;
	LRV(T);//�������
	cout << caclnum(T);//ͳ�ƽ�����
	LevelOrder(T);//��α���
	system("pause");
	
	return 0;
}

