#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];

int top = -1;

void pushArray(int data){
    if(top == MAX -1){
        printf("Stack Overflow \n");
        return;
    }
    stack[++top] = data;
}

void popArray(){
    if(top == -1){
        printf("Stack UnderFlow");
        return;
    }

    printf("\nElement Popped %d " , stack[top--]);
}

void display(){
    int i ;

    if(top == -1){
        printf("\nStack in empty");
        return;
    }
    printf("TOP -> ");
    for(i = top ; i >= 0 ; i--){
        printf("%d " , stack[i]);
    }
}

int main(){
    int ch ;
    int element;

    do{
        printf("\n1 .Push");
        printf("\n2 .Pop");
        printf("\n3 .Display");

        printf("\nEnter Your Choice : ");
        scanf("%d" , &ch);

        switch(ch){
            case 1:
            printf("Element to push : ");
            scanf("%d" , &element);
            pushArray(element);

            break;

            case 2:
            popArray();
            break;

            case 3:
            display();
            break;

            case 4:
            printf("Exiting....");
            break;

            default:
            printf("invalid");

        }
    }while(ch != 4);

    return 0;
}