#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*left , *right;
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
    printf("%d" , root -> data);
    inorder(root -> right);
}

void preorder(struct Node* root){
    if(root == NULL){
        return ;
    }

    printf("%d" , root -> data);
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(struct Node* root){
    if(root == NULL){
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    printf("%d" , root -> data);
    
}

void leafNodes(struct Node* root){
    if(root == NULL){
        return ;
    }

    if(root -> left == NULL && root -> right == NULL){
         printf("%d" , root -> data);
         return ;
    }

    leafNodes(root -> left);
    leafNodes(root -> right);
 }

 void nonLeafNodes(struct Node* root){
    if(root == NULL){
        return ;
    }

    if(root -> left != NULL || root -> right != NULL){
        printf("%d" , root -> data);
    }

    nonLeafNodes(root -> left);
    nonLeafNodes(root -> right);
 }


 int countLeaf(struct Node* root){
    if(root == NULL){
        return 0;
    }

    if(root -> left == NULL && root -> right == NULL){
        return 1;
    }

    return countLeaf(root -> left) +
    countLeaf(root -> right);
 }

 int countNonLeaf(struct Node* root){
    if(root == NULL){
        return 0;
    }

    if(root -> left == NULL && root -> right == NULL){
        return 0;
    }

    return 1 + countNonLeaf(root -> left) + countNonLeaf(root -> right);
 }

 void levels(struct Node* root , int level){
    if(root == NULL){
        return;
    }

    printf("\nNODE : %d AND LEVEL : %d" , root -> data , level );

    levels(root -> left , level + 1);
    levels(root -> right , level + 1);
 }

 int main(){
    struct Node* root ;

    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);


    printf("Inorder : ");
    inorder(root);

    printf("\npostorder : ");
    postorder(root);

    printf("\npreorder : ");
    preorder(root);

    printf("\nLeaf Nodes: ");
    leafNodes(root);

    printf("\nNumber of Leaf Nodes: %d", countLeaf(root));

    printf("\nNon-Leaf Nodes: ");
    nonLeafNodes(root);

    printf("\nNumber of Non-Leaf Nodes: %d", countNonLeaf(root));

    printf("\n\nLevels of All Nodes:\n");
    levels(root, 1);
 }