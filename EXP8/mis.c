#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertEnd(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPosition(int pos, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->data = data;

    if (pos <= 1 || head == NULL) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;

    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void deleteFirst(){
    struct Node* temp = head;
    if(head == NULL){
        return;
    }

    head = head -> next;

    free(temp);
}


void deleteLargest(){
    struct Node* temp = head ;
    struct Node* maxNode = head;
    struct Node* maxPrev = NULL;
    struct Node* prev = NULL;

    if(head == NULL){
        return;
    }

    while(temp != NULL){

        if(temp -> data > maxNode -> data){
            maxNode = temp;
            maxPrev = prev;
        }

        prev = temp;
        temp = temp -> next;
    }

    if(maxPrev == NULL){
        head = head -> next;
    }else{
        maxPrev -> next = maxNode -> next;
    }
    free(maxNode);
}


void deleteSmallest(){
    struct Node* temp = head;
    struct Node* minNode = head;
    struct Node* prev = NULL;
    struct Node* minPrev = NULL;


    if(head == NULL){
        return;
    }

    while(temp != NULL){

        if(temp -> data < minNode -> data){
            minNode = temp ;
            minPrev = prev;
        }

        prev = temp;
        temp = temp -> next;
    }

    if(minPrev == NULL){
        head = head -> next;
    }else{
        minPrev -> next = minNode -> next;
    }

    free(minNode);
}

int main() {
    int n, data, count;

    printf("Enter The Number Of MIS Digits: ");
    scanf("%d", &n);

    int mis[n];

    printf("Enter the MIS number: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &mis[i]);
    }

    for (int i = 0; i < n; i++) {
        count = 0;

        for (int j = 0; j < i; j++) {
            if (mis[i] == mis[j]) {
                count++;
            }
        }

        if (count == 0) {
            insertEnd(mis[i]);
        }
        else if (count == 1) {
            insertEnd(mis[i] * 10);
        }
        else if (count == 2) {
            insertAtPosition(3, mis[i] * 100);
        }
        else {
            insertEnd(mis[i]);
        }
    }

    printf("Linked List: ");
    display();

    deleteLargest();
    printf("\nAfter deleting largest:\n");
    display();

    deleteSmallest();
    printf("\nAfter deleting smallest:\n");
    display();

    deleteFirst();
    printf("\nAfter deleting first element:\n");
    display();

    return 0;
}