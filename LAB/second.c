#include <stdio.h>
#include <stdlib.h>

int binarySearch(int a[] , int target , int n){
    int start = 0 ; 
    int end = n -1;
    
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(a[mid] == target){
            printf("\nTarget Found ");
            return mid;
        }
        else if(target < a[mid] ){
            end = mid - 1;
        }
        else if(target > a[mid]){
            start = mid + 1;
        }
    }
    printf("\nTarget Not Found\n");
    return -1;
}

void insertionSort(int a[] , int n){
    for (int i = 1 ; i < n ; i++){
        int key = a[i];
        int j = i - 1;

        while( j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void display(int a[] , int n){
    for(int i = 0 ; i < n ; i++){
        printf("%d , " , a[i]);
    }
}

int main(){
    int n ;
    int a[100];
    int target;

    printf("\nEnter the Number of elements : ");
    scanf("%d" , &n);

    printf("\nEnter Elements : ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &a[i]);
    }

    printf("\nEnter the Element you want to search : ");
    scanf("%d" , &target);

    display(a , n);

    binarySearch(a , target , n);

    insertionSort(a , n);
    display(a , n);


}