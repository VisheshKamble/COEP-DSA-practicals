#include<stdio.h>
#include <stdlib.h>

void removeduplicates(double a[] , int *n){
    for(int i = 0 ; i < *n ; i++){
        for(int j = i + 1 ; j < *n ; j++){
            if(a[j] == a[i]){
                for(int k = j ; k < *n -1 ; k++){
                    a[k] = a[k + 1];
                 }
                 (*n)--;
                 j--;
            }
        }
    } 
}

int main(){
    double a[100];
    int n;
    printf("\nEnter the number of elements : ");
    scanf("%d" , &n);

    printf("\nEnter the duplicate elements : ");
    for(int i = 0 ; i < n ; i++){
        scanf("%lf " , &a[i]);
    }

    removeduplicates(a , &n);

    printf("\nRemoved Duplicates : ");
    for(int i = 0 ; i < n ; i++){
        printf("%g " , a[i] );
    }

    return 0;

}