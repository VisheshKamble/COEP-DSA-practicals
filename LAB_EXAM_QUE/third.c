#include<stdio.h>
#include<stdlib.h>

void quicksort(int a[] , int low , int high){

    if(low < high){

    int pivot = a[high];
    int i = low -1;
    int temp;

    for(int  j = low ; j < high ; j++){
        if(a[j] < pivot){
            i++;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp; 
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    int p = i + 1;

    quicksort(a , low, p -1);
    quicksort(a , p + 1 , high);
}
}


int linearSearch(int a[] , int target , int n){
    for(int i = 0 ; i < n ; i++){
        if(a[i] == target){
            printf("Element Found");
            return 1;
        }
    }

    printf("Element Not Found");
    return -1;
}

void display(int a[] , int n){
    for(int i = 0 ; i < n ; i++){
        printf("%d , " , a[i]);
    }
}

int main(){
    int a[100];
    int n;
    int target ;

    printf("Enter the Number Of Elements : ");
    scanf("%d" , &n);

    printf("\nEnter Elements : ");
    for(int i = 0 ; i < n ; i++){
    scanf("%d" , &a[i]);
    }

    quicksort(a , 0 , n - 1);

    printf("element you want to search : ");
    scanf("%d" , &target);

    linearSearch(a , target , n);

    display(a , n);

}