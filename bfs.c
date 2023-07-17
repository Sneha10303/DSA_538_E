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
    int nV;
    struct Node** aL;
};

struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int v)
{
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->nV = v;
    g->aL = (struct Node**)malloc(v * sizeof(struct Node*));
    for (int i = 0; i < v; i++)
    {
        g->aL[i] = NULL;
    }
    return g;
}

void addEdge(struct Graph* g, int src, int dest)
{
    struct Node* newNode = createNode(dest);
    newNode->next = g->aL[src];
    g->aL[src] = newNode;

    newNode = createNode(src);
    newNode->next = g->aL[dest];
    g->aL[dest] = newNode;
}

void bfs(struct Graph* g, int sV)
{
    bool visited[MAX_SIZE] = { false };
    int queue[MAX_SIZE];
    int front = 0;
    int rear = 0;

    visited[sV] = true;
    queue[rear++] = sV;

    printf("BFS traversal: ");
    while (front < rear)
    {
        int cV = queue[front++];
        printf("%d ", cV);
        struct Node* temp = g->aL[cV];
        while (temp != NULL)
        {
            int aV = temp->vertex;
            if (!visited[aV])
            {
                visited[aV] = true;
                queue[rear++] = aV;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    int v, edges, sV;

    printf("Number of vertices = ");
    scanf("%d", &v);
    printf("Number of edges = ");
    scanf("%d", &edges);

    struct Graph* g = createGraph(v);

    printf("Enter the edges :\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(g, src, dest);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &sV);

    bfs(g, sV);

    return 0;
}
/*0 2
0 1
1 4
1 3
2 6
2 5*/
