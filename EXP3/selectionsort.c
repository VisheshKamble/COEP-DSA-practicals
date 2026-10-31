#include<stdio.h>
#include<time.h>

int main(){
    int a[1000];
    int n ;
    int min ;
    clock_t start , end ;
    
    
    printf("Enter the Number of Elements : ");
    scanf("%d" , &n);

    printf("Enter Elements : ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &a[i]);
    }

    start = clock();

    for(int i = 0 ; i < n -1 ; i++){
        min = i ;
        for(int  j = i + 1 ; j < n ; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp ;
    }

    end = clock();

    printf("Sorted Elements : ");
    for(int i = 0 ; i < n ; i++){
        printf("%d ", a[i] );
    }


    printf("\n Time : %6f Seconds " , (double) (end - start) / CLOCKS_PER_SEC);



   return 0;


}