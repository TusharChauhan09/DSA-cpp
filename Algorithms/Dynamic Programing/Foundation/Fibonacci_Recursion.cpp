#include<iostream>
using namespace std;
int fibo(int n){
    if(n<=1) return 1;
    return fibo(n-2) + fibo(n-1);
}
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    cout<<fibo(n);
}