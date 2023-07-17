#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100
struct Node
{
    int vertex;
    struct Node* next;
};

struct Graph
{
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

}

void dfs(struct Graph* graph, int startVertex)
{
    bool visited[MAX_SIZE] = { false };
    int stack[MAX_SIZE];
    int top = -1;
    stack[++top] = startVertex;

    printf("DFS traversal: ");
    while (top >= 0)
    {
        int currentVertex = stack[top--];

        if (visited[currentVertex])
            continue;

        visited[currentVertex] = true;
        printf("%d ", currentVertex);
        struct Node* temp = graph->adjLists[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex])
            {
                stack[++top] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    int vertices, edges, startVertex;

    printf("Number of vertices: ");
    scanf("%d", &vertices);
    printf("Number of edges: ");
    scanf("%d", &edges);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the edges = \n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dfs(graph, startVertex);

    return 0;
}

