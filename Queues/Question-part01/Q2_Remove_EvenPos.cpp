// Q-2
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void Remove_Even(queue<int>&q){
    int n = q.size();
    for(int i=0;i<n;i++){
        if(i%2!=0){
            q.push(q.front());
        }
        q.pop();
    }
}

int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    Remove_Even(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}