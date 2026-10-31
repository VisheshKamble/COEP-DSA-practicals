#include<stdio.h>
#include<time.h>

int main(){
    int a[1000];
    int n;
    clock_t start , end ;

    printf("Enter the number of elements : ");
    scanf("%d" , &n);

    printf("\nEnter the elements :  ");
    for (int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    }

    start = clock();

    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    end = clock();

    printf("Sorted Elements : ");
    for(int i = 0 ; i < n ; i++){
        printf("%d " , a[i]);
    }

    printf("\nTime : %6f seconds" , (double) (end - start) / CLOCKS_PER_SEC);

  return 0;

}
