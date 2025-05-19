#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    // 1. Unordered Set
    unordered_set<int>s;
    
    //1 Insertion
    s.insert(1);
    s.insert(2);
    s.insert(3);

    // 2 traversal
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
 
    //3 Size
    cout<<s.size()<<endl;

    //4 Removal
    s.erase(2);
    
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    
    //5 find
    if(s.find(1)!=s.end()){
        cout<<"1 found"<<endl;
    }
    else{
        cout<<"1 not found"<<endl;
    }
    
    //6 clear
    s.clear();
    for(auto i:s){  // nothing wil be printed
        cout<<i<<" ";
    }
    cout<<endl;

    // 7 empty
    if(s.empty()){
        cout<<"Set is empty"<<endl;
    }
    else{
        cout<<"Set is not empty"<<endl;
    }

    s.insert(1);
    //8 count
    if(s.count(1)==1){
        cout<<"1 found"<<endl;
    }
    else{
        cout<<"1 not found"<<endl;
    }


    return 0;
}