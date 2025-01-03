#include<iostream>
#include<vector>
using namespace std;

void add(vector<vector<int>> &graph,int src,int des, bool undir=true){
    graph[src].push_back(des);
    if(undir){
        graph[des].push_back(src);
    }
}

void dfs(int node, vector<vector<int>>graph , vector<int>&visited){
    visited[node]=1;
    for(auto neighbour: graph[node]){
        if(visited[neighbour]==0){
            dfs(neighbour,graph,visited);
        }
    }
}

int Connected_Components(vector<vector<int>>&graph,int v){
    int result=0;
    vector<int>visited(v,0);
    for(int i=0;i<v;i++){
        if(visited[i]==0){        // check for the source of connected components
            result++;             // add the number of the connected components
            dfs(i,graph,visited); // dfs will be done on those nodes only which are not travelled before
        }
    }
    return result;
}

int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;

    vector<vector<int>>graph(v,vector<int>());      // list or vector

    while(e--){
        int src;
        int des;
        cin>>src;
        cin>>des;
        add(graph,src,des);   
    }

    cout<<"The number of connected components are : "<<Connected_Components(graph,v);

    return 0;
}


// 7 8
// 0 1 
// 1 4
// 0 4
// 0 3
// 3 4
// 2 5
// 2 6 
// 5 6
// The number of connected components are : 2