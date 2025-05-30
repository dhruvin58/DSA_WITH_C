#include <stdio.h>
#include <stdlib.h>
typedef struct SNODE
{
    int data;
    struct SNODE *next;
    struct SNODE *prev;
} SNODE;
typedef struct LIST
{
    SNODE *head;
    SNODE *tail;
} LIST;
LIST *CREATELIST();
SNODE *CREATENODE(int size);
void INSERT_FIRST(LIST *list, int value);
void INSERT_LAST(LIST *list, int value);
void DELETE_FIRST(LIST *list);
void DELETE_LAST(LIST *list);
void DISPLAY(LIST *list);
void DESTROY(LIST *list);

int main()
{
    LIST *list = CREATELIST();

    INSERT_FIRST(list, 10);
    INSERT_FIRST(list, 20);
    DISPLAY(list);

    INSERT_LAST(list, 30);
    INSERT_LAST(list, 40);

    DISPLAY(list);

    DELETE_FIRST(list);

    DISPLAY(list);

    DELETE_LAST(list);

    DISPLAY(list);

    DESTROY(list);

    return 0;
}
LIST *CREATELIST()
{
    LIST *list = (LIST *)malloc(sizeof(LIST));
    if (list == NULL)
    {
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    list->head = NULL;
    list->tail = NULL;

    return list;
}
SNODE *CREATENODE(int value)
{
    SNODE *new = (SNODE *)malloc(sizeof(SNODE));
    if (new == NULL)
    {
        printf("Memory Allocation Failed\n");
        exit(1);
    }

    new->data = value;
    new->next = NULL;
    new->prev = NULL;

    return new;
}
void INSERT_FIRST(LIST *list, int value)
{
    SNODE *new = CREATENODE(value);
    if (new == NULL)
    {
        printf("Memory allocation failed..\n");
        return;
    }
    if (list->head == NULL && list->tail == NULL)
    {
        printf("List is empty..\n");
        list->head = new;
        list->tail = new;
    }
    else
    {
        new->next = list->head;
        new->prev = NULL;
        list->head->prev = new;
        list->head = new;
    }
}
void INSERT_LAST(LIST *list, int value)
{
    SNODE *new = CREATENODE(value);
    if (new == NULL)
    {
        printf("Memory allocation failed..\n");
        return;
    }
    if (list->head == NULL && list->tail == NULL)
    {
        printf("List is empty..\n");
        list->head = new;
        list->tail = new;
    }
    else
    {
        SNODE *temp = list->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = list->tail;
        list->tail = new;
    }
}
void DELETE_FIRST(LIST *list)
{
    if (list->head == NULL && list->tail == NULL)
    {
        printf("List is empty..\n");
        return;
    }
    if (list->head == list->tail)
    {
        printf("list is empty..\n");
        list->head = NULL;
        list->tail = NULL;
        free(list->head);
    }
    list->head = list->head->next;
    list->head->prev = NULL;
    free(list->head);
}
void DELETE_LAST(LIST *list)
{
    if (list->head == NULL && list->tail == NULL)
    {
        printf("List is empty..\n");
        return;
    }
    if (list->head == list->tail)
    {
        printf("list is empty..\n");
        list->head = NULL;
        list->tail = NULL;
        free(list->head);
    }
    list->tail->prev->next = NULL;
    list->tail = list->tail->prev;
    free(list->tail);
}
void DISPLAY(LIST *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    SNODE *temp = list->head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void DESTROY(LIST *list)
{
    SNODE *temp = list->head;
    while (temp != NULL)
    {
        SNODE *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(list);
}