/*----------------------------------------------------------------
设立一个队首指针front ，一个队尾指针rear ，分别指向队首和队尾元素。

 ◆ 初始化：front=rear=0。
 ◆ 队列为空：front=rear。
 ◆ 队满：rear=MaxSize。
 ◆ 入队：将新元素插入rear所指的位置，然后rear加1。
 ◆ 出队：删去front所指的元素，然后加1并返回被删元素。
 ◆ 取队首元素：返回fornt指向的元素值
 -----------------------------------------------------------------*/

#include <stdio.h>
#include <assert.h>
#include <Windows.h>

#define MaxSize 10  //队列的最大容量

typedef int DataType;  //队列中元素类型
typedef struct Queue
{
    DataType Queue[MaxSize];
    int fornt;   //队头指针
    int rear;    //队尾指针
}SeqQueue;
typedef struct Queue
{
	DataType Queue[MaxSize];
	int front;
	int rear;
}SeqQueue;

//队列初始化，将队列初始化为空队列
void InitQueue(SeqQueue *SQ)
{
    SQ->fornt = SQ->rear = 0;  //把对头和队尾指针同时置0
 }

//判断队列为空

int IsEmpty(SeqQueue* SQ)
{
    if (SQ->fornt == SQ->rear)
    {
        return 1;
    }
    return 0;
}

//判断队列是否为满

int IsFull(SeqQueue* SQ)
{
    if (SQ->rear == MaxSize) 
    {
        return 1;
    }
    return 0;
}

//入队,将元素data插入到队列SQ中

void EnterQueue(SeqQueue* SQ,DataType data)
{
    if (IsFull(SQ))
    {
        printf("队列已满\n");
        return 0;
    }
    SQ->Queue[SQ->rear] = data;  //在队尾插入元素data
    SQ->rear = SQ->rear + 1;     //队尾指针后移一位
}

//出队，将队列中队头的元素data出队，出队后队头指针front后移一位
int DeleteQueue(SeqQueue* SQ,DataType* data)
{
    if (IsEmpty(SQ))
    {
        printf("队列为空！\n");
        return 0;
    }
    *data = SQ->Queue[SQ->fornt];   //出队元素值
    SQ->fornt = (SQ->fornt)+1;      //队尾指针后移一位
    return 1;
}

//获取队首元素

int GetHead(SeqQueue* SQ,DataType* data)
{
    if (IsEmpty(SQ))
    {
        printf("队列为空!\n");
    }
    return *data = SQ->Queue[SQ->fornt];  
}

//清空队列

void ClearQueue(SeqQueue* SQ)
{
    SQ->fornt = SQ->rear = 0;
}

//打印队列中的与元素

void PrintQueue(SeqQueue* SQ)
{
    assert(SQ);    
    int i = SQ->fornt;
    while(i<SQ->rear)
    {
        printf("%-3d", SQ->Queue[i]);
        i++;
    }
    printf("\n");
}
int main()
{
    SeqQueue SQ;
    DataType data;
    //初始化队列
    InitQueue(&SQ);
    //入队
    EnterQueue(&SQ, 1);
    EnterQueue(&SQ, 2);
    EnterQueue(&SQ, 3);
    EnterQueue(&SQ, 4);
    EnterQueue(&SQ, 5);
    EnterQueue(&SQ, 6);
    EnterQueue(&SQ, 8);
    EnterQueue(&SQ, 10);
    EnterQueue(&SQ, 12);
    EnterQueue(&SQ, 15);
    EnterQueue(&SQ, 16);

    //打印队列中的元素
    printf("队列中的元素为：");
    PrintQueue(&SQ);
    printf("\n");
    //出队
    DeleteQueue(&SQ, &data);
    printf("出队元素为：%d\n", data);
    printf("\n");
    DeleteQueue(&SQ, &data);
    printf("出队元素为：%d\n", data);
    printf("\n");
    printf("队列中的元素为：");
    PrintQueue(&SQ);
    printf("\n");
    //获取队首元素
    data = GetHead(&SQ, &data);
    printf("队首元素为：%d\n", data);
    printf("#元素16入队#\n");
    //元素16入队
    EnterQueue(&SQ, 16);
    printf("队列中的元素为：");
    PrintQueue(&SQ);
    printf("\n");
    system("pause");
    return 0;
}
