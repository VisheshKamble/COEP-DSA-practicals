#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

//stack using array 

int stack[MAX] ;
int t = -1;

void pushArray(int data){
    if(t == MAX - 1){
        printf("Stack Overflow \n");
        return;
    }

    stack[++t] = data;
    
}

void popArray(){
    if(t == -1){
        printf("Stack UnderFlow \n");
        return;
    }

    printf("Element Popped : %d" , stack[t--]);
}

void displayArray(){
    int i;

    if(t == -1){
        printf("Stack is Empty :");
        return;
    }

    for(i = t ; i >= 0 ; i--){
        printf("%d " , stack[i]);
    }
}

//Stack Using Linked List 

struct Node {
    int data;
    struct Node * next;
};

struct Node * head = NULL;

void linkedpush (int data){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode -> data = data;

    if(head == NULL){
        head = newNode ;
        return;
    }

    newNode -> next = head;
    head = newNode;    
}

void linkedpop(){
    struct Node *temp = NULL;

    if(head == NULL){
        printf("Stack is Empty");
        return;
    }

    temp = head ;
    printf("Element to be popped : %d" , temp -> data);

    head = head -> next;
    free(temp);
}

void displayLinked(){
    struct Node *temp = NULL;

    if(head == NULL){
        printf("Stack is Empty");
        return;
    }

    temp = head ;
    while(temp != NULL){
        printf("%d " , temp -> data);
        temp = temp -> next;
    }
}


//infix to postfix 

int precendence(char ch){
    if(ch == '*' || ch == '/'){
        return 2;
    }

    if(ch == '+' || ch == '-'){
        return 1;
    }
    return  0;
}

void infixtopostfix(){
    char infix[MAX] , postfix[MAX] , stack[MAX];
    int i , j = 0;
    int t = -1;

    printf("Enter the Expression : ");
    scanf("%99s" , infix);

    for(i = 0 ; infix[i] != '\0' ; i++){
        char ch = infix[i];

        if(isalnum((unsigned char) ch)){
            postfix[j++] = ch;
        }

        else if(ch == '('){
            stack[++t] = ch ;
        }

        else if(ch == ')'){
            if(t != -1 && stack[i] != '('){
                postfix[j++] = stack[t--];
            }

            if(t != -1){
                t--;
            }
        }

        else{
            if(t != -1 && stack[i] != '(' && precendence(stack[t])  >=  precendence(ch)){
                postfix[j++] = stack[t--];
            }

            stack[++t] = ch;
        }
    }

    while(t != -1){
        postfix[j++] = stack[t--];
    }

    postfix[j] = '\0';
    printf("PostFix Expressrion %s \n\n" , postfix);
}

void evaluatepostfix(){
    char exp[MAX];
    int stack[MAX];
    int a , b ;
    int t = -1;


    printf("Enter the Expression : ");
    scanf("%99s" , exp);

    for(int i = 0 ; exp[i] != '\0' ; i++){

        if(isdigit((unsigned char) exp[i])){
            stack[++t] = exp[i] - '0';
        }
        else{
            if(t < 1){
                printf("Invalid Operation");
            }else{
                b = stack[t--];
                a = stack[t--];

                if(exp[i] == '+'){
                    stack[++t] = a + b;
                }
                else if(exp[i] == '-'){
                    stack[++t] = a - b;
                }
                else if(exp[i] == '*'){
                    stack[++t] = a * b;
                }
                else if(exp[i] == '/'){

                    if(b == 0){
                        printf("Cannot Divivde By Zero\n");
                    }
                    else{
                        stack[++t] = a / b;
                    }

                }
                else{
                    printf("Invalid");
                }
            }
        } 
    }

    if(t == 0){
        printf("PostFix Evaluation : %d " , stack[t]);
    }
    else{
        printf("Invalid Expression");
    }

}

int main(){
    int choice ;
    int op ;
    int data;

    do{
        printf("1.Stack Using Linked List\n");
        printf("2.Stack Using Array\n");
        printf("3.Exit\n");
        printf("4.Infix To Postfix \n");
        printf("5.PostFix Evaluation \n");

        printf("Enter Your Choice : \n");
        scanf("%d" , &choice);

        switch(choice){

             case 1:
                printf("1. PUSH\n2. POP\n3. DISPLAY\n");
                scanf("%d", &op);

                if (op == 1)
                {
                    printf("Enter Value: ");
                    scanf("%d", &data);
                    pushArray(data);
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
                    scanf("%d", &data);
                    linkedpush(data);
                }
                else if (op == 2)
                {
                    linkedpop();
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
            printf("\nExiting .........");
            break;

            case 4:
            infixtopostfix();
            break;

            case 5:
            evaluatepostfix();

            default:
            printf("\nInvalid Operation");
        }
    }while(choice != 3);
}