#include <stdio.h>
#include <stdlib.h>
typedef struct QUEUE
{
    int *queue;
    int rear;
    int front;
    int size;
} QUEUE;
QUEUE *CREATE(int size)
{
    QUEUE *q = (QUEUE *)malloc(sizeof(QUEUE));
    if (q == NULL)
    {
        printf("Memory Allocation Failed..\n");
        return NULL;
    }
    q->queue = (int *)malloc(size * sizeof(int));
    if (q->queue == NULL)
    {
        printf("Memory Allocation failed..\n");
        return NULL;
    }
    q->size = size;
    q->front = -1;
    q->rear = -1;

    return q;
}
int IS_EMPTY(QUEUE *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    return 0;
}
int IS_FULL(QUEUE *q)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        return 1;
    }
    return 0;
}
void ENQUEUE(QUEUE *q, int value)
{
    if (IS_FULL(q))
    {
        printf("QUEUE is full..\n");
        return;
    }
    else if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
    }
    q->queue[q->rear] = value;
}
int DEQUEUE(QUEUE *q)
{
    if (IS_EMPTY(q))
    {
        printf("Queue is empty..\n");
        return -1;
    }
    int value = q->queue[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }

    return value;
}
void DISPLAY(QUEUE *q)
{
    if (IS_EMPTY(q))
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
void DESTROY(QUEUE **q)
{
    if (*q == NULL)
        return;

    if ((*q)->queue != NULL)
        free((*q)->queue);

    free(*q);
    *q = NULL; // Prevent dangling pointer
}

int main()
{
    QUEUE *queue = CREATE(5);
    printf("Queue created succesfully..\n");
    ENQUEUE(queue, 10);
    ENQUEUE(queue, 20);
    ENQUEUE(queue, 30);
    ENQUEUE(queue, 40);
    ENQUEUE(queue, 50);  // Should show full message

    DISPLAY(queue);

    DEQUEUE(queue);
    DEQUEUE(queue);

    DISPLAY(queue);

    ENQUEUE(queue, 60);
    ENQUEUE(queue, 70);

    DISPLAY(queue);

    DESTROY(&queue);

    return 0;
}