#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>pq;
    pq.push(10);
    pq.push(2);
    pq.push(-6);
    pq.push(81);

    cout<<pq.top();
    cout<<"\n";
    
    pq.pop();
    cout<<pq.top();
    cout<<"\n";

    pq.pop();
    cout<<pq.top();


    return 0;
}