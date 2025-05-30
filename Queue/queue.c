#include<stdio.h>
#include<stdlib.h>
typedef struct QUEUE
{
    int *queue;
    int front;
    int rear;
    int size;
}QUEUE;
int IS_FULL(QUEUE* q);
int IS_EMPTY(QUEUE* q);
QUEUE* CREATE(int size);
void ENQUEUE(QUEUE* q, int value);
int DEQUEUE(QUEUE* q);
void DISPLAY(QUEUE* q);
void DESTROY(QUEUE* q);
int main()
{
    QUEUE* queue = CREATE(10);
    printf("Queue created Successfully..\n");
    ENQUEUE(queue,10);
    ENQUEUE(queue,20);
    ENQUEUE(queue,30);
    ENQUEUE(queue,40);
    ENQUEUE(queue,50);
    DISPLAY(queue);
    printf("Dequeued element is %d\n",DEQUEUE(queue));
    DISPLAY(queue);
    return 0;
}

int IS_FULL(QUEUE* q)
{
    if(q->rear == q->size-1)
    {
        return 1;
    }
    return 0;
}
int IS_EMPTY(QUEUE* q)
{
    if(q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    return 0;
}
QUEUE* CREATE(int size)
{
    QUEUE* q = (QUEUE*)malloc(size*sizeof(QUEUE));
    if(q == NULL)
    {
        printf("Memory Allocation Failed..\n");
        return NULL;
    }
    q->queue = (int*)malloc(size*sizeof(int));
    if(q->queue == NULL)
    {
        printf("Memory Allocation Failed...\n");
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    q->size = size;
}
void ENQUEUE(QUEUE* q, int value)
{
    if (IS_FULL(q))
    {
        printf("Queue is full..");
        return;
    }
    else if(q->rear == -1 && q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        (q->rear)++;
    }
    q->queue[q->rear] = value;
}
int DEQUEUE(QUEUE* q)
{
    if(IS_EMPTY(q))
    {
        printf("Queue is empty..\n");
        return -1;
    }
    int value = q->queue[q->front];
    q->front++;
    return value;
}
void DISPLAY(QUEUE* q)
{
    if(IS_EMPTY(q))
    {
        printf("Queue is empty..\n");
        return;
    }
    printf("Displaying Emelments..\n");
    for (int i = q->front; i < q->rear; i++)
    {
        printf("%d\n",q->queue[i]);
    }
}
void DESTROY(QUEUE* q)
{
    free(q->queue);
    free(q);
}