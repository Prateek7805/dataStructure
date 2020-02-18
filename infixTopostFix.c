#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

#define size 100
int stack[size];
int top=-1;
void infixTopostfix(char [], char []);
int main(){
char infix[size], postfix[size];
printf("Enter the infix expression: ");
gets(infix);
printf("The postfix expression is: ");
infixTopostfix(infix, postfix);
puts(postfix);
return 0;
}
void push(char ch){
if(top>size-1)
    printf("stack Overflow\n");
else{
    top++;
    stack[top]=ch;
}
}

char pop(){
if(top==-1)
    printf("stack underflow");
else{
    top--;
    return stack[top+1];
}

}

bool isOperator(char ch){
if(ch=='*'||ch=='^'||ch=='/'||ch=='-'||ch=='+')
    return true;
else return false;
}

int priority(char ch){
if(ch=='^')
    return 1;
else if(ch ='*'||ch=='/')
    return 2;
else if(ch ='+'||ch=='-')
    return 3;
}

void infixTopostfix(char infix[], char postfix[]){
char token;
char stackTop;
int i=0,j=0;
push('(');
strcat(infix, ")");
token=infix[i];
while(infix[i]!='\0'){
    if(token=='(')
        push(token);
    else if(isdigit(token)||isalpha(token))
    {
        postfix[j]=token;
        j++;
    }
    else if(isOperator(token)){
        stackTop=pop();
        while(isOperator(stackTop)&&(priority(stackTop)>=priority(token))){
            postfix[j]=stackTop;
            j++;
            stackTop=pop();
        }
        push(stackTop);
        push(token);
    }
    else if(token==')'){
       stackTop=pop();
        while(stackTop!='('){
                postfix[j]=stackTop;
                j++;
                stackTop=pop();
              }i++;  token=infix[i];

    }
}
postfix[j]='\0';
return;

}
