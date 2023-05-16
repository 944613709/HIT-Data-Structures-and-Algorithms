/*----------------------------------------------------------------
����һ������ָ��front ��һ����βָ��rear ���ֱ�ָ����׺Ͷ�βԪ�ء�

 �� ��ʼ����front=rear=0��
 �� ����Ϊ�գ�front=rear��
 �� ������rear=MaxSize��
 �� ��ӣ�����Ԫ�ز���rear��ָ��λ�ã�Ȼ��rear��1��
 �� ���ӣ�ɾȥfront��ָ��Ԫ�أ�Ȼ���1�����ر�ɾԪ�ء�
 �� ȡ����Ԫ�أ�����forntָ���Ԫ��ֵ
 -----------------------------------------------------------------*/

#include <stdio.h>
#include <assert.h>
#include <Windows.h>

#define MaxSize 10  //���е��������

typedef int DataType;  //������Ԫ������
typedef struct Queue
{
    DataType Queue[MaxSize];
    int fornt;   //��ͷָ��
    int rear;    //��βָ��
}SeqQueue;
typedef struct Queue
{
	DataType Queue[MaxSize];
	int front;
	int rear;
}SeqQueue;

//���г�ʼ���������г�ʼ��Ϊ�ն���
void InitQueue(SeqQueue *SQ)
{
    SQ->fornt = SQ->rear = 0;  //�Ѷ�ͷ�Ͷ�βָ��ͬʱ��0
 }

//�ж϶���Ϊ��

int IsEmpty(SeqQueue* SQ)
{
    if (SQ->fornt == SQ->rear)
    {
        return 1;
    }
    return 0;
}

//�ж϶����Ƿ�Ϊ��

int IsFull(SeqQueue* SQ)
{
    if (SQ->rear == MaxSize) 
    {
        return 1;
    }
    return 0;
}

//���,��Ԫ��data���뵽����SQ��

void EnterQueue(SeqQueue* SQ,DataType data)
{
    if (IsFull(SQ))
    {
        printf("��������\n");
        return 0;
    }
    SQ->Queue[SQ->rear] = data;  //�ڶ�β����Ԫ��data
    SQ->rear = SQ->rear + 1;     //��βָ�����һλ
}

//���ӣ��������ж�ͷ��Ԫ��data���ӣ����Ӻ��ͷָ��front����һλ
int DeleteQueue(SeqQueue* SQ,DataType* data)
{
    if (IsEmpty(SQ))
    {
        printf("����Ϊ�գ�\n");
        return 0;
    }
    *data = SQ->Queue[SQ->fornt];   //����Ԫ��ֵ
    SQ->fornt = (SQ->fornt)+1;      //��βָ�����һλ
    return 1;
}

//��ȡ����Ԫ��

int GetHead(SeqQueue* SQ,DataType* data)
{
    if (IsEmpty(SQ))
    {
        printf("����Ϊ��!\n");
    }
    return *data = SQ->Queue[SQ->fornt];  
}

//��ն���

void ClearQueue(SeqQueue* SQ)
{
    SQ->fornt = SQ->rear = 0;
}

//��ӡ�����е���Ԫ��

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
    //��ʼ������
    InitQueue(&SQ);
    //���
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

    //��ӡ�����е�Ԫ��
    printf("�����е�Ԫ��Ϊ��");
    PrintQueue(&SQ);
    printf("\n");
    //����
    DeleteQueue(&SQ, &data);
    printf("����Ԫ��Ϊ��%d\n", data);
    printf("\n");
    DeleteQueue(&SQ, &data);
    printf("����Ԫ��Ϊ��%d\n", data);
    printf("\n");
    printf("�����е�Ԫ��Ϊ��");
    PrintQueue(&SQ);
    printf("\n");
    //��ȡ����Ԫ��
    data = GetHead(&SQ, &data);
    printf("����Ԫ��Ϊ��%d\n", data);
    printf("#Ԫ��16���#\n");
    //Ԫ��16���
    EnterQueue(&SQ, 16);
    printf("�����е�Ԫ��Ϊ��");
    PrintQueue(&SQ);
    printf("\n");
    system("pause");
    return 0;
}
