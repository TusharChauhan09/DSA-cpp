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

int maximum(Node* root){
    if(root==nullptr){
        return INT8_MIN;
    }
    int Tree_max = max(root->data,max(maximum(root->left),maximum(root->right)));
    return Tree_max;
}

int main(){
    Node* a = new Node(2);
    Node* b = new Node(4);
    Node* c = new Node(10);
    Node* d = new Node(6);
    Node* e = new Node(15);
    Node* f = new Node(11);


    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->right = f;

    cout<<"The Tree max Node is: ";
    cout<<maximum(a);

    return 0;
}