#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow ;
    struct Node * next;
};

struct Node* insertend(struct Node *head , int c , int p){
    struct Node * newNode = malloc (sizeof(struct Node));

    newNode -> coeff = c ;
    newNode -> pow = p;
    newNode -> next = NULL;
    
    if(head == NULL){
        return newNode;
    }

    struct Node* temp = head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = newNode;

    return head;
}

void display(struct Node * head){
    struct Node* temp = head;

    if(head == NULL){
        printf("List Is Empty");
    }

    while(temp != NULL){
        printf("%dx^%d" , temp -> coeff , temp -> pow);

        if(temp -> next != NULL){
            printf("+");
        }

        temp = temp -> next;
    }

    printf("\n");
}


struct Node * add (struct Node * a  , struct Node * b){
    struct Node * result = NULL;

    while(a != NULL && b != NULL){
        if(a -> pow == b -> pow){
            result = insertend(result , a -> coeff + b -> coeff , a -> pow);

            a = a -> next;
            b = b -> next;
        }

        else if(a -> pow > b -> pow){
            result = insertend(result , a -> coeff , a -> pow);

            a = a -> next;
        }
        else{
            result = insertend(result , b -> coeff , b -> pow);
            b = b -> next;
        }
    }

    while(a != NULL){
        result = insertend(result , a -> coeff , a -> pow);
        a = a -> next;
    }

    while(b != NULL){
        result = insertend(result , b -> coeff , b -> pow);
        b = b -> next;
    }

    return result;
}

struct Node * sub (struct Node * a , struct Node * b){
    struct Node * result = NULL;

    while( a != NULL && b != NULL){
        if(a -> pow == b -> pow){
            result = insertend(result , a -> coeff - b -> coeff , a -> pow);

            a = a -> next ;
            b = b -> next ;
        }

        else if( a -> pow  > b -> pow){
            result = insertend(result , a -> coeff , a -> pow);

            a = a -> next;
        }

        else{
            result = insertend(result , -b -> coeff , b -> pow);

            b = b -> next;
        }
    }



    while (a != NULL){
        result = insertend(result , a -> coeff , a -> pow);
        a = a -> next;
    }

    while(b != NULL){
        result = insertend(result , b -> coeff , b -> pow);

        b = b -> next;
    }

    return result;
}


int main(){
    int n ; 
    int c ; 
    int p ;
    struct Node * a = NULL;
    struct Node * b = NULL;
    struct Node * result = NULL;

    printf("Enter the number of terms in first polynomial : ");
    scanf("%d" , &n);


    for(int i = 0 ; i < n ; i++){
        printf("Enter Coefficents and power : ");
        scanf("%d %d" , &c , &p);

        a = insertend(a , c , p);
    }

    printf("Enter the number of Terms of Second Polynomial : ");
    scanf("%d" , &n);


    for(int i = 0 ; i < n ; i++){
        printf("Enter the Coefficient and power : ");
        scanf("%d %d" , &c , &p);

        b = insertend(b , c , p);
    }

    printf("\nFirst Polynomial : ");
    display(a);

    printf("\nSecond Polynomial : ");
    display(b);

    result = add(a , b);
    printf("\nAddition of polynomials : ");
    display(result);

    result = sub(a , b);
    printf("\nSubtraction of polynomials : ");
    display(result);

    return 0;
}