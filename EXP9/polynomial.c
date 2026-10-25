#include <stdio.h>
#include <stdlib.h>


struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

//insert term at end 

struct Node* insert(struct Node* head , int c , int p ){

    struct Node *newNode = malloc (sizeof(struct Node));

    newNode -> coeff = c ;
    newNode -> pow = p ;
    newNode -> next = NULL;

    if(head == NULL){
        return newNode;
    }

    struct Node* temp = head ;
    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = newNode;

  return head;
}

//display the polynomial 

void display(struct Node* head){

    struct Node* temp = head;

    while(temp != NULL){
        printf("%dx^%d" , temp -> coeff , temp -> pow);

        if(temp -> next != NULL){
            printf(" + ");
        }

        temp = temp -> next;
    
    }

    printf("\n");
}

struct Node* add(struct Node* a , struct Node* b){

    struct Node* result = NULL;

    while(a != NULL && b != NULL){

        if(a -> pow == b -> pow){
            result = insert(result , a -> coeff + b -> coeff , a -> pow );

            a = a -> next;
            b = b -> next;

        }
        else if(a -> pow > b -> pow){
            result = insert(result , a -> coeff , a -> pow);

            a = a -> next;

        }
        else {
            result = insert(result , b -> coeff , b -> pow);

            b = b -> next;
        }        
    }

    while(a != NULL){
        result = insert(result , a -> coeff , a -> pow);
        a = a -> next;
    }

    while(b != NULL){
        result = insert(result , b -> coeff , b -> pow);
    }
    return result;
}


//subtract 

struct Node* sub (struct Node *a , struct Node *b){
    struct Node* result = NULL;

    while(a != NULL && b != NULL){

        if(a -> pow == b -> pow){

            result = insert(result , a -> coeff - b -> coeff , a -> pow);

            a = a-> next ;
            b = b -> next ;
        }
        else if(a -> pow > b -> pow){
            result = insert(result , a -> coeff , a -> pow);

            a = a-> next;
        }
        else {
            result = insert (result  , b -> coeff , b -> pow);
            b = b -> next;
        }
    }

    while (a != NULL){
        result = insert(result , a-> coeff , a-> pow);
        a = a -> next;
    }

    while (b!= NULL){
        result = insert(result , b -> coeff , b -> pow);
        b = b-> next;
    }
    return result;
}


int main(){

    struct Node * a = NULL;
    struct Node * b = NULL ;
    struct Node * result = NULL;
    int n ;
    int c ;
    int p ;

    printf("Enter the Number Of Terms : ");
    scanf("%d" , &n);

    for (int i = 0 ; i < n ; i++){
        printf("Enter Coefficient and power : ");
        scanf("%d %d" , &c , &p);

        a = insert(a , c , p);
    }

    printf("Enter the number of Terms of Second Polynomial : ");
    scanf("%d" , &n);

    for(int i = 0 ; i < n ; i++){
        printf("Enter Coefficient and power : ");
        scanf("%d %d" , &c , &p);

        b = insert(b , c , p);
    }

    printf("\n First Polynomial :  ");
    display(a);

    printf("\n Second Polynoimal : ");
    display(b);

    printf("Addition :  ");
    result = add(a , b);
    display(result);

    printf("Subtraction : ");
    result = add(a , b);
    display(result);

    return 0;
}