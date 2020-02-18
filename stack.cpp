#include<iostream>
#include<stdlib.h>
using namespace std;
#define maxsize 5
class stack{
private:
    int top;
    int stk[5];
public:
    stack();
     push(int);
    int pop();
    display();
    int isEmpty();
    int isFull();
};
stack :: stack(){
top=-1;
}

stack:: push(int num){
if(isFull()){
    cout<<"stack overflow";
}
else{
top++;
stk[top]=num;
}
}
stack:: pop(){
if(isEmpty()){
    cout<<"stack underflow";
    return 0;
}
top--;
return stk[top+1];
}

stack :: display(){
for(int i=0; i<=top; i++)
    cout<<stk[i]<<"\t";
cout<<endl;
}

stack :: isFull(){
if(top>=maxsize-1)
    return 1;
return 0;
}

stack :: isEmpty(){
if(top==-1)
    return 1;
return 0;
}

int main(){
int n;
int val;
stack st;
while(1){
cout<<"1: push 2: pop 3; display 4: exit: ";
cout<<"Enter choice: ";
cin>>n;
switch(n){
case 1:
    cout<<"Enter value to be pushed: ";
    cin>>val;
    st.push(val);
    break;
case 2:
    cout<<st.pop()<<endl;
    break;
case 3:
    cout<<"stack contents"<<endl;
    st.display();
    break;
case 4:
    exit(0);
}


}
}
