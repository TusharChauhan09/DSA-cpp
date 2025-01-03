// 1 
#include<iostream>
using namespace std;
void f1(){
    cout<<"This mult function \n";
    return;              
}
int f2(int a,int b){
    f1();
    return a*b;
}

void f3(int x){
    if(x){                     // Base Case
        return;
    } 
    cout<<"hello";
    x--;
    f3(x);                     // (2) Recursion / Fuction Calling Itself
}

int main(){
    int m = f2(2,3);          // (1) function call
    cout<<m;

    f3(3);
    
    return 0;
}

