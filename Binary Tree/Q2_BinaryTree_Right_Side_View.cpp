#include<iostream>
#include<queue>
#include<climits>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data1){
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};
Node* Construct_LevelOrder(vector<int>v){
    queue<Node*>q;
    Node* root = new Node(v[0]);
    q.push(root);
    int i=1;
    int j=2;

    while(q.size()>0 && i<v.size()){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;

        if(v[i]!=INT_MIN) l = new Node(v[i]);
        else l = nullptr;

        if(j!=v.size() && v[j]!=INT_MIN) r = new Node(v[j]);
        else r = nullptr;

        temp->left=l;
        temp->right=r;

        if(l!=nullptr) q.push(l);
        if(r!=nullptr) q.push(r);

        i+=2; j+=2;
    }
    
    return root;
}


// methode -1
void nthlevel(Node* root,int level,int cur,vector<int>&ans){
    if(root==nullptr){
        return;
    }
    if(cur==level){
        ans[cur]=root->data;
    }
        nthlevel(root->left,level,cur+1,ans);
        nthlevel(root->right,level,cur+1,ans);
}
int level(Node* root){
    if(root==nullptr){
        return 0;
    }
    int l = 1 + max(level(root->left),level(root->right));
    return l;
}
void levelOrder(Node* root, vector<int>&ans){
    int n = ans.size();
    for(int i=0;i<=n-1;i++){
        nthlevel(root,i,0,ans);
    }
}

// methode -2
void result(Node* root,vector<int>&ans,int cur){
        if(root==nullptr){
            return;
        }
        ans[cur] = root->data;
        result(root->left,ans,cur+1);
        result(root->right,ans,cur+1);
    }


int main(){
    vector<int>v = {1,2,3,4,5};
    Node* root = Construct_LevelOrder(v);

    vector<int> ans(level(root),0);
    levelOrder(root,ans);

    for(auto i:ans){
        cout<<i<<" ";
    }

    cout<<"\n";

    vector<int> answer(level(root),0);
    result(root,answer,0);
    for(auto i:answer){
        cout<<i<<" ";
    }


    return 0;
}