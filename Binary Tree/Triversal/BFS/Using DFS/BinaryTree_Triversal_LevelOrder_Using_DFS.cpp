#include<iostream>
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

void nthlevel(Node* root,int level,int cur){
    if(root==nullptr){
        return;
    }
    if(cur==level){
        cout<<root->data<<" ";
        return;
    }
        nthlevel(root->left,level,cur+1);
        nthlevel(root->right,level,cur+1);
}
int level(Node* root){
    if(root==nullptr){
        return 0;
    }
    int l = 1 + max(level(root->left),level(root->right));
    return l;
}
void levelOrder(Node* root){
    int n = level(root);
    for(int i=1;i<=n;i++){
        nthlevel(root,i,1);
        cout<<"\n";
    }
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(7);
    Node* c = new Node(9);
    Node* d = new Node(2);
    Node* e = new Node(6);
    Node* f = new Node(9);
    Node* g = new Node(5);
    Node* h = new Node(11);
    Node* j = new Node(5);


    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->right = f;

    e->left = g;
    e->right = h;

    f->left = j;

    cout<<"\nElements are: \n";
    levelOrder(a);

    return 0;
}