#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* head = NULL;

void insertEnd(int data){

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode ;
        return;
    }

    struct Node * temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = newNode;


}

void insertAtSpecific(int pos  , int data){
    struct Node * newNode = malloc(sizeof(struct Node));
    newNode -> data = data;

    if(pos <= 1 || head == NULL){
        head = newNode;
        return;
    }

    struct Node *temp = head;

    for(int i = 1 ; i < pos - 1 && temp != NULL ; i++){
        temp = temp -> next;
    }

    if(temp == NULL){
        printf("Position Not In Array");
        return;
    }

    newNode -> next = temp -> next;
    temp-> next = newNode;


}

void display(){
    struct Node* temp ;
    if(head == NULL){
        return ;
    }

    temp = head;
    while(temp != NULL){
        printf("%d -> " , temp -> data);
        temp = temp -> next;
    }

    printf("NULL \n");    
}


void deleteFirst(){
    struct Node* temp ;
    if(head == NULL){
        printf("List Is Empty");
        return;
    }

    temp = head;
    head = head -> next;
    free(temp);
}


void deleteLargest(){
    struct Node*temp = head;
    struct Node*prev = NULL;
    struct Node*max = head;
    struct Node*maxprev = NULL;

    if(head == NULL){
        printf("List Is Empty");
        return;
    }

    if(head -> next == NULL){
        printf("Only One In the List and Deleted");
        free(head);
    }

    while(temp != NULL){
        if(max -> data < temp -> data){
            maxprev = prev;
            max = temp;
        }

        prev = temp ;
        temp = temp -> next;
    }

    maxprev -> next = max -> next;
    free(max);
    
}

void deleteSmallest(){
    struct Node * temp = head;
    struct Node * min = head;
    struct Node * prev = NULL;
    struct Node* minprev = NULL;

    if(head == NULL){
        printf("List Is Empty");
        return;
    }

    if(head -> next == NULL){
        printf("Only One Element and Hence deleted");
        return;
    }


    while(temp != NULL){
        if(min -> data > temp -> data){
            min = temp ;
            minprev = prev;
        }

        prev = temp;
        temp = temp -> next;
    }

    minprev -> next = min -> next;
    free (min);

}

int main(){
    int n ;
    int a[1000];
    int count ;
    printf("Enter the digits in MIS : ");
    scanf("%d" , &n);

    printf("Enter Your MIS : " );
    for (int i = 0 ; i < n ; i++){
        scanf("%d" , &a[i]);
    } 

    for(int i = 0 ; i < n ; i++){
        count = 0;
        for(int j = 0 ; j < i ; j++){
            if(a[j] == a[i]){
                count++;
            }
        }

        if(count == 0){
            insertEnd(a[i]);
        }
        else if(count == 1){
            insertEnd(a[i] * 10);
        }
        else if(count == 2){
            insertAtSpecific(2 , a[i]*100);
        }
        else{
            insertEnd(a[i]);
        }
    }

    display();

    printf("Delete First \n");
    deleteFirst();

    display();

    printf("Delete Largest \n");
    deleteLargest();

    display();

    printf("Delete Smallest \n");
    deleteSmallest();

    display();

}