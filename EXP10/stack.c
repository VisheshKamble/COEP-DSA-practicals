#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack Using Array

int stack[MAX];
int top = -1;

void pushArray(int data)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = data;
    }
}

void popArray()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Element Popped: %d\n", stack[top--]);
    }
}

void displayArray()
{
    int i;

    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

// Stack Using Linked List

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void linkedPush(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void popLinked()
{
    if (head == NULL)
    {
        printf("Stack Underflow / Empty\n");
        return;
    }

    struct Node *temp = head;

    printf("Element Popped: %d\n", temp->data);

    head = head->next;

    free(temp);
}

void displayLinked()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Infix to Postfix

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

void infixToPostFix()
{
    char infix[MAX], postfix[MAX], s[MAX];
    int i, j = 0, t = -1;

    printf("Enter Infix Expression: ");
    scanf("%99s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (isalnum((unsigned char)ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            s[++t] = ch;
        }
        else if (ch == ')')
        {
            while (t != -1 && s[t] != '(')
            {
                postfix[j++] = s[t--];
            }

            if (t != -1)
                t--;
        }
        else
        {
            while (t != -1 && s[t] != '(' &&
                   precedence(s[t]) >= precedence(ch))
            {
                postfix[j++] = s[t--];
            }

            s[++t] = ch;
        }
    }

    while (t != -1)
    {
        postfix[j++] = s[t--];
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

// Postfix Evaluation

void evaluatePostFix()
{
    char exp[MAX];
    int s[MAX];
    int t = -1;
    int i, a, b;

    printf("Enter Postfix Expression: ");
    scanf("%99s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit((unsigned char)exp[i]))
        {
            s[++t] = exp[i] - '0';
        }
        else
        {
            if (t < 1)
            {
                printf("Invalid Expression\n");
                return;
            }

            b = s[t--];
            a = s[t--];

            if (exp[i] == '+')
                s[++t] = a + b;

            else if (exp[i] == '-')
                s[++t] = a - b;

            else if (exp[i] == '*')
                s[++t] = a * b;

            else if (exp[i] == '/')
            {
                if (b == 0)
                {
                    printf("Division by Zero\n");
                    return;
                }

                s[++t] = a / b;
            }
            else
            {
                printf("Invalid Operator\n");
                return;
            }
        }
    }

    if (t == 0)
        printf("Result: %d\n", s[t]);
    else
        printf("Invalid Expression\n");
}

// Main Function

int main()
{
    int choice, op, val;

    do
    {
        printf("\n1. Stack Using Array\n");
        printf("2. Stack Using Linked List\n");
        printf("3. Infix to Postfix\n");
        printf("4. Postfix Evaluation\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("1. PUSH\n2. POP\n3. DISPLAY\n");
                scanf("%d", &op);

                if (op == 1)
                {
                    printf("Enter Value: ");
                    scanf("%d", &val);
                    pushArray(val);
                }
                else if (op == 2)
                {
                    popArray();
                }
                else if (op == 3)
                {
                    displayArray();
                }
                else
                {
                    printf("Invalid Operation\n");
                }
                break;

            case 2:
                printf("1. Linked PUSH\n2. Linked POP\n3. DISPLAY\n");
                scanf("%d", &op);

                if (op == 1)
                {
                    printf("Enter Value: ");
                    scanf("%d", &val);
                    linkedPush(val);
                }
                else if (op == 2)
                {
                    popLinked();
                }
                else if (op == 3)
                {
                    displayLinked();
                }
                else
                {
                    printf("Invalid Operation\n");
                }
                break;

            case 3:
                infixToPostFix();
                break;

            case 4:
                evaluatePostFix();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while (choice != 5);

    return 0;
}