#include <stdio.h>
#define MAX 10

struct Edge
{
    int u, v, w;
};

struct Edge e[45];
int n, m;

int findParent(int parent[], int v)
{
    while (parent[v] != v)
    {
        v = parent[v];
    }

    return v;
}

void kruskalMST()
{
    int i, j, u, v, cost = 0, count = 0;
    int parent[MAX];
    struct Edge temp;

    for (i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < m - i - 1; j++)
        {
            if (e[j].w > e[j + 1].w)
            {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }

    printf("\nEdges of Kruskal's MST:\n");

    for (i = 0; i < m; i++)
    {
        u = findParent(parent, e[i].u);
        v = findParent(parent, e[i].v);

        if (u != v)
        {
            printf("%d - %d = %d\n", e[i].u, e[i].v, e[i].w);

            cost += e[i].w;
            parent[u] = v;
            count++;
        }

        if (count == n - 1)
        {
            break;
        }
    }

    if (count == n - 1)
        printf("Total MST Cost = %d\n", cost);
    else
        printf("MST Not Possible\n");
}

int main()
{
    int i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (source destination weight):\n");

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }

    kruskalMST();

    return 0;
}