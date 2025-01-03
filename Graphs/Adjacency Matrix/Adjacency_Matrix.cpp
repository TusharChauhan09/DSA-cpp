#include<iostream>
#include<vector>
using namespace std;

void add(vector<vector<int>> &graph,int src,int des, bool undir=true){
    graph[src][des] = 1;
    if(undir){
        graph[des][src] = 1;
    }
}

void display(vector<vector<int>> graph){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto j: graph[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int v;   // vertex 
    cin>>v;
    int e;   // edge
    cin>>e;

    vector<vector<int>>graph(v,vector<int>(v,0));   // Adjacency Matrix

    while(e--){
        int src;
        int des;
        cin>>src;
        cin>>des;
        add(graph,src,des);  // false (for directed graph) 
    }

    display(graph);
    
    return 0;
}

// 7  7  {0 1 0 2 1 5 2 5 2 3 3 6 6 4}