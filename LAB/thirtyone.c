#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *stack[100];
int top = -1;

struct Node* createNode(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void push(struct Node *node)
{
    stack[++top] = node;
}

struct Node* pop()
{
    return stack[top--];
}

void inorderNonRecursive(struct Node *root)
{
    struct Node *temp = root;

    while (temp != NULL || top != -1)
    {
        while (temp != NULL)
        {
            push(temp);
            temp = temp->left;
        }

        temp = pop();

        printf("%d ", temp->data);

        temp = temp->right;
    }
}

int main()
{
    struct Node *root = NULL;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &value);

        root = insert(root, value);
    }

    printf("Inorder Traversal: ");
    inorderNonRecursive(root);

    return 0;
}