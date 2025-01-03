#include<iostream>
#include<vector>
using namespace std;

void add(vector<vector<int>>&graph,int src,int des,bool undir=true){
    graph[src].push_back(des);
    if(undir){
        graph[des].push_back(src);
    }
}

void display(vector<vector<int>>graph){
    for(int i=0;i<graph.size();i++){
        cout<<i<<"->";
        for(auto j: graph[i]){
            cout<<j<<",";
        }
        cout<<"\n";
    }
}

int main(){
    int v,e;
    cin>>v>>e;

    vector<vector<int>>graph(v);

    while(e--){
        int src,des;
        cin>>src>>des;
        add(graph,src,des);
    }

    display(graph);
}