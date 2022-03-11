template<class T>class queue
{
private:
	struct Node
	{
		T data;
		Node *next;
	};
	Node *head;//!
	Node *rear;//！队尾 
	Node *p;
	int length;
 
public:
	queue()
	{
		head = NULL;
		rear = NULL;//！初始化 
		length = 0;
	}
	void push(T n)//入队
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
	void pop()//出栈   不会！！并且不会！！！将出栈的元素返回
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
	int size()//返回元素个数
	{
		return length;
	}
	T front()//!返回队首元素
	{
		return head->data;
	}
	bool empty()//判断栈是不是空的
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
