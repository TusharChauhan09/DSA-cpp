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

void result(Node* root ,vector<int>v, vector<vector<int>> &ans,int targetSum){
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr){
            if(targetSum==root->data){
                v.push_back(root->data);
                ans.push_back(v);
            }
            return;
        }
        v.push_back(root->data);
        result(root->left,v,ans,(targetSum-root->data));
        result(root->right,v,ans,(targetSum-root->data));
        }

int main(){
    vector<int>a = {5,4,8,11,INT_MIN,13,4,7,2,INT_MIN,INT_MIN,5,1};
    Node* root = Construct_LevelOrder(a);

    vector<vector<int>>ans;
    vector<int>v;
    int targetSum = 22;

    result(root,v,ans,targetSum);

    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }


    return 0;
}