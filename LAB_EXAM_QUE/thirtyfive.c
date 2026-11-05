#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node * front = NULL;
struct Node * rear = NULL;

void enqueue(){
    struct Node *newNode = malloc(sizeof(struct Node));

    printf("Enter Element : ");
    scanf("%d" , &newNode->data);
    newNode -> next = NULL;

    if(front == NULL){
        front = newNode;
        rear = newNode;
    }
    else{
    rear -> next = newNode;
    }
    rear = newNode;

}

void dequeue(){
    if(front == NULL){
        printf("Queue is Empty\n");
        return;
    }

    struct Node * temp = front;
    printf("Dequeue Element : %d" , front -> data);

    front = front -> next;

    if(front == NULL){
        rear == NULL;
    }

    free(temp);
}


void display(){
    if(front == NULL){
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp = front;

    while(temp != NULL){
        printf("%d -> " , temp -> data);
        temp = temp -> next;
    }
}

int main(){
int choice;

while (1)
{
    printf("\n1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Display");
    printf("\n4. Exit");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
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