#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<limits.h>
using namespace std;

void add(vector<vector<int>> &graph,int src,int des, bool undir=true){
    graph[src].push_back(des);
    if(undir){
        graph[des].push_back(src);
    }
}

void BFS(vector<vector<int>> graph,unordered_set<int>&visted,vector<int>&distance,int src,int des){
    queue<int>q;
    q.push(src);
    visted.insert(src);
    distance[src]=0;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(auto neighbour: graph[current]){
            if(!visted.count(neighbour)){
                q.push(neighbour);
                visted.insert(neighbour);
                distance[neighbour]= distance[current]+1;
            }
        }
    }
    cout<<"\n";
}

// void BFS(vector<vector<int>> graph,/*unordered_set<int>&visted,*/vector<int>&visited,vector<int>&distance,int src,int des){
//     queue<int>q;
//     visited[src]=1;
//     q.push(src);
//     distance[src]=0;

//     while(!q.empty()){
//         int current = q.front();
//         q.pop();
//         for(auto neighbour : graph[current]){
//             if(visited[neighbour]==0){
//                 q.push(neighbour);
//                 visited[neighbour]=1;
//                 distance[neighbour]=distance[current]+1;
//             }
//         }
//     }
// }

int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;

    vector<vector<int>>graph(v,vector<int>());      // list or vector
    unordered_set<int>visted;
    // vector<int>visted(v,0);

    vector<int>distance(v, INT_MAX);

    while(e--){
        int src;
        int des;
        cin>>src;
        cin>>des;
        add(graph,src,des);   
    }

    int src,des;
    cin>>src>>des;
    cout<<"result: ";
    BFS(graph,visted,distance,src,des);

    cout<<"Shortest from "<<src<<" : ";
    for(auto i: distance){
        cout<<i<<" ";
    }
    cout<<"\n";

    cout<<"distance is: "<<distance[des] - distance[src];

    return 0;
}

// 7
// 8
// 0
// 1
// 0
// 4
// 1
// 3
// 4
// 3
// 1
// 5
// 5
// 6 
// 6
// 2
// 5
// 2
// 0
// 6
// result:
// Shortest from 0 : 0 1 3 2 1 2 3
// distance is: 3

