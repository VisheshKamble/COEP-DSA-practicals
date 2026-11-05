#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node *head = NULL;

void insertEnd(){
    struct Node*newNode = malloc(sizeof(struct Node));

    printf("Enter the Element : ");
    scanf("%d" , &newNode -> data);

    if(head == NULL){
        head = newNode;
        head -> next = head;
        return;
    }

    struct Node*temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }

    newNode -> next = head;
    temp -> next = newNode;

}


void deleteEnd(){
    struct Node*temp = head;
    struct Node*prev = NULL;

    if(head == NULL){
        return;
    }

    if(head -> next == head){
        head = NULL;
    }
    
    while(temp -> next != head){
        prev = temp;
        temp = temp -> next;
    }
    printf("Element Deleted : %d" , temp->data);
    prev -> next = head;

    free(temp);

}


void display(){
    struct Node*temp = head;

    if(head == NULL){
        printf("\nList is Empty");
        return;
    }

    do{
        printf("%d -> " , temp -> data);
        temp = temp -> next;
    }while(temp != head);

    printf("(HEAD)\n");
}

int main()
{
int choice;

while (1)
{
    printf("\n1. Insert At End");
    printf("\n2. Delete At End");
    printf("\n3. Display");
    printf("\n4. Exit");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            insertEnd();
            break;

        case 2:
            deleteEnd();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
    }
}

return 0;

}