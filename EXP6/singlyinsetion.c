#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *head = NULL;

void insertBeginning(){
struct Node * newNode ;
newNode = (struct Node*)malloc(sizeof(struct Node));

printf("Enter Element : ");
scanf("%d" , &newNode->data);
newNode -> next = head;
head = newNode;

printf("Element Inserted at Beginning\n");

}

void insertEnd(){
    struct Node* newNode ;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter Element : ");
    scanf("%d" , &newNode->data);
    
    newNode->next  = NULL;
    

    if(head == NULL){
        head = newNode;
    }

    struct Node* temp = head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = newNode;

    printf("Element Inserted at End\n");
}


void insertAfterElement (){
    struct Node* newNode ;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("After Which Element you want to Insert : ");
    int element ;
    scanf("%d" , &element);

    struct Node* temp = head ;

    while (temp != NULL && temp -> data != element){
        temp = temp -> next;
    }

    if(temp == NULL){
        printf("Element Not Found\n");
        return;
    }

    printf("Enter Element : ");
    scanf("%d" , &newNode->data);
    newNode -> next = temp -> next;
    temp -> next = newNode;

    printf("Element Inserted After %d\n", element);
}




void display(){
    struct Node* temp = head;

    if(temp == NULL){ 
        printf("List is Empty\n");
        return;
    }

    printf("Elements in the List : ");
    while(temp != NULL){
        printf("%d -> " , temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main(){
    int choice;

    do{
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Element\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");


        scanf("%d" , &choice);

        switch(choice){
            case 1:
                insertBeginning();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                insertAfterElement();
                break;
            case 4:
                display();
                break;
            case 5: 
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    }while(choice != 4);
}
