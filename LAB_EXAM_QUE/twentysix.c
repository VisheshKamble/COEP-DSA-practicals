#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*head = NULL;

void create(){
    struct Node*a , *b , *c , *d , *e;

    a = malloc(sizeof(struct Node));
    b = malloc(sizeof(struct Node));
    e = malloc(sizeof(struct Node));
    d = malloc(sizeof(struct Node));
    e = malloc(sizeof(struct Node));

    a -> data = 10;
    b -> data = 20;
    c -> data = 30;
    d -> data = 40;
    e -> data = 50;



    head = a ;
    a -> next = b ;
    b -> next = c ;
    c -> next = d ;
    d -> next = e ;
    e -> next = head ;

}


void search(){
    int element;
    struct Node*temp = head;
    int pos = 1;

    if(head == NULL){
        return;
    }

    printf("Enter the element to be search : ");
    scanf("%d" , &element);

    while(temp -> next != head && temp -> data != element){
        pos++;
        temp = temp -> next;
    }

    if(temp -> next == head && temp -> data != element){
        printf("Element not found");
    }

    printf("Element Found At Position : %d " , pos);

}

void count(){
    struct Node*temp = head;
    int count = 1;

    if(head == NULL){
        return;
    }

    while(temp -> next != head){
        count++;
        temp = temp -> next;
    }
    printf("Count Of Nodes : %d" , count);
}


int main(){
    create();
    search();
    count();
}