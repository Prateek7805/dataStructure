#include<iostream>
using namespace std;
int fact(int n){
if(n==1)
    return n;
return n*fact(n-1);
}

int main(){
int num;
cout<<"Enter the number"<<endl;
cin>>num;
cout<<"The factorial of the number:"<<fact(num);
}

