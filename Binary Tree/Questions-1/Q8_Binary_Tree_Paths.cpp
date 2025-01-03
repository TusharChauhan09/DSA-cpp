#include<iostream>
#include<vector>
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

void helper(Node* root, string s, vector<string>&path){
    if(root==nullptr){ // for null node
        return;
    }
    string a = to_string(root->data);
    if(root->left==nullptr && root->right==nullptr){  // for leaf node
        s += a;
        path.push_back(s);
        return ;
    }
    helper(root->left,s+a+"->",path);
    helper(root->right,s+a+"->",path);
}
vector<string>paths(Node* root){
    vector<string>path;
    string s ="";
    helper(root,s,path);
    return path;
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    Node* h = new Node(9);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    d->right = h;

    c->right = f;

    f->left = g;

    vector<string>path = paths(a); 
    cout<<"All the paths are below: \n";
    for(auto i: path){
        cout<<i<<"    ";
    }

    return 0;
}