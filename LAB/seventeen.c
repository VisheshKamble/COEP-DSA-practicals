#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100

int precendence(char ch){
    if(ch == '*' || ch == '/'){
        return 2;
    }
    if(ch == '+' || ch == '-'){
        return 1;
    }

    return 0;
}

void infixtopostfix(){
    int j = 0;
    int t = -1;

    char infix[MAX] , postfix[MAX] , stack[MAX];
    
    printf("Enter the Infix Expression : ");
    scanf("%99s" , infix);

    for(int i = 0 ; infix[i] != '\0' ; i++){
        char ch = infix[i];

        if(isalnum((unsigned char) ch)){
            postfix[j++] = ch;
        }
        else if(ch == '('){
            stack[++t] = ch;
        }
        else if(ch == ')'){
            while(t != -1 && stack[t] != '('){
                postfix[j++] = stack[t--];
            }

            if(t != -1){
                t--;
            }
        }

        else{

            while(t != -1 && stack[t] != '(' && precendence(ch) <= precendence(stack[t])){
                postfix[j++] = stack[t--];
            }

            stack[++t] = ch;
        }
    }

        while(t != -1){
            postfix[j++] = stack[t--];
        }

        postfix[j] = '\0';

        printf("postFix Evaluation : %s" , postfix);
}

int main(){
    infixtopostfix();
}


