template<class T>class stack
{
private:
	struct Node
	{
		T data;
		Node *next;
	};
	Node *head;
	Node *p;
	int length;
 
public:
	stack()
	{
		head = NULL;
		length = 0;
	}
	void push(T n)//��ջ
	{
		Node *q = new Node;
		q->data = n;
		if (head == NULL)
		{
			q->next = head;
			head = q;
			p = q;
		}
		else
		{
			q->next = p;
			p = q;
		}
		length++;
	}
 
	void pop()//��ջ   ���ᣡ�����Ҳ��ᣡ��������ջ��Ԫ�ط���
	{
		if (length <= 0)
		{
			abort();
		}
		Node *q;
		T data;
		q = p;
		data = p->data;
		p = p->next;
		delete(q);
		length--;
	}
	int size()//����Ԫ�ظ���
	{
		return length;
	}
	T top()//����ջ��Ԫ��
	{
		return p->data;
	}
	bool empty()//�ж�ջ�ǲ��ǿյ�
	{
		if (length == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
