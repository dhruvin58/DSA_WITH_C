#include <stdio.h>
#include <stdlib.h>

typedef struct SNODE {
    int vertex;
    struct SNODE *next;
} SNODE;

typedef struct GRAPH {
    int noOfVertex;
    SNODE **adjlist;
} GRAPH;


SNODE *CREATENODE(int vertex);
GRAPH *CREATEGRAPH(int noOfVertex);
void addEdge(GRAPH *g, int src, int dest);
void displayGraph(GRAPH *g);
void freeGraph(GRAPH *g);
void populateGraph(GRAPH *g, int edges);
void DFS(GRAPH *g, int startVertex, int *visited);
void BFS(GRAPH *g, int startVertex);

int main() {
    int vertices, edges, startVertex;

    printf("Enter Number Of Vertices: ");
    scanf("%d", &vertices);

    printf("Enter Number Of Edges: ");
    scanf("%d", &edges);

    GRAPH *graph = CREATEGRAPH(vertices);
    populateGraph(graph, edges);

    printf("\nAdjacency List Representation:\n");
    displayGraph(graph);

    int *visited = (int *)calloc(vertices, sizeof(int));
    printf("\nDFS Traversal starting from vertex 0:\n");
    DFS(graph, 0, visited);
    free(visited);

    printf("\n\nBFS Traversal starting from vertex 0:\n");
    BFS(graph, 0);

    freeGraph(graph);
    return 0;
}

SNODE *CREATENODE(int vertex) {
    SNODE *new = (SNODE *)malloc(sizeof(SNODE));
    if (new == NULL) {
        printf("Memory Allocation Failed..\n");
        return NULL;
    }
    new->vertex = vertex;
    new->next = NULL;
    return new;
}

GRAPH *CREATEGRAPH(int noOfVertex) {
    GRAPH *graph = (GRAPH *)malloc(sizeof(GRAPH));
    if (graph == NULL) {
        printf("Memory Allocation Failed..\n");
        return NULL;
    }
    graph->noOfVertex = noOfVertex;
    graph->adjlist = (SNODE **)malloc(noOfVertex * sizeof(SNODE *));
    if (graph->adjlist == NULL) {
        printf("Memory Allocation Failed..\n");
        free(graph);
        return NULL;
    }
    for (int i = 0; i < noOfVertex; i++) {
        graph->adjlist[i] = NULL;
    }
    return graph;
}

void addEdge(GRAPH *g, int src, int dest) {
    SNODE *new = CREATENODE(dest);
    new->next = g->adjlist[src];
    g->adjlist[src] = new;

    new = CREATENODE(src);
    new->next = g->adjlist[dest];
    g->adjlist[dest] = new;
}

void displayGraph(GRAPH *g) {
    for (int i = 0; i < g->noOfVertex; i++) {
        SNODE *temp = g->adjlist[i];
        printf("%d:", i);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeGraph(GRAPH *g) {
    for (int i = 0; i < g->noOfVertex; i++) {
        SNODE *temp = g->adjlist[i];
        while (temp) {
            SNODE *freetmp = temp;
            temp = temp->next;
            free(freetmp);
        }
    }
    free(g->adjlist);
    free(g);
}


void populateGraph(GRAPH *g, int edges) {
    int source, destination;
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (source and destination) %d: ", i + 1);
        scanf("%d %d", &source, &destination);
        addEdge(g, source, destination);
    }
}

void DFS(GRAPH *g, int startVertex, int *visited) {
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    SNODE *temp = g->adjlist[startVertex];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFS(g, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

void BFS(GRAPH *g, int startVertex) {
    int *visited = (int *)calloc(g->noOfVertex, sizeof(int));
    int *queue = (int *)malloc(g->noOfVertex * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        SNODE *temp = g->adjlist[currentVertex];
        while (temp) {
            if (!visited[temp->vertex]) {
                queue[rear++] = temp->vertex;
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }

    free(queue);
    free(visited);
}
