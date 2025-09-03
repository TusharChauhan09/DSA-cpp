#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void add(vector<vector<int>> &graph,int src,int des, bool undir=true){
    graph[src].push_back(des);
    if(undir){
        graph[des].push_back(src);
    }
}


// USING VISTED AS UNORDERED SET
bool DFS(vector<vector<int>>graph ,unordered_set<int>&visted,int current, int end){

    if(current==end) return true;    // base case

    visted.insert(current); //marked visted

    for(auto neighbour: graph[current]){
        if(!visted.count(neighbour)){            // visted.count(neighbour) it will give =>  if visted then 1 else 0
            bool result = DFS(graph,visted,neighbour,end);
            if(result) return true;
        }
    }
    return false;
}

// USING VISTED AS VECTOR
// bool DFS(vector<vector<int>>graph ,vector<int>&visted,int current, int end){       // Visted vector
//     if(current==end) return true;       // base case

//     visted[current]=1; //marked visted

//     for(auto neighbour: graph[current]){
//         if(visted[neighbour]==0){           
//             bool result = DFS(graph,visted,neighbour,end);
//             if(result) return true;
//         }
//     }
//     return false;
// }


bool anyPath(vector<vector<int>>graph ,unordered_set<int>&visted/*vector<int>&visted*/, int src, int des){
    return DFS(graph,visted,src,des);
}

int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;

    vector<vector<int>>graph(v,vector<int>());      // list or vector
    unordered_set<int>visted;
    // vector<int>visted(v,0);

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
    cout<<anyPath(graph,visted,src,des);

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
// result: 1
