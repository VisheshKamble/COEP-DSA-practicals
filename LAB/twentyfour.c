#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(){
    struct Node *newNode = malloc(sizeof(struct Node));

    printf("Enter Element To Be Inserted : ");
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

    head = newNode;
}

void deletebeginning(){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    if(head -> next == head){
        head = NULL;
        return;
    }

    struct Node* temp = head;
    struct Node*last = head;

    while(last -> next != head){
        last = last -> next;
    }
    printf("\nElement Deleted : %d" , head -> data);
    head = head -> next;
    last -> next = head;

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
    printf("\n1. Insert At Beginning");
    printf("\n2. Delete At Beginning");
    printf("\n3. Display");
    printf("\n4. Exit");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            insertBeginning();
            break;

        case 2:
            deletebeginning();
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