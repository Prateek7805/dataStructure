#include<iostream>

using namespace std;
int fibonacci(int n){
cout<<"||"<<n<<"||\t";
if(n==0|| n==1)
    return n;
return fibonacci(n-1)+fibonacci(n-2);


}
int main(){
int num;
cout<<"Enter the number of fibonacci terms: ";
cin>>num;
for(int i=0; i<num; i++)
    cout<<fibonacci(i)<<endl;
}
