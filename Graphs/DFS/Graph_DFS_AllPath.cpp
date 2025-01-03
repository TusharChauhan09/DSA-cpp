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
void DFS(vector<vector<int>>graph ,unordered_set<int>&visted,vector<int>&path, vector<vector<int>>&All_Path,int current, int end){

    if(current==end){      // base case
        path.push_back(current);
        All_Path.push_back(path);
        path.pop_back(); 
        return;         
    }
    visted.insert(current); //marked visted
    path.push_back(current);

    for(auto neighbour: graph[current]){
        if(!visted.count(neighbour)){            // visted.count(neighbour) it will give =>  if visted then 1 else 0
            DFS(graph,visted,path, All_Path,neighbour,end);
        }
    }
    path.pop_back();
    visted.erase(current);
    return;
}

// USING VISTED AS VECTOR
// void DFS(vector<vector<int>>graph ,vector<int>&visted,vector<int>&path, vector<vector<int>>&All_Path,int current, int end){       // Visted vector
//     if(current==end){      // base case
//     path.push_back(current);
//     All_Path.push_back(path);
//     path.pop_back(); 
//     return ;          
//     }
//     visted[current]=1; //marked visted
//     path.push_back(current);
//     for(auto neighbour: graph[current]){
//         if(visted[neighbour]==0){           
//             DFS(graph,visted,path,All_Path,neighbour,end);
//         }
//     }
//     path.pop_back();
//     visted[current]=0;
//     return;
// }


void allPath(vector<vector<int>>graph ,unordered_set<int>&visted/*vector<int>visted*/,vector<int>&path, vector<vector<int>>&All_Path, int src, int des){
    return DFS(graph,visted, path,All_Path ,src,des);
}

int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;

    vector<vector<int>>graph(v,vector<int>());      // list or vector
    
    unordered_set<int>visted;
    // vector<int>visted(v,0);

    vector<int>path;       
    vector<vector<int>>All_Path;      // store all paths

    while(e--){
        int src;
        int des;
        cin>>src;
        cin>>des;
        add(graph,src,des);   
    }

    int src,des;
    cin>>src>>des;
    cout<<"result: \n";
    allPath(graph,visted,path,All_Path,src,des);

    for(int i=0;i<All_Path.size();i++){
        
        for(auto j: All_Path[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }

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
// 0 1 5 6
// 0 1 5 2 6
// 0 4 3 1 5 6
// 0 4 3 1 5 2 6
