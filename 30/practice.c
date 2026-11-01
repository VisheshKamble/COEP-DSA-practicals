#include <stdio.h>
#define MAX 10

struct Edge{
    int u , v , w;
};

struct Edge e[45];
int n , m ;

int findparent (int parent[] , int v){
    if(parent[v] != v){
        v = parent[v];
    }
    return v;
}

void kruskals(){
    int u , v , cost = 0 , count = 0;

    int parent[MAX];
    struct Edge temp;

    for(int i = 0 ; i < n ; i++){
        parent[i] = i;
    }

    for(int i = 0 ; i < m - 1 ; i++){
        for(int j = 0 ; j < m - i - 1 ; j++){
            if(e[j].w > e[j+1].w){
                temp = e[j];
                e[j] = e[j+1];
                e[j+1] = temp;
            }
        }
    }

    printf("Kruskals MST : \n");

    for(int i = 0 ; i < m ; i++){
        u = findparent(parent , e[i].u);
        v = findparent(parent , e[i].v);

        if(u != v){
            printf("%d -- %d = %d\n" , e[i].u , e[i].v , e[i].w);

            cost += e[i].w;
            parent[u] = v;
            count++;
        }
        if(count == n - 1){
            break;
        }
    }

    if(count == n - 1){
        printf("\nTotal Cost : %d" , cost);
    }
   
    else{
        printf("MST NOT POSSIBLE;");
    }
}


int main(){
   

    printf("Enter the number of vertices : ");
    scanf("%d" , &n);
    printf("Enter the Number Of Edges : ");
    scanf("%d" , &m);
    printf("Enter Source Destination and Weight : \n");
    for(int i = 0 ; i < m ; i++ ){
        scanf("%d%d%d" , &e[i].u , &e[i].v , &e[i].w); 
    }

    kruskals();

    return 0;
}