#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data ;
    struct Node*left;
    struct Node*right;
};

struct Node* create(int data){
    struct Node * newNode = malloc(sizeof(struct Node));

    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

struct Node* insert(struct Node* root , int data){
    if(root == NULL){
        return create(data);
    }

    if(data < root -> data){
        root -> left = insert(root -> left , data);
    }
    else{
        root -> right = insert(root -> right , data);
    }
    return root;
}

void inorder (struct Node * root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    printf("%d , " , root -> data);
    inorder(root -> right);
}

void postorder(struct Node*root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d , " , root -> data);
}

void preorder(struct Node * root){
    if(root == NULL){
        return ;
    }

    printf("%d ," , root -> data);
    preorder(root -> left);
    preorder(root -> right);
}

int depth(struct Node* root){
    if(root == NULL){
        return 0;
    }

    int left = depth(root -> left);
    int right = depth(root -> right);

    if(left > right){
        return left + 1;
    }
    return right + 1;
}

void search(struct Node* root , int data){
    if(root == NULL){
        return ;
    }
    if(data == root -> data){
        printf("Found");
        return;
    }
    else if(data < root -> data){
     search(root -> left , data);
    }else{
        search(root -> right , data);
    }
}


struct Node* deleteNode(struct Node *root , int data){
    
   struct Node * temp = malloc(sizeof(struct Node));

   if(root == NULL){
    return NULL;
   }

   else if(data < root -> data){
    root -> left = deleteNode(root -> left , data);
   }
   else if(data > root -> data){
    root -> right = deleteNode(root -> right , data);
   }
   
else{
    if(root -> left == NULL){
        temp = root -> right;
        free(root);
        return temp;
    }

    if(root -> right == NULL){
        temp = root -> left;
        free(root);
        return temp;
    }

    temp = root -> right;

    while(temp -> left != NULL){
        temp = temp -> left;
    }

    root -> data = temp -> data;

    root -> right = deleteNode(root -> right , temp -> data);
  }

  return root ;
}

int main()
{
    struct Node *root = NULL;
    int choice, x;

    do
    {
        printf("\n\n1. Insert\n2. Delete\n3. Search\n");
        printf("4. Inorder\n5. Preorder\n6. Postorder\n");
        printf("7. Depth\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &x);
                search(root, x);
                break;

            case 4:
                inorder(root);
                break;

            case 5:
                preorder(root);
                break;

            case 6:
                postorder(root);
                break;

            case 7:
                printf("Depth = %d", depth(root));
                break;

    
            case 0:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 0);

    return 0;
}