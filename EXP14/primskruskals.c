#include <stdio.h>

#define MAX 10

#define INF 9999

int graph [MAX][MAX] , n ;
struct Edge {
    int u , v , w ;
};

struct Edge e[45];
int m ;

void prims(){

    int visited[MAX] = {0};

    int a , b , i , j ,min , cost = 0 ;
    int x = 0 ;
    int y = 0 ;

    printf("Prims MST \n : ");
    
    visited[0] = 1 ;

    for( i = 0 ; i < n - 1 ; i++){
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

       printf("%d - %d = %d" , x , y , min);
       cost += min ;
       visited[y] = 1;
    }

    printf("Total MST Cost -> %d" , cost);
}


void kruskals(){
    int i , j , u , v , cost = 0 , count = 0 ;
    int parent[MAX];
    struct Edge temp ;

    for( i = 0 ; i < n ; i++ ){
        parent[i] = i;
    }

    for( i = 0 ; i < m - 1 ; i++){
        for( j = 0 ; j < m - i - 1 ; j++){
            if(e[j].w > e[j + 1].w){
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp ;
            }
        }
    }


    printf("Kruskals MST : \n");

    for(i = 0 ; i < m ; i++){
        u = e[i].u;
        v = e[i].v;

        while(parent[u] != u){
            u = parent[u];
        }

        while(parent[v] != v){
            v = parent[v];
        }

        if(u != v){
            printf("%d - %d = %d" , e[i].u  , e[i].v , e[i].w);

            cost += e[i].w;
            parent[u] = v ;
            count++;
        }

        if(count == n -1){
            break;
        }
    }

        if(count == n - 1){
            printf("Total MST cost Kruskals : %d" , cost);
        }else{
            printf("MST Not Possible");
        }
}

int main(){
    int u , v , w;

    printf("Enter the Number Of Vertices and Edges : ");
    scanf("%d%d",&n , &m);

    for(int i = 0 ; i < m  ; i++){
        printf("Enter the Source , Destination , Weigths : ");
        scanf("%d%d%d", &u , &v , &w);

        e[i].u = u ;
        e[i].v = v ;
        e[i].w = w ;

        graph[u][v] = w;
        graph[v][u] = w ;
    }

    prims();
    kruskals();

    return 0;
}