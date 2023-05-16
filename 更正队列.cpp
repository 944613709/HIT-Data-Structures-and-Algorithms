template<class T>class queue
{
private:
	struct Node
	{
		T data;
		Node *next;
	};
	Node *head;//!
	Node *rear;//����β 
	Node *p;
	int length;
 
public:
	queue()
	{
		head = NULL;
		rear = NULL;//����ʼ�� 
		length = 0;
	}
	void push(T n)//���
	{
		Node *node = new Node;
		node->data = n;
		node->next = NULL//!
		if (head == NULL)
		{
			head = node;
			rear = node;
		}
		else
		{
			rear->next = node;
			rear = node;
		}
		length++;
	}
	void pop()//��ջ   ���ᣡ�����Ҳ��ᣡ��������ջ��Ԫ�ط���
	{
		if (length <= 0)
		{
			abort();
		}
		Node *temp = head;
		head = head->next;
		delete (temp);
		length--;
	}
	int size()//����Ԫ�ظ���
	{
		return length;
	}
	T front()//!���ض���Ԫ��
	{
		return head->data;
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
