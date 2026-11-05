#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int pow;
    struct Node* next;
};

struct Node *insertEnd(struct Node*head , int c , int p){
    struct Node*newNode = malloc(sizeof(struct Node));

    newNode -> coeff = c;
    newNode -> pow = p;
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode;
        return head;
    }

    struct Node *temp = head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;

    return head;
}


void display(struct Node* head){
    struct Node * temp = head;
    if(head == NULL){
        return;
    }

    while(temp != NULL){
        printf("%dx^%d" , temp -> coeff , temp -> pow);
        if(temp -> next!= NULL){
            printf("+");
        }
        temp = temp -> next;
    }
}


struct Node * add(struct Node * a , struct Node * b){
    struct Node * result = NULL;

    while(a != NULL && b != NULL){
        if(a -> pow == b -> pow){
            result = insertEnd(result , a -> coeff + b -> coeff , a -> pow);

            a = a -> next;
            b = b -> next;
        }
        else if(a -> pow > b -> pow){
            result = insertEnd(result , a -> coeff , a -> pow);
            a = a -> next;
        }
        else{
            result = insertEnd(result , b -> coeff , b -> pow);
            b = b -> next;
        }
    }

    while(a != NULL){
        result = insertEnd(result , a -> coeff , a -> pow);
        a = a -> next;
    }
    while(b != NULL){
        result  = insertEnd(result , b -> coeff , b -> pow);
    }


    return result;
}

int main(){

    struct Node *a = NULL;
    struct Node *b = NULL;
    struct Node *result = NULL;
    int c;
    int p;
    int n;

    printf("\nEnter the number of terms for first : ");
    scanf("%d" , &n);
    
    printf("\nEnter For First Polynomial : \n");
    for(int i = 0 ; i < n ; i++){
        printf("\nEnter Coeff and power : ");
        scanf("%d %d" , &c , &p);

        a = insertEnd(a , c , p);
    }

    
    printf("\nEnter the number of terms for second : ");
    scanf("%d" , &n);

    printf("\nEnter For second Polynomial : \n");
    for(int i = 0 ; i < n ; i++){
        printf("\nEnter Coeff and power : ");
        scanf("%d %d" , &c , &p);

        b = insertEnd(b , c , p);
    }


    printf("\nFirst Polynomial : ");
    display(a);

    printf("\nSecond Polynomial : ");
    display(b);

    printf("\nAdditon : ");
    result = add(a , b);
    display(result);

    return 0;
}