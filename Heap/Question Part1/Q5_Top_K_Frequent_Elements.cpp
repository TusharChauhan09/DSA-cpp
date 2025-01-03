// Q5
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<int>v = {1,1,1,2,2,3};
    int k = 2;
    priority_queue<int,vector<int>,greater<int>>pq;

    for(int i =0;i<v.size();i++){
        pq.push(v[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }

    cout<<"The "<<k<<" largest element is : "<<pq.top();
    return 0;
}