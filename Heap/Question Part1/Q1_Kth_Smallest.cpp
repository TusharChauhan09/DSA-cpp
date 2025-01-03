// Q1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<int>v = {10,20,-4,6,18,2,105,118};
    int k = 3;
    priority_queue<int>pq;

    for(int i =0;i<v.size();i++){
        pq.push(v[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }

    cout<<"The "<<k<<" smallest element is : "<<pq.top();
    return 0;
}