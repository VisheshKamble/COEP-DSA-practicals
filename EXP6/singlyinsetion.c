
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning()
{
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
        return;

    printf("Enter the element to insert at beginning: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;

    printf("Successfully inserted at the beginning.\n");
}

void insertEnd()
{
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
        return;

    printf("Enter the element to insert at end: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Successfully inserted at the end.\n");
}

void insertAfterElement()
{
    int element;

    printf("Enter the element after which to insert: ");
    scanf("%d", &element);

    struct Node *temp = head;

    while (temp != NULL && temp->data != element)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element not found!\n");
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
        return;

    printf("Enter the element to insert: ");
    scanf("%d", &newNode->data);

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Successfully inserted after %d.\n", element);
}

void insertAtPosition()
{
    int pos;

    printf("Enter the position: ");
    scanf("%d", &pos);


    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
        return;

    printf("Enter the element: ");
    scanf("%d", &newNode->data);

    
    struct Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position does not exist!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted at position %d.\n", pos);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Elements in the list: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Element\n");
        printf("4. Insert at Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                insertAfterElement();
                break;

            case 4:
                insertAtPosition();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
