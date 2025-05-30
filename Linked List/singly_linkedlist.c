#include<stdio.h>
#include<stdlib.h>
typedef struct SNODE
{
    int data;
    struct SNODE* next;
}SNODE;
SNODE* CREATE_NODE(int value);
SNODE* INSERT_FIRST(SNODE* head, int value);
SNODE* INSERT_LAST(SNODE* head, int value);
SNODE* DELETE_FIRST(SNODE* head);
SNODE* DELETE_LAST(SNODE* head);
void DISPLAY(SNODE* head);
void DESTROY(SNODE* head);
// int main()
// {
//     SNODE* head = CREATE_NODE(40);
//     head = INSERT_FIRST(head,30);
//     head = INSERT_FIRST(head,20);
//     head = INSERT_FIRST(head,10);
//     // DISPLAY(head);
//     head = INSERT_LAST(head,50);
//     head = DELETE_FIRST(head);
//     DISPLAY(head);
//     // head = DELETE_FIRST(head);
//     // head = DELETE_FIRST(head);
//     // head = DELETE_FIRST(head);
//     // head = DELETE_FIRST(head);
//     head = DELETE_LAST(head);
//     DISPLAY(head);
//     DESTROY(head);


//     return 0;
// }
SNODE* CREATE_NODE(int value)
{
    SNODE* s = (SNODE*)malloc(sizeof(SNODE));
    if(s==NULL)
    {
        printf("Memory Allocation Failed..\n");
        return NULL;
    }
    s->data = value;
    s->next = NULL;

    return s;
}
SNODE* INSERT_FIRST(SNODE* head, int value)
{   
    SNODE* new = CREATE_NODE(value);
    if(head == NULL)
    {
        return new;
    }
    else
    {
        new->next = head;
        head = new;
    }
    return head;
}
SNODE* INSERT_LAST(SNODE* head, int value)
{
    SNODE* new = CREATE_NODE(value);
    if(head == NULL)
    {
        return new;
    }
    SNODE* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;

    return head;
}
SNODE* DELETE_FIRST(SNODE* head)
{
    if(head == NULL)
    {
        printf("List is empty..\n");
        return NULL;
    }
    else if(head->next == NULL)
    {
        printf("Only one element..so after deleting list will be empty..\n");
        printf("Value : %d \n", head->data);
        free(head);
        return NULL;
    }
    else
    {
        SNODE* temp = head;
        printf("Deleted Value is : %d\n",temp->data);
        head = temp->next;
        free(temp);
    }
    return head;
}
SNODE* DELETE_LAST(SNODE* head)
{
    if(head == NULL)
    {
        printf("List is Empty..\n");
        return NULL;
    }
    else if(head->next == NULL)
    {
        printf("Only one element..so after deleting list will be empty..\n");
        printf("Value : %d\n",head->data);
        free(head);
        return NULL;
    }
    else
    {   SNODE* temp = head;
        SNODE* prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp=temp->next;
        }
        prev->next = NULL;
        free(temp);
        return head;
    }
}
void DISPLAY(SNODE* head)
{
    if(head == NULL)
    {
        printf("List is empty..\n");
    }
    else if(head->next == NULL)
    {
        printf("%d -> " ,head->data);
    }
    else
    {   
        SNODE* temp = head;
        while (temp)
        {
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void DESTROY(SNODE* head)
{
    if(head == NULL)
    {
        printf("List is empty..\n");
        return;
    }
    SNODE* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("List Destroyed..\n");
}