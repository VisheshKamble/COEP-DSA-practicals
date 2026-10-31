#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node * right;
};

struct Node* create(int data){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> right = NULL;
    newNode -> left = NULL;

    return newNode;
}

void inorder(struct Node * root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    printf("%d , " , root -> data);
    inorder(root -> right);
}

void postorder(struct Node * root){
    if(root == NULL){
        return ;
    }

    postorder(root -> left);
    postorder(root -> right);
    printf("%d , " , root -> data);
}

void preorder(struct Node*root){
    if(root == NULL){
        return;
    }

    printf("%d , " , root -> data);
    preorder(root -> left );
    preorder(root -> right);
}


void leafNodes(struct Node * root){
    if(root == NULL){
        return;
    }

    if(root -> left == NULL && root -> right == NULL){
        printf("%d , " , root -> data);
        return;
    }

    leafNodes(root -> left);
    leafNodes(root -> right);
}

void NonLeafNodes(struct Node * root){
    if(root == NULL){
        return;
    }

    if(root -> left != NULL || root -> right != NULL){
        printf("%d , " , root -> data);
    }

    NonLeafNodes(root -> left);
    NonLeafNodes(root -> right);
}

int countLeaf(struct Node *root){
   if(root == NULL){
    return 0;
   } 

   if(root -> right == NULL && root -> left == NULL){
    return 1;
   }

   return countLeaf(root -> left) + countLeaf(root -> right);
}

int countNonLeaf(struct Node * root){
    if(root == NULL){
        return 0;
    }

    if(root -> left == NULL && root -> right == NULL){
        return 0;
    }

    return 1 + countNonLeaf(root -> left) + countNonLeaf(root -> right);
}
void levels(struct Node * root , int level){
    if(root == NULL){
        return ;
    }

    printf("\n Node : %d and Level : %d" , root -> data , level );

    levels(root -> left , level + 1);
    levels(root -> right , level + 1 );
}

int height (struct Node *root){
    if (root == NULL){
        return -1;
    }

    int heightleft = height(root -> left);
    int heightright = height(root -> right);

    if(heightleft > heightright){
        return 1 + heightleft;
    }
    return 1 + heightright;
}

int main(){
    struct Node * root;

    root = create(20);
    root -> left = create(50);
    root -> right = create(35);
    root -> left -> left = create(42);
    root -> left -> right = create(23);
    root -> right -> left = create(98);
    root -> right -> right = create(32);


    printf("Inorder : ");
    inorder(root);

    printf("\npreorder : ");
    preorder(root);

    printf("\npostorder : ");
    postorder(root);


    printf("\nLeaf Nodes : ");
    leafNodes(root);

    printf("\nNon Leaf Nodes : ");
    NonLeafNodes(root);

    printf("\nCount Leaf : %d "  ,countLeaf(root));

    printf("\nCount Non Leaf %d: " , countNonLeaf(root));
  

    printf("\nLevels : ");
    levels(root , 0);

    printf("\nheight of tree %d :", height(root));

}
