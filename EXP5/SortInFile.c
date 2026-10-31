#include<stdio.h>
#include<string.h>

int main(){
    char name[100][100] , temp[100];
    int n = 0 ;

    FILE *fp;

    fp = fopen("names.txt" , "r");

    if(fp == NULL){
        printf("File Not Found");
        return 1;
    }

    while(fgets(name[n] , 100 , fp)  != NULL){
        name[n][strcspn(name[n] , "\n")] = '\0';
        n++;
    }

    fclose(fp);

    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(strcmp(name[j] , name[j + 1]) > 0){
                strcpy(temp , name[j]);
                strcpy(name[j] , name[j + 1]);
                strcpy(name[j + 1] , temp);
            }
        }
    }

    printf("Alphabetic<al Order Display : ");
    for(int i = 0 ; i < n ; i++){
        printf("%s " , name[i]);
    }
    return 0 ;
}