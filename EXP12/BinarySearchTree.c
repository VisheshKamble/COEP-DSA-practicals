
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

struct Node* insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void search(struct Node *root, int data)
{
    if (root == NULL)
        printf("Not Found\n");
    else if (root->data == data)
        printf("Found\n");
    else if (data < root->data)
        search(root->left, data);
    else
        search(root->right, data);
}

struct Node* deleteNode(struct Node *root, int data)
{
    struct Node *temp;

    if (root == NULL)
        return NULL;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = root->right;

        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int depth(struct Node *root)
{
    int left, right;

    if (root == NULL)
        return 0;

    left = depth(root->left);
    right = depth(root->right);

    if (left > right)
        return left + 1;

    return right + 1;
}

void leafNode(struct Node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);

    leafNode(root->left);
    leafNode(root->right);
}

int main()
{
    struct Node *root = NULL;
    int choice, x;

    do
    {
        printf("\n\n1. Insert\n2. Delete\n3. Search\n");
        printf("4. Inorder\n5. Preorder\n6. Postorder\n");
        printf("7. Depth\n8. Leaf Nodes\n0. Exit\n");
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

            case 8:
                printf("Leaf nodes: ");
                leafNode(root);
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
