#include<iostream>
using namespace std;
int fact(int n){
    if(n==0 || n==1){        // base case 
        return 1;
    }
    int f = n * fact(n-1);
    return f;
}
int main(){
    int n;
    cout<<"Enter the input: "; 
    cin>>n;

    cout<<fact(n);

    return 0;
}