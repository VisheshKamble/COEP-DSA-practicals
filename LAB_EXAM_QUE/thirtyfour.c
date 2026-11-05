#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1; 
int rear = -1;

void enqueue(){
    int value ;

    if(rear == SIZE -1){
        printf("Queue is FULL\n");
        return;
    }
    else{

        printf("Enter Element : ");
        scanf("%d" , &value);

        if(front == -1){
            front = 0;
        }

        rear++;
        queue[rear] = value;
    }
    printf("Value Inserted \n");
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue is Empty \n");
        return;
    }
    printf("Element Dequeue : %d" , queue[front]);
    front++;

    if(front > rear){
        front = -1;
        rear = -1;
    }
}

void display(){
    if(front == -1 || rear == -1){
        printf("Queue is Empty\n");
        return;
    }

    for(int i = front ; i <= rear ; i++){
        printf("QUEUE : %d" , queue[i]);
    }
}

int main(){
    int ch;
    do{
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Enter Choice : ");
        scanf("%d" , &ch);

        switch(ch){
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
            printf("Exiting...");
            break;

            default:
            printf("Invalid");
        }

    }while(ch != 4);
}