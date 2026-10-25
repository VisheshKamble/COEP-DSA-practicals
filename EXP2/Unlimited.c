#include <stdio.h>

#include<stdlib.h>


struct Node{
    char digit;
    struct Node * next;
};

int main(){

    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode ;

    char ch ;

    printf("Enter a Large Number :  ");

    while((ch = getchar()) != '\n' && ch != EOF ){
        if(ch >= '0' && ch <= '9'){
            newNode = malloc(sizeof(struct Node));

            if(newNode == NULL){
                printf("Memory Not Allocated");
                return 1;
            }

            newNode -> digit = ch ;
            newNode -> next = NULL;

            if(head == NULL){
                head = newNode;
            }else{
                temp -> next = newNode;
            }

            temp = newNode;
        
        }
    }

    printf("Linked List : ");

    temp = head;

    while(temp != NULL){
        printf("%c -> " , temp -> digit);
        temp = temp -> next;
    }

printf("NULL\n");
return 0;

}