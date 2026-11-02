#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*prev ;
    struct Node *next;
};

struct Node *head = NULL;

void insertbeginning(){
    struct Node* newNode = malloc(sizeof(struct Node));

    printf("Enter Element : ");
    scanf("%d" , &newNode -> data);

    newNode -> prev = NULL;

    if(head == NULL){
        newNode -> next = NULL; 
        head = newNode;
        return;
    }

    newNode -> next = head;
    head -> prev = newNode;

    head = newNode;
}

void insertEnd(){
    struct Node *newNode = malloc(sizeof(struct Node));
    printf("\nEnter Element : ");
    scanf("%d" , &newNode -> data);

    newNode -> next = NULL;
    if(head == NULL){
        newNode -> prev = NULL;
        head = newNode;
        return;
    }

    struct Node * temp = head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = newNode;
    newNode -> prev = temp;
}

void insertAfter(){
    struct Node *newNode = malloc(sizeof(struct Node));
    int n;
    printf("\nEnter the element after which you to insert : ");
    scanf("%d" , &n);

    printf("\nEnter Element : ");
    scanf("%d" , &newNode ->data);

    if(head == NULL){
        newNode -> prev = NULL;
        newNode -> next = NULL;
        head = newNode;
        return ;
    }

    struct Node *temp = head ;

    while(temp != NULL && temp -> data != n){
        temp = temp -> next;
    }

    if(temp == NULL){
        printf("Doesnt Exists");
        return;
    }
    newNode -> prev = temp;
    newNode -> next = temp -> next;
    if(temp -> next != NULL){
        temp -> next -> prev = newNode;
    }

    temp -> next = newNode;
}

void display(){
    if(head == NULL){
        return ;
    }
    struct Node *temp = head;

    while(temp != NULL){
        printf("%d <-> " , temp -> data);
        temp = temp -> next;
    }
  printf("NULL\n");
}

int main(){
insertbeginning();
display();

insertbeginning();
display();

insertbeginning();
display();

insertEnd();
display();

insertEnd();
display();

insertAfter();
display();

return 0;
   
}