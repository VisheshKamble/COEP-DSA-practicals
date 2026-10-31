#include <stdio.h>
#include <time.h>

int main(){
    clock_t start , end ;
    int key , j ;
    int n ;
    int a[1000];

    printf("Enter the number of elements : ");
    scanf("%d" , &n);

    printf("Enter Elements : ");
    for(int  i = 0 ; i < n ; i++){
        scanf("%d" , &a[i]);
    }

    start = clock();
    for(int i = 1 ; i < n ; i++){
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }

    end = clock();


    printf("Sorted Array : ");
    for(int i = 0 ; i < n ; i++){
        printf("%d " , a[i]);
    }

    printf("\n Time : %6f Seconds" , (double) (end - start) / CLOCKS_PER_SEC );

    return 0;
}