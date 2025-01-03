#include<iostream>
using namespace std;
int sum(int n){
    if(n==0){        // base case
        return 0;
    }
    int s = n + sum(n-1);     // kam + recursion call
    return s;
}
int main(){
    int n;
    cout<<"Enter the input: "; 
    cin>>n;

    cout<<sum(n);

    return 0;
}