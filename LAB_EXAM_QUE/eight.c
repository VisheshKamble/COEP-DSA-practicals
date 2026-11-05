#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
void createNode(){
    struct Node* a , *b , *c , *d , *e;

    a = malloc(sizeof(struct Node));
    b = malloc(sizeof(struct Node));
    c = malloc(sizeof(struct Node));
    d = malloc(sizeof(struct Node));
    e = malloc(sizeof(struct Node));

    a -> data = 10;
    b -> data = 20;
    c -> data = 30;
    d -> data = 40; 
    e -> data = 50;
    
    head = a;
    a -> next = b;
    b -> next = c;
    c -> next = d;
    d -> next = e;
    e -> next = NULL;
}

void display(){
    struct Node *temp = head;
    if(head == NULL){
        return;
    }

    while(temp != NULL){
        printf("%d -> " , temp -> data);
        temp = temp -> next;
    }
  printf("NULL\n");
}

 void reverse(){
    struct Node*curr = head;
    struct Node*prev = NULL;
    struct Node*temp ;

    if(head == NULL){
        return;
    }

    while(curr != NULL){
        temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }

    head = prev;
}

int main(){

    createNode();
    display();

    printf("\nReversed : ");
    reverse();
    display();

}