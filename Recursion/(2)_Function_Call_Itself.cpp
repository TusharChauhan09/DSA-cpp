// 2
#include<iostream>
using namespace std;
void f1(int x){
    if(x==0){                     // Base Case
        return;
    } 
    cout<<"hello\n";
    x--;
    f1(x);                     // (2) Recursion / Fuction Calling Itself
}

int main(){
    f1(3);
    return 0;
}

