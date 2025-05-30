#include <stdio.h>
#include <stdlib.h>
int **createMatrix(int vertices);
void printMatrix(int **matrix, int vertices);
void addEdge(int **matrix, int u, int v);
void populateGraph(int **matrix, int Edge, int vertices);
void freeMatrix(int **matrix, int vertices);
void BFS(int** matrix, int vertices, int start);
void DFS(int **matrix, int vertices, int start, int *visited);
int main()
{
    int vertices;
    printf("Enter Number of vertices");
    scanf("%d",&vertices);
    int **mat = createMatrix(vertices);
    printMatrix(mat, vertices);
    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    populateGraph(mat, edges, vertices);
    printMatrix(mat, vertices);
    BFS(mat, vertices, 0);
    int *visited = (int*)calloc(vertices, sizeof(int));
    DFS(mat, vertices, 0, visited);
    free(visited);
    DFS_UTIL(mat,vertices, 0);
    freeMatrix(mat, vertices);
    return 0;
}
int **createMatrix(int vertices)
{
    int **matrix = (int **)malloc(vertices * sizeof(int *));
    if (matrix == NULL)
    {
        printf("Memory Allocation failed..\n");
        return 0;
    }
    for (int i = 0; i < vertices; i++)
    {
        matrix[i] = (int *)calloc(vertices, sizeof(int));
        if (matrix[i] == NULL)
        {
            printf("Memory Allocation Failed..\n");
            return 0;
        }
    }
    return matrix;
}
void printMatrix(int **matrix, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void addEdge(int **matrix, int u, int v)
{
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}
void populateGraph(int **matrix, int Edge, int vertices)
{
    for (int i = 0; i < Edge; i++)
    {
        int u, v;
        printf("Enter Your Starting and Ending vertex to draw graph..\n");
        scanf("%d %d", &u, &v);
        if(u >= 0 && u < vertices && v >= 0 && v < vertices)
        {
         addEdge(matrix, u, v);
        }
        else
        {
            printf("Wrong Numbers..\n");
        }
    }
}
void freeMatrix(int **matrix, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        free(matrix[i]);
    }
    free(matrix);   
}
void BFS(int** matrix, int vertices, int start)
{
    int *visited = (int*)calloc(vertices,sizeof(int));
    int *queue = (int*)malloc(vertices*sizeof(int));
    int rear = 0;
    int front = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < vertices; i++)
        {
            if(matrix[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
        
    }
    free(queue);
    free(visited);
}
void DFS(int **matrix, int vertices, int start, int *visited)
{
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < vertices; i++)
    {
        if(matrix[start][i] == 1 && visited[i] == 0)
        {
            DFS(matrix, vertices, i, visited);
        }
    }
}