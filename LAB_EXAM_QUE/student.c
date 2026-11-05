#include<stdio.h>
#include<stdlib.h>

struct Student {
    int rollno;
    int marks;
    char name[20];
};

void sortstudents(struct Student s[] , int n){
    int min ;
    struct Student temp;
    for(int i = 0 ; i < n - 1 ; i++){
        min = i;

        for(int j = i + 1 ; j < n ; j++){
            if(s[j].marks < s[min].marks){
                min = j;
            }
        }

        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
}

void displaysort(struct Student s[] , int n){
    
    for(int i = 0 ; i < n ; i++){
    printf("%d %d %s \n" , s[i].rollno , s[i].marks , s[i].name );
    }
}

int main(){

    struct Student s[10];
    int n ;

    printf("Enter the number of Student : ");
    scanf("%d" , &n);

    for(int i = 0 ; i < n ; i++){
        printf("Enter Roll No , Marks , Name : ");
        scanf("%d %d %s" , &s[i].rollno , &s[i].marks , &s[i].name);
    }

    sortstudents(s , n);

    printf("Sorted Records : \n");
    displaysort(s , n);
}