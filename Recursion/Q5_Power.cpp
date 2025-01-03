#include<iostream>
using namespace std;
int power(int a,int b){
    if(b==0){        // base case 
        return 1;
    }
    return a*power(a,b-1);
}
int main(){
    int a,b;
    cout<<"Enter the input: "; 
    cin>>a>>b;

    cout<<power(a,b);

    return 0;
}