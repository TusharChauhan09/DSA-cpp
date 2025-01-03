#include<iostream>
using namespace std;
void print(int n){
    if(n==0){        // base case 
        return;
    }
    print(n-1);     // recursion call
    cout<<n<<"\n";  // kam
}
int main(){
    int n;
    cout<<"Enter the input: "; 
    cin>>n;

    print(n);

    return 0;
}