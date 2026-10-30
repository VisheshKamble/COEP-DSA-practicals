#include <stdio.h>
#define MAX 10
#define INF 9999


int graph [MAX][MAX] , n;
struct Edge {
    int u , v , w;
};

struct Edge e[45];

int m;

void prims(){
    int visited[MAX] = {0};
    int i , j , a , b , min , cost = 0;
    int x = 0 ;
    int y = 0 ;

    visited[0] = 1 ;

    printf("\nPrims MST \n");

    for( i = 0 ; i < n -1 ; i++){
        min = INF;

        for(a = 0 ; a < n ; a++){
            for(b = 0 ; b < n ; b++){
                if(visited[a] && !visited[b] && graph[a][b] != 0 && graph[a][b] < min){
                    min = graph[a][b];
                    x = a ;
                    y = b ;
                }
            }
        }


        printf("%d - %d = %d \n" , x , y ,min);
        cost += min;
        visited[y] = 1 ;
    }

    printf("\n Minimum Cost = %d" , cost);

}

void kruskal()
{
    int i, j, u, v, cost = 0, count = 0;
    int parent[MAX];
    struct Edge temp;

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < m - 1; i++)
        for (j = 0; j < m - i - 1; j++)
            if (e[j].w > e[j + 1].w)
            {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }

    printf("\nKruskal's MST:\n");

    for (i = 0; i < m; i++)
    {
        u = e[i].u;
        v = e[i].v;

        while (parent[u] != u)
            u = parent[u];

        while (parent[v] != v)
            v = parent[v];

        if (u != v)
        {
            printf("%d - %d : %d\n", e[i].u, e[i].v, e[i].w);
            cost += e[i].w;
            parent[u] = v;
            count++;
        }

        if (count == n - 1)
            break;
    }

    printf("Total cost = %d\n", cost);
}


int main(){
    int i , u , v ,w ;

    printf("Enter the Number vertices and edges : ");
    scanf("%d%d" , &n , &m);

    for( i = 0 ; i < m ; i++){
        printf("Enter the source , destination , weights : ");
        scanf("%d%d%d" , &u , &v , &w);

        e[i].u = u ;
        e[i].v = v ;
        e[i].w = w ;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    prims();

    return 0;
}