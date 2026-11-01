#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data ;
    struct Node * next;
};

struct Node * head = NULL;

void reverse(){
    struct Node*curr = head , *temp , *prev = NULL;

    while(curr != NULL){
        temp = curr -> next;
        curr -> next = prev ;
        prev = curr;
        curr = temp;
    }

    head = prev;
}

void display(){
    struct Node* temp = head;
    if(head == NULL){
        return;
    }

    while(temp != NULL){
        printf("%d -> " , temp -> data);
        temp = temp -> next;
    }

    printf("NULL\n");
}

int main(){

    int n ;
    struct Node * temp = head;
    
    printf("Enter the size of list : ");
    scanf("%d" , &n);

    for(int i = 0 ; i < n ; i++){
         struct Node * newNode = malloc(sizeof(struct Node));
        printf("\nEnter the Element: ");
        scanf("%d" , &newNode -> data);

        newNode -> next = NULL;

        if(head == NULL){
            head = newNode;
        }else{
            temp -> next = newNode;

        }
        temp = newNode;
    }


    printf("\nOriginal List : ");
    display();

    printf("\nReversed List : ");
    reverse();
    display();

    return 0;
}