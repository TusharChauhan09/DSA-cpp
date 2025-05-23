// Ordered Set
#include<iostream>
#include<Set>
using namespace std;
int main(){
    //set
    set<int>s;

    s.insert(3);
    s.insert(1);
    s.insert(2);

    // In sorted order 
    for(auto i: s){
        cout<<i<<" ";
    }
    cout<<endl;


    return 0;
}