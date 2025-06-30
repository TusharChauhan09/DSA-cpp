#include<iostream>
#include<queue>
using namespace std;
int main(){
        int arr[] = {6,5,3,2,8,10,9};
        priority_queue<int,vector<int>,greater<int>>pq;
        int cost = 0;
        for(auto i: arr){
            pq.push(i);
        }
        while(pq.size()!=1){
            int first = pq.top();
            pq.pop();
            int sec = pq.top();
            pq.pop();
            cost += (first+sec);
            pq.push(first+sec);
        }
        cout<<cost;
}