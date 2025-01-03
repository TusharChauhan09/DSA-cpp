#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

void add(vector<unordered_map<int,int>> &graph,int src,int des,int weight, bool undir=true){
    graph[src][des] = weight;
    if(undir){
        graph[des][src] = weight;
    }
}

void display(vector<unordered_map<int,int>> &graph){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto j: graph[i]){
            cout<<"("<<j.first<<","<<j.second<<") ,";
        }
        cout<<"\n";
    }
}

int main(){
    int v;   // vertex 
    cin>>v;
    int e;   // edge
    cin>>e;

    vector<unordered_map<int,int>> graph(v,unordered_map<int,int>());   // Adjacency Map

    while(e--){
        int src;
        int des;
        int weight;
        cin>>src;
        cin>>des;
        cin>>weight;
        add(graph,src,des,weight);  // false (for directed graph) 
    }

    display(graph);
    
    return 0;
}

// 7  7  {0 1 0 2 1 5 2 5 2 3 3 6 6 4}