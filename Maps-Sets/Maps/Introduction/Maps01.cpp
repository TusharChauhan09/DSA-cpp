// Unordered map
#include<iostream>
#include<unordered_Map>
using namespace std;
int main(){
    unordered_map<string,int>mp;
    // Or
    // pair<string,int>p;
    // unordered_map<p>mp;

    //1. insertion
    mp["tushar"]=1; 
    mp.insert({"tarshit",2});
    mp.insert(make_pair("mayur",3));
    pair<string,int>p;
    p.first="tanish";
    p.second=4;
    mp.insert(p);

    //2. triversal
    for(auto i:mp){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    //3. size
    cout<<mp.size()<<endl;

    //4. find
    if(mp.find("tarshit")!=mp.end()){
        cout<<"tarshit found"<<endl;
    }
    else{
        cout<<"tarshit not found"<<endl;
    }

    //5. erase
    mp.erase("tarshit");
    for(auto i:mp){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    //6. clear
    mp.clear();
    for(auto i:mp){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    //7. count
    if(mp.count("tarshit")==1){
        cout<<"tarshit found"<<endl;
    }
    else{
        cout<<"tarshit not found"<<endl;
    }
    
    // 8.is empty
    if(mp.empty()){
        cout<<"Map is empty"<<endl;
    }
    else{
        cout<<"Map is not empty"<<endl;
    }



    return 0;
}