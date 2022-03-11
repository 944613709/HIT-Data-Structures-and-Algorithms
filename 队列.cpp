/* ************************************************************************
*       Filename:  queue.c
*    Description:  
*        Version:  1.0
*        Created:  2018年03月22日 21时50分52秒
*       Revision:  none
*       Compiler:  gcc
*         Author:  YOUR NAME (),
*        Company:  
* ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
struct Link
{
        int data;
        struct Link* next;
};
struct Queue
{
        struct Link* front;
        struct Link* rear;
        int size;
};

void QueueInit(struct Queue* queue)
{
        queue->front = NULL;
        queue->rear = NULL;
        queue->size = 0;
}
 
int QueueEmpty(struct Queue* queue)
{
        return (queue->size == 0);
}

void QueuePush(struct Queue* queue, const int data)
{
        struct Link* node;
        node = (struct Link*)malloc(sizeof(struct Link));
        assert(node != NULL);
        
        node->data = data;
        node->next = NULL;
        
        if(QueueEmpty(queue))
        {
            queue->front = node;
            queue->rear = node;
        }
        else
        {            
            queue->rear->next = node;
            queue->rear = node;
        }
        ++queue->size;
}
 
int QueuePop(struct Queue* queue, int* data)
{
        if (QueueEmpty(queue))
        {
                return 0;
        }
        struct Link* tmp = queue->front;
        *data = queue->front->data;
        queue->front = queue->front->next;
        free(tmp);
        --queue->size;
 
        return 1;
}
void QueueDestroy(struct Queue* queue)
{
     struct Link* tmp;
     while(queue->front)
     {
         tmp = queue->front;
         queue->front = queue->front->next;
         free(tmp);
     }
}

int main(void)
{
        struct Queue queue;
        QueueInit(&queue);
        int i;
        for (i=0; i<5; i++)
        {
                QueuePush(&queue, i);
        }
        while (!QueueEmpty(&queue))
        {
                QueuePop(&queue, &i);
                printf("%d ", i);
        }
 
        printf("\n");
 
        return 0;
}
