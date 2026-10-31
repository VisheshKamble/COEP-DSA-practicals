#include<stdio.h>

int main(){
    int a[100];
    int n ; 

    FILE *fp;

    fp = fopen("numbers.txt" , "r");

    if(fp == NULL){
        printf("File Not Found");
        return 1;
    }

    fscanf(fp , "%d" , &n);

    for(int i = 0 ; i < n ; i++){
        fscanf(fp , "%d" , &a[i]);
    }

    fclose(fp);

    for(int i = 0 ; i < n - 1; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("Sorted Numbers From File : ");
    for(int i = 0 ; i < n ; i++){
        printf("%d ", a[i]);
    }

return 0;

}