#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define stackSize 100
#define exprSize 100

int stack[stackSize];
int top=-1;

void push(int );
int pop();
int evalExpr(char []);
int calc(int,int, char);

int main(){
int result=0;
int expression[exprSize];
printf("Enter a valid post expression: ");
gets(expression);
result=evalExpr(expression);
printf("The result of the expression is : %d\n",result);

}

void push(int value){
if(top>=stackSize-1){
    printf("Stack overflow\n");
    return;
}
else{
top++;
stack[top]=value;
}
}

int pop(){
if(top<0){
    printf("Stack underflow\n");
    return;
}
else{
top--;
return stack[top+1];
}
}

int evalExpr(char postfix[]){
int i;
int result;
for(i=0; postfix[i]!='\0'; i++){
    if(isdigit(postfix[i]))
        push(postfix[i]-30);
    else if('+'||'-'||'*'||'/'||'^'){
        result=calc(pop(), pop(), postfix[i]);
        push(result);
    }
}
return pop();
}

int calc(int a, int b, char ch){

switch(ch){
case '+':
    return a+b;
case '-':
    return a-b;
case '*':
    return a*b;
case '/':
    return (a/b);
case '^':
    return round(pow(a,b));
    default: printf("INVALID");
}
}
