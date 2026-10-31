#include <stdio.h>
#include <time.h>

void quicksort(int a[] , int low , int high){
    int temp , pivot ;

    if(low < high){
        pivot = a[high];
        int i = low  - 1 ;
        for(int j = low ; j < high ; j++){
            if(a[j] < pivot){
                i++;

                temp = a[i];
                a[i] = a[j];
                a[j] = temp;

            }
        }

        temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp ;

        int p = i + 1;

        quicksort(a , low , p - 1);
        quicksort(a , p + 1 , high);
    }
}

int main(){

    int n ; 
    int a[1000];
    clock_t start , end ;

    printf("Enter the Number Of Elements : ");
    scanf("%d" , &n);

    printf("\nEnter The Elements : ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &a[i]);
    }


    start = clock();

    quicksort(a , 0 , n - 1);

    end = clock();

    printf("\nSorted Array :  ");
    for(int i = 0 ; i < n ; i++){
        printf("%d " , a[i]);
    }

    printf("\n Time  : %6f Seconds" , (double) (end - start) / CLOCKS_PER_SEC );

    return 0;
}