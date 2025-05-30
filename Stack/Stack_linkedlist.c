#include<stdio.h>
#include<stdlib.h>
#include"singly_linkedlist.c"
SNODE* PUSH(SNODE* head, int value)
{
    return INSERT_FIRST(head,value);
}
SNODE* POP(SNODE* head)
{
    return DELETE_FIRST(head);
}
int peek(SNODE* head)
{
    if(head == NULL)
    {
        printf("Stack is empty..");
        return -1;
    }
    return head->data;
}
int main()
{
    SNODE* head = NULL;
    head = PUSH(head,10);
    head = PUSH(head,20);
    head = PUSH(head,30);
    head = PUSH(head,40);
    head = POP(head);
    DISPLAY(head);
    printf("Top Value is : %d",peek(head));
    
    return 0;
}