#include<stdio.h>
#define MAX 10
#define INF 9999

int graph[MAX][MAX];
int n;
int edgeA[MAX] , edgeB[MAX] , edgeCost[MAX];
int totalCost = 0;

void prims(){

    int visited[MAX] = {0};

    int a , b , x , y , min , i;

    visited[0] = 1;

    for(int i = 0 ; i < n - 1 ; i++){
        min = INF;
        x = -1;
        y = -1;

        for(a = 0 ; a < n ; a++){
            for(b = 0 ; b < n ; b++){
                if(visited[a] && !visited[b] && graph[a][b] != 0 && graph[a][b] < min){
                    min = graph[a][b];
                    x = a;
                    y = b;
                }
            }
        }
        edgeA[i] = x;
        edgeB[i] = y;
        edgeCost[i] = min;

        totalCost += min;

        visited[y] = 1;
    }

}


    void display(){
        printf("Edges of Minimum Spanning Tree : \n");

        for(int i = 0 ; i < n -1 ; i++){
            printf("%d --- %d = %d\n"  , edgeA[i] , edgeB[i] , edgeCost[i] );
        }

        printf("Total Cost - > %d " , totalCost);
    }

int main(){
    int i , j ;

    printf("Enter the number of vertices : ");
    scanf("%d" , &n);

    printf("Enter Adjacency Matrix (0 for nor edge)\n");

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d" , &graph[i][j]);
        }
    }

    prims();
    display();

    return 0;
}