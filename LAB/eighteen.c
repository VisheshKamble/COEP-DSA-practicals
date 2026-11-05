#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*left , *right;
};

struct Node*createNode(int data){
    struct Node*newNode = malloc(sizeof(struct Node));

    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

void inorder(struct Node*root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    printf("%d ," , root -> data);
    inorder(root -> right);
}

void preorder(struct Node*root){
    if(root == NULL){
        return;
    }

    printf("%d , " , root -> data);
    preorder(root -> left);
    preorder(root -> right);
}


void leafNodes(struct Node*root){
    if(root == NULL){
        return ;
    }

    if(root -> left == NULL && root -> right == NULL){
        printf("%d " , root -> data);
        return;
    }

    leafNodes(root -> left);
    leafNodes(root -> right);
}

void nonleafNodes(struct Node*root){
    if(root == NULL){
        return ;
    }

    if(root -> left != NULL || root -> right != NULL){
        printf("%d " , root -> data);
    }
    nonleafNodes(root -> left);
    nonleafNodes(root -> right);
}

int countleaf(struct Node* root){
    if(root == NULL){
        return 0;
    }

    if(root -> left == NULL && root -> right == NULL){
        return 1;
    }

    return countleaf(root -> left) + countleaf(root -> right);
}

int countnonleaf(struct Node* root){
    if(root == NULL){
        return 0;
    }
    if(root -> left == NULL && root -> right ==  NULL){
        return 0;
    }

   return 1 + countnonleaf(root -> left) + countnonleaf(root -> right);
}

int height(struct Node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root -> left);
    int right = height(root -> right);

    if(left > right){
        return left + 1;
    }
    return right + 1;
}



int main(){
    struct Node* root ;

    root = createNode(20);
    root->left = createNode(30);
    root -> right = createNode(10);
    root -> left -> left = createNode(25);
    root -> left -> right = createNode(29);
    root -> right -> left = createNode(21);
    root -> right -> right = createNode(28);

    printf("inorder traversal : ");
    inorder(root);

    printf("\npreorder traversal :");
    preorder(root);

    printf("\nDisplay Leaf Nodes :");
    leafNodes(root);

    printf("\nDisplay Non Leaf Nodes : ");
    nonleafNodes(root);

    printf("\nCount Leaf Nodes : %d" , countleaf(root));

    printf("\nCount Non Leaf Nodes : %d" , countnonleaf(root));
    
    printf("\nHeight : %d" ,  height(root));

}

