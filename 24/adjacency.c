#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *adj[10];
int n;

void insertEdge(int u, int v)
{
    struct Node *newNode;

    newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

void displayGraph()
{
    int i;
    struct Node *temp;

    for (i = 0; i < n; i++)
    {
        printf("%d: ", i);

        temp = adj[i];

        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int i, m, u, v;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter edges (u v):\n");

    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        insertEdge(u, v);
    }

    displayGraph();

    return 0;
}