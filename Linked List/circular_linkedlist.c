#include <stdio.h>
#include <stdlib.h>
typedef struct SNODE
{
    int data;
    struct SNODE *next;
} SNODE;
SNODE *CREATE(int value)
{
    SNODE *new = (SNODE *)malloc(sizeof(SNODE));
    if (new == NULL)
    {
        printf("Memory Allocation Failed..\n");
        return NULL;
    }
    new->data = value;
    new->next = new;

    return new;
}
SNODE *INSERT_FIRST(SNODE *head, int value)
{
    SNODE *new = CREATE(value);
    if (new == NULL)
    {
        printf("memory alocation failed..\n");
        return NULL;
    }
    if (head == NULL)
    {
        return new;
    }
    SNODE *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    new->next = head;
    head = new;
    temp->next = new;

    return head;
}
SNODE *INSERT_LAST(SNODE *head, int value)
{
    SNODE *new = CREATE(value);
    if (new == NULL)
    {
        return head;
    }
    if (head == NULL)
    {
        return new;
    }
    SNODE *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->next = head;
    return head;
}
SNODE *DELETE_FIRST(SNODE *head)
{
    if (head == NULL)
    {
        printf("List is empty..\n");
        return NULL;
    }
    SNODE *temp = head;
    SNODE *del = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
    free(del);

    return head;
}
SNODE* DELETE_LAST(SNODE* head)
{
    if (head == NULL)
    {
        printf("List is empty..\n");
        return NULL;
    }
    SNODE* temp = head;
    SNODE* prev = NULL;

    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);

    return head;
    
}
void DISPLAY(SNODE *head)
{
    if (head == NULL)
    {
        printf("List is empty..\n");
        return;
    }
    SNODE *temp = head;
    do
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("%d", head->data);
    printf("\n");
}
void DESTROY(SNODE *head)
{
    if (head == NULL) return;

    SNODE *temp = head, *nextNode;
    do
    {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != head);
}
int main()
{
    SNODE *head = CREATE(20);
    head = INSERT_FIRST(head, 10);
    head = INSERT_LAST(head, 1000);
    head = INSERT_LAST(head, 2000);
    head = INSERT_LAST(head, 3000);
    head = DELETE_FIRST(head);
    head = DELETE_LAST(head);
    DISPLAY(head);
    DESTROY(head);
    return 0;
}