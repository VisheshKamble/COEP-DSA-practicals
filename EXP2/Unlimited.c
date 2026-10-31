#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char digit;
    struct Node * next;
}Integer;

int main(){
    Integer *head = NULL , *temp = NULL , *newNode ;

    printf("Enter a Large Number : ");
    char ch;
    
    while((ch = getchar()) != '\n' && ch != EOF){

        if(ch >= '0' && ch <= '9'){
        newNode = malloc(sizeof(Integer));
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

printf("Large Integer : ");

temp = head;
while(temp != NULL){
    printf("%c " , temp -> digit);
    temp = temp -> next;
}

printf("NULL");

return 0;

}