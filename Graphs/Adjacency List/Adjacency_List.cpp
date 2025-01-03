#include<iostream>
#include<vector>
#include<list>
using namespace std;

void add(vector<list<int>> &graph,int src,int des, bool undir=true){
    graph[src].push_back(des);
    if(undir){
        graph[des].push_back(src);
    }
}

void display(vector<list<int>> graph){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto j: graph[i]){
            cout<<j<<",";
        }
        cout<<"\n";
    }
}

int main(){
    int v;   // vertex 
    cin>>v;
    int e;   // edge
    cin>>e;

    vector<list<int>>graph(v,list<int>());   // Adjacency list

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

// 7 7 0 1 0 2 1 5 2 5 2 3 3 6 6 4