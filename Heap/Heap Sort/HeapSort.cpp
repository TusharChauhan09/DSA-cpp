#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int arr[] = {10,1,2,20,5,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    priority_queue<int>pq;   // using Max Heap
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }

    int x= n-1;
    while(!pq.empty()){
        arr[x--] = pq.top();
        pq.pop();
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}