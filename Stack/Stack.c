#include <stdio.h>
#include <stdlib.h>
typedef struct STACK
{
    int *stack;
    int top;
    int size;
} STACK;
STACK *CREATE(int size);
int IS_EMPTY(STACK *s);
int IS_FULL(STACK *s);
void push(STACK *s, int value);
int pop(STACK *s);
int peek(STACK *s);
void display(STACK* s);
void destroy(STACK *s);
// int main()
// {
//     STACK *stack = CREATE(10);
//     printf("Stack Created Successfully..\n");
//     push(stack,10);
//     push(stack,20);
//     push(stack,30);
//     push(stack,40);
//     display(stack);
//     printf("Poped Value is : %d\n",pop(stack));
//     display(stack);
//     printf("Top Most Value is : %d\n",peek(stack));
//     display(stack);
//     DESTROY(stack);
//     return 0;
// }
int IS_EMPTY(STACK *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}
int IS_FULL(STACK *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}
STACK *CREATE(int size)
{
    STACK *s = (STACK *)malloc(sizeof(STACK));
    if (s == NULL)
    {
        printf("Memory Allocation Failed..\n");
        return NULL;
    }
    s->size = size;
    s->stack = (int *)malloc(size * sizeof(int));
    if (s->stack == NULL)
    {
        printf("Memory Allocation Failed..\n");
        free(s);
        return NULL;
    }
    s->top = -1;

    return s;
}
void push(STACK *s, int value)
{
    if (IS_FULL(s))
    {
        printf("Stack is full..\n");
        return;
    }
    (s->top)++;
    s->stack[s->top] = value;
}
int pop(STACK *s)
{
    if (IS_EMPTY(s))
    {
        printf("stack is empty..\n");
        return -1;
    }
    int value;
    value = s->stack[s->top];
    (s->top)--;

    return value;
}
int peek(STACK *s)
{
    if (IS_EMPTY(s))
    {
        printf("Stack is empty..\n");
        return -1;
    }

    return s->stack[s->top];
}
void display(STACK* s)
{
    if(IS_EMPTY(s))
    {
        printf("Stack is empty..\n");
        return;
    }
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d \n",s->stack[i]);

    }
    printf("\n");
}
void destroy(STACK *s)
{
    free(s->stack);
    free(s);
}