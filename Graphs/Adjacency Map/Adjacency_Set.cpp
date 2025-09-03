#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

void add(vector<unordered_set<int>> &graph,int src,int des, bool undir=true){
    graph[src].insert(des);
    if(undir){
        graph[des].insert(src);
    }
}

void display(vector<unordered_set<int>> &graph){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto j: graph[i]){
            cout<<"("<<j<<") ";
        }
        cout<<"\n";
    }
}

int main(){
    int v;   // vertex 
    cin>>v;
    int e;   // edge
    cin>>e;

    vector<unordered_set<int>> graph(v,unordered_set<int>());   // Adjacency Map

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