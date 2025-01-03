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

int level(Node* root){
    if(root==nullptr){
        return 0;
    } 
    int Tree_level = 1 + max(level(root->left),level(root->right));
    return Tree_level;
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(4);
    Node* c = new Node(7);
    Node* d = new Node(2);
    Node* e = new Node(5);
    Node* f = new Node(8);
    Node* g = new Node(9);


    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->right = f;

    d->left = g;

    cout<<"The Tree level is: ";
    cout<<level(a);

    return 0;
}