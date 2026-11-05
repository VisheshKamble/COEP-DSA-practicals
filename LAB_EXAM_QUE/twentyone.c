
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

void inorder(struct Node* root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    printf("%d ", root -> data);
    inorder(root -> right);
}

struct Node* insert(struct Node* root, int data){
    if(root == NULL){
        return createNode(data);
    }

    if(data < root -> data){
        root -> left = insert(root -> left, data);
    }
    else if(data > root -> data){
        root -> right = insert(root -> right, data);
    }

    return root;
}

void search(struct Node* root, int data){
    if(root == NULL){
        printf("Not Found");
        return;
    }

    if(root -> data == data){
        printf("Found");
        return;
    }
    else if(data < root -> data){
        search(root -> left, data);
    }
    else{
        search(root -> right, data);
    }
}


struct Node* deleteNode(struct Node* root , int data){
    struct Node* temp;

    if(root == NULL){
        return NULL;
    }

    if(data < root -> data){
        root -> left = deleterNode(root -> left , data);
    }
    else if(data > root -> data){
        root -> right = deleteNode(root->right , data);
    }

    else {

        if(root -> left == NULL){
            temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL){
        temp = root -> left ;
        free(root);
        return temp;
      }

      temp = root -> right;

      while(temp -> left != NULL){
        temp = temp -> left;
      }

      root -> data = temp -> data;
      root ->right = deleteNode(root -> right , temp -> data);
    }
    return root;
}

int main(){
    struct Node* root = NULL;
    int choice;
    int element;

    do{
        printf("\n\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Inorder");
        printf("\n4. Exit");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter Element: ");
                scanf("%d", &element);

                root = insert(root, element);
                break;

            case 2:
                printf("Element To Search: ");
                scanf("%d", &element);

                search(root, element);
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                break;

            case 4:
                printf("Exiting...");
                break;

            default:
                printf("Invalid Choice");
        }

    }while(choice != 4);

    return 0;
}
