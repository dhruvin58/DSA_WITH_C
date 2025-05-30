#include <stdio.h>
#include <stdlib.h>
typedef struct QUEUE
{
    int *queue;
    int front;
    int rear;
    int size;
} QUEUE;
QUEUE *CREATE(int size)
{
    QUEUE *q = (QUEUE *)malloc(size * sizeof(QUEUE));
    if (q == NULL)
    {
        printf("Memory Allocation Failed..\n");
        return NULL;
    }
    q->queue = (int *)malloc(size * sizeof(int));
    if (q->queue == NULL)
    {
        printf("Memory Allocation Failed...\n");
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    q->size = size;
}
void INSERT_AT_FRONT(QUEUE *q, int value)
{
    if ((q->front == 0 && q->rear == q->size - 1) || (q->rear + 1 == q->front))
    {
        printf("Queue is full.\n");
        return;
    }
    else if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
    }
    else if (q->front == 0)
    {
        q->front = q->size - 1;
    }
    else
    {
        q->front--;
    }
    q->queue[q->front] = value;
}
void INSERT_AT_REAR(QUEUE *q, int value)
{
    if ((q->front == 0 && q->rear == q->size - 1) || (q->front == q->rear + 1))
    {
        printf("Queue is full..\n");
    }
    else if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
    }
    else if (q->rear == q->size - 1)
    {
        q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->queue[q->rear] = value;
}
void DELETE_AT_FRONT(QUEUE *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty..\n");
        return;
    }
    else if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else if (q->front == q->size - 1)
    {
        q->front = 0;
    }
    else
    {
        q->front++;
    }
}
void DELETE_AT_REAR(QUEUE *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty..\n");
        return;
    }
    else if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else if (q->rear == 0)
    {
        q->rear = q->size - 1;
    }
    else
    {
        q->rear--;
    }
}
void DISPLAY(QUEUE *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty..\n");
        return;
    }
    int i = q->front;
    while (1)
    {
        printf("%d ", q->queue[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}
void DESTROY(QUEUE *q)
{
    free(q->queue);
    free(q);
}
int main()
{
    QUEUE *queue = CREATE(10);
    INSERT_AT_FRONT(queue, 10);
    INSERT_AT_FRONT(queue, 100);
    INSERT_AT_FRONT(queue, 1000);
    DISPLAY(queue);
    DELETE_AT_FRONT(queue);
    INSERT_AT_REAR(queue, 20);
    INSERT_AT_REAR(queue, 30);
    DISPLAY(queue);
    DELETE_AT_REAR(queue);
    DISPLAY(queue);
    DESTROY(queue);
}