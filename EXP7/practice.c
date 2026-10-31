#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node* head = NULL;

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

    head = a ;
    a -> next = b ;
    b -> next = c ;
    c -> next = d ;
    d -> next = e ;
    e -> next = NULL ;
}


void display(){
    if(head == NULL){
        printf("List Is Empty");
        return;
    }

    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> " , temp -> data);
        temp = temp -> next;
    }

    printf("NULL \n");
}


void count(){
    int count = 0;

    if(head == NULL){
        printf("List Is Empty");
        return;
    }

    struct Node * temp = head;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }

    printf("Total Number Of Elements : %d \n" , count);
}


void reverse (struct Node* temp){
    if(temp == NULL){
        return ;
    }

    reverse(temp -> next);
    printf("%d -> " , temp -> data);

}

void search(){
    int element;
    int pos = 1;
    printf("Enter the Element You Have to Search For : ");
    scanf("%d" , &element);

    struct Node* temp = head ;

    if(head == NULL){
        printf("List Is Empty ! Hence Cannot Found");
        free(temp);
        return;
    }

    while(temp != NULL && temp -> data != element){
        pos++;
        temp = temp -> next;
    }

    if(temp == NULL){
        printf("element Not In The List");
        return;
    }

    printf("Element found at position : %d ! \n" , pos );

}

void deleteBeginning(){
    struct Node *temp = head;

    if(head == NULL){
        printf("List Is Empty");
        return;
    }

    head = head -> next;
    free(temp);

    printf("Deletion At Beginning Successful\n");
}

void deleteEnd(){
    struct Node *temp ;

    if(head == NULL){
        printf("List Is Empty");
        return;
    }

    if(head -> next == NULL){
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }

    free(temp -> next);
    temp -> next = NULL;

    printf("Deleted Last Successfully\n");

}


void deleteSpecific(){

    struct Node * prev = NULL;
    struct Node * temp = NULL;

    int element;

    printf("Enter the Element To be Deleted : ");
    scanf("%d" , &element);

    if(head == NULL){
        printf("List Is Empty");
        return;
    }

    temp = head ;
    while(temp != NULL && temp -> data !=  element){
        prev = temp;
        temp = temp -> next;
    }

    prev -> next = temp -> next;

    free(temp);

    printf("Element Deleted SuccessFully\n");

}

int main(){
    int ch;

    create();
    display();

    do{
        printf("1.Reverse \n");
        printf("2.count \n");
        printf("3.delete Beginning \n");
        printf("4.search \n");
        printf("5:Delete End\n");
        printf("6.Delete Specific\n");
        printf("7.Display\n");
        printf("8. Exit \n");

        printf("Enter Choice : ");
        scanf("%d" , &ch);

        switch(ch){
            case 1:
            if(head == NULL){
                printf("List is Empty");
            }else{
                printf("Reverse List : ");
                reverse(head);
                printf("NULL\n");
            }

            break;

            case 2:
            count();
            break;

            case 3:
            deleteBeginning();
            break;

            case 4:
            search();
            break;

            case 5:
            deleteEnd();
            break;

            case 6:
            deleteSpecific();
            break;

            case 7:
            display();
            break;

            case 8:
            printf("Exit....");
            break;

            default:
            printf("Invalid");

        }

    }while(ch != 8);
   

    return 0;
}