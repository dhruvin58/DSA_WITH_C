#include <stdio.h>
#include <stdlib.h>
typedef struct SNODE
{
    int data;
    struct SNODE *next;
    struct SNODE *right;
    struct SNODE *left;
} SNODE;
SNODE *createNode(int value);
SNODE *insertNode(SNODE *root, int value);
void levelOrder(SNODE *root);
int smallestElement(SNODE *root);
int largestElement(SNODE *root);
int heightOfTree(SNODE *root);
int depthOfTree(SNODE *root);
int totalNodes(SNODE *root);
int internalNodes(SNODE *root);
int externalNodes(SNODE *root);
void freeTree(SNODE *root);
int main()
{
    SNODE *root = NULL;
    int node[] = {10, 20, 5, 15, 30, 25, 35};
    int n = sizeof(node) / sizeof(node[0]);

    for (int i = 0; i < n; i++)
    {
        root = insertNode(root, node[i]);
    }
    printf("Level Order..\n");
    levelOrder(root);
    printf("\n");

    printf("Largest Element is %d \n", largestElement(root));

    printf("Smallest Element is %d \n", smallestElement(root));

    printf("Height Of the tree is %d..\n", heightOfTree(root));

    printf("Depth Of the tree is : %d\n", depthOfTree(root));

    printf("Total Nodes Are: %d\n", totalNodes(root));

    printf("Total External Nodes are: %d\n", externalNodes(root));

    printf("Total Internal Nodes are: %d\n", internalNodes(root));

    freeTree(root);
    return 0;
}
SNODE *createNode(int value)
{
    SNODE *newNode = (SNODE *)malloc(sizeof(SNODE));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
SNODE *insertNode(SNODE *root, int value)
{
    if (root == NULL)
    {
        root = createNode(value);
    }
    if (root->data > value)
    {
        root->left = insertNode(root->left, value);
    }
    if (root->data < value)
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}
void levelOrder(SNODE *root)
{
    if (root == NULL)
    {
        return;
    }
    SNODE *queue[100];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        SNODE *current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }
        if (current->right != NULL)
        {
            queue[rear++] = current->right;
        }
    }
}
void freeTree(SNODE *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    freeTree(root);
}
int smallestElement(SNODE *root)
{
    if (root == NULL)
    {
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
int largestElement(SNODE *root)
{
    if (root == NULL)
    {
        return 0;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}
int heightOfTree(SNODE *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftheight = heightOfTree(root->left);
    int rightheight = heightOfTree(root->right);

    return (leftheight > rightheight ? leftheight : rightheight) + 1;
}
int depthOfTree(SNODE *root)
{
    return heightOfTree(root) - 1;
}
int totalNodes(SNODE *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + totalNodes(root->left) + totalNodes(root->right);
}
int internalNodes(SNODE *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left != NULL || root->right != NULL)
    {
        return 1 + internalNodes(root->left) + internalNodes(root->right);
    }
    return 0;
}
int externalNodes(SNODE *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return externalNodes(root->left) + externalNodes(root->right);
}