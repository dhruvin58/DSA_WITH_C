#include<stdio.h>
#include<stdlib.h>
typedef struct SNODE
{
    int data;
    struct SNODE* next;
    struct SNODE* left;
    struct SNODE* right;
}SNODE;
SNODE* createNode(int value);
void leftNode(SNODE* root, int value);
void rightNode(SNODE* root ,int value);
void preOrder(SNODE* root);
void inOrder(SNODE* root);
void postOrder(SNODE* root);
int main()
{
    SNODE* root = createNode(10);
    leftNode(root,20);
    rightNode(root,30);
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    return 0;
}
SNODE* createNode(int value)
{
    SNODE* new = (SNODE*)malloc(sizeof(SNODE));
    if(new == NULL)
    {
        printf("Memory Allocation failed..\n");
        return NULL;
    }
    new->next = NULL;
    new->data = value;
    new->right = NULL;
    new->left = NULL;

    return new;
}
void leftNode(SNODE* root ,int value)
{
    SNODE* new = createNode(value);
    root->left = new;
}

void rightNode(SNODE* root ,int value)
{
    SNODE* new = createNode(value);
    root->right = new;
}
void preOrder(SNODE* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(SNODE* root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void postOrder(SNODE* root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}