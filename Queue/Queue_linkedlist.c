#include<stdio.h>
#include<stdlib.h>
#include"singly_linkedlist.c"
SNODE* ENQUEUE(SNODE* head, int value)
{
    return INSERT_LAST(head,value);
}
SNODE* DEQUEUE(SNODE* head)
{
    return DELETE_FIRST(head);
}
int main()
{
    SNODE* head = NULL;
    head = ENQUEUE(head,10);    
    head = ENQUEUE(head,20);
    head = ENQUEUE(head,30);
    head = ENQUEUE(head,40);
    DISPLAY(head);
    head = DEQUEUE(head);
    DISPLAY(head);

    return 0;
}