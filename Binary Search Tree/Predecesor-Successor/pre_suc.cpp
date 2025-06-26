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

void display(Node* root){
    if(root==nullptr) return;
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

Node* bst(Node* root, int n){
    if(root==nullptr){
        return new Node(n);
    }
    if(root->data>n) root->left = bst(root->left,n);
    else root->right = bst(root->right,n);
    return root;
}

Node* construct(vector<int>v){
    Node* root = new Node(v[0]);
    for(int i=1;i<v.size();i++){
        bst(root,v[i]);
    }
    return root;
}


Node* predcessor(Node* root){
    if(root==nullptr) return nullptr;
    if(root->left==nullptr) return nullptr;
    Node* pred = root->left;
    while(pred->right){
        pred=pred->right;
    }
    return pred;
}

Node* successor(Node* root){
    if(root==nullptr) return nullptr;
    if(root->right==nullptr) return nullptr;
    Node* suc = root->right;
    while(suc->left){
        suc=suc->left;
    }
    return suc;
}

int main(){
    // construct
    vector<int>v = {50,30,20,40,70,60,80};
    Node* root = construct(v);

    display(root);
    cout<<"\n";
 

    // pass the node not the value if value then find node function should be made
    Node* pred = predcessor(root);
    cout<<pred->data<<"\n";

    Node* suc = successor(root);
    cout<<suc->data<<"\n";
 
    return 0;
}