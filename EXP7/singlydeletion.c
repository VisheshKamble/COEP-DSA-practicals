#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data ;
    struct Node * next ;
};

struct Node * head  = NULL;

void create(){
    struct Node *a , *b , *c , *d , *e;
    a = malloc(sizeof(struct Node));
    b = malloc(sizeof(struct Node));
    c = malloc(sizeof(struct Node));
    d = malloc(sizeof(struct Node));
    e = malloc(sizeof(struct Node));


    a -> data = 10;
    b -> data = 20;
    c -> data = 30;
    d -> data = 40;
    e -> data = 50;

    head = a;
    a -> next = b;
    b -> next = c;
    c -> next = d;
    d -> next = e ;
    e -> next = NULL;

}


void display(){
    struct Node* temp = head ;

    if(head == NULL){
        printf("List Is Empty : ");
        return;
    }

    while(temp != NULL){
        printf("%d -> " , temp -> data);
        temp = temp -> next;
    }

    printf("NULL ");
}


void count(){
    struct Node * temp = head;
    int count = 0  ;

    if(head == NULL){
        printf("\nList Count : %d " , count );
        return ;
    }

    while(temp != NULL){
        count++;
        temp = temp -> next;
    }

    printf("\nElements in the List : %d " , count);
}


void reverse(struct Node* temp){
    if(temp == NULL){
        return;
    }

    reverse(temp->next);
    printf("%d -> " , temp -> data);
}

void deleteBeginning(){
    struct Node* temp ;

    if(head == NULL){
        printf("\nList Is Empty");
        return;
    }

    if(head -> next == NULL){
        printf("\nElement Deleted : %d" , head -> data);
        free(head);
        head = NULL;
        return; 
    }

    temp = head;
    head = head -> next;
    printf("\nElement deleted  : %d" , temp -> data );
    free(temp);

    printf("\n Element Deleted Successfully");
}

void deleteEnd(){
    struct Node*temp;
    
    if(head == NULL){
        printf("\nList Is Empty");
        return;
    }

    if(head -> next == NULL){
        printf("\nElement Deleted : %d ", head -> data);
        free(head);
        return;
    }

    temp = head;

    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    printf("\nElement Deleted : %d" , temp -> next -> data);
    free(temp -> next);

    temp -> next = NULL;
    return;
}

void deleteSpecific(){
    struct Node* temp ;
    struct Node* prev = NULL ;
    
    int element;

    printf("Enter Element to be deleted : ");
    scanf("%d" , &element);
    if(head == NULL){
        printf("\nList Is Empty");
        return;
    }

    temp = head;

    while(temp != NULL && temp -> data != element){
        prev = temp ;
        temp = temp -> next;
    }

    if(temp == NULL){
        printf("\nELement not found");
        return;
    }

    if(prev == NULL){
        head = head -> next;
    }else{
    prev -> next = temp -> next;
    }

    free(temp);
    printf("\nSpecific Element Deleted");
}

void search(){
    int element ;
    struct Node* temp = head ;
    int pos = 1;

    printf("Enter Element To Be Searched : ");
    scanf("%d" , &element);

    if(head == NULL){
        printf("\nElement Not Found , List Is Empty");
        return;
    }

    while(temp != NULL && temp -> data != element){
        pos++;
        temp = temp -> next;
    }

    if(temp == NULL){
        printf("\nElement Not Found");
        return;
    }

    printf("Element Found At Position : %d" , pos);

}


int main(){
    int choice ;

    create();
    display();

    do{
        printf("\n 1.Delete Beginning");
        printf("\n 2.Delete End");
        printf("\n 3.Delete Specific");
        printf("\n 4.Reverse");
        printf("\n 5.Display");
        printf("\n 6.Search");
        printf("\n 7.Count");
        printf("\n 8.Exit");


        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            deleteBeginning();
            break;

            case 2:
            deleteEnd();
            break;

            case 3:
            deleteSpecific();
            break;

            case 4:
            if(head == NULL){
                printf("\nList is Empty");
            }else{
                printf("Reverse List : ");
                reverse(head);
                printf("NULL\n");
            }
            break;

            case 5:
            display();
            break;

            case 6:
            search();
            break;

            case 7:
            count();
            break;

            case 8: 
            printf("Terminating.....");
            break;

            default :
            printf("Invalid Choice");
        }

    }while(choice != 8);
}