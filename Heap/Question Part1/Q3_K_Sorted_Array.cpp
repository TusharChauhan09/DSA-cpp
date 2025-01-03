// Q3
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<int>v = {6,5,3,2,8,10,9};
    int k = 3;
    vector<int>ans;
    priority_queue<int,vector<int>,greater<int>>pq;

    for(int i =0;i<v.size();i++){
        pq.push(v[i]);
        if(pq.size()>k){
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }

    cout<<"sorted array is :\n";
    for(auto i: ans){
        cout<<i<<" ";
    }
    
    return 0;
}